#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Client.h"
#include "ClientFileManager.h"
#include "ReadData.h"

using namespace std;

// ===============================
// Transactions Menu Enums
// ===============================
enum enTrMenu
{
    Deposit = 1,
    Withdraw,
    TotalBalance,
    MainMenuTransaction
};

// ===============================
// Transaction Functions
// ===============================

// Checks permissions, then loops through the transactions menu 
// until the user chooses to return to the Main Menu
void RunTransactionsMenu();

// Converts user integer choice to enTrMenu enumeration type
enTrMenu ChooseTransaction(int choice);

// Routes execution to the selected transaction screen
void MoveToTransaction(enTrMenu Menu);

// Handles depositing funds into a specified client account
void DepositRecord();

// Handles withdrawing funds from a specified client account
void WithdrawRecord();

// Displays the total balances summary for all system clients
void TotalBalanceRecords();

// Prompts for an account number and returns its vector index for transactions
int GetTransactionRecordIndex(vector<stClientRecord>& Records, const string& Message);