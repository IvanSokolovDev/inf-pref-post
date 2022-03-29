#include <string>
#include <stack>
#include <iostream>

using namespace std;

#include "InfToPost.h"
#include "InfToPref.h"

bool InfToPref::isNumber(const string& str) {
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

bool InfToPref::isCharacter(string str) {
    if (str[0] >=  'a' & str[0] <= 'z') {
        return true;
    }

    return false;
}

bool InfToPref::isOpenBracket(const string& str) {
    return OPEN_BRACKET == str;
}

bool InfToPref::isCloseBracket(const string& str) {
    return CLOSE_BRACKET == str;
}

void InfToPref::deleteSpaces() {
    string temp = "";
    for (int i = 0; i < input.length(); i++) {
        if (input.at(i) != ' ') {
            temp += input.at(i);
        }
    }
    input = temp;
}

void InfToPref::setMulti() {
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
        }
    }
}

void InfToPref::reverseBracket() {
    for (int i = 0; i < input.length(); i++) {
        string elem = to_string(input[i]);
        string temp = input;

        if (isCloseBracket(elem)) {
            input = temp.replace(i, 1, "(");
        } else if (isOpenBracket(elem)) {
            input = temp.replace(i, 1, ")");
        }
    }
}

string InfToPref::reverseString(string str) {
    string inputTemp;

    for (int i = str.length(); i >= 0; i--) {
        inputTemp += str[i];
    }
    return inputTemp;
}

string InfToPref::getInput() {
    return input;
}

InfToPref::InfToPref(string str) {
    input = str;
}

void InfToPref::createPrefix() {
    cout << "    Входная строка" << endl;
    cout << "        " + getInput() << endl;

    deleteSpaces();
    setMulti();

    cout << "    Убираем пробелы и расставляем *" << endl;
    cout << "        " + input << endl;

    input = reverseString(input);

    reverseBracket();

    cout << "    Перевернули строку" << endl;
    cout << "        " + input << endl;

    cout << "Конвертируем в постфикс" << endl;
    InfToPost infToPost(input);
    infToPost.createPostfix();
    output = infToPost.getPostfix();
    cout << "    Постфикс" << endl;
    cout << "        " + output << endl;

    output = reverseString(output);
}

string InfToPref::getPrefix() {
    return output;
}


