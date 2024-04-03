all: test
	./test.o
	@echo "\n"
#	valgrind ./test.o

test:
	cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 test.c get_next_line.c -o test.o

clean:
	rm -f *.o

.PHONY: all test clean