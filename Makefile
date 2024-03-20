all:
	cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 test.c get_next_line.c get_next_line_utils.c get_next_line.h -o test.o

clean:
	rm -f *.o