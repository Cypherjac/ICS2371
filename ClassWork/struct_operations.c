#include <stdio.h>

#define STUDENT_NAME_SIZE 20
#define REG_NUMBER_SIZE 50
#define NUMBER_OF_STUDENTS 5
#define MIN_COURSES 3
#define MAX_COURSES 8

struct StudentDetails {
    char first_name[STUDENT_NAME_SIZE];
    char last_name[STUDENT_NAME_SIZE];
    char reg_number[REG_NUMBER_SIZE];
    int courses_number;
    char courses[][5];
} student_details[5];

void display_options(){
    printf("\nWhat do you want to do next?\n");
    printf("1. Add another student\n");
    printf("2. Edit an existing student\n");
    printf("3. Display student details\n");
    printf("4. Exit\n");
}

void store_student_details(int i){
    int courses_number = 3, retries = 0;
    printf("Enter first name: ");
    scanf("%s", student_details[i].first_name);
    printf("Enter last name: ");
    scanf("%s", student_details[i].last_name);
    printf("Enter registration number: ");
    scanf("%s", student_details[i].reg_number);
    printf("Ener the number of courses being undertaken\nA minimum of 3 courses, maximum of 8: ");
    scanf("%d", &courses_number);
    
    while(courses_number < MIN_COURSES || courses_number > MAX_COURSES){
        retries++;
        printf("You need to enter a minimum of %d and a maximum of %d!\n", MIN_COURSES, MAX_COURSES);
        if(retries == 3){
            courses_number = 3;
            printf("Number of courses set to %d!\n", MIN_COURSES);
            break;
        }
        scanf("%d", &courses_number);
    }

    student_details[i].courses_number = courses_number;
    for(int c = 0; c < courses_number; c++){
        printf("Course %d: ", c+1);
        scanf("%s", student_details[i].courses[c]);
    }
    printf("-- Student details recorded! --\n");
}


void edit_student_details(int count){
    int access, option;
    printf("Available students: %d\n", count);
    printf("Enter the number of the student you want to edit: \n");
    scanf("%d", &access);

    while(!(access > 0 && access <= count)){
        printf("Student is not available!\n");
        scanf("%d", &access);
    }
    // Adjust to match array index
    access -= 1;

    printf("What field do you want to edit?\n");
    printf("1. First Name\n");
    printf("2. Last Name\n");
    printf("3. Reg. Number\n");
    printf("4. Courses\n");
    scanf("%d", &option);
    
    switch(option){
        case 1:
            printf("Enter the new First Name\n");
            scanf("%s", student_details[access].first_name);
            break;
        case 2:
            printf("Enter the new Last Name\n");
            scanf("%s", student_details[access].last_name);
            break;
        case 3:
            printf("Enter the new Reg. Number\n");
            scanf("%s", student_details[access].reg_number);
            break;
        case 4:
            printf("Available courses:\n");
            for(int i = 0; i < student_details[access].courses_number; i++){
                printf("%d. %s", i+1, student_details[access].courses[i]);
            }
            int course_number;
            printf("Enter the course you want to edit: \n");
            scanf("%d", &course_number);
            printf("Enter the new course: \n");
            scanf("%s", student_details[access].courses[course_number]);
            break;
    }
}

void display_student_details(int count){
    for(int i = 0; i < count; i++){
        printf("----- STUDENT %d Details\n", i+1);
        printf("Name: %s %s\n", student_details[i].first_name, student_details[i].last_name);
        printf("Reg. No.: %s\n", student_details[i].reg_number);
        printf("Courses:\n");
        for(int c = 0; c < student_details[i].courses_number; c++){
            printf("Course %d: %s\n", c+1, student_details[i].courses[c]);
        }
        printf("-----\n");
    }
}

int main(){

    int option = 3, student_count = 0;

    printf("----- STUDENT RECORDS PROGRAM -----\n");
    printf("Enter the details of the first student:\n");

    store_student_details(student_count);
    student_count++;

    while((option > 0 && option <= 4)){
        display_options();
        scanf("%d", &option);
        if(option > 0 && option <= 4){
            switch(option){
                case 1:
                    store_student_details(student_count);
                    student_count++;
                    break;
                case 2:
                    edit_student_details(student_count);
                    break;
                case 3:
                    display_student_details(student_count);
                    break;
                case 4:
                    return 0;
            }
        }
        else {
            printf("Command not identified\n");
        }
    }

    return 0;
}