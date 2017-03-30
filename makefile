PROGRAM= solution
PROGRAM_DBG = solution.dbg
CC= gcc
CFLAGS= -Wall
CFLAGS_DBG = -Wall -g

all: $(PROGRAM)
solution: solution.o parse.o tree.o list.o
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: debug
debug: $(PROGRAM_DBG)
solution.dbg: solution.o parse.o tree.o list.o
	$(CC) $(CFLAGS_DBG) -o $@ $^

.PHONY: clean
clean:
	rm -rf $(PROGRAM) $(PROGRAM_DBG) *.o
