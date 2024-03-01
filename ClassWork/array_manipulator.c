// NASIR JACOB IDRIS
// ENE212-0223/2019

#include <stdio.h>
#include <stdlib.h>

int compare_func(const void *a, const void *b) {
   return ( *(int*)a - *(int*)b );
}

int main(){
    int n = 10;
    int numbers[10] = {11, 23, 17, 34, 62, 5, 19, 36, 25};
    int reference[10];
    int insert_value = 55;
    int insert_location = 5;
    int remove_location = 3;

    for(int i = 0; i < n; i++){
        printf("%d, ", numbers[i]);
        reference[i] = numbers[i];
    }
    printf("\n-- Original Array \n\n");

    printf("Enter the value to insert: ");
    scanf("%d", &insert_value);

    // Insert number at predefined location
    for(int j = 0; j < n; j++){
        if(j < insert_location){
            printf("%d, ", numbers[j]);
        }
        else if(j == insert_location){
            numbers[j] = insert_value;
            printf("-> %d <-, ", numbers[j]);
        }
        else if(j > insert_location){
            numbers[j] = reference[j-1];
            printf("%d, ", numbers[j]);
        }
    }

    printf("\n-- Array after adding element in the middle (%d) - Index [%d] \n\n", insert_value, insert_location);

    // Sort after inserting
    qsort(numbers, 10, sizeof(int), compare_func);
    for(int s = 0; s < n; s++){
        printf("%d, ", numbers[s]);
    }
    printf("\n-- Sorted array after inserting element \n\n");

    printf("Enter the position to remove an element: ");
    scanf("%d", &remove_location);
    int removed_number = numbers[remove_location];

    // Remove number at another predefined location
    for(int j = 0; j < n; j++){
        if(j >= remove_location && j < n-1){
            numbers[j] = numbers[j+1];
        }
        else if(j == n-1){
            numbers[j] = 0;
        }
    }
    
    // Print array after deleting element
    for(int p = 0; p < n; p++){
        printf("%d, ", numbers[p]);
    }
    printf("\n-- Array after removing element (%d) - Index [%d] \n\n", removed_number, remove_location);

}