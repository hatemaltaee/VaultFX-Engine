#include "StringUtils.h"

// ===============================
// Split String Implementation
// ===============================

// Splits a string into substrings using a specified string separator delimiter
vector<string> SplitString(const string& Text, const string& Separator)
{
    vector<string> Tokens;

    size_t Start = 0;
    size_t End;

    while ((End = Text.find(Separator, Start)) != string::npos)
    {
        Tokens.push_back(Text.substr(Start, End - Start));

        Start = End + Separator.length();
    }

    Tokens.push_back(Text.substr(Start));

    return Tokens;
}