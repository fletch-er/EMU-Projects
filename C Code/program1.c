#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

double compute_pi(int n);
double compute_sqrt(double x);
int is_prime(int n);
void display_primes(int n);
void process_scores();
double compute_tax(int income, char *status, char *state);
int quadratic(double a, double b, double c, double *solution1, double *solution2);
int factorial(int n);
void file_count(char *file, int *characters, int *lines);
void file_sort(char *infile, char *outfile);
// Helper functions for problem 9, file-sort
void swapAll(int *i_arr, char *gr_arr, double *gpa_arr, int x, int y);
void swapID(int *arr, int x, int y);
void swapGrade(char *arr, int x, int y);
void swapGPA(double *arr, int x, int y);
// End helper functions
void file_student(char *infile);

struct Student {
    char name[32];
    int age;
    double gpa;
};

// Comparator for qsort to compare the names of students and determine which one comes first alphabetically
int comparator(const void* p, const void* q) 
{ 
    return strcmp(((struct Student*)p)->name, ((struct Student*)q)->name); 
} 

int main()
{
    int selection;
    int flag = 1;
    while (flag)
    {
        printf("Please enter your selection, 0 to see options, or 11 to quit: ");
        scanf("%d", &selection);
        switch (selection)
        {
        case 0:
            printf("1-computing pi\n2-computing square root\n3-displaying primes\n4-processing grades\n5-computing tax\n6-solving quadratic\n7-computing factorial\n8-counting file\n9-sorting file\n10-student file\n11-quit\n");
            break;
        case 1:
            printf("Compute Pi using ___ terms: ");
            int input;
            scanf("%d", &input);
            double pi = compute_pi(input);
            printf("%f", pi);
            break;
        case 2:
            printf("Compute Square Root of what number: ");
            double root_in;
            scanf("%lf", &root_in);
            double sqrt = compute_sqrt(root_in);
            printf("%f", sqrt);
            break;
        case 3:
            printf("Display primes less than or equal to: ");
            scanf("%d", &input);
            display_primes(input);
            break;
        case 4:
            process_scores();
            break;
        case 5:
            // Case written before learning about advanced string manipulation/input such as puts, gets etc.
            // Could easily be rewritten for cleaner input without having to loop through the array
            // like we do with scanf
            // Still works perfectly fine though.
            printf("Please enter income: ");
            int income = 0;
            scanf("%d", &income);
            printf("Please enter marital tolower(status): ");
            char status[32];
            for (int i = 0; i < sizeof(status); i++)
                status[i] = tolower(status[i]);
            scanf("%s", status);
            printf("Please enter In or Out of State: ");
            char state[2];
            scanf("%s", state);
            double tax_rate = compute_tax(income, status, state);
            printf("\nTax: %0.2f", tax_rate);
            break;
        case 6:
            printf("Please enter in a, b, and c seperated by spaces: ");
            double a, b, c;
            scanf("%lf%lf%lf", &a, &b, &c);
            double first_sol, second_sol;
            double *first_solution = &first_sol;
            double *second_solution = &second_sol;
            if (!(quadratic(a, b, c, first_solution, second_solution) == 1))
                *first_solution, *second_solution = 0.0;
            printf("The solutions are: %0.2lf and %0.2lf", *first_solution, *second_solution);
            break;
        case 7:
            printf("Compute factorial of: ");
            scanf("%d", &input);
            int fact = factorial(input);
            printf("The factorial of %d is %d", input, fact);
        case 8:
            printf("Enter in the name of the input file: ");
            char fileName[32];
            scanf("%s", fileName);
            int char_count = 0;
            int line_count = 1;
            printf("Char: %d\tLine: %d\n", char_count, line_count);
            file_count(fileName, &char_count, &line_count);
            printf("Char: %d\tLine: %d\n", char_count, line_count);
            break;
        case 9:
            /*
                File has student info in 3 columns seperated by blanks. The first line is the number of students.
                Read in num students and then loop through all students and scan.
                Sorting is based on ID,
            */
            printf("Enter the name of input file: ");
            char in_file[32];
            scanf("%s", in_file);
            printf("Enter the name of output file: ");
            char out_file[32];
            scanf("%s", out_file);
            file_sort(in_file, out_file);
            break;
        case 10:
            /*
                10 is like 9 except we create a struct. Each line get's its own struct. Same process
            */
            printf("Enter the name of input file: ");
            char input_file[32];
            scanf("%s", input_file);
            file_student(input_file);
            break;
        case 11:
            flag = 0;
            break;
        }
    }
    return 0;
}

