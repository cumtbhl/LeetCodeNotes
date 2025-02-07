#include<iostream>
#include<string>
#include<vector>
using namespace std;

//  https://leetcode.cn/problems/valid-anagram/description/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        vector<int> count(26,0);

        for (auto i : s) {
            count[i - 'a']++;
        }

        for (auto i : t) {
            count[i - 'a']--;
        }
        
        for (auto i : count) {
            if (i != 0) {
                return false;
            }
        }
        return true;
    }
};


int main(){
    Solution s;
    string a = "huangle";
    string b = "lehuangle";
    cout << s.isAnagram(a,b) << endl;
    return 0;
}