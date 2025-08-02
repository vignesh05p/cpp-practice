//  DSA Question: Diameter of a Binary Tree
// Problem Statement:
// Given the root of a binary tree, return the length of the diameter of the tree.

// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

// The length of a path is represented by the number of edges between the nodes


#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int maxDiameter = 0;

    int depth(TreeNode* node) {
        if (node == NULL) return 0;

        int leftDepth = depth(node->left);
        int rightDepth = depth(node->right);

        // Update diameter if current path is longer
        maxDiameter = max(maxDiameter, leftDepth + rightDepth);

        // Return depth of this subtree
        return 1 + max(leftDepth, rightDepth);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return maxDiameter;
    }
};

// Driver code
int main() {
    /*
        Sample Tree:
              1
             / \
            2   3
           / \
          4   5
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    cout << "Diameter of Binary Tree: " << sol.diameterOfBinaryTree(root) << endl;

    return 0;
}
