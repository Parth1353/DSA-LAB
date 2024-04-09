#include <iostream>
using namespace std;

// Node structure for BST
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};


class BinarySearchTree {
private:
    TreeNode* root;

    
    TreeNode* createNode(int data) {
        TreeNode* newNode = new TreeNode;
        newNode->data = data;
        newNode->left = newNode->right = nullptr;
        return newNode;
    }

   
    TreeNode* insertRec(TreeNode* root, int data) {
        if (root == nullptr) {
            return createNode(data);
        }

        if (data < root->data) {
            root->left = insertRec(root->left, data);
        } else if (data > root->data) {
            root->right = insertRec(root->right, data);
        }

        return root;
    }

    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;

        while (current && current->left != nullptr) {
            current = current->left;
        }

        return current;
    }
    TreeNode* deleteNodeRec(TreeNode* root, int data) {
        if (root == nullptr) {
            return root;
        }

        if (data < root->data) {
            root->left = deleteNodeRec(root->left, data);
        } else if (data > root->data) {
            root->right = deleteNodeRec(root->right, data);
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

            TreeNode* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNodeRec(root->right, temp->data);
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

public:

    BinarySearchTree() {
        root = nullptr;
    }

    void insert(int data) {
        root = insertRec(root, data);
        cout << "Element " << data << " inserted into the BST." << endl;
    }
    void remove(int data) {
        if (root == nullptr) {
            cout << "BST is empty. Cannot delete." << endl;
            return;
        }

        root = deleteNodeRec(root, data);
        cout << "Element " << data << " deleted from the BST." << endl;
    }

    void inorder() {
        cout << "Inorder Traversal: ";
        inorderRec(root);
        cout << endl;
    }

    void preorder() {
        cout << "Preorder Traversal: ";
        preorderRec(root);
        cout << endl;
    }

    void postorder() {
        cout << "Postorder Traversal: ";
        postorderRec(root);
        cout << endl;
    }
    void displayMenu() {
        cout << "\nMenu:\n";
        cout << "1. Insert a node\n";
        cout << "2. Delete a node\n";
        cout << "3. Inorder Traversal\n";
        cout << "4. Preorder Traversal\n";
        cout << "5. Postorder Traversal\n";
        cout << "6. Exit\n";
    }
};

int main() {
    BinarySearchTree bst;
    int choice, data;

    do {
        bst.displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the data to insert: ";
                cin >> data;
                bst.insert(data);
                break;
            case 2:
                cout << "Enter the data to delete: ";
                cin >> data;
                bst.remove(data);
                break;
            case 3:
                bst.inorder();
                break;
            case 4:
                bst.preorder();
                break;
            case 5:
                bst.postorder();
                break;
            case 6:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 6);

    return 0;
}