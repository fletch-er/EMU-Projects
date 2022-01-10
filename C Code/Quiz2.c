#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void quiz(char *infile, char *outfile);

int main()
{
    printf("Enter the name of input file: ");
    char in_file[32];
    scanf("%s", in_file);
    printf("Enter the name of output file: ");
    char out_file[32];
    scanf("%s", out_file);
    quiz(in_file, out_file);
}

void quiz(char *infile, char *outfile)
{
    FILE *file_input;
    file_input = fopen(infile, "r");
    FILE *file_output;
    file_output = fopen(outfile, "w");

    int num_students;
    fscanf(file_input, "%d", &num_students);

    int size = 100;
    char names[1024];
    int ages[1024];

    char temp_name[64];
    int temp_age;
    int count = 0;
    while ((fscanf(file_input, "%s %d", temp_name, &temp_age)) == 2)
    {
        // SOMETHING IS WRONG HERE
        strcpy(names, temp_name);
        ages[count] = temp_age;
        count++;
    }
    
    // names and ages now filled with data
    int sum = 0;
    int counter = 0;
    double average = 0.0;
    for (int i = 0; i < num_students; i++) {
        if (ages[i] > 25) {
            sum += ages[i];
            counter++;
            fprintf(file_output, "%s %d\n", names[i], ages[i]);
        }
    }
    average = sum / counter;
    fprintf(file_output, "Average is: %0.2f", average);

    fclose(file_input);
    fclose(file_output);
}