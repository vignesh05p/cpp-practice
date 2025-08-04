// 🌳 DSA Question: Validate Binary Search Tree
// Problem Statement:
// Given the root of a binary tree, determine if it is a valid Binary Search Tree (BST).

// A valid BST satisfies:

// All nodes in the left subtree are less than the root.

// All nodes in the right subtree are greater than the root.

// Both left and right subtrees are also BSTs.

// ✨ Example:
// vbnet
// Copy
// Edit
// Input:
//     2
//    / \
//   1   3

// Output: true
// vbnet
// Copy
// Edit
// Input:
//     5
//    / \
//   1   4
//      / \
//     3   6

// Output: false
// Explanation: 4 is in the right subtree of 5 but has a left child 3 < 5.
// 📂 Topics:
// Binary Trees

// Recursion

// DFS

// In-order Traversal


#include <iostream>
#include <climits>
using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    bool validate(TreeNode* node, long long minVal, long long maxVal) {
        if (!node) return true;

        if (node->val <= minVal || node->val >= maxVal)
            return false;

        return validate(node->left, minVal, node->val) &&
               validate(node->right, node->val, maxVal);
    }

public:
    bool isValidBST(TreeNode* root) {
        return validate(root, LLONG_MIN, LLONG_MAX);
    }
};

// Driver code
int main() {
    /*
        Example:
            5
           / \
          1   7
             / \
            6   8
    */
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(7);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    Solution sol;
    cout << "Is valid BST? " << (sol.isValidBST(root) ? "Yes" : "No") << endl;

    return 0;
}
