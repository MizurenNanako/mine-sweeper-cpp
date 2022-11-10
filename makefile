CXX		 	= g++
CXXFLAGS	= -O3
LDFLAGS		= -lncurses

test: CXXFLAGS = -g
test: test.o input.o printer.o ncurses.o game.o board.o ncurses_window.o
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@

test.cpp:
ncurses_window.cpp: ncurses.hpp
(*.cpp) : $(*.hpp) util.hpp

(*.o) : $(*.cpp)
	$(CXX) $(CXXFLAGS) -c $<

clean_exec : 
	if (ls ./test); then rm test; fi

clean_obj : 
	if (ls ./*.o); then rm *.o; fi

clean : clean_exec clean_obj