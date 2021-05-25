CC = g++
C_OPTS = -g -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference

all: clean prep compile

clean:
	rm -rf dist

prep:
	mkdir dist

compile: create_bins

create_bins: main.bin test.bin

main.bin: src/main.cpp
	$(CC) $(C_OPTS) -I./src src/agency.cpp src/agencies_list.cpp $< -o ./dist/$@

test.bin: test/test.cpp
	$(CC) $(C_OPTS) /usr/src/gtest/src/gtest-all.cc  -I /usr/src/gtest -lpthread -I/src src/agency.cpp src/agencies_list.cpp $< -o ./dist/$@