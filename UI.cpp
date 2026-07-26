#include "UI.h"

// ===============================
// Center Text
// ===============================

// Centers a string within a given space width and prints it
void PrintStringForCenter(const string& Text, int CountSpace)
{
    int LeftSpace = (CountSpace / 2) - ((int)Text.length() / 2);

    if (LeftSpace < 0)
        LeftSpace = 0;

    cout << setw(LeftSpace) << " " << Text << endl;
}

// ===============================
// Screen Header
// ===============================

// Clears the console screen and prints a standardized screen header box
void PrintScreenHeader(const string& Title)
{
    system("cls");

    cout << string(100, '=') << endl;

    PrintStringForCenter(Title, 100);

    cout << string(100, '=') << endl;
}

// ===============================
// Main Menu
// ===============================

// Displays the primary bank system navigation menu options
void PrintMainMenu()
{
    PrintScreenHeader("Bank System");

    cout << "\n\t[1] Show Client List."
        << "\n\t[2] Add New Client."
        << "\n\t[3] Delete Client."
        << "\n\t[4] Update Client."
        << "\n\t[5] Find Client."
        << "\n\t[6] Transactions."
        << "\n\t[7] Manage Users."
        << "\n\t[8] Logout."
        << endl;

    cout << string(100, '=') << endl;
}

// ===============================
// Login Menu
// ===============================

// Displays the initial entry menu options for logging in or exiting
void PrintLoginScreenMenu()
{
    PrintScreenHeader("Login Screen Menu");

    cout << "\n\t[1] Login."
        << "\n\t[2] Exit."
        << endl;

    cout << string(100, '=') << endl;
}

// ===============================
// Manage Users Menu
// ===============================

// Displays options for user administration and permission settings
void PrintManageUsersMenu()
{
    PrintScreenHeader("Manage Users Menu");

    cout << "\n\t[1] List Users."
        << "\n\t[2] Add New User."
        << "\n\t[3] Delete User."
        << "\n\t[4] Update User."
        << "\n\t[5] Search User."
        << "\n\t[6] Main Menu."
        << endl;

    cout << string(100, '=') << endl;
}