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
// Main Menu
// ===============================

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
// Manage Users Menu
// ===============================

void ManageUserMenu()
{
    // Fixed: this used to check the wrong permission (FindClient)
    // in the original code. It must check ManageUser.
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
// First run bootstrap
// ===============================
// The original project had no way to create the very first user,
// since logging in requires an existing user in Users.txt.
// If the users file is empty, we create a default admin account
// so the system is actually usable.

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
// Start Bank System
// ===============================

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
