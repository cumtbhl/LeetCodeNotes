#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//  https://leetcode.cn/problems/binary-tree-inorder-traversal/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//  递归遍历
class Solution {
public:
    void inorder_traversal(TreeNode *root, vector<int> &vec) {
        if (root == NULL) return;
        inorder_traversal(root->left, vec);
        vec.push_back(root->val);
        inorder_traversal(root->right, vec);
    }

    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        inorder_traversal(root, result);
        return result;
    }
};

//  迭代遍历
class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> stack;
        if (root == NULL) return result;
        while (root != NULL || !empty(stack)) {
            if (root != NULL) {
                stack.push(root);
                root = root->left;
            }
            else {
                TreeNode *tmp = stack.top();
                stack.pop();
                result.push_back(tmp->val);
                root = tmp->right;
            }
        }
        return result;
    }
};

int main()
{
    Solution2 s;
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    node1->right = node2;
    node2->left = node3;

    vector<int> result = s.inorderTraversal(node1);
    for (auto i : result) {
        cout << i << endl;
    }
    return 0;
}