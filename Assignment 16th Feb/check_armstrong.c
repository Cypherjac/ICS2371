/*
ENE212-0223/2019
Nasir Jacob Idris
*/
// Armstrong Number Checker

#include <stdio.h>
#include <math.h>

int check_armstrong(int number) {
    int initial, remainder, n = 0;
    double result = 0.0;

    initial = number;

    // store the number of digits of the given number in n
    while(initial != 0) {
        initial /= 10;
        n++;
    }
    initial = number;

    // check whether the number is an armstrong number
    while(initial != 0){
        remainder = initial % 10;
        // add the next digit raised to a power equal to n(n = the number of digits)
        result += pow(remainder, n);
        initial /= 10;
    }

    // cast the result as an integer value (from the initial double type)
    return (int)result == number;
}

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    if(check_armstrong(number)){
        printf("%d is an armstrong number.\n", number);
    }
    else {
        printf("%d is not an armstrong number.\n", number);
    }

    return 0;
}