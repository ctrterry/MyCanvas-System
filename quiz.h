#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/**
 * @class name - Quizzes
 * @purpose - This class provides information on the quizzes
 * section of Canvas.
 * @param - none
 * @return - none
 * @author - Vinson Wong
*/

class Quizzes{
    public:
        void assignmentQuizzes();

    private:
};

/**
 * @function name - assignedQuizzes
 * @purpose - This function provides provides the current list of quizzes.
 * @param - none
 * @return - none
 * @author - Vinson Wong
*/

void Quizzes::assignmentQuizzes(){
    cout << "Assignment Quizzes" << endl;
    cout << "=====================" << endl;
    cout << "Quiz 1 - Chapter 9 Classes" << endl;
    cout << "Due Sep 13 at 11:59pm Sep 13 at 11:59pm | 10 pts | 10 Questions" << endl;
}