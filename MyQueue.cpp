#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <stack>
using namespace std;

//  https://leetcode.cn/problems/implement-queue-using-stacks/

class MyQueue {
public:
    stack<int> in_stack;
    stack<int> out_stack;
    MyQueue() {
        
    }
    
    void push(int x) {
        in_stack.push(x);
    }
    
    int pop() {
        if (out_stack.empty()) {
            while (!in_stack.empty()) {
                out_stack.push(in_stack.top());
                in_stack.pop();
            }
        }
        int result = out_stack.top();
        out_stack.pop();
        return result;
    }
    
    int peek() {
        if (out_stack.empty()) {
            while (!in_stack.empty()) {
                out_stack.push(in_stack.top());
                in_stack.pop();
            }
        }
        return out_stack.top();
    }
    
    bool empty() {
        return in_stack.empty() && out_stack.empty();
    }
};


int main(){
    MyQueue queue;
    queue.push(1);
    queue.push(2);
    int res1 = queue.pop();
    int res2 = queue.pop();
    cout << res1 << endl;
    cout << res1 << endl;
    cout << queue.empty() << endl;
    return 0;
}