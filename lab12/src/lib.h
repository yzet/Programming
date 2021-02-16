#ifndef _LABORATORY_12_14_
#define _LABORATORY_12_14_

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * Return count of numbers in text
 *
 * @param text text
 * @return count of numbers in text
 *
**/
size_t get_count_of_numbers_in_text(char text[]);

/**
 * Set numbers from text into numbers in text array
 *
 * @param text text
 * @param numbers_in_text array for numbers
 * @return
 *
**/
void get_numbers_in_text(char text[], long *numbers_in_text);

/**
 * Take input and print result by scanf and printf
 *
 * @param input string for input
 * @return
 *
**/
void use_scanf_and_printf(char *input);

/**
 * Print numbers by printf
 *
 * @param numbers array with numbers
 * @param count_of_numbers count of numbers
 * @return
 *
**/
void print_numbers_by_printf(long *numbers, size_t count_of_numbers);

/**
 * Create string for output
 * @param output string for output
 * @param numbers array with numbers
 * @param count_of_numbers count of numbers
 * 
**/
void create_output_string(char *output, long *numbers, size_t count_of_numbers);

/**
 * Take input and print result by gets and puts
 *
 * @param input string for input
 * @return
 *
**/
void use_gets_and_puts(char *input);

/**
 * Print numbers by puts
 *
 * @param numbers array with numbers
 * @param count_of_numbers count of numbers
 * @return
 *
**/
void print_numbers_by_puts(long *numbers, size_t count_of_numbers);

/**
 * Take input and print result by getc and putc
 *
 * @param input string for input
 * @param input_length maximum input length
 * @return
 *
**/
void use_getc_and_putc(char *input, size_t input_length);

/**
 * Print numbers by putc
 *
 * @param numbers array with numbers
 * @param count_of_numbers count of numbers
 * @return
 *
**/
void print_numbers_by_putc(long *numbers, size_t count_of_numbers);

/**
 * Take input and print result by read and write
 *
 * @param input string for input
 * @return
 *
**/
void use_read_and_write(char *input);

/**
 * Print numbers by write
 *
 * @param numbers array with numbers
 * @param count_of_numbers count of numbers
 * @return
 *
**/
void print_numbers_by_write(long *numbers, size_t count_of_numbers);

/**
 * Move carrige to next raw by searching '\n'.
 * 
 * @param input input string which was read
 * @return
**/
void move_carriage_to_next_raw(char *input);

#endif