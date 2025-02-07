#include<iostream>
#include<unordered_set>
#include<algorithm>
using namespace std;

//  https://leetcode.cn/problems/happy-number/description/

class Solution {
public:
    int getSum(int n){
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n = n / 10;
        }
        return sum;
    }

    bool isHappy(int n){
        unordered_set<int> set;
        while (1) {
            int sum = getSum(n);
            if (sum == 1) {
                return true;
            }
            if (set.find(sum) == set.end()) {
                set.insert(sum);
                n = sum;
            }
            else {
                return false;
            }
        }
    }
};


int main(){
    Solution s;
    cout << s.isHappy(2) << endl;
    return 0;
}
