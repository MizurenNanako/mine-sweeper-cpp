#include "input.hpp"
#include <ncurses.h>
#include <queue>
#include <thread>
#include <mutex>
#include <atomic>

struct input_impl
{
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
                switch (getch())
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

typedef struct input_impl *m;

namespace cgt
{
    input_t::input_t()
    {
        raw();
        intrflush(stdscr, FALSE);
        keypad(stdscr, TRUE);
        set_escdelay(10);
        impl = new input_impl;
        m(impl)->start_listen();
    }

    input_t::~input_t()
    {
        m(impl)->stop_listen();
        delete m(impl);
    }

    input_event_t input_t::get_input()
    {
        return m(impl)->consume();
    }
}