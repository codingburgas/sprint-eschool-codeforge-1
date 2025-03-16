#pragma once

#include <iostream>
#include <string>
using namespace std;


string catNames[4]={ "Addition", "Subtraction", "Multiplication", "Division" };
string aQuest[13] = { "5 + 6 =","7 + 8 =","4 + 9 =","5 + 4 =","3 + 6 =","9 + 3 =","7 + 4 =","8 + 5 =","3 + 2 =","1 + 6 =","2 + 7 =","1 + 9 =","0 + 8 =" };
int aCorrAnsw[13] = { 11, 15, 13, 9, 9, 13, 11, 13, 5, 7, 9, 10, 8 };

string bQuest[13] = { "6 - 2 =","8 - 1 =","9 - 4 =","5 - 3 =","6 - 1 =","9 - 3 =","7 - 4 =","8 - 5 =","3 - 2 =","6 - 1 =","7 - 2 =","9 - 1 =","8 - 0 =" };
int bCorrAnsw[13] = { 4, 7, 5, 2, 5, 6, 3, 3, 1, 5, 5, 8, 8 };

string cQuest[13] = { "5 * 6 =","7 * 8 =","4 * 9 =","5 * 4 =","3 * 6 =","9 * 3 =","7 * 4 =","8 * 5 =","3 * 2 =","1 * 6 =","2 * 7 =","9 * 1 =","8 * 0 =" };
int cCorrAnsw[13] = { 30, 56, 36, 20, 18, 27, 28, 40, 6, 6, 14, 9, 0 };

string dQuest[13] = { "30 / 5 =","56 / 7 =","36 / 4 =","21 / 3 =","18 / 6 =","9 / 3 =","28 / 4 =","40 /8 =","18 / 2 =","6 / 1 =","81 / 9 =","0 / 1 =","0 / 8 =" };
int dCorrAnsw[13] = { 6, 8, 9, 7, 3, 3, 7, 5, 9, 9, 0, 0};

int aTest[13];
int bTest[13];
int cTest[13];
int dTest[13];

int aAnsw[13];
int bAnsw[13];
int cAnsw[13];
int dAnsw[13];

string studNames[100];
int Results[100];
int studCounter = 0;

int catPerform[4];



