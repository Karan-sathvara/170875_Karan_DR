/*
* File Name     : header.h
* Description   : contains function declaration of all Modules
* Author        : Karan Sathvara
* Created       : 04-02-2026
*/

#include <stdint.h>

#ifndef HEADER_H
#define HEADER_H

/*   Module 1    */
void print_HelloWorld();

void print_HelloWorld2();

void temp_converter();

void celsius_fahrenheit();

void celsius_fahrenheit_reverse();

void verify_EOF();

void value_of_EOF();

void count_blanks_tabs_newlines();

void removeMultipleSpaces();

void escape_special_characters();

void word_counter();

void print_words_per_line();

void histogram();

void print_histogram_ofWord_frequency();

void convert_temperature_using_helper();

void print_longest_line();

void print_lines_longer_than_8char();

void remove_trailing_TabsSpace();

void print_reverse_string();

void detab();

void entab();

void fold_after_tenchars();

void remove_commentsFrom_cfile();

void check_syntax_errors();

/*   Module 2    */

void range_of_charcters();

void printFirst_tenChar();

void htoi();

void squeeze();

void any();

void setbits();

void invert();

void rightrot();

void bitcount();

void lower();

/*   Module 3    */

void binarysearch();

void escapes_tab_newline();

void expand();

void integer_to_character();

void itob();

void itoa();

/* extra version of 2 and 6 */
void Module3Task7();
void Module3Task8();

/*   Module 4    */

void strindex();

void extended_atof();

void reverse_Polish_calculator();

void duplicate_swap_clear_stack();

void sin_exp_pow_stack();

void assign_value_to_characters();

void string_using_ungets();

void modified_getch();

void eof_efficient();

void revised_calculator_using_getline();

void modified_getop();

void integer_to_char_recursive();

void reverse1_recursively();

void swap_elements();

/* ------ Module 5 ------ */

void getint();

void getfloat();

void str_cat();

void str_end();

void versions_of_libFunctions();

void pointer_versions_of_Functions();

void modified_readlines();

void calender();

void calender_using_ptr();

void RPN_using_CLI(int8_t argc, char *argv[]);

void entab_detab_CLI(int8_t argc, char *argv[]);

void CLI_detab(int16_t tabstops[], int16_t ntab);
void CLI_detab(int16_t tabstops[], int16_t ntab);

void modified_entab_detab_CLI();

void Mn_CLI_detab(int8_t idxM, int8_t idxN);
void Mn_CLI_detab(int8_t idxM, int8_t idxN);

void tail(int8_t argc, char *argv[]);

void modified_sort(int8_t argc, char *argv[]);

void addedFolding_sort(int8_t argc, char *argv[]);

void addedDir_order_sort(int8_t argc,char *argv[]);

void sort_specific_fields(int8_t argc, char *argv[]);

void modified_dcl();

void undcl();

void modified_dcl_for_args();

/* ------ Module 6 ------ */

void modified_getword();

#endif
