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
	$(CC) $(C_OPTS) -I./src src/agency.cpp  src/legal_agency.cpp src/marriage_agency.cpp src/agency_creator.cpp src/agencies_vector.cpp $< -o ./dist/$@

test.bin: test/test.cpp
	$(CC) $(C_OPTS) /usr/src/gtest/src/gtest_main.cc /usr/src/gtest/src/gtest-all.cc -I /usr/include -I /usr/src/gtest -L /usr/local/lib -lpthread -I/src src/agency.cpp src/legal_agency.cpp src/marriage_agency.cpp src/agencies_vector.cpp $< -o ./dist/$@