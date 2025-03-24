#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

//  https://leetcode.cn/problems/find-largest-value-in-each-tree-row/description/

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
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> queue;
        if (root == NULL) return result;
        queue.push(root);
        while (!empty(queue)) {
            int size = queue.size();
            int max = INT_MIN;
            for (int i = 0; i < size; i++) {
                TreeNode* cur = queue.front();
                queue.pop();
                max = cur->val > max ? cur->val : max;
                if (cur->left != NULL) queue.push(cur->left);
                if (cur->right != NULL) queue.push(cur->right);
            }
            result.push_back(max);
        }
        return result;
    }
};

int main() {
    Solution s;
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

    vector<int> result = s.largestValues(node1);
    for (auto i : result) {
        cout << i << endl;
    }
    return 0;
}