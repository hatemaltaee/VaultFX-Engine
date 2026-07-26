#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Client.h"

using namespace std;

// ===============================
// File Operations
// ===============================

// Load all client records from the storage file into memory
vector<stClientRecord> LoadRecords();

// Save the entire vector of client records back to the storage file
void SaveRecords(const vector<stClientRecord>& Records);

// Append a single new client record directly to the end of the file
void AddRecordToFile(const stClientRecord& Record);