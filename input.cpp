#include "input.hpp"
#include <queue>
#include <thread>
#include <mutex>
#include <atomic>
#include "ncurses.hpp"
#include <ncurses.h>

struct input_impl
{
    cgt::ncurses_t ncurse;
    std::queue<cgt::input_event_t> event_queue;
    std::thread *p_listener_thread;
    std::mutex queue_lock;
    std::atomic<int> loop_indicater = 1;
    cgt::input_event_t consume()
    {
        while (event_queue.empty())
            ;
        queue_lock.lock();
        auto r = event_queue.front();
        event_queue.pop();
        queue_lock.unlock();
        return r;
    }
    void extend(cgt::input_event_t ev)
    {
        queue_lock.lock();
        event_queue.push(ev);
        queue_lock.unlock();
    }
    void start_listen()
    {
        auto listener = [this]()
        {
            while (this->loop_indicater.load() == 1)
            {
                switch (ncurse.getkey())
                {
                case KEY_UP:
                    this->extend(cgt::input_event_t::up);
                    break;
                case KEY_DOWN:
                    this->extend(cgt::input_event_t::down);
                    break;
                case KEY_LEFT:
                    this->extend(cgt::input_event_t::left);
                    break;
                case KEY_RIGHT:
                    this->extend(cgt::input_event_t::right);
                    break;
                case 27: // ESC or ALT
                case 'q':
                    this->extend(cgt::input_event_t::esc);
                    break;
                case 'm':
                    this->extend(cgt::input_event_t::mark);
                    break;
                case 's':
                    this->extend(cgt::input_event_t::select);
                default:
                    break;
                }
            }
        };
        p_listener_thread = new std::thread(listener);
    }
    void stop_listen()
    {
        loop_indicater.store(0);
        p_listener_thread->join();
    }
};

static std::atomic<size_t> _ref_cnt{0};

namespace cgt
{
#define impl ((struct input_impl *)(_impl))
    input_t::input_t()
    {
        if (!_ref_cnt.load())
        {
            _impl = new input_impl;
            impl->start_listen();
        }
        ++_ref_cnt;
    }

    input_t::~input_t()
    {
        --_ref_cnt;
        if (!_ref_cnt.load())
        {
            impl->stop_listen();
            delete impl;
        }
    }

    input_event_t input_t::get_input()
    {
        return impl->consume();
    }
}