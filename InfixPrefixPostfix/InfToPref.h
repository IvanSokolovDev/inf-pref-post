#ifndef SOLUTION_INFTOPREF_H
#define SOLUTION_INFTOPREF_H


using namespace std;

#include "InfToPost.h"

class InfToPref {
private:
    string OPEN_BRACKET = "(";
    string CLOSE_BRACKET = ")";
    string input;
    string output;

    static bool isNumber(const string& str);

    static bool isCharacter(string str);

    bool isOpenBracket(const string& str);

    bool isCloseBracket(const string& str);

    void deleteSpaces();

    void setMulti();

    void reverseBracket();

    static string reverseString(string str);

    string getInput();
public:
    InfToPref(string str);

    void createPrefix();

    string getPrefix();
};

#endif


