#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

//  https://leetcode.cn/problems/repeated-substring-pattern/

//  1.暴力解法
//  1.满足条件的子串的首字符 = s[0]
//  2.满足条件的子串的长度 <= [s.size() / 2]
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = 1;
        for (; len <= (s.size() / 2); len++) {
            if (s.size() % len != 0) continue;
            string substr = s.substr(0, len);
            string result = "";
            for (int i = 1; i <= (s.size() / len); i++) {
                result += substr;
            }
            if (result == s) return true;
        }
        return false;
    }
};


int main(){
    string s = "abcabcabcabc";
    Solution sol;
    bool res = sol.repeatedSubstringPattern(s);
    cout << res << endl;
    return 0;
}