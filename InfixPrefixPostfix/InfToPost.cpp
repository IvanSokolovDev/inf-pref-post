#include <iostream>
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

    bool isOperator(const string& string) {
        for (int i = 0; OPERATORS.length(); i++) {
            if (to_string(OPERATORS[i]) == string) {
                return true;
            }
        }

        return false;
    }

    bool isOpenBracket(const string& string) {
        return OPEN_BRACKET == string;
    }

    bool isCloseBracket(const string& string) {
        return CLOSE_BRACKET == string;
    }

    static int getPriority(const string& string) {
        if (string == "+" || string == "-") {
            return 0;
        } else if (string == "*" || string == "/") {
            return 1;
        } else if (string == "^") {
            return 2;
        }

        return -1;
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

    string getInput() {
        return input;
    }
public:
    InfToPost(string str) {
        input = str;
    }

    void createPostfix() {
        cout << "    Входная строка" << endl;
        cout << "        " + getInput() << endl;

        deleteSpaces();
        setMulti();

        cout << "    Убираем пробелы и расставляем *" << endl;
        cout << "        " + getInput() << endl;

        int index = 0;

        while (index < input.length()) {
            string token = to_string(input[index]);

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

    string getPostfix() {
        return output;
    }
};
