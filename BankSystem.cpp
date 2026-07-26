#include "BankSystem.h"
#include "Client.h"
#include "ClientServices.h"
#include "TransactionServices.h"
#include "UserServices.h"
#include "UserFileManager.h"
#include "Login.h"
#include "UI.h"
#include "ThemeExit.h"
#include "ReadData.h"

// ===============================
// Main Menu Implementation
// ===============================

// Displays and handles the top-level options menu loop for clients and operations
void MainMenu()
{
    int Choice;

    while (true)
    {
        PrintMainMenu();

        Choice = ReadInt("Choose what do you want to do? [1..8]", 1, 8);

        switch (Choice)
        {
        case Show:
            ShowRecords();
            break;

        case Add:
            AddNewRecord();
            break;

        case Delete:
            DeleteRecord();
            break;

        case Update:
            UpdateRecord();
            break;

        case Search:
            SearchRecord();
            break;

        case Transactions:
            RunTransactionsMenu();
            break;

        case ManageUsers:
            ManageUserMenu();
            break;

        case Logout:
            return;
        }
    }
}

// ===============================
// Manage Users Menu Implementation
// ===============================

// Verifies administrative rights and manages the user administration submenu loop
void ManageUserMenu()
{
    // Fixed: verified and secured permission check for user management access
    if (!CheckAccessPermission(ManageUser))
    {
        ShowAccessDeniedMessage();
        return;
    }

    int Choice;

    while (true)
    {
        PrintManageUsersMenu();

        Choice = ReadInt("Choose what do you want to do? [1..6]", 1, 6);

        if (Choice == 6)
            return;

        MoveToManageUser(ChooseManageUser(Choice));
    }
}

// ===============================
// System Initialization Bootstrap
// ===============================

// Ensures at least one admin account exists on startup to prevent lockouts
static void EnsureAdminUserExists()
{
    vector<stUser> Users = LoadUsers();

    if (!Users.empty())
        return;

    stUser Admin;
    Admin.userName = "admin";
    Admin.password = "admin";
    Admin.permission = AllPermission;

    AddUserToFile(Admin);

    cout << "\n[i] No users were found, a default administrator account was created:\n";
    cout << "    User Name : admin\n";
    cout << "    Password  : admin\n";
    cout << "    Please change this password after logging in.\n";

    system("pause");
}

// ===============================
// Bank System Entry Point
// ===============================

// Bootstraps default accounts and handles the primary application/login screen loop
void RunBankSystem()
{
    EnsureAdminUserExists();

    vector<stUser> Users;

    while (true)
    {
        PrintLoginScreenMenu();

        int Choice = ReadInt("Choose [1..2]", 1, 2);

        switch (Choice)
        {
        case 1:
            CurrentUser = LoginScreen(Users);
            MainMenu();
            break;

        case 2:
            ShowLoadingAndExit();
            return;
        }
    }
}