﻿#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

struct Question {
    string question;
    string options[4];
    char correctAnswer;
};

void startQuiz() {
    vector<Question> questions = {
        //Geography questions
        {"What is the longest river in the world?", {"Amazon River", "Mississippi River", "Nile River", "Yangtze River"}, 'c'},
        {"Which country has the largest population?", {"India", "United States", "China", "Brazil"}, 'c'},
        {"What is the capital of Canada?", {"Toronto", "Vancouver", "Ottawa", "Montreal"}, 'c'},
        {"The Great Barrier Reef is located off the coast of which country?", {"Australia", "Indonesia", "Philippines", "Fiji"}, 'a'},
        {"Which desert is the largest in the world?", {"Sahara", "Gobi", "Atacama", "Kalahari"}, 'a'},
        {"Which continent has the most countries?", {"Asia", "Africa", "Europe", "North America"}, 'b'},
        {"Mount Everest is part of which mountain range?", {"Rockies", "Alps", "Himalayas", "Andes"}, 'c'},
        {"Which ocean is the deepest?", {"Atlantic", "Pacific", "Indian", "Arctic"}, 'b'},
        {"What is the capital of Japan?", {"Beijing", "Seoul", "Tokyo", "Bangkok"}, 'c'},
        {"The Amazon Rainforest is primarily located in which country?", {"Brazil", "Argentina", "Colombia", "Venezuela"}, 'a'},

        //Chemistry questions
        {"What is the chemical symbol for gold?", {"Au", "Ag", "Pb", "Fe"}, 'a'},
        {"What is the most abundant gas in Earth’s atmosphere?", {"Oxygen", "Carbon Dioxide", "Nitrogen", "Hydrogen"}, 'c'},
        {"Which element is necessary for respiration?", {"Helium", "Oxygen", "Nitrogen", "Argon"}, 'b'},
        {"What is the pH of pure water?", {"7", "5", "9", "3"}, 'a'},
        {"Which element is used in pencils?", {"Lead", "Graphite", "Carbon", "Silicon"}, 'b'},
        {"What is the common name for H2O2?", {"Hydrogen peroxide", "Hydrochloric acid", "Sulfuric acid", "Baking soda"}, 'a'},
        {"Which gas is commonly used to fill balloons to make them float?", {"Oxygen", "Helium", "Carbon dioxide", "Nitrogen"}, 'b'},
        {"What is the atomic number of carbon?", {"6", "8", "12", "14"}, 'a'},
        {"What is the chemical formula for table salt?", {"NaCl", "KCl", "HCl", "CaCl2"}, 'a'},
        {"What type of bond is formed when electrons are shared?", {"Ionic", "Covalent", "Metallic", "Hydrogen"}, 'b'},

        //History questiosn
        {"Who was the first President of the United States?", {"Thomas Jefferson", "George Washington", "Abraham Lincoln", "John Adams"}, 'b'},
        {"In what year did World War II end?", {"1943", "1944", "1945", "1946"}, 'c'},
        {"The Renaissance was a cultural movement that began in which country?", {"France", "England", "Italy", "Spain"}, 'c'},
        {"Who discovered America in 1492?", {"Ferdinand Magellan", "Christopher Columbus", "Marco Polo", "Vasco da Gama"}, 'b'},
        {"The Great Wall of China was built to protect against invasions from which group?", {"Mongols", "Persians", "Romans", "Ottomans"}, 'a'},
        {"The Industrial Revolution began in which country?", {"France", "Germany", "England", "United States"}, 'c'},
        {"Who was the leader of Germany during World War II?", {"Joseph Stalin", "Winston Churchill", "Adolf Hitler", "Franklin D. Roosevelt"}, 'c'},
        {"What document was signed in 1776 to declare American independence?", {"Bill of Rights", "Magna Carta", "Declaration of Independence", "Constitution"}, 'c'},
        {"What was the capital of the Roman Empire?", {"Athens", "Rome", "Constantinople", "Alexandria"}, 'b'},
        {"The Cold War was primarily between which two countries?", {"China and Japan", "France and Germany", "USA and USSR", "UK and Spain"}, 'c'},

        //Math questions
        {"What is 8 × 7?", {"48", "56", "64", "72"}, 'b'},
        {"What is the square root of 81?", {"7", "8", "9", "10"}, 'c'},
        {"What is 15% of 200?", {"20", "25", "30", "35"}, 'c'},
        {"If a triangle has angles of 60° and 60°, what is the third angle?", {"30°", "60°", "90°", "120°"}, 'a'},
        {"What is 12³?", {"1,248", "1,726", "1,728", "1,832"}, 'c'},
        {"What is ¾ as a decimal?", {"0.25", "0.50", "0.75", "1.25"}, 'c'},
        {"Solve: 2x + 5 = 15", {"3", "5", "7", "10"}, 'b'},
        {"What is π approximately equal to?", {"2.14", "3.14", "4.14", "5.14"}, 'b'},
        {"How many degrees are in a right angle?", {"45°", "90°", "180°", "270°"}, 'b'},
        {"What is 2⁵?", {"10", "25", "32", "50"}, 'c'},

        //English questions
        {"What is a synonym for 'happy'?", {"Sad", "Joyful", "Angry", "Tired"}, 'b'},
        {"Which word is a noun?", {"Run", "Quickly", "House", "Beautiful"}, 'c'},
        {"Which word is the past tense of 'go'?", {"Goes", "Going", "Went", "Go"}, 'c'},
        {"Which word is spelled correctly?", {"Acommodate", "Accommodate", "Acomodate", "Accommadate"}, 'b'},
        {"Which word is an adjective?", {"Run", "Beautiful", "Quickly", "Loudly"}, 'b'},
        {"What is the opposite of 'strong'?", {"Tough", "Weak", "Hard", "Brave"}, 'b'},
        {"Which of these is an adverb?", {"Jump", "Slow", "Quickly", "Green"}, 'c'},
        {"Which word means 'to look at books'?", {"Read", "Reed", "Red", "Ride"}, 'a'},
        {"Which of these is a pronoun?", {"Dog", "She", "Table", "Run"}, 'b'},
        {"Which word means 'a place where people live'?", {"Car", "House", "Tree", "Road"}, 'b'}
    };

    random_shuffle(questions.begin(), questions.end());
    int score = 0;

    for (int i = 0; i < 20; i++) {
        cout << i + 1 << ". " << questions[i].question << endl;
        cout << "   a) " << questions[i].options[0] << endl;
        cout << "   b) " << questions[i].options[1] << endl;
        cout << "   c) " << questions[i].options[2] << endl;
        cout << "   d) " << questions[i].options[3] << endl;

        cout << "Your answer: ";
        char userAnswer;
        cin >> userAnswer;

        if (tolower(userAnswer) == questions[i].correctAnswer) {
            cout << "\033[32m" << "Correct!\n" << "\033[0m" << endl;
            score++;
        }
        else {
            cout << "\033[1;31m" << "Incorrect! The correct answer is " << questions[i].correctAnswer << ") "
                << questions[i].options[questions[i].correctAnswer - 'a'] << ".\n" << "\033[0m" << endl;
        }
    }

    cout << "Quiz Complete! Your final score: " << score << "/20" << endl;
}