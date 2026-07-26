#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

// ===============================
// Constants
// ===============================

// File storage path for user accounts data
const string fileNameForUsers = "Users.txt";

// Internal delimiter used to separate user data fields within text files
const string separatorOfUsers = "&&^^%%";

// ===============================
// System Permissions (Bitwise Mask)
// ===============================
enum enPermission
{
    AllPermission = -1,

    ShowClients = 1,
    AddClient = 2,
    DeleteClient = 4,
    UpdateClient = 8,
    FindClient = 16,
    Transaction = 32,
    ManageUser = 64
};

// ===============================
// User Menu Enums
// ===============================
enum enUserMenu
{
    ListUser = 1,
    AddUser,
    DeleteUsers,
    UpdateUsers,
    SearchUsers,
    MainMenuUser
};

// ===============================
// User Record Structure
// ===============================
struct stUser
{
    string userName;
    string password;

    int permission = 0;
};

// ===============================
// Current Session State
// ===============================

// Global reference tracking the currently authenticated user
extern stUser CurrentUser;

// ===============================
// UI Output Functions
// ===============================

// Prints table header for displaying users list
void PrintUserHeader();

// Prints a single user record formatted into a table row
void PrintUser(const stUser& User, int position);

// Displays a formatted table listing all system users
void PrintUsers(const vector<stUser>& Users);

// Displays standard error message when a user lacks required permissions
void ShowAccessDeniedMessage();

// ===============================
// Serialization & Conversion
// ===============================

// Converts a user structure into a delimited single-line record for file storage
string ConvertUserToLine(const stUser& User);

// Converts a vector of user structures into a vector of delimited string lines
vector<string> ConvertUsersToLines(const vector<stUser>& Users);

// ===============================
// Search Operations
// ===============================

// Searches for a username in the users vector and returns its vector index (-1 if not found)
int FindUserIndex(const string& Value, const vector<stUser>& Users);

// ===============================
// User Input Reader
// ===============================

// Prompts for and reads new user credentials and permission settings
stUser ReadUserData();