#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

// ===============================
// General UI Functions
// ===============================

// Prints spaces to dynamically align and center text on the console output
void PrintStringForCenter(const string& Text, int CountSpace);

// Displays a formatted, consistent header block for a given screen title
void PrintScreenHeader(const string& Title);

// ===============================
// Menu Interfaces
// ===============================

// Renders the primary system application main menu
void PrintMainMenu();

// Renders the user authentication and login screen interface
void PrintLoginScreenMenu();

// Renders the administration and user management submenu interface
void PrintManageUsersMenu();