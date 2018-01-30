// Check Parentheses with ?(any)

#include <iostream>
#include <string>

using namespace std;

bool checkParentheses(string& str) {
    int i, a, b;
    
    a = 0;
    b = 0;
    for (i = 0; i < str.size(); i++) {
        if (str[i] == ')') {
            a++;
        } else {
            b++;
        }
        if (a > b) {
            return false;
        }
    }
    
    a = 0;
    b = 0;
    for (i = str.size() - 1; i >= 0; i--) {
        if (str[i] == '(') {
            a++;
        } else {
            b++;
        }
        if (a > b) {
            return false;
        }
    }
    
    return true;
}

bool checkParenthesesFast(string& str) {
    int i, question, count;
    
    question = 0;
    count = 0;
    for (i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            count++;
        } else if (str[i] == ')') {
            count--;
        } else {
            question++;
            count--;
        }
        
        while (question > 0 && count < 0) {
            question--;
            count += 2;
        }
        
        if (count < 0) {
            return false;
        }
    }
    
    return count == 0;
}

int main(int argc, char* argv[]) {
    string str;
    
    str = "((()))";
    cout << str << ": " << checkParentheses(str) << "\n";
    cout << str << ": " << checkParenthesesFast(str) << "\n";
    
    str = "()()()";
    cout << str << ": " << checkParentheses(str) << "\n";
    cout << str << ": " << checkParenthesesFast(str) << "\n";
    
    str = "(?????";
    cout << str << ": " << checkParentheses(str) << "\n";
    cout << str << ": " << checkParenthesesFast(str) << "\n";
    
    str = "(?)))?";
    cout << str << ": " << checkParentheses(str) << "\n";
    cout << str << ": " << checkParenthesesFast(str) << "\n";
    
    return 0;
}

