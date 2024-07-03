#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

Node* insertNode(Node* root, int value) {
    if (root == NULL) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    }

    else {
        root->right = insertNode(root->right, value);
    }

    return root;
}


void preOrder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    Node* root = NULL; 

    int numbers[] = {12, 16, 20, 24, 32};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    for (int i = 0; i < n; ++i) {
        root = insertNode(root, numbers[i]);
    }

    cout << "pre-order : ";
    preOrder(root);
    cout << endl;

    cout << "in-order : ";
    inOrder(root);
    cout << endl;

    cout << "post-order: ";
    postOrder(root);
    cout << endl;

    return 0;
}

