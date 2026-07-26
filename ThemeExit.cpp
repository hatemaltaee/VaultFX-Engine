#include "ThemeExit.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

// ===============================
// Loading And Exit Visual UI
// ===============================

// Displays an animated loading progress bar before terminating the application
void ShowLoadingAndExit()
{
    cout << "\nExiting the program...\n\n";

    const int Width = 50;

    for (int i = 0; i <= 100; i++)
    {
        int Position = i * Width / 100;

        cout << "\r[";

        for (int j = 0; j < Width; j++)
        {
            if (j < Position)
                cout << char(219); // ASCII block character for progress fill
            else
                cout << " ";
        }

        cout << "] " << i << "%" << flush;

        this_thread::sleep_for(chrono::milliseconds(10));
    }

    cout << "\n\nGood Bye :-)\n";
}