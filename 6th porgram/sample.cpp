#include <iostream>
#include <stack>
#include <cctype>
#include <cmath>
using namespace std;

void evaluatePostfixExpression(string &postfixExpr, stack<int>& operandStack) {
    string temp = "";
    for (int index = 0; index < postfixExpr.size(); index++) {
        char currentChar = postfixExpr[index];
        if (currentChar == '$') {
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();
            int result = pow(operand1, operand2);
            operandStack.push(result);
        } else if (currentChar == '+') {
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();
            int result = operand1 + operand2;
            operandStack.push(result);
        } else if (currentChar == '-') {
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();
            int result = operand1 - operand2;
            operandStack.push(result);
        } else if (currentChar == '*') {
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();
            int result = operand1 * operand2;
            operandStack.push(result);
        } else if (currentChar == '/') {
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();
            int result = operand1 / operand2;
            operandStack.push(result);
        } else if (isdigit(currentChar)) {
            temp = "";
            while (isdigit(postfixExpr[index])) {
                temp += postfixExpr[index];
                index++;
            }
            index--; 
            int operand = stoi(temp);
            operandStack.push(operand);
        }
    }
}

int main() {
    string postfixExpr = "2 3$5 2 2 $*+12 6/-";
    stack<int> operandStack;
    evaluatePostfixExpression(postfixExpr, operandStack);
    cout << operandStack.top();
    return 0;
}
