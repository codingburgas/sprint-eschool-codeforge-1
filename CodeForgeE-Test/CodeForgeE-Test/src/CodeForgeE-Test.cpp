#include <iostream>
#include <string>
#include <Windows.h>
#include "test.h"
#include "choiceSelector.h"

using namespace std;

void printMenu()
{
    system("cls");
    cout << "Choose one of the following options:" << endl;
    cout << "1. Take a test" << endl;
    cout << "2. Students with the highest score" << endl;
    cout << "3. Students with the lowest score" << endl;
    cout << "4. Average test score" << endl;
    cout << "5. Category with the highest performance" << endl;
    cout << "6. Category with the lowest performance" << endl;
    cout << "7. Exit" << endl << endl;
    cout << "Your choice (1-7):";
}
void initStudents()
//initialization of the arrays with student names and results
{
    for (int i = 0; i < 100; i++) {
        studNames[i] = "";
        Results[i] = 0;
    }
}

int main()
{
    studCounter = 0; //number of tested students
    initStudents();
   

    for (int i = 0; i < 4; i++) 
        catPerform[i]=0;
      
    int choice; //selected alternative
    do
    {
        do
        {
            printMenu();
            cin >> choice;
        } while ((choice < 1) or (choice > 7));

        switch (choice) {
        case 1:
            //test doing
            system("cls");
            //startTest();
            choiceSelector();
            //Sleep(4000);
            break;
        case 2:
            //students with highest score
            studMaxResult();
            Sleep(4000);
            break;
        case 3:
            //students with lowest score
            studMinResult();
            Sleep(4000);
            break;
        case 4:
            //average test score
            if (studCounter > 0) averageTest();
            else cout << "To generate this statistic, at least one student must have taken the test!";
            Sleep(4000);
            break;
        case 5:
            //category with highest success rate
            if (studCounter > 0) highSuccCat();
            else cout << "To generate this statistic, at least one student must have taken the test!";
            Sleep(4000);
            break;
        case 6:
            //category with lowest success rate
            if (studCounter > 0) lowSuccCat();
            else cout << "To generate this statistic, at least one student must have taken the test!";
            Sleep(4000);
            break;
        }
    } while (choice != 7);

}


