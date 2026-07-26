#include "User.h"
#include "UI.h"
#include "ReadData.h"

// ===============================
// Global Current User Definition
// ===============================

// Global state holding the currently authenticated system user
stUser CurrentUser;

// ===============================
// Print User Header
// ===============================

// Prints the column headers for the users tabular display
void PrintUserHeader()
{
    cout << left
        << setw(4) << "No."
        << setw(18) << "| User Name"
        << setw(15) << "| Password"
        << "| Permission"
        << endl;

    cout << string(80, '-') << endl;
}

// ===============================
// Print Single User
// ===============================

// Prints formatted record details for a single user
void PrintUser(const stUser& User, int position)
{
    cout << left
        << setw(4) << position
        << "| " << setw(16) << User.userName
        << "| " << setw(13) << User.password
        << "| " << User.permission
        << endl;
}

// ===============================
// Print All Users
// ===============================

// Renders the entire list of users in a formatted table layout
void PrintUsers(const vector<stUser>& Users)
{
    PrintUserHeader();

    for (int i = 0; i < (int)Users.size(); i++)
    {
        PrintUser(Users[i], i + 1);
    }

    cout << string(80, '=') << endl;
}

// ===============================
// Access Control UI
// ===============================

// Displays a standardized access denied warning screen for restricted actions
void ShowAccessDeniedMessage()
{
    PrintScreenHeader("Access Denied");

    cout << "\n\n";
    cout << "  [!] You don't have permission\n"
        << "      to access this section.\n\n";
    cout << "  Contact administrator if needed.\n";

    system("pause");
}

// ===============================
// Record Serialization
// ===============================

// Converts an stUser structure into a single delimited string line for storage
string ConvertUserToLine(const stUser& User)
{
    return
        User.userName + separatorOfUsers +
        User.password + separatorOfUsers +
        to_string(User.permission);
}

// Converts a collection of stUser structures into vector of formatted string lines
vector<string> ConvertUsersToLines(const vector<stUser>& Users)
{
    vector<string> Lines;

    for (const stUser& User : Users)
    {
        Lines.push_back(ConvertUserToLine(User));
    }

    return Lines;
}

// ===============================
// Search Operations
// ===============================

// Searches for a user by username and returns their vector index (-1 if not found)
int FindUserIndex(const string& Value, const vector<stUser>& Users)
{
    for (int i = 0; i < (int)Users.size(); i++)
    {
        if (Users[i].userName == Value)
        {
            return i;
        }
    }

    return -1;
}

// ===============================
// Read User Data & Bitwise Permissions
// ===============================

// Prompts for user credentials and calculates bitwise flags for granular permissions
stUser ReadUserData()
{
    stUser User;

    User.userName = ReadString("Enter User Name");
    User.password = ReadString("Enter Password");

    bool FullAccess = ReadBool("Do you want Full Access?");

    if (FullAccess)
    {
        User.permission = AllPermission;
    }
    else
    {
        User.permission = 0;

        if (ReadBool("Show Client List"))
            User.permission |= ShowClients;

        if (ReadBool("Add Client"))
            User.permission |= AddClient;

        if (ReadBool("Delete Client"))
            User.permission |= DeleteClient;

        if (ReadBool("Update Client"))
            User.permission |= UpdateClient;

        if (ReadBool("Find Client"))
            User.permission |= FindClient;

        if (ReadBool("Transactions"))
            User.permission |= Transaction;

        if (ReadBool("Manage Users"))
            User.permission |= ManageUser;

        // Automatically convert all flag combinations (summing to 127) to full admin access
        if (User.permission == 127)
            User.permission = AllPermission;
    }

    return User;
}