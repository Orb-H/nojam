#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<string> op;
    stack<string> p_op; // P연산자==피연산자
    string input;
    string tmp1, tmp2;
    
    cin >> input;

    for (int i = 0; i < input.length(); i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            p_op.push(input.substr(i, 1));
        } else {
            switch(input[i]) {
                case '*':
                case '/':
                    while (!op.empty() && (op.top() == "*" || op.top() == "/")) {
                        tmp1 = p_op.top();
                        p_op.pop();
                        tmp2 = p_op.top();
                        p_op.pop();
                        p_op.push(tmp2 + tmp1 + op.top());
                        op.pop();
                    }
                    break;
                case '+':
                case '-':
                    while (!op.empty() && (op.top() == "+" || op.top() == "-" || op.top() == "*" || op.top() == "/")) {
                        tmp1 = p_op.top();
                        p_op.pop();
                        tmp2 = p_op.top();
                        p_op.pop();
                        p_op.push(tmp2 + tmp1 + op.top());
                        op.pop();
                    }
                    break;
                case ')':
                    while (!op.empty() && op.top() != "(") {
                        tmp1 = p_op.top();
                        p_op.pop();
                        tmp2 = p_op.top();
                        p_op.pop();
                        p_op.push(tmp2 + tmp1 + op.top());
                        op.pop();
                    }
                    op.pop();
                    break;
            }
            if (input[i] != ')')
                op.push(input.substr(i, 1));
        }
    }

    while (!op.empty()) {
        tmp1 = p_op.top();
        p_op.pop();
        tmp2 = p_op.top();
        p_op.pop();
        p_op.push(tmp2 + tmp1 + op.top());
        op.pop();
    }

    cout << p_op.top();
}