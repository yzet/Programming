#targets = main1.c main2.c main3.c main4.c main5.c main6.c
#CC = gcc
#C_OPTS = -std=gnu11 -g -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -I./src
CC = clang
C_OPTS = -fsanitize=address -g -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -I./src src/lib.c


all: clean prep compile

clean:
	rm -rf dist

prep:
	mkdir dist

compile: create_bins

touch:
	doxygen Doxyfile

create_bins: main.bin	
main.bin: src/main.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
