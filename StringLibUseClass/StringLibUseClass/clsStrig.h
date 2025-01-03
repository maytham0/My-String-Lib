#pragma once

#include<iostream>
#include <vector>
#include<string>


using namespace std;

class clsString
{
private:
    string _Value;
    string _Value2;
    string _Delim;
    char _MyChar;
public:
    clsString()
    {
        _Value = "";
    }
    clsString(string Value,string Delim, char MyChar)
    {
        _Value = Value;
        _Delim = Delim;
        _MyChar = MyChar;
    }
    void setValue(string Value)
    {
        _Value = Value;
    }
    string GetValue()
    {
        return _Value;
    }
    __declspec(property(get = GetValue, put = setValue))string Value;

    void setDelim(string Delim)
    {
        _Delim = Delim;
    }
    string getDelim()
    {
        return _Delim;
    }
    __declspec(property(get = getDelim, put = setDelim))string Delim;
    void setChar(char Mychar)
    {
        _MyChar = Mychar;
    }
    char getChar()
    {
        return _MyChar;
    }
    



    static vector<string> SplitString(string S1, string Delim) {
        vector<string> vString;
        short pos = 0;
        string sWord;
        // define a string variable
        // use find() function to get the position of the delimiters
        while ((pos = S1.find(Delim)) != std::string::npos) {
            sWord = S1.substr(0, pos); // store the word
            if (sWord != "") {
                vString.push_back(sWord);
            }
            S1.erase(0, pos + Delim.length());
        }
        if (S1 != "") {
            vString.push_back(S1); // it adds last word of the string.
        }
        return vString;
    }
    vector<string> SplitString()
    {
        return SplitString(_Value, _Delim);
    }

