#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

//  https://leetcode.cn/problems/reverse-string/

class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(), s.end());
    }
};

class Solution2 {
public:
    void reverseString(vector<char>& s) {
        int size = s.size();
        int i = 0;
        int j = size - 1;
        for (; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }
};

int main(){

    return 0;
}