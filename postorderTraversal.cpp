#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

//  https://leetcode.cn/problems/binary-tree-postorder-traversal/description/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void postorder_traversal (TreeNode* root, vector<int>& vec) {
        if (root == NULL) return;
        postorder_traversal (root->left, vec);
        postorder_traversal (root->right, vec);
        vec.push_back(root->val);
    }

    vector<int> postorderTraversal (TreeNode* root) {
        vector<int> result;
        postorder_traversal (root, result);
        return result;
    }
};


class Solution2 {
public:
    vector<int> postorderTraversal (TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> stack;
        if (root == NULL) return result;
        stack.push(root);
        while (!empty(stack)) {
            TreeNode* tmp = stack.top();
            stack.pop();
            result.push_back(tmp->val);
            if (tmp->left != NULL) stack.push(tmp->left);
            if (tmp->right != NULL) stack.push(tmp->right);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution2 s;
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node8 = new TreeNode(8);
    TreeNode* node9 = new TreeNode(9);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node5->left = node6;
    node5->right = node7;
    node3->right = node8;
    node8->left = node9;

    vector<int> result = s.postorderTraversal (node1);
    for (auto i : result) {
        cout << i << endl;
    }
    return 0;
}