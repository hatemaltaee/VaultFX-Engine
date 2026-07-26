#include "UserFileManager.h"
#include "StringUtils.h"

// ===============================
// Load Users
// ===============================

// Reads all non-empty lines from the users file and converts them to a vector of stUser structures
vector<stUser> LoadUsers()
{
    vector<string> Lines;

    fstream File;

    File.open(fileNameForUsers, ios::in);

    if (File.is_open())
    {
        string Line;

        while (getline(File, Line))
        {
            if (!Line.empty())
            {
                Lines.push_back(Line);
            }
        }

        File.close();
    }

    return ConvertLinesToUsers(Lines);
}

// ===============================
// Deserialization & Conversions
// ===============================

// Converts a vector of delimited string lines into a collection of stUser structures
vector<stUser> ConvertLinesToUsers(const vector<string>& Lines)
{
    vector<stUser> Users;

    for (const string& Line : Lines)
    {
        Users.push_back(ConvertLineToUser(Line));
    }

    return Users;
}

// Parses a single delimited text line into an stUser structure
stUser ConvertLineToUser(const string& Line)
{
    stUser User;

    vector<string> Parts = SplitString(Line, separatorOfUsers);

    if (Parts.size() != 3)
    {
        return User;
    }

    User.userName = Parts[0];
    User.password = Parts[1];
    User.permission = stoi(Parts[2]);

    return User;
}

// ===============================
// Persistence Operations
// ===============================

// Appends a single formatted user record to the end of the user data file
void AddUserToFile(const stUser& User)
{
    fstream File;

    File.open(fileNameForUsers, ios::out | ios::app);

    if (File.is_open())
    {
        File << ConvertUserToLine(User) << endl;

        File.close();
    }
}

// Overwrites the user storage file with the updated vector of user records
void SaveUsers(const vector<stUser>& Users)
{
    fstream File;

    File.open(fileNameForUsers, ios::out);

    if (File.is_open())
    {
        for (const stUser& User : Users)
        {
            File << ConvertUserToLine(User) << endl;
        }

        File.close();
    }
}