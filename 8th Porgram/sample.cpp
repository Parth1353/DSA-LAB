#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;

    TreeNode* insertRec(TreeNode* root, int data) {
        if (root == nullptr) {
            return new TreeNode(data);
        }

        if (data < root->data) {
            root->left = insertRec(root->left, data);
        } else {
            root->right = insertRec(root->right, data);
        }
        return root;
    }

    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    TreeNode* deleteRec(TreeNode* root, int data) {
        if (root == nullptr) {
            return nullptr;
        }

        if (data < root->data) {
            root->left = deleteRec(root->left, data);
        } else if (data > root->data) {
            root->right = deleteRec(root->right, data);
        } else {
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            TreeNode* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteRec(root->right, temp->data);
        }
        return root;
    }

    void inorderRec(TreeNode* root) {
        if (root == nullptr) return;
        inorderRec(root->left);
        cout << root->data << " ";
        inorderRec(root->right);
    }

    void preorderRec(TreeNode* root) {
        if (root == nullptr) return;
        cout << root->data << " ";
        preorderRec(root->left);
        preorderRec(root->right);
    }

    void postorderRec(TreeNode* root) {
        if (root == nullptr) return;
        postorderRec(root->left);
        postorderRec(root->right);
        cout << root->data << " ";
    }

    void levelorderIter(TreeNode* root) {
        if (root == nullptr)
            return;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            cout << current->data << " ";

            if (current->left != nullptr)
                q.push(current->left);
            if (current->right != nullptr)
                q.push(current->right);
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(int data) {
        root = insertRec(root, data);
        cout << "Element " << data << " inserted." << endl;
    }

    void remove(int data) {
        if (root == nullptr) {
            cout << "Tree is empty. Cannot delete." << endl;
            return;
        }
        root = deleteRec(root, data);
        cout << "Element " << data << " deleted." << endl;
    }

    void inorder() {
        inorderRec(root);
        cout << endl;
    }

    void preorder() {
        preorderRec(root);
        cout << endl;
    }

    void postorder() {
        postorderRec(root);
        cout << endl;
    }

    void levelorder() {
        levelorderIter(root);
        cout << endl;
    }

    void displayMenu() {
        cout << "\nMenu:\n";
        cout << "1. Insert an element\n";
        cout << "2. Delete an element\n";
        cout << "3. Inorder Traversal\n";
        cout << "4. Preorder Traversal\n";
        cout << "5. Postorder Traversal\n";
        cout << "6. Levelorder Traversal\n";
        cout << "7. Exit\n";
    }
};

int main() {
    BinaryTree tree;
    int choice, data;

    do {
        tree.displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the data to insert: ";
                cin >> data;
                tree.insert(data);
                break;
            case 2:
                cout << "Enter the data to delete: ";
                cin >> data;
                tree.remove(data);
                break;
            case 3:
                cout << "Inorder Traversal: ";
                tree.inorder();
                break;
            case 4:
                cout << "Preorder Traversal: ";
                tree.preorder();
                break;
            case 5:
                cout << "Postorder Traversal: ";
                tree.postorder();
                break;
            case 6:
                cout << "Levelorder Traversal: ";
                tree.levelorder();
                break;
            case 7:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 7);

    return 0;
}
