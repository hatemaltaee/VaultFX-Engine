#include "ReadData.h"
#include <iostream>
#include <limits>

using namespace std;

// ===============================
// Read String
// ===============================

// Prompts the user for a text string input and handles leading whitespace
string ReadString(string message)
{
    string Text;

    cout << "\n  " << message << " : ";

    getline(cin >> ws, Text);

    return Text;
}

// ===============================
// Read Integer
// ===============================

// Prompts for an integer input with type validation and optional range checking
int ReadInt(string message, int min, int max, bool checkRange)
{
    int Number;

    while (true)
    {
        cout << "\n  " << message << " : ";

        cin >> Number;

        if (cin.fail())
        {
            cout << "\n[!] Invalid integer.\n";

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (checkRange && (Number < min || Number > max))
        {
            cout << "\n[!] Number must be between " << min << " and " << max << ".\n";
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return Number;
        }
    }
}

// ===============================
// Read Double
// ===============================

// Prompts for a floating-point (double) input with type validation
double ReadDouble(string message)
{
    double Number;

    while (true)
    {
        cout << "\n  " << message << " : ";

        cin >> Number;

        if (cin.fail())
        {
            cout << "\n[!] Invalid number.\n";

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return Number;
        }
    }
}

// ===============================
// Read Character
// ===============================

// Prompts for a single character input and clears the remaining buffer line
char ReadChar(string message)
{
    char Letter;

    cout << "\n  " << message << " : ";

    cin >> Letter;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return Letter;
}

// ===============================
// Read Long Long
// ===============================

// Prompts for a 64-bit integer input with type validation and optional range checking
long long ReadLongLong(string message, long long min, long long max, bool checkRange)
{
    long long Number;

    while (true)
    {
        cout << "\n  " << message << " : ";

        cin >> Number;

        if (cin.fail())
        {
            cout << "\n[!] Invalid number.\n";

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (checkRange && (Number < min || Number > max))
        {
            cout << "\n[!] Number out of range.\n";
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return Number;
        }
    }
}

// ===============================
// Read Boolean
// ===============================

// Prompts for a boolean input (0 for false, 1 for true) with input validation
bool ReadBool(string message)
{
    int Value;

    while (true)
    {
        cout << "\n  " << message << " (0 = No , 1 = Yes) : ";

        cin >> Value;

        if (cin.fail())
        {
            cout << "\n[!] Enter only 0 or 1.\n";

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (Value != 0 && Value != 1)
        {
            cout << "\n[!] Enter only 0 or 1.\n";
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return Value;
        }
    }
}