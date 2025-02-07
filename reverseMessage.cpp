#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

//  https://leetcode.cn/problems/fan-zhuan-dan-ci-shun-xu-lcof/

class Solution {
public:
    string reverseMessage(string message) {
        int slow = 0;
        int fast = 0;
        int size = message.size();
        for(; fast < size; ) {
            if (message[fast] != ' ') {
                if (slow == 0) {
                    while (message[fast] != ' ' && fast < size) {
                        message[slow++] = message[fast++];
                    }
                }
                else {
                    message[slow++] = ' ';
                    while (message[fast] != ' ' && fast < size) {
                        message[slow++] = message[fast++];
                    }
                }
            }
            fast++;
        }
        message.resize(slow);
        reverse(message.begin(), message.end());
        for(int i = 0; i < message.size();) {
            if (message[i] != ' ') {
                int k = i;
                while(message[i] != ' ' && i < message.size()) {
                    i++;
                }
                reverse(message.begin() + k, message.begin() + i);
            }
            i++;
        }
        return message;
    }
};


int main(){
    string s1 = "  hello world!  ";
    Solution sol;
    string res = sol.reverseMessage(s1);
    cout << res << endl;
    return 0;
}