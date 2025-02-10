#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <stack>
#include <queue>
using namespace std;

//  https://leetcode.cn/problems/evaluate-reverse-polish-notation/

//  逆波兰表达式：操作符在操作数之后
//  RPN：Reverse Polish Notation
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> stack;
        int length = tokens.size();
        for(int i = 0; i < length; i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                long long num1 = stack.top();
                stack.pop();
                long long num2 = stack.top();
                stack.pop();
                if (tokens[i] == "+") {
                    stack.push(num2 + num1);
                }
                else if (tokens[i] == "-") {
                    stack.push(num2 - num1);
                }
                else if (tokens[i] == "*") {
                    stack.push(num2 * num1);
                }
                else if (tokens[i] == "/") {
                    stack.push(num2 / num1);
                }
            }
            else {
                stack.push(stoi(tokens[i]));
            }
        }
        return stack.top();
    }
};

int main(){
    Solution s;
    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << s.evalRPN(tokens) << endl;
    return 0;
}