#include <iostream>
#include "InfToPost.h"
#include "InfToPref.h"

using namespace std;

int main() {
    string input = "(a + b) / (c + d - 1)";
    //string input = "(a+3)*5-(2*b)";
    //string input = "1 + (2 * 3) / 4 - 5";
    //string input = "a+b/(c-d)";

    cout << "Постфиксная запись:" << endl;
    InfToPost infToPost(input);
    infToPost.createPostfix();
    cout << "Постфикс" << endl;
    cout << "    " + infToPost.getPostfix() << endl;

    cout << endl;

    cout << "Префиксная запись:" << endl;
    InfToPref infToPref(input);
    infToPref.createPrefix();
    cout << "Префикс" << endl;
    cout << "    " + infToPref.getPrefix() << endl;

    return 0;
}


