#include "UserServices.h"
#include "UI.h"
#include "Navigation.h"
#include "ReadData.h"

// ===============================
// Move User Menu
// ===============================

// Routes control flow to the selected user management operation
void MoveToManageUser(enUserMenu UserMenu)
{
    switch (UserMenu)
    {
    case ListUser:
        ShowUsers();
        break;

    case AddUser:
        AddNewUser();
        break;

    case DeleteUsers:
        DeleteUser();
        break;

    case UpdateUsers:
        UpdateUser();
        break;

    case SearchUsers:
        SearchUser();
        break;

    case MainMenuUser:
        // Returning back to Manage Users caller loop
        break;
    }
}

// ===============================
// Choose User Menu Option
// ===============================

// Maps integer options to user menu enum values
enUserMenu ChooseManageUser(int choice)
{
    switch (choice)
    {
    case 1: return ListUser;
    case 2: return AddUser;
    case 3: return DeleteUsers;
    case 4: return UpdateUsers;
    case 5: return SearchUsers;
    default: return MainMenuUser;
    }
}

// ===============================
// Show Users
// ===============================

// Verifies access rights and renders the full user list table
void ShowUsers()
{
    if (!CheckAccessPermission(ManageUser))
    {
        ShowAccessDeniedMessage();
        return;
    }

    vector<stUser> Users = LoadUsers();

    PrintScreenHeader("Show Users (" + to_string(Users.size()) + ")");

    PrintUsers(Users);

    GoBackToMainMenu();
}

// ===============================
// Add New User
// ===============================

// Handles adding new user credentials and permission settings
void AddNewUser()
{
    if (!CheckAccessPermission(ManageUser))
    {
        ShowAccessDeniedMessage();
        return;
    }

    char Answer;

    do
    {
        PrintScreenHeader("Add New User");

        stUser User = ReadUserData();

        vector<stUser> Users = LoadUsers();

        while (IsUserExist(User.userName, Users) || User.userName == "close")
        {
            cout << "\nUser Name already exists!\n";

            User.userName = ReadString("Enter another User Name");
        }

        AddUserToFile(User);

        cout << "\nUser Added Successfully.\n";

        Answer = ReadChar("Do you want to add another User? Y/N");

    } while (toupper(Answer) == 'Y');

    GoBackToMainMenu();
}

// ===============================
// Delete User
// ===============================

// Removes a user record by username
void DeleteUser()
{
    if (!CheckAccessPermission(ManageUser))
    {
        ShowAccessDeniedMessage();
        return;
    }

    PrintScreenHeader("Delete User");

    vector<stUser> Users = LoadUsers();

    PrintUsers(Users);

    int Index = ReadUserIndex(Users, "Enter User Name For Delete");

    if (Index != -1)
    {
        Users.erase(Users.begin() + Index);

        SaveUsers(Users);

        cout << "\nUser Deleted Successfully.\n";
    }

    GoBackToMainMenu();
}

// ===============================
// Update User
// ===============================

// Updates credentials and permissions for an existing user
void UpdateUser()
{
    if (!CheckAccessPermission(ManageUser))
    {
        ShowAccessDeniedMessage();
        return;
    }

    PrintScreenHeader("Update User");

    vector<stUser> Users = LoadUsers();

    PrintUsers(Users);

    int Index = ReadUserIndex(Users, "Enter User Name For Update");

    if (Index == -1)
    {
        GoBackToMainMenu();
        return;
    }

    string UserName = Users[Index].userName;

    Users[Index] = ReadUserData();

    Users[Index].userName = UserName;

    SaveUsers(Users);

    cout << "\nUser Updated Successfully.\n";

    GoBackToMainMenu();
}

// ===============================
// Search User
// ===============================

// Looks up and displays details for a specific user
void SearchUser()
{
    if (!CheckAccessPermission(ManageUser))
    {
        ShowAccessDeniedMessage();
        return;
    }

    PrintScreenHeader("Search User");

    vector<stUser> Users = LoadUsers();

    int Index = ReadUserIndex(Users, "Enter User Name For Search");

    if (Index != -1)
    {
        PrintUser(Users[Index], Index + 1);
    }

    GoBackToMainMenu();
}

// ===============================
// Read User Index Helper
// ===============================

// Interactively prompts for a username until found or cancelled with "close"
int ReadUserIndex(vector<stUser>& Users, const string& Message)
{
    string UserName = ReadString(Message);

    if (UserName == "close")
        return -1;

    int Index = FindUserIndex(UserName, Users);

    while (Index == -1)
    {
        cout << "\nUser Not Found!\n";

        UserName = ReadString(Message);

        if (UserName == "close")
            return -1;

        Index = FindUserIndex(UserName, Users);
    }

    return Index;
}

// ===============================
// Check User Existence
// ===============================

// Checks whether a given username exists in the users vector
bool IsUserExist(const string& UserName, const vector<stUser>& Users)
{
    return FindUserIndex(UserName, Users) != -1;
}

// ===============================
// Get User Information
// ===============================

// Retrieves complete record details for a logged-in user
stUser InformationForUser(const string& UserName)
{
    vector<stUser> Users = LoadUsers();

    for (const stUser& User : Users)
    {
        if (User.userName == UserName)
            return User;
    }

    return {};
}

// ===============================
// Access Control Validation
// ===============================

// Validates current user permissions using bitwise AND comparison
bool CheckAccessPermission(enPermission Permission)
{
    if (CurrentUser.permission == AllPermission)
        return true;

    return (CurrentUser.permission & Permission) == Permission;
}