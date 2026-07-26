#pragma once

#include <string>
#include <climits>

using namespace std;

// ===============================
// Input Functions
// ===============================

// Prompts the user with a message and reads a full line text string
string ReadString(string message);

// Reads an integer value with optional range checking (min/max boundaries)
int ReadInt(string message, int min = INT_MIN, int max = INT_MAX, bool checkRange = true);

// Prompts the user and reads a floating-point double value
double ReadDouble(string message);

// Prompts the user and reads a single character input
char ReadChar(string message);

// Reads a 64-bit long long integer with optional range validation
long long ReadLongLong(string message, long long min = LLONG_MIN, long long max = LLONG_MAX, bool checkRange = true);

// Prompts the user and reads a boolean value (1/0 or Y/N logic)
bool ReadBool(string message);