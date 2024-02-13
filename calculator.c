#include <stdio.h>

int sum(int a, int b){
    return a + b;
}

int difference(int a, int b){
    return a - b;
}

int main(){
    int num1, num2;
    printf("Enter your first number: "); scanf("%d", &num1);
    printf("Enter your second number: "); scanf("%d", &num2);
    printf("The sum of the numbers is: %d\n", sum(num1, num2));
    printf("The difference of the numbers is: %d\n", difference(num1, num2));
    printf("The sum and difference of the numbers are %d and %d\n", sum(num1, num2), difference(num1, num2));
}
