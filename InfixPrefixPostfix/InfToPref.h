#ifndef SOLUTION_INFTOPREF_H
#define SOLUTION_INFTOPREF_H

#include <string>
#include <stack>

using namespace std;

#include <string>
#include <stack>
#include <iostream>

#include <string>
#include <stack>
#include <iostream>

using namespace std;

#include "InfToPost.h"

class InfToPref {
private:
    string OPEN_BRACKET = "(";
    string CLOSE_BRACKET = ")";
    string input;
    string output;

    static bool isNumber(const string& string) {
        for (char a : string){
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

    static bool isCharacter(string string) {
        if (string[0] >=  'a' & string[0] <= 'z') {
            return true;
        }

        return false;
    }

    bool isOpenBracket(const string& string) {
        return OPEN_BRACKET == string;
    }

    bool isCloseBracket(const string& string) {
        return CLOSE_BRACKET == string;
    }

    void deleteSpaces() {
        for (int i = 0; i < input.length(); i++) {
            if (input[i] == ' ') {
                remove(&input[i]);
                i--;
            }
        }
    }

    void setMulti() {
        for (int i = 0; i < input.length() - 1; i++) {
            string first = to_string(input[i]);
            string second = to_string(input[i + 1]);

            string temp = input;
            string multi = first + "*" + second;

            if (isCloseBracket(first) & isOpenBracket(second)) {
                input = temp.replace(i, i + 2, multi);
            } else if (isNumber(first) & isOpenBracket(second)) {
                input = temp.replace(i, i + 2, multi);
            } else if (isCharacter(first) & isOpenBracket(second)) {
                input = temp.replace(i , i + 2, multi);
            } else if (isCloseBracket(first) & isNumber(second)) {
                input = temp.replace(i, i + 2, multi);
            } else if (isCloseBracket(first) & isCharacter(second)) {
                input = temp.replace(i, i + 2, multi);
            } else if (isNumber(first) & isCharacter(second)) {
                input = temp.replace(i, i + 2, multi);
            } else if (isCharacter(first) & isNumber(second)) {
                input = temp.replace(i, i + 2, multi);
            } else if (isCharacter(first) & isCharacter(second)) {
                input = temp.replace(i, i + 2, multi);
            }
        }
    }

    void reverseBracket() {
        for (int i = 0; i < input.length(); i++) {
            string elem = to_string(input[i]);
            string temp = input;

            if (isCloseBracket(elem)) {
                input = temp.replace(i, i + 1, "(");
            } else if (isOpenBracket(elem)) {
                input = temp.replace(i, i + 1, ")");
            }
        }
    }

    static string reverseString(string str) {
        string inputTemp;

        for (int i = str.length(); i >= 0; i--) {
            inputTemp = inputTemp.append(to_string(str[i]));
        }
        return inputTemp;
    }

    string getInput() {
        return input;
    }
public:
    InfToPref(string str) {
        input = str;
    }

    void createPrefix() {
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

    string getPrefix() {
        return output;
    }
};

#endif


