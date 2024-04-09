#include <iostream>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;

public:
    BinaryTree() : root(nullptr) {}

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    TreeNode* insertRecursive(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->data) {
            node->left = insertRecursive(node->left, value);
        } else {
            node->right = insertRecursive(node->right, value);
        }

        return node;
    }

    void inorderTraversal() {
        cout << "Inorder Traversal: ";
        inorderRecursive(root);
        cout << endl;
    }

    void inorderRecursive(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        inorderRecursive(node->left);
        cout << node->data << " ";
        inorderRecursive(node->right);
    }
};

int main() {
    BinaryTree tree;

    cout << "Binary Tree Implementation" << endl;
    cout << "Enter elements to insert into the binary tree (-1 to stop):" << endl;

    int value;
    while (true) {
        cout << "Enter value: ";
        cin >> value;

        if (value == -1) {
            break;
        }

        tree.insert(value);
    }

    tree.inorderTraversal();

    return 0;
}
