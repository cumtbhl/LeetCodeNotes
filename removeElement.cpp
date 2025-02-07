#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

//  https://leetcode.cn/problems/remove-element/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        int slow = 0;
        int fast = 0;
        int count = 0;
        for (; fast < size; ) {
            if (nums[fast] != val) {
                nums[slow++] = nums[fast++];
                count++;
            }
            else {
                fast++;
            }
        }
        return count;
    }
};


int main(){
    vector<int> vec = {0,1,2,2,3,0,4,2};
    Solution sol;
    int res = sol.removeElement(vec, 2);
    cout << res << endl;
    return 0;
}