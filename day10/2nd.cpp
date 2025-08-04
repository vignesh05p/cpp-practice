// // 🌲 DSA Question 2: Level Order Traversal of Binary Tree
// // Problem Statement:
// // Given the root of a binary tree, return the level order traversal of its nodes' values.
// // (i.e., from left to right, level by level).


// ✨ Example:
// lua
// Copy
// Edit
// Input:
//     3
//    / \
//   9  20
//      / \
//     15  7

// Output: [[3], [9,20], [15,7]]
// 📂 Topics:
// Binary Trees

// Breadth-First Search (BFS)

// Queues

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> level;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            result.push_back(level);
        }

        return result;
    }
};

// Driver code
int main() {
    /*
        Tree:
             3
            / \
           9  20
              / \
             15  7
    */
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<vector<int>> levels = sol.levelOrder(root);

    cout << "Level Order Traversal:" << endl;
    for (const auto& level : levels) {
        for (int val : level)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}
