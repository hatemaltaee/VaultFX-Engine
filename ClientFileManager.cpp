#include "ClientFileManager.h"

// ===============================
// Load Records
// ===============================

// Reads all non-empty lines from the client data file and converts them to a vector of stClientRecord
vector<stClientRecord> LoadRecords()
{
    vector<string> Lines;

    fstream File;

    File.open(fileNameForClient, ios::in);

    if (File.is_open())
    {
        string Line;

        while (getline(File, Line))
        {
            if (!Line.empty())
            {
                Lines.push_back(Line);
            }
        }

        File.close();
    }

    return ConvertLinesToRecords(Lines);
}

// ===============================
// Save Records
// ===============================

// Overwrites the client storage file with the current vector of client records
void SaveRecords(const vector<stClientRecord>& Records)
{
    fstream File;

    File.open(fileNameForClient, ios::out);

    if (File.is_open())
    {
        for (const stClientRecord& Record : Records)
        {
            File << ConvertRecordToLine(Record) << endl;
        }

        File.close();
    }
}

// ===============================
// Add Record
// ===============================

// Appends a single formatted client record line to the end of the data file
void AddRecordToFile(const stClientRecord& Record)
{
    fstream File;

    File.open(fileNameForClient, ios::out | ios::app);

    if (File.is_open())
    {
        File << ConvertRecordToLine(Record) << endl;

        File.close();
    }
}