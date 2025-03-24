#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

//  https://leetcode.cn/problems/populating-next-right-pointers-in-each-node/

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        vector<vector<Node*>> result;
        queue<Node*> queue;
        if (root == NULL) return NULL;
        queue.push(root);
        while (!empty(queue)) {
            int size = queue.size();
            vector<Node*> tmp;
            for (int i = 0; i < size; i++) {
                Node* cur = queue.front();
                queue.pop();
                tmp.push_back(cur);
                if (cur->left != NULL) queue.push(cur->left);
                if (cur->right != NULL) queue.push(cur->right);
            }
            result.push_back(tmp);
        }
        for(auto i : result) {
            int size = i.size();
            int k = 0;
            for (; k <= size -2; k++) {
                i[k]->next = i[k + 1];
            }
            i[k]->next = NULL;
        }
        return result[0][0];
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

    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;

    Node* result = s.connect(node1);

    return 0;
}