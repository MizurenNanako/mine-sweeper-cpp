CXX		 	= g++
CXXFLAGS	= -O3
LDFLAGS		= -lncurses

test: CXXFLAGS = -g
test: OBJS = test.o input.o printer.o
test: test.o input.o printer.o
	$(CXX) $(CXXFLAGS) $(OBJS) $(LDFLAGS) -o $@

(*.o) : $(*.cpp)
	$(CXX) $(CXXFLAGS) -c $<

clean_exec : test
	rm $<

clean_obj : 
	rm *.o

clean : clean_exec clean_obj