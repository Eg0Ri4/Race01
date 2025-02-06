CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -Iinc

all: way_home

way_home:
	clang  $(CFLAGS) src/*.c -o read_file

clean:
	rm -f way_home	

re: clean all
