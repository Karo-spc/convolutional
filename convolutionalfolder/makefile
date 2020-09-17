sources:=$(wildcard *.cpp)
objects:=$(patsubst %.cpp,%.o,$(sources))
exe=main.exe

.PHONY: all
all: $(exe)


%.o: %.cpp
	g++ -c -std=c++11 $< -o $@

$(exe): $(objects)
	g++ $? -o $@
	rm -rf $(objects)
	doxygen -g
	doxygen Doxyfile



	


