#pragma once
#include <iostream>
#include <string>
#include <time.h>
#include "questions.h"


using namespace std;

void genNewTest()
//function generates a new test by randomly selecting five questions from each of the four categories
{
    int qNumb = 0;  //number of the generated question from a given category
    int qCount = 0; //number of generated questions from a given category
    srand(time(0)); //sets the starting point of the random number generation algorithm

    //generates the questions from test A
    while (qCount < 5) {
        qNumb = rand() % 13; //number from 0 to 12 obtained as the remainder of dividing a randomly generated number by 13 
        if (aTest[qNumb] == 0) {
            aTest[qNumb] = 1;
            qCount += 1;
        }        
    }
    //generates the questions from test B
    qNumb = 0;  qCount = 0;
    while (qCount < 5) {
        qNumb = rand() % 13;
        if (bTest[qNumb] == 0) {
            bTest[qNumb] = 1;
            qCount += 1;
        }
    }
    //generates the questions from test C
    qNumb = 0;  qCount = 0;
    while (qCount < 5) {
        qNumb = rand() % 13;
        if (cTest[qNumb] == 0) {
            cTest[qNumb] = 1;
            qCount += 1;
        }     
    }
    //generates the questions from test D
    qNumb = 0;  qCount = 0;
    while (qCount < 5) {
        qNumb = rand() % 13;
        if (dTest[qNumb] == 0) {
            dTest[qNumb] = 1;
            qCount += 1;
        }        
    }
    //prepare the arrays in which the student's answers will be recorded
    for (int i = 0; i < 13; i++) {
        aAnsw[i] = 0;
        bAnsw[i] = 0;
        cAnsw[i] = 0;
        dAnsw[i] = 0;
    }       
}

void deleteTest()
//the function resets the arrays containing the current test and the answers given by the student
{
    for (int i = 0; i < 13; i++) {
        //delete the questions for each category
        aTest[i] = 0;
        bTest[i] = 0;
        cTest[i] = 0;
        dTest[i] = 0;

        //reset the answers to the questions for each category
        aAnsw[i] = 0;
        bAnsw[i] = 0;
        cAnsw[i] = 0;
        dAnsw[i] = 0;
    }
}

void printTitleTestCat(string catName)
//the function prints on the screen the name of the category from which tasks are to be solved
{
    cout << "Solve the problem from " << catName << endl;
}

double pointsToGrade(int points)
//the function converts the number of points into a score
{
    double grade = ((points * 6.0) / 20.0);
    if (grade < 2.5) grade = 2;
    else if (grade < 3.5) grade = 3;
    else if (grade < 4.5) grade = 4;
    else if (grade < 5.5) grade = 5;
    else grade = 6;
    return grade;
}

