# Usage:
# make				# compile files, creates program,  and run
# make build		# compile files and creates program
# make run			# runs the program

.PHONY: all build run debug clean

SRCS := $(wildcard *.cpp) $(wildcard **/*.cpp) $(wildcard **/**/*.cpp)

all: build run

build:
	clang++ -std=c++14 ${SRCS} -o program

run:
	./program

debug:
	clang++ -std=c++14 ${SRCS} -o program -g

clean:
	rm program
