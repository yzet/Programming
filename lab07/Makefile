#targets = main1.c main2.c main3.c main4.c main5.c main6.c
CC = gcc
C_OPTS = -std=gnu11 -g -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -I./src

all: clean prep compile

clean:
	rm -rf dist

prep:
	mkdir dist

compile: create_bins

create_bins: main_lab_5.bin main_lab_6.bin main.bin
	
main_lab_5.bin: src/main_lab_5.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
main_lab_6.bin: src/main_lab_6.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
main.bin: src/main.c
	$(CC) $(C_OPTS) $< -o ./dist/$@