void startTest()
{
    studCounter += 1; //increase the student counter
    cout << endl<<endl<<endl<<"Enter a name: ";
    cin >> studNames[studCounter-1]; //writing the name of the student who will take the test in the array of student names

    genNewTest(); //creating a new test
    int answer;
    
    system("cls");
   
    //displaying the questions from the first category
    printTitleTestCat(catNames[0]);    
    for (int i = 0; i < 13; i++) {
        if (aTest[i] == 1) {
            cout << aQuest[i]; //displaying a question from category a on the screen
            cin >> answer;
            if (answer == aCorrAnsw[i]) //checking whether the entered answer is correct
                aAnsw[i] = 1; //correct answer                                               
        }
    }
    //displaying the questions from the second category
    printTitleTestCat(catNames[1]);
    for (int i = 0; i < 13; i++) {
       if (bTest[i] == 1) {
            cout << bQuest[i]; //displaying a question from category b on the screen
            cin >> answer;
            if (answer == bCorrAnsw[i]) //checking whether the entered answer is correct
                bAnsw[i] = 1;  
       }
    }
    //displaying the questions from the third category
    printTitleTestCat(catNames[2]);
    for (int i = 0; i < 13; i++) {
        if (cTest[i] == 1) {
            cout << cQuest[i]; //displaying a question from category c on the screen
            cin >> answer;
            if (answer == cCorrAnsw[i]) //checking whether the entered answer is correct
                cAnsw[i] = 1;         
        }
    }
    //displaying the questions from the fourth category
    printTitleTestCat(catNames[3]);
    for (int i = 0; i < 13; i++) {
        if (dTest[i] == 1) {
            cout << dQuest[i]; //displaying a question from category d on the screen
            cin >> answer;
            if (answer == dCorrAnsw[i]) //checking whether the entered answer is correct
                dAnsw[i] = 1;         
        }
    }
    
    for (int i = 0; i < 13; i++) {
        //calculating the student's total score from all categories
        Results[studCounter-1] += aAnsw[i] + bAnsw[i] + cAnsw[i] + dAnsw[i];
        //increasing the points received by category by the points received by the student
        catPerform[0] += aAnsw[i];
        catPerform[1] += bAnsw[i];
        catPerform[2] += cAnsw[i];
        catPerform[3] += dAnsw[i];
    }
    cout << "You got " << Results[studCounter-1] << " points and the grade is "<<pointsToGrade(Results[studCounter - 1])<<" .";
    deleteTest(); 
}
void studMaxResult()
//the function finds the highest score from all the tests taken and
//displays the names of the students who received this score on the screen
{
    system("cls");
    int maxResult = 0;
    //traversing the array of results to find the highest score
    for (int i = 0; i < studCounter; i++) {
        if (Results[i] > maxResult) maxResult = Results[i];
    }
    cout << "Students with the highest gread " << maxResult << " points, and the greade is "<<pointsToGrade(maxResult) <<" ." << endl;
    //displaying the names of the students with the highest score
    for (int i = 0; i < studCounter; i++) {
        if (Results[i] == maxResult) cout << studNames[i] << endl;
    }
}

void studMinResult()
//the function finds the lowest score from all tests taken and
//displays the names of the students who received this score on the screen
{
    system("cls");
    int minResult = 20;
    //traversing the array of results to find the lowest score
    for (int i = 0; i < studCounter; i++) {
        if (Results[i] < minResult) minResult = Results[i];
    }
    cout << "Students with the lowest gread " << minResult << " points, and the greade is "<< pointsToGrade(minResult)<<" ."<< endl;
    //displaying the names of the students with the lowest score
    for (int i = 0; i < studCounter; i++) {
        if (Results[i] == minResult) cout << studNames[i] << endl;
    }
}

void averageTest()
{
    system("cls");
    int sumResult = 0;
    //finding the sum of the scores of all students
    for (int i = 0; i < studCounter; i++) {
        sumResult += Results[i];
    }
    double avResult = (sumResult / studCounter);
    cout << "Avereg score in points " << avResult << " and the gread is " << pointsToGrade(avResult) <<" ." << endl;
}

void highSuccCat()
{
    system("cls");
    int maxSuccCat = 0;
    //traversing the array of scores by category to find the highest score
    for (int i = 0; i < 4; i++) {
        if (catPerform[i] > maxSuccCat) maxSuccCat = catPerform[i];
    }
    cout << "Categories with the highest success rate from " << (maxSuccCat/studCounter) << " points:" << endl;
    //outputting the names of the categories with the highest success rate
    for (int i = 0; i < 4; i++) {
        if (catPerform[i] == maxSuccCat) cout << catNames[i] << endl;
    }
}


void lowSuccCat()
{
    system("cls");
    int minSuccCat = 5*studCounter;
    //traversing the array of scores by category to find the lowest score
    for (int i = 0; i < 4; i++) {
        if (catPerform[i] < minSuccCat) minSuccCat = catPerform[i];
    }
    cout << "Categories with the lowest success rate of " << minSuccCat << " points:" << endl;
    //outputting the names of the categories with the lowest success rate
    for (int i = 0; i < 4; i++) {
        if (catPerform[i] == minSuccCat) cout << catNames[i] << endl;
    }
}
