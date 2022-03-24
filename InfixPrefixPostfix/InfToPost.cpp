#include <iostream>
#include <string>
#include <stack>
#include "InfToPost.h"

using namespace std;


bool InfToPost::isNumber(const string& str) {
    for (char a : str){
        if (a != 45){
            if ((a < 48) || (a > 57)) {
                if ((a != '.' & a != ',')) {
                    return false;
                }
            }
        }
    }

    return true;
}

bool InfToPost::isCharacter(string str) {
    if (str[0] >=  'a' & str[0] <= 'z') {
        return true;
    }

    return false;
}

bool InfToPost::isOperator(const string& str) {
    for (int i = 0; OPERATORS.length(); i++) {
        string temp = "";
        temp += OPERATORS.at(i);
        if (temp == str) {
            return true;
        }
    }

    return false;
}

bool InfToPost::isOpenBracket(const string& str) {
    return OPEN_BRACKET == str;
}

bool InfToPost::isCloseBracket(const string& str) {
    return CLOSE_BRACKET == str;
}

int InfToPost::getPriority(const string& str) {
    if (str == "+" || str == "-") {
        return 0;
    } else if (str == "*" || str == "/") {
        return 1;
    } else if (str == "^") {
        return 2;
    }

    return -1;
}

void InfToPost::deleteSpaces() {
    string temp = "";
    for (int i = 0; i < input.length(); i++) {
        if (input.at(i) != ' ') {
            temp += input.at(i);
        }
    }
    input = temp;
}

void InfToPost::setMulti() {
    for (int i = 0; i < input.length() - 1; i++) {
        string first = "";
        first += input[i];
        string second = "";
        second += input[i + 1];

        string temp = input;
        string multi = first + "*" + second;

        if (isCloseBracket(first) & isOpenBracket(second)) {
            input = temp.replace(i, 2, multi);
        } else if (isNumber(first) & isOpenBracket(second)) {
            input = temp.replace(i, 2, multi);
        } else if (isCharacter(first) & isOpenBracket(second)) {
            input = temp.replace(i , 2, multi);
        } else if (isCloseBracket(first) & isNumber(second)) {
            input = temp.replace(i, 2, multi);
        } else if (isCloseBracket(first) & isCharacter(second)) {
            input = temp.replace(i, 2, multi);
        } else if (isNumber(first) & isCharacter(second)) {
            input = temp.replace(i, 2, multi);
        } else if (isCharacter(first) & isNumber(second)) {
            input = temp.replace(i, 2, multi);
        } else if (isCharacter(first) & isCharacter(second)) {
            input = temp.replace(i, 2, multi);
        } else if (isOpenBracket(first) & isCharacter(second)) {
            input = temp.replace(i, 2, multi);
        }
    }
}

string InfToPost::getInput() {
    return input;
}

InfToPost::InfToPost(string str) {
    input = str;
}

void InfToPost::createPostfix() {
    cout << "    Входная строка" << endl;
    cout << "        " + getInput() << endl;

    deleteSpaces();
    setMulti();

    cout << "    Убираем пробелы и расставляем *" << endl;
    cout << "        " + getInput() << endl;

    int index = 0;

    while (index < input.length()) {
        string token = "";
        token += input[index];

        if (isNumber(token)) {
            for (int i = index + 1; i < input.length(); i++) {
                if (!isNumber(to_string(input[index]))) {
                    break;
                }

                index = i;
                token = token + input[index];
            }

            output.append(token).append(" ");
        } else if (isCharacter(token)) {
            output.append(token).append(" ");
        } else if (isOpenBracket(token)) {
            stack.push(token);
        } else if (isCloseBracket(token)) {
            while (!stack.empty() & !isOpenBracket(stack.top())) {
                output.append(stack.top()).append(" ");
                stack.pop();
            }

            stack.pop();
        } else if (isOperator(token)) {
            while (!stack.empty() && isOperator(stack.top()) &&
                   getPriority(token) <= getPriority(stack.top())) {
                output.append(stack.top()).append(" ");
                stack.pop();
            }

            stack.push(token);
        }

        index++;
    }

    while (!stack.empty()) {
        output.append(stack.top()).append(" ");
        stack.pop();
    }
}

string InfToPost::getPostfix() {
    return output;
}

