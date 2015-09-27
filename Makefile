CXX = g++
CXXFLAGS += -Wall -std=c++11

all: z85

z85: z85.cpp z85.o z85_impl.o
	$(CXX) $(CXXFLAGS) z85.cpp z85.o z85_impl.o -o z85

z85.o: lib-z85/z85.c
	$(CXX) -c lib-z85/z85.c

z85_impl.o: lib-z85/z85_impl.cpp
	$(CXX) -c lib-z85/z85_impl.cpp

clean:
	rm -f z85 z85.o z85_impl.o

