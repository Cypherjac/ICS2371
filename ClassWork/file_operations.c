#include <stdio.h>

char input_file[] = "C:\\wamp64\\www\\ICS2371-1\\ClassWork\\files\\input.txt";
char output_file[] = "C:\\wamp64\\www\\ICS2371-1\\ClassWork\\files\\output.txt";

int main()
{
    FILE *inputFile, *outputFile;
    char buffer[100];

    printf("Enter some text: ");
    fgets(buffer, sizeof(buffer), stdin);
    inputFile = fopen(input_file, "w+");
    if(inputFile == NULL){
        printf("Error creating input.txt\n");
        return 1;
    }
    fputs(buffer, inputFile);
    fclose(inputFile);

    inputFile = fopen(input_file, "r");
    if(inputFile == NULL){
        printf("Error opening input.txt\n");
        return 1;
    }

    // Append new content to the end of the file
    outputFile = fopen(output_file, "a");
    if(outputFile == NULL){
        printf("Error creating output.txt\n");
        fclose(inputFile);
        return 1;
    }

    while(fgets(buffer, sizeof(buffer), inputFile) != NULL){
        fputs(buffer, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("File contents copied successfully.\n");
    return 0;
}
