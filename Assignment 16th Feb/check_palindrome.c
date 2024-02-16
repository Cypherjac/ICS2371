/*
ENE212-0223/2019
Nasir Jacob Idris
*/
// Palindrome Checker

#include <stdio.h>
#include <string.h>

int check_palindrome(char value[]){
    int counter = 0;
    int string_size = strlen(value) - 1;

    while(string_size > counter) {
        if (value[counter++] != value[string_size--]) {
            printf("%s is not a palindrome.\n", value);
            return 0;
        }
    }

    printf("%s is a palindrome.\n", value);
    return 0;
}

int main() {
    char value[100];

    printf("Enter a string to check: ");
    fgets(value, sizeof(value), stdin);
    value[strlen(value) - 1] = '\0';

    check_palindrome(value);
    return 0;
}