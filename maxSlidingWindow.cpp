#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <stack>
#include <queue>
using namespace std;

//  https://leetcode.cn/problems/sliding-window-maximum/

class Solution {
private:
    // MyQueue 类作为 Solution 类的 private 成员，只能被 Solution 类的成员函数访问
    class MyQueue {
    // 将 MyQueue 类中的所有成员声明为 public，方便 Solution 类的成员函数访问
    public:
        deque<int> que;
        void pop(int val) {
            if (val == que.front()) {
                que.pop_front();
            }
        }
        void push(int val) {
            while (!que.empty() && val > que.back()) {
                que.pop_back();
            }
            que.push_back(val);
        }
        int max_value() {
            return que.front();
        }
    };

public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        MyQueue queue;
        vector<int> result;
        for (int i = 0; i < k; i++) {
            queue.push(nums[i]);
        }
        result.push_back(queue.max_value());
        for (int i = k; i < nums.size(); i++) {
            queue.pop(nums[i-k]);
            queue.push(nums[i]);
            result.push_back(queue.max_value());
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    vector<int> result = s.maxSlidingWindow(nums,3);
    for (auto i : result) {
        cout << i << endl;
    }
    return 0;
}