#pragma once

#include <fstream>
#include <string>
#include <vector>
#include "User.h"

using namespace std;

// ===============================
// File Operations
// ===============================

// Reads user records from disk storage and returns them as a vector of stUser structures
vector<stUser> LoadUsers();

// Converts a collection of delimited text lines into a vector of stUser structures
vector<stUser> ConvertLinesToUsers(const vector<string>& Lines);

// Parses a single delimited text record line into an stUser structure
stUser ConvertLineToUser(const string& Line);

// Appends a single new user record to the end of the user data file
void AddUserToFile(const stUser& User);

// Overwrites the user data file with the updated vector of stUser structures
void SaveUsers(const vector<stUser>& Users);