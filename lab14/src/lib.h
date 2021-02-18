#include <stdlib.h>
#include <dirent.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

/**
 * Iterates over files and directories, displays their names on the screen
 *  
 * @param directory_name name of directory for iterate
 * @param count_of_space count of space for name
**/
void show_directory_file_struct(char *directory_name, int count_of_space);

/**
 * Calculate directory size
**/
void get_directory_size();

/**
 * Read directory name from console and save it
 *  
 * @param to string for saving directory name
**/
void get_directory_name(char *to);


/**
 * Print directory size in console
**/
void show_directory_size();


/**
 * Calculate directory size 
 *  
 * @param directory_name name of directory for calculating
**/
double calculate_directory_size(char *directory_name);

/**
 * Calculate file size 
 *  
 * @param file file for calculating
**/
long int calculate_file_size(FILE * file);

/**
 * Determine digits 
**/
void calculate_count_of_digits();

/**
 * Read text from file
 * 
 * @param filename name of file
 * @param result string for saving text from file
 * @param buf_size maximum number of characters
**/
void read_from_file(char *filename, char **result, size_t buf_size);

/**
 * Read text from file
 * 
 * @param filename name of file
 * @param numbers array with numbers
 * @param count_of_numbers count of numbers
**/
void write_to_file(char *filename, long *numbers, size_t count_of_numbers);

/**
 * Return count of numbers in text
 *
 * @param text text
 * @return count of numbers in text
**/
size_t get_count_of_numbers_in_text(char *text);

/**
 * Set numbers from text into numbers in text array
 *
 * @param text text
 * @param numbers_in_text array for numbers
 * @return
**/
void get_numbers_in_text(char *text, long *numbers_in_text);

/**
 * Move carrige to next raw by searching '\n'.
 * 
 * @param input input string which was read
 * @return
**/
void move_carriage_to_next_raw(char *input);