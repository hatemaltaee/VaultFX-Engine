#include "ClientServices.h"
#include "UI.h"
#include "Navigation.h"
#include "UserServices.h"
#include "User.h"

// ===============================
// Show Records
// ===============================

// Checks permissions, loads all client records, and displays them in table view
void ShowRecords()
{
    if (!CheckAccessPermission(ShowClients))
    {
        ShowAccessDeniedMessage();
        return;
    }

    vector<stClientRecord> Records = LoadRecords();

    PrintScreenHeader("Show Client Records (" + to_string(Records.size()) + ")");

    PrintRecords(Records);

    GoBackToMainMenu();
}

// ===============================
// Add Record
// ===============================

// Handles adding new client records with uniqueness validation on account numbers
void AddNewRecord()
{
    if (!CheckAccessPermission(AddClient))
    {
        ShowAccessDeniedMessage();
        return;
    }

    char Answer;

    do
    {
        PrintScreenHeader("Add New Client Record");

        stClientRecord Record = ReadClientData();

        vector<stClientRecord> Records = LoadRecords();

        while (IsRecordExist(Record.accountNumber, Records) || Record.accountNumber == "close")
        {
            cout << "\nAccount Number already exists!\n";

            Record.accountNumber = ReadString("Enter another Account Number");
        }

        AddRecordToFile(Record);

        cout << "\nClient Added Successfully.\n";

        Answer = ReadChar("Do you want to add another client? Y/N");

    } while (toupper(Answer) == 'Y');

    GoBackToMainMenu();
}

// ===============================
// Delete Record
// ===============================

// Prompts for an account number and deletes the matching client record from storage
void DeleteRecord()
{
    if (!CheckAccessPermission(DeleteClient))
    {
        ShowAccessDeniedMessage();
        return;
    }

    PrintScreenHeader("Delete Client Record");

    vector<stClientRecord> Records = LoadRecords();

    PrintRecords(Records);

    int Index = ReadRecordIndex(Records, "Enter Account Number For Delete");

    if (Index != -1)
    {
        Records.erase(Records.begin() + Index);

        SaveRecords(Records);

        cout << "\nClient Deleted Successfully.\n";
    }

    GoBackToMainMenu();
}

// ===============================
// Update Record
// ===============================

// Prompts for an account number and updates client details while preserving account number
void UpdateRecord()
{
    if (!CheckAccessPermission(UpdateClient))
    {
        ShowAccessDeniedMessage();
        return;
    }

    PrintScreenHeader("Update Client Record");

    vector<stClientRecord> Records = LoadRecords();

    PrintRecords(Records);

    int Index = ReadRecordIndex(Records, "Enter Account Number For Update");

    if (Index == -1)
    {
        GoBackToMainMenu();
        return;
    }

    string AccountNumber = Records[Index].accountNumber;

    cout << "\nEnter New Data:\n";

    Records[Index].PINCode = ReadString("PIN Code");
    Records[Index].name = ReadString("Name");
    Records[Index].phone = ReadString("Phone");
    Records[Index].accountBalance = ReadDouble("Account Balance");

    Records[Index].accountNumber = AccountNumber;

    SaveRecords(Records);

    cout << "\nClient Updated Successfully.\n";

    GoBackToMainMenu();
}

// ===============================
// Search Record
// ===============================

// Searches for a specific client record by account number and prints its details
void SearchRecord()
{
    if (!CheckAccessPermission(FindClient))
    {
        ShowAccessDeniedMessage();
        return;
    }

    PrintScreenHeader("Search Client Record");

    vector<stClientRecord> Records = LoadRecords();

    int Index = ReadRecordIndex(Records, "Enter Account Number For Search");

    if (Index != -1)
    {
        PrintRecord(Records[Index], Index + 1);
    }

    GoBackToMainMenu();
}

// ===============================
// Read Record Index
// ===============================

// Prompts for account number input in a loop until found or until user cancels with "close"
int ReadRecordIndex(vector<stClientRecord>& Records, const string& Message)
{
    string AccountNumber = ReadString(Message);

    if (AccountNumber == "close")
        return -1;

    int Index = FindRecordIndex(AccountNumber, Records);

    while (Index == -1)
    {
        cout << "\nAccount Number Not Found!\n";

        AccountNumber = ReadString(Message);

        if (AccountNumber == "close")
            return -1;

        Index = FindRecordIndex(AccountNumber, Records);
    }

    return Index;
}

// ===============================
// Check Record Existence
// ===============================

// Returns true if the account number exists in the provided records vector
bool IsRecordExist(const string& AccountNumber, const vector<stClientRecord>& Records)
{
    return FindRecordIndex(AccountNumber, Records) != -1;
}