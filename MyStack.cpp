#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <stack>
#include <queue>
using namespace std;

//  https://leetcode.cn/problems/implement-stack-using-queues/

//  1.2个 queue 实现 stack
// class MyStack {
// public:
//     queue<int> q1;
//     queue<int> q2;

//     MyStack() {
        
//     }
    
//     void push(int x) {
//         q1.push(x);
//     }
    
//     int pop() {
//         int size = q1.size();
//         size--;
//         while(size) {
//             q2.push(q1.front());
//             q1.pop();
//             size--;
//         }
//         int res = q1.front();
//         q1.pop();

//         int size2 = q2.size();
//         for (int i = 1; i <= size2; i++) {
//             q1.push(q2.front());
//             q2.pop();
//         }
//         return res;
//     }
    
//     int top() {
//         int size = q1.size();
//         size--;
//         while(size) {
//             q2.push(q1.front());
//             q1.pop();
//             size--;
//         }
//         return q1.front();
//     }
    
//     bool empty() {
//         return q1.empty();
//     }
// };

//  2.1个 queue 实现 stack
class MyStack {
public:
    queue<int> q1;

    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int size = q1.size();
        size--;
        while(size) {
            q1.push(q1.front());
            q1.pop();
            size--;
        }
        int res = q1.front();
        q1.pop();
        return res;
    }
    
    int top() {
        int size = q1.size();
        size--;
        while(size) {
            q1.push(q1.front());
            q1.pop();
            size--;
        }
        int res = q1.front();
        q1.push(q1.front());
        q1.pop();
        return res;
    }
    
    bool empty() {
        return q1.empty();
    }
};

int main(){
    MyStack stack;
    stack.push(1);
    stack.push(2);
    int res1 = stack.pop();
    int res2 = stack.pop();
    cout << res1 << endl;
    cout << res2 << endl;
    cout << stack.empty() << endl;
    return 0;
}