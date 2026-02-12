// compile: g++ -std=c++14 -o pointers pointers.cpp
//To Do:
    // Validate that the name does not have numbers
    // Ensure rounding is done correctly
#include <iostream>
#include <string>
#include <limits> //fixes bad stuff with bad inputs
#include <iomanip> // for std::setprecision
//#include <cstring> // only for strcpy.


typedef struct Student {
    int id;
    char *f_name;
    char *l_name;
    int n_assignments;
    double *grades;
} Student;

int promptInt(std::string message, int min, int max);
double promptDouble(std::string message, double min, double max);
void promptString(std::string message, std::string *output);
void calculateStudentAverage(void *object, double *avg);

int main(int argc, char **argv)
{
    Student student;
    double average;
    std::string f_name, l_name;
    student.id = promptInt("Please enter the student's id number: ",0,999999999);
    promptString("Please enter the student's first name: ", &f_name);
    promptString("Please enter the student's last name: ", &l_name);
   /* student.f_name = new char[f_name.length() + 1];
    std::strcpy(student.f_name, f_name.c_str());
    student.l_name = new char[l_name.length() + 1];
    std::strcpy(student.l_name, l_name.c_str());*/
    student.n_assignments = promptInt("Please enter the number of assignments: ",1,134217728);
    double *grades = new double[student.n_assignments];
    student.grades = grades;
    for (int i = 0; i<student.n_assignments; i++)
    {
        grades[i] = promptDouble("Please enter grade for assignement "+std::to_string(i)+": ",0,1000.0);
    }

    calculateStudentAverage(&student, &average);
    std::cout << "Student: " << f_name << " " << l_name << " [" << student.id << "]" << std::endl;
    std::cout << "  Average grade: " << std::fixed << std::setprecision(1) << average << std::endl;

    // Sequence of user input -> store in fields of `student`

    // Call `CalculateStudentAverage(???, ???)`
    // Output `average`
    // promptInt("Int Data Validation Test: ",1,10);
    // promptDouble("Double Data Validation Test: ",1,10);
    // std::string test;
    // promptString("Str Test: ",&test);
    // std::cout << test;
    delete[] grades;
    return 0;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid int
   max: maximum value to accept as a valid int
*/
int promptInt(std::string message, int min, int max)
{
    int value;
    std::cout << message;
    std::cin >> value;
    if (std::cin.fail()) // If it is invalid
    {
        std::cin.clear(); //Clear error flags
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        std::cout << "Sorry, I cannot understand your answer"<< std::endl;
        return promptInt(message, min, max); //reprompt
    }
    else // Otherwise it is valid 
    {
        if(value>=min && value<=max) //Is it within range?
        {
            return value; // return Input
        }
        else // not within Range
        {
            std::cout << "Sorry, I cannot understand your answer"<< std::endl;
            return promptInt(message, min, max); // reprompt
        }
    }

}
/*
    message: text to output as the prompt
    output: pointer to a string, used to replace a value in main
*/
void promptString(std::string message, std::string *output)
{
    std::string input;
    std::cout << message;
    std::cin >> input;
    if (input.find(' ') != std::string::npos)  // If there is a space in any pos (npos) it is a very bad input. no no no.
    {
        std::cin.clear(); //Get those errors out of here
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Throw away bad input;
        std::cout << "Sorry, I cannot understand your answer" << std::endl; //Yell at user, could be better worded but not in specifications
        promptString(message, output); //try again user
    }
    else
    {
        *output = input; //Sets output to input.
    }
    
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid double
   max: maximum value to accept as a valid double
*/
double promptDouble(std::string message, double min, double max)
{
    double value;
    std::cout << message;
    std::cin >> value;
    if (std::cin.fail()) // if Invalid
    {
        std::cin.clear(); //Clear those flags
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        std::cout << "Sorry, I cannot understand your answer"<< std::endl; //Yell at user
        return promptDouble(message, min, max); //reprompt
    }
    else // otherwise it is valud
    {
        if(value>=min && value<=max) //If within range
        {
            return value;
        }
        else //else it is out of range
        {
            std::cout << "Sorry, I cannot understand your answer"<< std::endl; //Yell at user
            return promptDouble(message, min, max); //reprompt
        }
    }
    return value;
}

/*
   object: pointer to anything - your choice! (but choose something that will be helpful)
   avg: pointer to a double (can store a value here)
*/
void calculateStudentAverage(void *object, double *avg)
{
    // Code to calculate and store average grade
    *avg = 0;
    Student *student = (Student*)object; // Cast the void pointer to a Student pointer
    for (int i = 0; i < student->n_assignments; i++)
    {
        *avg += student->grades[i]; //Accumalate the average
    }
    *avg = *avg / student->n_assignments; // Divide by num of assignments.
    //fix bug where the average is not correct
    
}
