#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <stack>
#include <queue>
using namespace std;

//  https://leetcode.cn/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stack.push(')');
            }
            else if (s[i] == '[') {
                stack.push(']');
            }
            else if (s[i] == '{') {
                stack.push('}');
            }
            else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
                if (stack.empty() || stack.top() != s[i]) {
                    return false;
                }
                else {
                    stack.pop();
                }
            }
        }
        return stack.empty();
    }
};

int main(){
    Solution s;
    string str = "()[]{}";
    cout << s.isValid(str) << endl;
    return 0;
}