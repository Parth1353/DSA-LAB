#include <iostream>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST {
private:
    TreeNode* root;

public:
    BST() : root(nullptr) {}

    TreeNode* insert(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }

        return node;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    TreeNode* remove(TreeNode* node, int value) {
        if (node == nullptr) {
            return nullptr;
        }

        if (value < node->data) {
            node->left = remove(node->left, value);
        } else if (value > node->data) {
            node->right = remove(node->right, value);
        } else {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            } else if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            } else {
                TreeNode* minRight = findMin(node->right);
                node->data = minRight->data;
                node->right = remove(node->right, minRight->data);
            }
        }
        return node;
    }

    void remove(int value) {
        root = remove(root, value);
    }

    void inorderTraversal(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }

    void inorderTraversal() {
        cout << "Inorder Traversal: ";
        inorderTraversal(root);
        cout << endl;
    }
};

int main() {
    BST bst;

    cout << "Binary Search Tree (BST) Implementation" << endl;
    cout << "Enter elements to insert into the BST (-1 to stop):" << endl;

    int value;
    while (true) {
        cout << "Enter value: ";
        cin >> value;

        if (value == -1) {
            break;
        }

        bst.insert(value);
    }

    cout << "Enter element to delete from the BST: ";
    cin >> value;

    bst.remove(value);

    cout << "Inorder Traversal after deletion:" << endl;
    bst.inorderTraversal();

    return 0;
}
