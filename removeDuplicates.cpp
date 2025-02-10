#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <stack>
#include <queue>
using namespace std;

//  https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stack;
        for(int i = 0; i < s.size(); i++) {
            if (stack.empty() || stack.top() != s[i]) {
                stack.push(s[i]);
            }
            else {
                stack.pop();
            }
        }
        int len = stack.size();
        string result = "";
        while (len--) {
            result.push_back(stack.top());
            stack.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};



int main(){
    Solution s;
    string tokens = "abbaca";
    cout << s.removeDuplicates(tokens) << endl;
    return 0;
}