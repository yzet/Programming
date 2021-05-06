CC = g++
C_OPTS = -g -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference

all: clean prep compile

clean:
	rm -rf dist

prep:
	mkdir dist

compile: create_bins

create_bins: main.bin

main.bin: src/main.cpp
	$(CC) $(C_OPTS) -I./src src/agency.cpp src/agencies_dynamic_array.cpp $< -o ./dist/$@