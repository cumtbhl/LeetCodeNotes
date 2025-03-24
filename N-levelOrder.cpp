#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//  https://leetcode.cn/problems/n-ary-tree-level-order-traversal/description/

class Node {
public:
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val) {
        val = _val;
    }
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        queue<Node*> queue;
        if (root == NULL) return result;
        queue.push(root);
        while (!empty(queue)) {
            int size = queue.size();
            vector<int> tmp;
            for (int i = 0; i < size; i++) {
                Node* cur = queue.front();
                queue.pop();
                tmp.push_back(cur->val);
                for (auto j : cur->children) {
                    if (j != NULL) queue.push(j);
                }
            }
            result.push_back(tmp);
        }
        return result;
    }
};



int main() {
    Solution s;
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    Node* node7 = new Node(7);

    node1->children = {node2, node3, node4};
    node2->children = {node5};
    node3->children = {node6};
    node4->children = {node7};

    vector<vector<int>> result = s.levelOrder(node1);
    for (auto i : result) {
        cout << "......." << endl;
        for (auto j : i) {
            cout << j << " ";
        }
    }
    return 0;
}