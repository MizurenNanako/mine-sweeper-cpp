CXX		 	= g++
CXXFLAGS	= -O3
LDFLAGS		= -lncurses

test: CXXFLAGS = -g
test: test.o input.o printer.o ncurses.o
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@

(*.o) : $(*.cpp)
	$(CXX) $(CXXFLAGS) -c $<

clean_exec : 
	rm test

clean_obj : 
	rm *.o

clean : clean_exec clean_obj