#ifndef SOLUTION_INFTOPOST_H
#define SOLUTION_INFTOPOST_H

#include <string>
#include <stack>

using namespace std;

class InfToPost {
private:
    string OPERATORS = "+-*/^";
    string OPEN_BRACKET = "(";
    string CLOSE_BRACKET = ")";
    string input;
    string output;
    stack <string> stack;

    static bool isNumber(const string& str);

    static bool isCharacter(string str);

    bool isOperator(const string& str);

    bool isOpenBracket(const string& str);

    bool isCloseBracket(const string& str);

    static int getPriority(const string& str);

    void deleteSpaces();

    void setMulti();

    string getInput();
public:
    InfToPost(string str);

    void createPostfix();

    string getPostfix();
};

//class InfToPost {
//private:
//    string OPERATORS;
//    string OPEN_BRACKET;
//    string CLOSE_BRACKET;
//    string input;
//    string output;
//    stack <string> stack;
//
//    bool isNumber(string string);
//    bool isCharacter(string string);
//    bool isOperator(string string);
//    bool isOpenBracket(string string);
//    bool isCloseBracket(string string);
//    int getPriority(string string);
//    void deleteSpaces();
//    void setMulti();
//    string getInput();
//public:
//    InfToPost(string input);
//    void createPostfix();
//    string getPostfix();
//};

#endif
