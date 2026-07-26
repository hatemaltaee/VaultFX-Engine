#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "User.h"

using namespace std;

// ===============================
// Login Functions
// ===============================

// Displays the user login screen, prompts for credentials, and returns the authenticated user structure
stUser LoginScreen(vector<stUser>& Users);

// Validates whether the given username and password match an existing user record
bool IsValidLogin(const string& userName, const string& password);