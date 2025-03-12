#include "raylib.h"
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void GenerateMathProblem(int& a, int& b, char& op, int& result) {
    a = GetRandomValue(50, 100);
    b = GetRandomValue(1, 50);
    int operation = GetRandomValue(0, 3);
    switch (operation) {
    case 0: op = '+'; result = a + b; break;
    case 1: op = '-'; result = a - b; break;
    case 2: op = '*'; result = a * b; break;
    case 3: op = '/'; result = a / b; break;
    }
}

void test() {
    const int screenWidth = 1280;
    const int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "Math Test");
    int a, b, result;
    char op;
    GenerateMathProblem(a, b, op, result);
    char userInput[32] = "";
    int userAnswer = 0;
    bool answerChecked = false;
    bool isCorrect = false;
    int totalQuestions = 20;
    int currentQuestion = 1;
    int score = 0;
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        if (currentQuestion <= totalQuestions) {
            if (!answerChecked) {
                int key = GetCharPressed();
                while (key > 0) {
                    if (key >= '0' && key <= '9') {
                        int length = strlen(userInput);
                        if (length < 31) {
                            userInput[length] = (char)key;
                            userInput[length + 1] = '\0';
                        }
                    }
                    key = GetCharPressed();
                }
                if (IsKeyPressed(KEY_ENTER)) {
                    userAnswer = atoi(userInput); 
                    isCorrect = (userAnswer == result);
                    answerChecked = true;
                    if (isCorrect) {
                        score++;
                    }
                }
            }
            else {
                if (IsKeyPressed(KEY_SPACE)) {
                    GenerateMathProblem(a, b, op, result);
                    userInput[0] = '\0';
                    answerChecked = false;
                    currentQuestion++;
                }
            }
        }
        BeginDrawing();
        ClearBackground(RAYWHITE);
        if (currentQuestion <= totalQuestions) {
            DrawText(TextFormat("Question %d/%d", currentQuestion, totalQuestions), 100, 50, 30, BLACK);
            DrawText(TextFormat("%d %c %d = ?", a, op, b), 100, 100, 40, BLACK);
            DrawText("Your answer: ", 100, 200, 30, BLACK);
            DrawText(userInput, 300, 200, 30, BLACK);
            if (answerChecked) {
                if (isCorrect) {
                    DrawText("Correct! Press SPACE for the next question.", 100, 300, 30, GREEN);
                }
                else {
                    DrawText(TextFormat("Incorrect! The correct answer is %d. Press SPACE for the next question.", result), 100, 300, 30, RED);
                }
            }
        }
        else {
            DrawText("Test Complete!", 100, 100, 50, BLACK);
            DrawText(TextFormat("Your score: %d/%d", score, totalQuestions), 100, 200, 40, BLUE);
            DrawText("Press ESC to exit.", 100, 300, 30, BLACK);
        }

        EndDrawing();
    }
    CloseWindow();
}
