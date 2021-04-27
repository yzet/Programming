#CC = gcc
#C_OPTS = -std=gnu11 -g -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -I./src
CC = clang
# C_OPTS = -fsanitize=address -g -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -I./src src/data.c src/list.c src/ui.c src/time_calculate.c
C_OPTS = -std=gnu11 -g -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference

all: clean prep compile

clean:
	rm -rf dist

prep:
	mkdir dist

compile: create_bins

touch:
	doxygen Doxyfile

create_bins: main.bin test.bin
main.bin: src/main.c
	# $(CC) $(C_OPTS) $< -o ./dist/$@
	$(CC) -DDEBUG -I./shared $< -lagencies -L./shared -o dist/$@

test.bin: test/test.c
	# $(CC) $(C_OPTS) $< -o ./dist/$@
	$(CC) -I./shared $< -lagencies -L./shared -o dist/$@

create_agencies_static_library: agencies.o libagencies.a prep_shared_dir

agencies.o:
	$(CC) -c $(C_OPTS) -DDEBUG src/data.c -o ./dist/data.o
	$(CC) -c $(C_OPTS) -DDEBUG src/list.c -o ./dist/list.o
	$(CC) -c $(C_OPTS) -DDEBUG src/time_calculate.c -o ./dist/time_calculate.o
	$(CC) -c $(C_OPTS) -DDEBUG src/ui.c -o ./dist/ui.o

libagencies.a:
	ar rcs ./dist/$@ ./dist/data.o ./dist/list.o ./dist/time_calculate.o ./dist/ui.o

prep_shared_dir:
	cp src/agencies.h shared/
	cp src/data.h shared/
	cp src/list.h shared/
	cp src/time_calculate.h shared/
	cp src/ui.h shared/
	cp ./dist/libagencies.a shared/

ui.o:
	$(CC) -c -I./shared $(C_OPTS) src/ui.c -lagencies -L./shared -o ./dist/ui.o
