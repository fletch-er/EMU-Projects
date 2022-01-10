#include <iostream>
#include <string>
#include <fstream>
using namespace std;

double compute_pi(int n);
void scores();
void file_sort(char *infile, char *outfile);

class Rectangle
{
private:
    double width;
    double height;

public:
    Rectangle()
    {
        width = 0;
        height = 0;
    }
    Rectangle(double val)
    {
        width = val;
        height = val;
    }
    Rectangle(double v1, double v2)
    {
        width = v1;
        height = v2;
    }

    double getWidth()
    {
        return width;
    }
    double getHeight()
    {
        return height;
    }
    void setWidth(double w)
    {
        width = w;
    }
    void setHeight(double h)
    {
        height = h;
    }

    double area()
    {
        return width * height;
    }

    void display()
    {
        cout << width << " " << height;
    }
};

class Score
{
private:
    int num_students;
    double *scores;

public:
    Score(int input_num_students, double *input_scores)
    {
        num_students = input_num_students;
        scores = new double[num_students];
        for (int i = 0; i < num_students; i++)
        {
            scores[i] = input_scores[i];
        }
        this->num_students = num_students;
    }
    ~Score()
    {
        delete scores;
    }

    double avg = 0.0, total = 0.0;
    double average()
    {
        for (int i = 0; i < num_students; i++)
        {
            total = total + scores[i];
            avg = total / num_students;
        }
        return avg;
    }
    void display()
    {
        cout << "Scores: " << endl;
        for (int i = 0; i < num_students; i++)
            cout << *(scores + i) << endl;
        cout << "The average is: " << avg << endl;
    }
};

class Person
{
private:
    string name;
    int age;

public:
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    void set_name(string name)
    {
        this->name = name;
    }
    void set_age(int age)
    {
        this->age = age;
    }
    string get_name()
    {
        return this->name;
    }
    int get_age()
    {
        return age;
    }
};
class Student : public Person
{
private:
    int id;
    double gpa;

public:
    void set_id(int id)
    {
        this->id = id;
    }
    void set_gpa(double gpa)
    {
        this->gpa = gpa;
    }
    int get_id()
    {
        return id;
    }
    double get_gpa()
    {
        return gpa;
    }
    void show()
    {
        cout << "Name:" << get_name() << " Age:" << get_age();
        cout << " ID:" << get_id() << " GPA:" << get_gpa() << endl;
    }
};

double compute_pi(int n)
{
    double pi = 0;
    for (int i = 0; i < n; i++)
    {
        // Calculate denominator first
        int denominator = 2 * i + 1;
        // decide whether to add or subtract
        if (i % 2 == 0)
            // i is even, add fraction
            pi += 1.0 / denominator;
        else
            // i is odd, subtract fraction
            pi -= 1.0 / denominator;
    }
    // multiply by 4 at the end
    pi = 4 * pi;
    return pi;
}

void scores()
{
    double min_score;
    double max_score = 0;
    double avg_score = 0;
    int numStudents = 0;
    while (true)
    {
        cout << "Enter score, or -1 to quit: ";
        int score;
        cin >> score;
        if (score == -1)
            break;
        if (min_score > score)
            min_score = score;
        if (max_score < score)
            max_score = score;
        avg_score = avg_score + score;
        numStudents++;
    }
    cout << "Average score is: " << (avg_score / numStudents) << endl;
    cout << "Minimum score is: " << min_score << endl;
    cout << "Maximum score is: " << max_score << endl;
}

void file_sort(char *infile, char *outfile)
{
    ifstream fin(infile);
    ofstream fout(outfile);

    int id = 0;
    string name;
    double gpa = 0.0;
    int size;
    fin >> size;
    int* ids = new int[size];
    string* names = new string[size];
    double* gpaArr = new double[size];
    for (int i = 0; i < size; i++)
    {
        fin >> id >> name >> gpa;
        ids[i] = id;
        names[i] = name;
        gpaArr[i] = gpa;
    }
    fin.close();

    int tempId;
    double tempGpa;
    string tempStr;
    // Good old selection sort.
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (ids[i] > ids[j])
            {
                tempId = ids[i];
                ids[i] = ids[j];
                ids[j] = tempId;

                tempStr = names[i];
                names[i] = names[j];
                names[j] = tempStr;

                tempGpa = gpaArr[i];
                gpaArr[i] = gpaArr[j];
                gpaArr[j] = tempGpa;
            }
        }
    }

    fout << "Id\tName\tGPA" << endl;

    for (int i = 0; i < size; i++)
    {
        fout << ids[i] << "\t" << names[i] << "\t" << gpaArr[i] << endl;
    }
    fout.close();
}