#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "ReadData.h"
#include "StringUtils.h"

using namespace std;

// ===============================
// Constants
// ===============================
const string fileNameForClient = "ClientRecord.txt";
const string separatorOfClient = "%$#$%";

// ===============================
// Main Menu Enums
// ===============================
enum enMenu
{
    Show = 1,
    Add,
    Delete,
    Update,
    Search,
    Transactions,
    ManageUsers,
    Logout
};

// ===============================
// Client Record Structure
// ===============================
struct stClientRecord
{
    string accountNumber;
    string PINCode;
    string name;
    string phone;
    double accountBalance = 0;
};

// ===============================
// UI Display Functions
// ===============================
void PrintRecordHeader();
void PrintRecord(const stClientRecord& Record, int position);
void PrintRecords(const vector<stClientRecord>& Records);

// ===============================
// Conversion Functions
// ===============================
stClientRecord ConvertLineToRecord(const string& Line);
string ConvertRecordToLine(const stClientRecord& Record);
vector<stClientRecord> ConvertLinesToRecords(const vector<string>& Lines);
vector<string> ConvertRecordsToLines(const vector<stClientRecord>& Records);

// ===============================
// Search Functions
// ===============================
int FindRecordIndex(const string& Value, const vector<stClientRecord>& Records);

// ===============================
// Data Input Functions
// ===============================
stClientRecord ReadClientData();