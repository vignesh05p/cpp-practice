//to create a tree which i dynamic
//1. Preorder Traversal (Root → Left → Right)
//2. Inorder Traversal (Left → Root → Right)
//3. Postorder Traversal (Left → Right → Root)



#include <iostream>
#include <queue>
using namespace std;




struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};





// creating a tree using levle orederr input
Node* buildTreeLevelWise() {
    int rootData;
    cout << "Enter root value : ";
    cin >> rootData;

    if (rootData == -1) return nullptr;

    Node* root = new Node(rootData);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        int leftData, rightData;

        cout << "Enter left child of " << current->data << " (or -1 for null): ";
        cin >> leftData;
        if (leftData != -1) {
            current->left = new Node(leftData);
            q.push(current->left);
        }

        cout << "Enter right child of " << current->data << " (or -1 for null): ";
        cin >> rightData;
        if (rightData != -1) {
            current->right = new Node(rightData);
            q.push(current->right);
        }
    }

    return root;
}




// Traversals
void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}




//garbage collection
void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int height( Node* root){
    
    if (root==nullptr)
    return 0;
    int leftheight= height(root->left);
    int righttheight= height(root->right);
    return max(leftheight,righttheight)+1;
}








int main() {
    cout << "crete binary tree(-1 for null)::\n";

    Node* root = buildTreeLevelWise();

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nInorder: ";
    inorder(root);

    cout << "\nPostorder: ";
    postorder(root);
    
    cout << "\nHeight of the tree: " << height(root) << endl;

    deleteTree(root);
    


    return 0;
}
