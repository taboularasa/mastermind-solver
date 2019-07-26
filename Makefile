P = msolver
OBJECTS = solver.o
CFLAGS = -g -Wall
LDLIBS=
CC=gcc

$(P): $(OBJECTS)

testing: $(OBJECTS)

runtests: testing
	./testing

.PHONY: runtests
