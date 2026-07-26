#include "Client.h"

// ===============================
// UI Display Functions
// ===============================

// Prints the tabular header for displaying client records
void PrintRecordHeader()
{
    cout << left
        << setw(4) << "No."
        << setw(18) << "| Account Number"
        << setw(12) << "| PIN Code"
        << setw(37) << "| Name"
        << setw(17) << "| Phone"
        << "| Balance"
        << endl;

    cout << string(100, '-') << endl;
}

// Formats and prints a single client record row
void PrintRecord(const stClientRecord& Record, int position)
{
    cout << left
        << setw(4) << position
        << "| " << setw(16) << Record.accountNumber
        << "| " << setw(10) << Record.PINCode
        << "| " << setw(35) << Record.name
        << "| " << setw(15) << Record.phone
        << "| " << Record.accountBalance
        << endl;
}

// Iterates and displays a list of all client records in table format
void PrintRecords(const vector<stClientRecord>& Records)
{
    PrintRecordHeader();

    for (int i = 0; i < (int)Records.size(); i++)
    {
        PrintRecord(Records[i], i + 1);
    }

    cout << string(100, '=') << endl;
}

// ===============================
// Serialization & Conversion
// ===============================

// Parses a single delimited text line into an stClientRecord structure
stClientRecord ConvertLineToRecord(const string& Line)
{
    stClientRecord Record;

    vector<string> Parts = SplitString(Line, separatorOfClient);

    if (Parts.size() != 5)
    {
        return Record;
    }

    Record.accountNumber = Parts[0];
    Record.PINCode = Parts[1];
    Record.name = Parts[2];
    Record.phone = Parts[3];
    Record.accountBalance = stod(Parts[4]);

    return Record;
}

// Converts an stClientRecord structure into a delimited text line for file storage
string ConvertRecordToLine(const stClientRecord& Record)
{
    return
        Record.accountNumber + separatorOfClient +
        Record.PINCode + separatorOfClient +
        Record.name + separatorOfClient +
        Record.phone + separatorOfClient +
        to_string(Record.accountBalance);
}

// Converts a collection of text lines into a vector of stClientRecord structures
vector<stClientRecord> ConvertLinesToRecords(const vector<string>& Lines)
{
    vector<stClientRecord> Records;

    for (const string& Line : Lines)
    {
        Records.push_back(ConvertLineToRecord(Line));
    }

    return Records;
}

// Converts a collection of stClientRecord structures into a vector of formatted text lines
vector<string> ConvertRecordsToLines(const vector<stClientRecord>& Records)
{
    vector<string> Lines;

    for (const stClientRecord& Record : Records)
    {
        Lines.push_back(ConvertRecordToLine(Record));
    }

    return Lines;
}

// ===============================
// Search Operations
// ===============================

// Searches for a client by account number and returns its vector index (-1 if not found)
int FindRecordIndex(const string& Value, const vector<stClientRecord>& Records)
{
    for (int i = 0; i < (int)Records.size(); i++)
    {
        if (Records[i].accountNumber == Value)
        {
            return i;
        }
    }

    return -1;
}

// ===============================
// Data Input Reader
// ===============================

// Prompts the user and reads complete client information from input
stClientRecord ReadClientData()
{
    stClientRecord Record;

    Record.accountNumber = ReadString("Account Number");
    Record.PINCode = ReadString("PIN Code");
    Record.name = ReadString("Name");
    Record.phone = ReadString("Phone");
    Record.accountBalance = ReadDouble("Account Balance");

    return Record;
}