double compute_pi(int n)
{
    // Formula starts out at 1
    double pi = 1.0;
    // Flag to determine if we have to add or subtract the value
    int flag = -1;
    // Loop from 1 to number of digits we want to use
    for (int i = 1; i < n; i++)
    {
        // First we subtract 1/3, then we add 1/5, subtract 1/7... etc until we hit n
        pi += flag / (2.0 * i + 1.0);
        // swap flag so we subtract, then add, then subtract...
        flag = -flag;
    }
    return 4.0 * pi;
}

double compute_sqrt(double x)
{
    double last = x;
    double sqrt = 1;
    int count = 0;
    while (count < 10)
    {
        count++;
        sqrt = 0.5 * (last + (x / last));
        last = sqrt;
    }
    return sqrt;
}

int is_prime(int n)
{
    // i starts at 2 since we can skip 1. We only have to loop to n/2.
    for (int i = 2; i <= n / 2; i++)
    {
        // Number is not prime
        if (n % i == 0)
            return 0;
    }
    // if we get here without returning anything yet, it must be a prime.
    return 1;
}

void display_primes(int n)
{
    printf("Primes less than or equal to %d: ", n);
    for (int i = 1; i <= n; ++i)
    {
        if (is_prime(i))
            printf("%d ", i);
    }
}

void process_scores()
{
    double avg_score = 0;
    int min_score, max_score = 0;
    double count = 1.0;
    double sum = 0;
    char input_name[32];
    char min_student[32];
    char max_student[32];
    int input_score;
    printf("Please enter a student name and score: ");
    scanf("%s", input_name);
    scanf("%d", &input_score);
    for (int i = 0; i < sizeof(input_name); i++)
    {
        min_student[i] = input_name[i];
        max_student[i] = input_name[i];
    }
    avg_score = input_score;
    min_score = input_score;
    max_score = input_score;
    sum += input_score;
    printf("Avg: %0.2f\nMin: %d\nMax: %d\nBest Score: %s\nWorst Score: %s\n", avg_score, min_score, max_score, min_student, max_student);
    printf("Please enter a student name and score: ");
    scanf("%s", input_name);
    do
    {
        scanf("%d", &input_score);
        count++;
        sum += input_score;
        avg_score = sum / count;
        if (input_score < min_score)
        {
            min_score = input_score;
            for (int i = 0; i < sizeof(input_name); i++)
            {
                min_student[i] = input_name[i];
            }
        }
        else if (input_score > max_score)
        {
            max_score = input_score;
            for (int i = 0; i < sizeof(input_name); i++)
            {
                max_student[i] = input_name[i];
            }
        }
        printf("Avg: %0.2f\nMin: %d\nMax: %d\nBest Score: %s\nWorst Score: %s\n", avg_score, min_score, max_score, max_student, min_student);
        printf("Please enter a student name and score: ");
        scanf("%s", input_name);
    } while (tolower(input_name[0]) != 'q');
}

double compute_tax(int income, char *status, char *state)
{

    // TODO: refactor with switch statement.
    if (state[0] == 'i')
    {
        if (strcmp(status, "single") == 0 && income < 30000)
        {
            return income * 0.20;
        }
        else if (strcmp(status, "single") == 0)
        {
            return income * 0.25;
        }
        if (strcmp(status, "married") == 0 && income < 50000)
        {
            return income * 0.10;
        }
        else if (strcmp(status, "married") && income >= 50000)
        {
            return income * 0.15;
        }
    }
    else if (state[0] == 'o')
    {
        if (strcmp(status, "single") == 0 && income < 30000)
        {
            return income * 0.17;
        }
        else if (strcmp(status, "single") == 0)
        {
            return income * 0.22;
        }
        if (strcmp(status, "married") && income < 50000)
        {
            return income * 0.07;
        }
        else if (strcmp(status, "married") && income >= 50000)
        {
            return income * 0.12;
        }
    }
    return -1;
}

int quadratic(double a, double b, double c, double *solution1, double *solution2)
{
    // Do solutions exist?
    int d = b * b - 4 * a * c;
    if (d >= 0)
    {
        // Solutions exist
        *solution1 = (-b - sqrt(d)) / (2 * a);
        *solution2 = (-b + sqrt(d)) / (2 * a);
        return 1;
    }
    else
        return 0;
}

int factorial(int n)
{
    // base case
    if (n == 0)
        return 1;
    else
        // multiply it by itself-1 until just before itself-1 is 0.
        return n * factorial(n - 1);
}

