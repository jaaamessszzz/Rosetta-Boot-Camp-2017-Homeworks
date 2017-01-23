CPPFLAGS=-std=c++11

run_test: all
	./test_program.sh

all: main test
	rm *.o

test: Coordinates.o test.o MonteCarlo.o Landscape.cc run.o Uniform.o
	clang++ -o test Coordinates.o test.o MonteCarlo.o run.o Uniform.o

main: Coordinates.o main.o MonteCarlo.o Landscape.cc run.o Uniform.o
	clang++ -o main Coordinates.o main.o MonteCarlo.o run.o Uniform.o

test.o:
	clang++ $(CPPFLAGS) -c test.cc

main.o:
	clang++ $(CPPFLAGS) -c main.cc

Coordinates.o:
	clang++ $(CPPFLAGS) -c Coordinates.cc

MonteCarlo.o:
	clang++ $(CPPFLAGS) -c MonteCarlo.cc

Uniform.o:
	clang++ $(CPPFLAGS) -c Uniform.cc
