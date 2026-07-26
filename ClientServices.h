#pragma once

#include <vector>
#include <string>
#include "Client.h"
#include "ClientFileManager.h"

using namespace std;

// ===============================
// Client Record Operations
// ===============================

// Display all registered client records in a tabular view
void ShowRecords();

// Process input and add a new client record to the system
void AddNewRecord();

// Delete a specific client record using their account number
void DeleteRecord();

// Update existing client information (PIN, Name, Phone, Balance)
void UpdateRecord();

// Search and display details for a specific client record
void SearchRecord();

// ===============================
// Helper Functions
// ===============================

// Prompt for an account number and return its vector index if found
int ReadRecordIndex(vector<stClientRecord>& Records, const string& Message);

// Check whether a record exists in the list based on account number
bool IsRecordExist(const string& AccountNumber, const vector<stClientRecord>& Records);