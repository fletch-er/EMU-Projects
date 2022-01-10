#include <stdio.h>
#include <ctype.h>
#include <string.h>

void fileFun(char *in);


int main() {
    printf("Enter in the name of the input file: ");
    char fileName[32];
    scanf("%s", fileName);
    fileFun(fileName);
}

void fileFun(char *in) {
    char lastName[1024];
    int age;

    FILE *file_input;
    file_input = fopen(in, "r");

    while ((fscanf(file_input, "%s %d", lastName, &age)) == 2) {
        if (age >= 20 && strlen(lastName) <= 5) {
            printf("%s %d\n", lastName, age);
        }
    }
}