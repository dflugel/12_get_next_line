all: test
	./test.o
	@echo "\n"
#	valgrind --leak-check=full --track-origins=yes ./test.o

test:
	cc -Wall -Wextra -Werror -D BUFFER_SIZE=3 test.c get_next_line.c get_next_line_utils.c -o test.o

clean:
	rm -f *.o

fclean: clean

.PHONY: all test clean fclean