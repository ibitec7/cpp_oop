#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

bool isBalanced(string str) {
    stack<char> s;
    char openingBrackets[] = {'(', '[', '{'};
    char closingBrackets[] = {')', ']', '}'};

    for (char c : str) {
        bool isOpen = false;
        for (int i = 0; i < 3; ++i) {
            if (c == openingBrackets[i]) {
                isOpen = true;
                s.push(c);
                break;
            }
        }

        if (!isOpen) {
            if (s.empty()) {
                return false;  
            }

            char top = s.top();
            s.pop();

            if (c != closingBrackets[find(openingBrackets, openingBrackets + 3, top) - openingBrackets]) {
                return false;  
            }
        }
    }

    return s.empty();  
}

int main() {
    string input;
    cout << "Enter a string of parentheses, square brackets, and curly braces: ";
    cin >> input;

    if (isBalanced(input)) {
        cout << "The string is balanced." << endl;
    } else {
        cout << "The string is not balanced." << endl;
    }

    return 0;
}
