#include "TransactionServices.h"
#include "UI.h"
#include "UserServices.h"
#include "User.h"

// ===============================
// Run Transactions Menu (Loop)
// ===============================

// Displays and handles the dynamic loop for the transaction operations menu
void RunTransactionsMenu()
{
    if (!CheckAccessPermission(Transaction))
    {
        ShowAccessDeniedMessage();
        return;
    }

    while (true)
    {
        PrintScreenHeader("Transactions Menu");

        cout << "\n\t[1] Deposit."
            << "\n\t[2] Withdraw."
            << "\n\t[3] Total Balance."
            << "\n\t[4] Main Menu."
            << endl;

        cout << string(100, '=') << endl;

        int Choice = ReadInt("Choose what do you want to do? [1..4]", 1, 4);

        enTrMenu Menu = ChooseTransaction(Choice);

        if (Menu == MainMenuTransaction)
            return;

        MoveToTransaction(Menu);
    }
}

// ===============================
// Choose Transaction Option
// ===============================

// Maps user integer choices to the corresponding transaction enum action
enTrMenu ChooseTransaction(int choice)
{
    switch (choice)
    {
    case 1: return Deposit;
    case 2: return Withdraw;
    case 3: return TotalBalance;
    default: return MainMenuTransaction;
    }
}

// ===============================
// Move To Selected Transaction
// ===============================

// Routes the application flow to the chosen financial transaction action
void MoveToTransaction(enTrMenu Menu)
{
    switch (Menu)
    {
    case Deposit:
        DepositRecord();
        break;

    case Withdraw:
        WithdrawRecord();
        break;

    case TotalBalance:
        TotalBalanceRecords();
        break;

    case MainMenuTransaction:
        return;
    }
}

// ===============================
// Deposit Money
// ===============================

// Handles deposit transaction workflow, validating amounts before updating balances
void DepositRecord()
{
    PrintScreenHeader("Deposit Money");

    vector<stClientRecord> Records = LoadRecords();

    PrintRecords(Records);

    int Index = GetTransactionRecordIndex(Records, "Enter Account Number For Deposit");

    if (Index == -1)
        return;

    double Amount = ReadDouble("Enter Deposit Amount");

    while (Amount <= 0)
    {
        cout << "\nAmount must be greater than zero.\n";

        Amount = ReadDouble("Enter Deposit Amount");
    }

    Records[Index].accountBalance += Amount;

    SaveRecords(Records);

    cout << "\nDeposit Successful.\n";

    cout << "\nPress any key to continue...";
    system("pause>0");
}

// ===============================
// Withdraw Money
// ===============================

// Handles withdrawal transaction workflow with insufficient funds checking
void WithdrawRecord()
{
    PrintScreenHeader("Withdraw Money");

    vector<stClientRecord> Records = LoadRecords();

    PrintRecords(Records);

    int Index = GetTransactionRecordIndex(Records, "Enter Account Number For Withdraw");

    if (Index == -1)
        return;

    double Amount = ReadDouble("Enter Withdraw Amount");

    while (Amount <= 0 || Amount > Records[Index].accountBalance)
    {
        cout << "\nInvalid amount.\n";

        Amount = ReadDouble("Enter another amount");
    }

    Records[Index].accountBalance -= Amount;

    SaveRecords(Records);

    cout << "\nWithdraw Successful.\n";

    cout << "\nPress any key to continue...";
    system("pause>0");
}

// ===============================
// Total Balance
// ===============================

// Calculates and displays the cumulative balance across all registered client accounts
void TotalBalanceRecords()
{
    PrintScreenHeader("Total Balance");

    vector<stClientRecord> Records = LoadRecords();

    double Total = 0;

    for (const stClientRecord& Record : Records)
    {
        Total += Record.accountBalance;
    }

    PrintStringForCenter("Total Balance = " + to_string(Total), 100);

    cout << "\nPress any key to continue...";
    system("pause>0");
}

// ===============================
// Get Record Index For Transaction
// ===============================

// Helper function to search account index interactively; returns -1 on "close" or cancel
int GetTransactionRecordIndex(vector<stClientRecord>& Records, const string& Message)
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