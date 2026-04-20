/*
* File Name     : main.c
* Description   : contains function calling of all Modules
* Author        : Karan Sathvara
* Created       : 04-02-2026
*/


#include <stdio.h>
#include "header.h"
#include <stdint.h>

int main(int argc, char *argv[]){

/* --------- Module 1  --------- */

#if MODULE == 1 && TASK == 1
    print_HelloWorld();

#elif MODULE == 1 && TASK == 2
    print_HelloWorld2();

#elif MODULE == 1 && TASK == 3
    temp_converter();

#elif MODULE == 1 && TASK == 4
    celsius_fahrenheit();

#elif MODULE == 1 && TASK == 5
    celsius_fahrenheit_reverse();

#elif MODULE == 1 && TASK == 6
    verify_EOF();

#elif MODULE == 1 && TASK == 7
    value_of_EOF();

#elif MODULE == 1 && TASK == 8
    count_blanks_tabs_newlines();

#elif MODULE == 1 && TASK == 9
    removeMultipleSpaces();

#elif MODULE == 1 && TASK == 10
    escape_special_characters();

#elif MODULE == 1 && TASK == 11
    word_counter();

#elif MODULE == 1 && TASK == 12
    print_words_per_line();

#elif MODULE == 1 && TASK == 13
    histogram();

#elif MODULE == 1 && TASK == 14
    print_histogram_ofWord_frequency();

#elif MODULE == 1 && TASK == 15
    convert_temperature_using_helper();

#elif MODULE == 1 && TASK == 16
    print_longest_line();

#elif MODULE == 1 && TASK == 17
    print_lines_longer_than_8char();

#elif MODULE == 1 && TASK == 18
    remove_trailing_TabsSpace();

#elif MODULE == 1 && TASK == 19
    print_reverse_string();

#elif MODULE == 1 && TASK == 20
    detab();

#elif MODULE == 1 && TASK == 21
    entab();

#elif MODULE == 1 && TASK == 22
    fold_after_tenchars();

#elif MODULE == 1 && TASK == 23
    remove_commentsFrom_cfile();

#elif MODULE == 1 && TASK == 24
    check_syntax_errors();


/* --------- Module 2  --------- */


#elif MODULE == 2 && TASK == 1
    range_of_charcters();

#elif MODULE == 2 && TASK == 2
    printFirst_tenChar();

#elif MODULE == 2 && TASK == 3
    htoi();

#elif MODULE == 2 && TASK == 4
    squeeze();

#elif MODULE == 2 && TASK == 5
    any();

#elif MODULE == 2 && TASK == 6
    setbits();

#elif MODULE == 2 && TASK == 7
    invert();

#elif MODULE == 2 && TASK == 8
    rightrot();

#elif MODULE == 2 && TASK == 9
    bitcount();

#elif MODULE == 2 && TASK == 10
    lower();

/* --------- Module 3  --------- */


#elif MODULE == 3 && TASK == 1
    binarysearch();

#elif MODULE == 3 && TASK == 2
    escapes_tab_newline();

#elif MODULE == 3 && TASK == 3
    expand();

#elif MODULE == 3 && TASK == 4
    integer_to_character();

#elif MODULE == 3 && TASK == 5
    itob();

#elif MODULE == 3 && TASK == 6
    itoa();

/*  Task 2 with fgets */
#elif MODULE == 3 && TASK == 7
    Module3Task7();

/* Task 6 with string */
#elif MODULE == 3 && TASK == 8
    Module3Task8();



/* --------- Module 4  --------- */


#elif MODULE == 4 && TASK == 1
    strindex();

#elif MODULE == 4 && TASK == 2
    extended_atof();

#elif MODULE == 4 && TASK == 3
    reverse_Polish_calculator();

#elif MODULE == 4 && TASK == 4
    duplicate_swap_clear_stack();

#elif MODULE == 4 && TASK == 5
    sin_exp_pow_stack();

#elif MODULE == 4 && TASK == 6
    assign_value_to_characters();

#elif MODULE == 4 && TASK == 7
    string_using_ungets();

#elif MODULE == 4 && TASK == 8
    modified_getch();

#elif MODULE == 4 && TASK == 9
    eof_efficient();

#elif MODULE == 4 && TASK == 10
    revised_calculator_using_getline();

#elif MODULE == 4 && TASK == 11
    modified_getop();

#elif MODULE == 4 && TASK == 12
    integer_to_char_recursive();

#elif MODULE == 4 && TASK == 13
    reverse1_recursively();

#elif MODULE == 4 && TASK == 14
    swap_elements();


/* --------- Module 5  --------- */


#elif MODULE == 5 && TASK == 1
    getint();

#elif MODULE == 5 && TASK == 2
    getfloat();

#elif MODULE == 5 && TASK == 3
    str_cat();

#elif MODULE == 5 && TASK == 4
    str_end();

#elif MODULE == 5 && TASK == 5
    versions_of_libFunctions();

#elif MODULE == 5 && TASK == 6
    pointer_versions_of_Functions();

#elif MODULE == 5 && TASK == 7
    modified_readlines();

#elif MODULE == 5 && TASK == 8
    calender();

#elif MODULE == 5 && TASK == 9
    calender_using_ptr();

#elif MODULE == 5 && TASK == 10
    RPN_using_CLI(argc,argv);

#elif MODULE == 5 && TASK == 11
    entab_detab_CLI(argc,argv);

#elif MODULE == 5 && TASK == 12
    modified_entab_detab_CLI(argc,argv);

#elif MODULE == 5 && TASK == 13
    tail(argc,argv);

#elif MODULE == 5 && TASK == 14
    modified_sort(argc, argv);

#elif MODULE == 5 && TASK == 15
    addedFolding_sort(argc, argv);

#elif MODULE == 5 && TASK == 16
    addedDir_order_sort(argc, argv);

#elif MODULE == 5 && TASK == 17
    sort_specific_fields(argc, argv);

#elif MODULE == 5 && TASK == 18
    modified_dcl();

#elif MODULE == 5 && TASK == 19
    undcl();

#elif MODULE == 5 && TASK == 20
    modified_dcl_for_args();


/* --------- Module 6  --------- */

#elif MODULE == 6 && TASK == 1
    modified_getword();

#elif MODULE == 6 && TASK == 2
    word_freq_group_using_BST();

#elif MODULE == 6 && TASK == 3
    word_freq_withoutNoise_withLineNo_using_BST();

#elif MODULE == 6 && TASK == 4
    word_freq_decreasing_order_using_BST();

#elif MODULE == 6 && TASK == 5
    hash_table();

#elif MODULE == 6 && TASK == 6
    hashtable_with_macro();

/* --------- Module 7  --------- */


#endif

    return 0;
}
