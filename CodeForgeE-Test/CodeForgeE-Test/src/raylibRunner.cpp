#include "raylibRunner.h"
#include "raylib.h"

void RunRaylib() {
    InitWindow(800, 600, "Code Forge Menu");
    SetTargetFPS(60);

    bool startTest = false;
    int selectedOption = 0;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Center titles
        char mainTitle[] = "Code Forge";
        char subTitle[] = "Electronic Test";
        int mainTitleWidth = MeasureText(mainTitle, 50);
        int subTitleWidth = MeasureText(subTitle, 40);
        DrawText(mainTitle, (GetScreenWidth() - mainTitleWidth) / 2, 50, 50, BLACK);
        DrawText(subTitle, (GetScreenWidth() - subTitleWidth) / 2, 120, 40, BLACK);

        // Center menu options
        char option1[] = "1. Start Test";
        char option2[] = "2. Exit";
        int option1Width = MeasureText(option1, 20);
        int option2Width = MeasureText(option2, 20);

        // Highlight selected option
        Color option1Color = (selectedOption == 0) ? DARKBLUE : DARKGRAY;
        Color option2Color = (selectedOption == 1) ? DARKBLUE : DARKGRAY;

        DrawText(option1, (GetScreenWidth() - option1Width) / 2, 200, 20, option1Color);
        DrawText(option2, (GetScreenWidth() - option2Width) / 2, 250, 20, option2Color);

        // Input for selecting options
        if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) {
            selectedOption = (selectedOption + 1) % 2;
        }
        if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) {
            selectedOption = (selectedOption - 1 + 2) % 2;
        }
        if (IsKeyPressed(KEY_ENTER)) {
            if (selectedOption == 0) {
                startTest = true;
                break;
            }
            else if (selectedOption == 1) {
                break;
            }
        }

        // direct key exiting
        if (IsKeyPressed(KEY_TWO)) {
            break;
        }

        EndDrawing();
    }

    CloseWindow();

    if (startTest) {
        // start test
    }
}
