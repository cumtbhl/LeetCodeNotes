#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

//  https://leetcode.cn/problems/reverse-string-ii/

class Solution {
public:
    string reverseStr(string s, int k) {
        int size = s.size();
        int i = 0;
        for (; i <= size -1; i += 2 * k) {
            if (i + k <= size) {
                reverse(s.begin() + i, s.begin() + i + k);
            }
            else {
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};


int main(){

    return 0;
}