// compile: g++ -std=c++14 -o pointers pointers.cpp
#include <iostream>
#include <string>
#include <limits> //fixes bad stuff with bad inputs


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

    // Sequence of user input -> store in fields of `student`

    // Call `CalculateStudentAverage(???, ???)`
    // Output `average`
    promptInt("Int Data Validation Test: ",1,10);
    promptDouble("Double Data Validation Test: ",1,10);
    std::string test;
    promptString("Str Test: ",&test);
    std::cout << test;
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
    std::cin >> *output;
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
}
