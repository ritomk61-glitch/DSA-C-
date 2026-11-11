
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return -1;
}


string infixToPostfix(string s) {

    stack<char> st;
    string ans = "";

    for (int i = 0; i < s.length(); i++) {

        char ch = s[i];

        if (isalnum(ch)) {
            ans += ch;
        }

        else if (ch == '(') {
            st.push(ch);
        }

        else if (ch == ')') {

            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }

            if (!st.empty()) {
                st.pop();
            }
        }

        else {

            while (!st.empty() && st.top() != '(' &&
                   (precedence(st.top()) > precedence(ch) ||
                   (precedence(st.top()) == precedence(ch) && ch != '^'))) {

                ans += st.top();
                st.pop();
            }

            st.push(ch);
        }
    }

  
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    return ans;
}

int main() {

    string infix;

    cout << "Enter infix expression: ";
    cin >> infix;

    cout << "Postfix expression: "
         << infixToPostfix(infix) << endl;

    return 0;
}