    static short CountWords(string S1)
    {
        string delim = " "; // delimiter
        short Counter = 0;
        short pos = 0;
        string sWord; // define a string variable
        // use find() function to get the position of the delimiters
        while ((pos = S1.find(delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos); // store the word
            if (sWord != "")
            {
                Counter++;
            }
            //erase() until positon and move to next word.
            S1.erase(0, pos + delim.length());
        }
        if (S1 != "")
        {
            Counter++; // it counts the last word of the string.
        }
        return Counter;
    }
    short CountWords()
    {
        return CountWords(_Value);
    };

    /*string ReadString(string Msg)
    {
        string Text;
        cout << Msg;
        getline(cin >> ws, Text);
        return Text;
    }
    char ReadChar()
    {
        char X;
        cout << "\nPlease enter char :\n";
        cin >> X;
        return X;
    }*/
    static char InvertingCharacter(char MyChar)
    {
        return (isupper(MyChar)) ? tolower(MyChar) : toupper(MyChar);
    }
    char InvertingCharacter()
    {
        return InvertingCharacter(_MyChar);
    }


    static void PrintFirstLettersOfString(string Text)
    {
        bool IsSpace = true;
        for (int i = 0; i < Text.length(); i++)
        {
            if (Text[i] != ' ' && IsSpace)
                cout << Text[i] << endl;
            IsSpace = (Text[i] == ' ') ? true : false;
        }
    }
    void PrintFirstLettersOfString()
    {
        return PrintFirstLettersOfString(_Value);
    }

    static string UpperFirstLetterOfEachWord(string Text)
    {
        bool IsSpace = true;
        for (int i = 0; i < Text.length(); i++)
        {
            if (Text[i] != ' ' && IsSpace)
                Text[i] = toupper(Text[i]);
            IsSpace = (Text[i] == ' ') ? true : false;
        }
        return Text;
    }
    string UpperFirstLetterOfEachWord()
    {
        return  UpperFirstLetterOfEachWord(_Value);
    }

    static string LowerFirstLetterOfEachWord(string Text)
    {
        bool IsSpace = true;
        for (int i = 0; i < Text.length(); i++)
        {
            if (Text[i] != ' ' && IsSpace)
                Text[i] = tolower(Text[i]);
            IsSpace = (Text[i] == ' ') ? true : false;
        }
        return Text;
    }
    string LowerFirstLetterOfEachWord()
    {
        return LowerFirstLetterOfEachWord(_Value);
    }


    static string UpperAllLetterOfString(string Text)
    {
        for (int i = 0; i < Text.length(); i++)
        {
            Text[i] = toupper(Text[i]);
        }
        return Text;
    }
    string UpperAllLetterOfString()
    {
        return UpperAllLetterOfString(_Value);
    }

    static string LowerAllLetterOfString(string Text) {
        for (int i = 0; i < Text.length(); i++)
        {
            Text[i] = tolower(Text[i]);
        }
        return Text;
    }
    string LowerAllLetterOfString()
    {
        return LowerAllLetterOfString(_Value);
    }

    /*static string InvertAllLettersOfString(string Text)
    {
        for (int i = 0; i < Text.length(); i++)
        {
            Text[i] = InvertingCharacter(Text[i]);
        }
        return Text;
    }
    string InvertAllLettersOfString()
    {
        return  InvertAllLettersOfString(_Value);
    }*/


    static short CountLettersByMatchCase(string Text, char CharToCount, bool MatchCase = true)
    {
        short Counter = 0;
        for (int i = 0; i < Text.length(); i++)
        {
            if (MatchCase == false)
            {
                if (toupper(Text[i]) == toupper(CharToCount))
                    Counter++;
            }
            else
                if (Text[i] == CharToCount)
                    Counter++;
        }
        return Counter;
    }
    short CountLettersByMatchCase()
    {
        return  CountLettersByMatchCase(_Value, _MyChar);
    }

    static bool isvowel(char i)
    {
        i = tolower(i);
        return (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') ? true : false;
    }
    bool isvowel()
    {
        return isvowel(_MyChar);
    }

    static short CountVowelLetters(string Text)
    {
        short Counter = 0;
        for (int i = 0; i < Text.length(); i++)
        {
            if (isvowel(Text[i]))
                Counter++;
        }
        return Counter;
    }
    short CountVowelLetters()
    {
        return CountVowelLetters(_Value);
    }

    static string PrintAllVowelsInString(string Text, string Space = "  ")
    {
        string Vowels;
        for (int i = 0; i < Text.length(); i++)
        {
            if (isvowel(Text[i]))
                Vowels += Text[i] + Space;
        }
        return Vowels;
    }
    string PrintAllVowelsInString()
    {
        return PrintAllVowelsInString(_Value);

    }
    static void  PrintEachWordInString(string Text)
    {
        string Space = " ";
        string NewText;
        int Pos;
        while ((Pos = Text.find(Space)) != string::npos)
        {
            NewText = Text.substr(0, Pos);
            if (NewText != "")
                cout << NewText << endl;
            Text.erase(0, Pos + Space.length());
        }
        if (Text != "")
            cout << Text << endl;
    }

    void  PrintEachWordInString()
    {
        return  PrintEachWordInString(_Value);
    }

    static short CountEachWordInString(string Text)
    {
        short Counter = 0;
        string Space = " ";
        string NewText;
        int Pos;
        while ((Pos = Text.find(Space)) != string::npos)
        {
            NewText = Text.substr(0, Pos);
            if (NewText != "")
                Counter++;
            Text.erase(0, Pos + Space.length());
        }
        if (Text != "")
            return ++Counter;
    }
    short CountEachWordInString()
    {
        return CountEachWordInString(_Value);
    }

    static string TrimLeft(string Text, char Delim)
    {
        for (int i = 0; i < Text.length(); i++)
        {
            if (Text[i] != Delim)
                return Text = Text.substr(i, Text.length());
        }
    }
    string TrimLeft()
    {
        return TrimLeft(_Value, _MyChar);
    }
    static string TrimRight(string Text, char Delim)
    {
        for (int i = 0; i < Text.length(); i++)
        {
            if (Text[Text.length() - i - 1] != Delim)
                return Text = Text.substr(0, Text.length() - i);
        }
    }
    string TrimRight()
    {
        return TrimRight(_Value, _MyChar);
    }
    static string Trim(string Text, char Delim)
    {
        return TrimLeft(TrimRight(Text, Delim), Delim);
    }
    string Trim()
    {
        return Trim(_Value, _MyChar);
    }


    static string JoinString(vector <string> vSplit, string Delim)
    {
        string Line;
        for (string& temp : vSplit)
            Line += temp + Delim;
        return Trim(Line, '#');
    }
    string JoinString()
    {
        return JoinString(SplitString(), _Delim);
    }

    static string ReverseWords(string Text)
    {
        string Line;
        vector <string> vSplit = SplitString(Text, " ");
        vector <string>::iterator iter = vSplit.end();
        while (iter != vSplit.begin())
        {
            --iter;
            Line += *iter + " ";
        }
        Line = Line.substr(0, Line.length() - 1);
        return Line;
    }
    string ReverseWords() {

        return ReverseWords(_Value);
    }

    static string ReplaceWords(string Text, string WordToReplace, string ReplaceNew)
    {
        int Pos;
        while ((Pos = Text.find(WordToReplace)) != string::npos)
            Text = Text.replace(Pos, WordToReplace.length(), ReplaceNew);
        return Text;
    }
    string ReplaceWords()
    {//work in
        return ReplaceWords(_Value, "", "");
    }

    static string RemovePuncuations(string Text)
    {
        for (int i = 0; i < Text.length(); i++)
        {
            if (ispunct(Text[i]))
                Text[i] = ' ';
        }
        return Text;
    }
    string RemovePuncuations()
    {
        return RemovePuncuations(_Value);
    }

    static string PrintStringWithoutPunct(string Text, string Space)
    {
        string Word;
        vector <string> vText = SplitString(Text, " ");
        for (string& temp : vText)
            Word += temp + Space;
        return Word.substr(0, Word.length() - 1);
    }
    string PrintStringWithoutPunct()
    {
        return PrintStringWithoutPunct(_Value, _Delim);
    }
};


