#pragma once

#include <string>
#include <vector>

using namespace std;

// ===============================
// String Utilities
// ===============================

// Splits a string into a vector of substrings based on a specified delimiter/separator
vector<string> SplitString(const string& Text, const string& Separator);