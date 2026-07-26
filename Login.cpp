#include "Login.h"
#include <cstdlib>
#include "ReadData.h"
#include "ThemeExit.h"
#include "UI.h"
#include "UserFileManager.h"
#include "UserServices.h"

// ===============================
// Login Screen Implementation
// ===============================

// Prompts the user for credentials, handles retry attempts (max 5), and returns the logged-in user structure
stUser LoginScreen(vector<stUser>& Users)
{
    string UserName;
    string Password;

    int Attempts = 0;

    while (Attempts < 5)
    {
        PrintScreenHeader
        (
            Attempts == 0 ?
            "Login Screen" :
            "Login Again Attempt " + to_string(Attempts)
        );

        UserName = ReadString("Enter User Name");
        Password = ReadString("Enter Password");

        if (IsValidLogin(UserName, Password))
        {
            cout << "\nLogin Successfully.\n";

            system("pause");

            return InformationForUser(UserName);
        }

        cout << "\nInvalid User Name or Password.\n";

        Attempts++;

        system("pause");
    }

    // Prevents unauthorized entry after 5 failed attempts by cleanly closing the application
    ShowLoadingAndExit();

    exit(0);
}

// ===============================
// Credential Validation
// ===============================

// Verifies if the entered username and password exist in the system records
bool IsValidLogin(const string& userName, const string& password)
{
    vector<stUser> Users = LoadUsers();

    for (const stUser& User : Users)
    {
        if (User.userName == userName && User.password == password)
        {
            return true;
        }
    }

    return false;
}