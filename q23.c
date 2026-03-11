#include <stdio.h>

int main() {

    printf("Hello world");

    // This is single line comment

    printf("This is not // a comment");

    char c = '/';
    char star = '*';

    /*
        This is a multiline comment
        It should disappear completely
    */

    printf("Multiline /* not comment */ inside string");


    printf("Escaped quote: \" still string");

    /*

    This is also comment


    */


    printf("Done!");

}