void file_count(char *file, int *characters, int *lines)
{
    char input;
    FILE *file_input;
    file_input = fopen(file, "r");
    if (file_input == NULL)
    {
        printf("Could not open file!");
        return;
    }
    input = getc(file_input);
    do
    {
        if (input == '\n')
            *lines += 1;
        else
            *characters += 1;
        input = getc(file_input);
    } while (input != EOF);
}

void file_sort(char *infile, char *outfile)
{

    // Create input and output file
    FILE *file_input;
    file_input = fopen(infile, "r");
    FILE *file_output;
    file_output = fopen(outfile, "w");

    // Can't find input file
    if (file_input == NULL)
    {
        printf("Could not open file!");
        return;
    }

    // Found input file. First line is number of students
    int num_students;
    fscanf(file_input, "%d", &num_students);

    // Allocate appropriate space for the arrays to store student data
    int size = 100;
    int *student_id_arr;
    char *grade_arr;
    double *gpa_arr;
    student_id_arr = (int *)malloc(size * sizeof(int));
    grade_arr = (char *)malloc(size * sizeof(char));
    gpa_arr = (double *)malloc(size * sizeof(double));

    int student_id;
    char grade;
    double gpa;

    int count = 0;
    // fscanf returns the number of valid inputs.
    while ((fscanf(file_input, "%d %c %lf", &student_id, &grade, &gpa)) == 3)
    {
        student_id_arr[count] = student_id;
        grade_arr[count] = grade;
        gpa_arr[count] = gpa;
        count++;
    }

    // Selection sort
    for (int i = 0; i < num_students; i++)
    {
        int min = student_id_arr[i];
        for (int j = i; j < num_students; j++)
        {
            if (student_id_arr[j] < min)
            {
                swapAll(student_id_arr, grade_arr, gpa_arr, i, j);
            }
        }
    }

    // Write to file
    for (int j = 0; j < num_students; j++)
    {
        fprintf(file_output, "%d %c %f\n", student_id_arr[j], grade_arr[j], gpa_arr[j]);
    }

    free(student_id_arr);
    free(grade_arr);
    free(gpa_arr);
    fclose(file_input);
    fclose(file_output);
}

// Problem 9 helper functions
void swapAll(int *i_arr, char *gr_arr, double *gpa_arr, int x, int y)
{
    swapID(i_arr, x, y);
    swapGrade(gr_arr, x, y);
    swapGPA(gpa_arr, x, y);
}

void swapGrade(char *arr, int x, int y)
{
    char temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

void swapID(int *arr, int x, int y)
{
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

void swapGPA(double *arr, int x, int y)
{
    double temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}
// End helper functions

void file_student(char *infile) {
    FILE *file_input;
    file_input = fopen(infile, "r");

    if (file_input == NULL)
    {
        printf("Could not open file!");
        return;
    }

    // Found input file. First line is number of students
    int num_students;
    fscanf(file_input, "%d", &num_students);

    struct Student *s = (struct Student*)malloc(num_students*sizeof(struct Student));
    // s is now an array of structures
    struct Student *struct_pointer;
    char student_name[64];
    int student_age;
    double student_gpa;
    int count = 0;

    while ((fscanf(file_input, "%s %d %lf", &student_name, &student_age, &student_gpa)) == 3)
    {
        struct_pointer = &s[count];
        strcpy(struct_pointer->name, student_name);
        struct_pointer->age = student_age;
        struct_pointer->gpa = student_gpa;
        count++;
    }
    
    // calculate average gpa and names of those whose gpa is >= 2
    double sum = 0;
    for (int i = 0; i < num_students; i++) {
        sum += s[i].gpa;
        if (s[i].gpa >= 2) {
            printf("%s has a GPA higher than 2.\n", s[i].name);
        }
    }
    double avg_gpa = sum/num_students;
    printf("\nAverage GPA: %0.2f\n", avg_gpa);

    // I know we didn't discuss quicksort in this class but I couldn't get myself
    // to write ANOTHER sorting method by comparing the names
    // when quicksort is already implemented in standard C.
    qsort(s, num_students, sizeof(struct Student), comparator); 

    printf("\nStudent Records sorted by Name:\n"); 
    for (int i = 0; i < num_students; i++) { 
        printf("Name = %s, Age = %d, GPA = %0.2f \n", s[i].name, s[i].age, s[i].gpa); 
    } 

    free(s);
}
