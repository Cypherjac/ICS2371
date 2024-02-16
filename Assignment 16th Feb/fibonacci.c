/*
ENE212-0223/2019
Nasir Jacob Idris
*/
// Fibonacci Series

#include <stdio.h>

int fibonacci(int number) {
    if(number <= 1){
        return number;
    }
    else {
        return(fibonacci(number-1) + fibonacci(number-2));
    }
}

int main() {
    int number;
    printf("Enter number of terms in the series: ");
    scanf("%d", &number);

    printf("Fibonacci Series: ");
    for(int i = 0; i < number; i++){
        // Check for the last number
        // Otherwise append an arrow after every number in the series
        if(i != number-1){
            printf("%d -> ", fibonacci(i));
        }
        else {
            printf("%d", fibonacci(i));
        }
    }

    return 0;
}
