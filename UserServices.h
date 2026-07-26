#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "User.h"
#include "UserFileManager.h"

using namespace std;

// ===============================
// User Menu Navigation
// ===============================

// Routes execution to the appropriate user management function based on menu choice
void MoveToManageUser(enUserMenu UserMenu);

// Converts an integer choice into its corresponding enUserMenu enumeration value
enUserMenu ChooseManageUser(int choice);

// ===============================
// User Operations
// ===============================

// Displays a formatted list of all registered system users
void ShowUsers();

// Handles prompting, reading, and storing a new user account
void AddNewUser();

// Handles selecting and removing an existing user account
void DeleteUser();

// Handles updating credentials and permissions of an existing user account
void UpdateUser();

// Searches for and displays details of a specific user account
void SearchUser();

// ===============================
// Helper & Validation Functions
// ===============================

// Prompts for a username and returns its vector index for operations
int ReadUserIndex(vector<stUser>& Users, const string& Message);

// Checks whether a given username already exists within the users list
bool IsUserExist(const string& UserName, const vector<stUser>& Users);

// Prompts and builds permissions/credentials data for a specific username
stUser InformationForUser(const string& UserName);

// Verifies if the currently logged-in user possesses a specific permission bit
bool CheckAccessPermission(enPermission Permission);