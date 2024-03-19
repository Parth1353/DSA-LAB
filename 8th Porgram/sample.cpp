#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

Node *insert(Node *&root, int data) {
    if (root == NULL) {
        root = new Node(data);
    } else {
        if (data < root->data) {
            root->left = insert(root->left, data);
        } else {
            root->right = insert(root->right, data);
        }
    }
    return root;
}

void input(Node *&root, bool &flag) {
    int data;
    cin >> data;

    while (data != -1) {
        root = insert(root, data);
        cin >> data;
    }
    if (data == -1) {
        flag = false;
    }
}

Node *mini(Node *root) {
    if (root == NULL) {
        return NULL;
    }
    Node *temp = root;
    while (temp->left != NULL) {
        temp = temp->left;
    }
    return temp;
}

Node *maxi(Node *root) {
    if (root == NULL) {
        return NULL;
    }
    Node *temp = root;
    while (temp->right != NULL) {
        temp = temp->right;
    }
    return temp;
}

Node *deleteNode(Node *&root, int val) {
    if (root == NULL) {
        return NULL;
    }
    if (val == root->data) {
    
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        if (root->left != NULL && root->right == NULL) {
            Node *left = root->left;
            delete root;
            return left;
        }
        if (root->left == NULL && root->right != NULL) {
            Node *right = root->right;
            delete root;
            return right;
        }
        if (root->left != NULL && root->right != NULL) {
            Node *minNode = mini(root->right);
            root->data = minNode->data;
            deleteNode(root->right, minNode->data);
            return root;
        }
    } else if (val > root->data) {
        root->right = deleteNode(root->right, val);
    } else {
        root->left = deleteNode(root->left, val);
    }
    return root;
}

void inorder(Node *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node *root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node *root = nullptr;
    bool flag = true;
    while (flag) {
        input(root, flag);
    }
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    cout << endl;

    return 0; // Added return statement
}
