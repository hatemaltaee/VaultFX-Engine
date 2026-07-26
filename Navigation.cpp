#include "Navigation.h"
#include <iostream>
#include <cstdlib>

using namespace std;

// ===============================
// Back To Main Menu
// ===============================

// Pauses execution until a key is pressed, then returns to the caller
void GoBackToMainMenu()
{
    cout << "\n\nPress any key to return to Main Menu...";

    system("pause>0");

    // NOTE: Returning control directly to the caller loop (MainMenu)
    // prevents unnecessary recursive calls and keeps the stack clean.
}