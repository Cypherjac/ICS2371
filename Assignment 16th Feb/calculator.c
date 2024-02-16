/*
ENE212-0223/2019
Nasir Jacob Idris
*/
// Advanced Calculator
// Integers-only support to allow demonstration of the modulus function
// Division returns an integer that is rounded off

#include <stdio.h>
#include <string.h>
#include <math.h>

char *operators[] = {"sum", "dif", "div", "mul", "mod", "com", "all"};

// Operator Functions
int sum(int a, int b){
    return a+b;
}
int difference(int a, int b){
    return a-b;
}
int division(int a, int b){
    return a/b;
}
int multiplication(int a, int b){
    return a*b;
}
void comparison(int a, int b){
    if(a > b){
        printf("%d is greater than %d (%d > %d)\n", a, b, a, b);
    }
    else if(b > a){
        printf("%d is greater than %d (%d > %d)\n", b, a, b, a);
    }
    else {
        printf("%d is equal to %d (%d = %d)\n", b, a, b, a);
    }
}
int modulus(int a, int b){
    return a%b;
}

// Commands to be input in the terminal
void initialize_commands(){
    printf("-----------------------------\n");
    printf("Enter a command:\n");
    printf("all: All\n");
    printf("sum: Sum\n");
    printf("dif: Difference\n");
    printf("div: Division\n");
    printf("mul: Multiplication\n");
    printf("mod: Modulus\n");
    printf("com: Comparison\n");
    printf("exit: Exit\n");
    printf("-------------------\n");
}

int main(){
    int num1, num2;
    char command[4];
    // State variable to check whether to wait for user input or exit the calculator session
    int state = 1;
    while(state){
        initialize_commands();
        scanf("%s", command);
        // check command in the library of commands before executing
        if(!strcmp(command, "exit")){
            state = 0;
            break;
        }
        else {
            int len = sizeof(operators)/sizeof(operators[0]);
            int i;
            for(i = 0; i < len; ++i)
            {
                if(!strcmp(operators[i], command))
                {
                    printf("Enter your first number: ");
                    scanf("%d", &num1);
                    printf("Enter your second number: ");
                    scanf("%d", &num2);
                    if(!strcmp(command, "sum")){
                        printf("%d + %d = %d\n", num1, num2, sum(num1, num2));
                    }
                    else if(!strcmp(command, "dif")){
                        printf("%d - %d = %d\n", num1, num2, difference(num1, num2));
                    }
                    else if(!strcmp(command, "div")){
                        printf("%d / %d = %d\n", num1, num2, division(num1, num2));
                    }
                    else if(!strcmp(command, "mul")){
                        printf("%d * %d = %d\n", num1, num2, multiplication(num1, num2));
                    }
                    else if(!strcmp(command, "com")){
                        comparison(num1, num2);
                    }
                    else if(!strcmp(command, "mod")){
                        printf("%d mod %d = %d\n", num1, num2, modulus(num1, num2));
                    }
                    else if(!strcmp(command, "all")){
                        printf("%d + %d = %d\n", num1, num2, sum(num1, num2));
                        printf("%d - %d = %d\n", num1, num2, difference(num1, num2));
                        printf("%d / %d = %d\n", num1, num2, division(num1, num2));
                        printf("%d * %d = %d\n", num1, num2, multiplication(num1, num2));
                        comparison(num1, num2);
                        printf("%d mod %d = %d\n", num1, num2, modulus(num1, num2));
                    }
                }
            }
        }
    }
}
