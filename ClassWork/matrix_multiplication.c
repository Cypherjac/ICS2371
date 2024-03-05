// NASIR JACOB IDRIS
// ENE212-0223/2019

#include <stdio.h>
#include <stdlib.h>
// Imports EXIT_FAILURE

#define R1 3
#define C1 2
#define R2 2
#define C2 3

int check_compatibility(){
    if(R1 == C2){
        return 1;
    }
    else {
        return 0;
    }
}

int main(){
    int matrix1[R1][C1] =
    {
        {1, 2},
        {3, 4},
        {8, 9},
    };
    int matrix2[R2][C2] =
    {
        {7, 8, 9},
        {4, 5, 6},
    };

    if(check_compatibility() == 1){
        printf("The 2 matrices are COMPATIBLE:\n[Matrix1 Rows = %d][Matrix2 Cols = %d]\n", R1, C2);
    }
    else {
        printf("The matrices are NOT COMPATIBLE:\n[Matrix1 Rows = %d][Matrix2 Cols = %d]\n", R1, C2);
        exit(EXIT_FAILURE);
    }

    int matrix_result[R1][C2];

    // initialize the matrix with 0s
    for(int i = 0; i < R1; i++){
        for(int j = 0; j < C2; j++){
            matrix_result[i][j] = 0;
        }
    }

    // Multiply the matrices
    for(int i = 0; i < R1; i++){
        for(int j = 0; j < C2; j++){
            for (int k = 0; k < R2; k++){
                matrix_result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
            printf("%d\t", matrix_result[i][j]);
        }
        printf("\n");
    }

}