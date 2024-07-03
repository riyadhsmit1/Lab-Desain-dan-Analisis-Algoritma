#include <iostream>
using namespace std;

// Struktur Node untuk representasi simpul dalam tree
struct Node {
    int data;
    Node* left;
    Node* right;

    // Konstruktor untuk inisialisasi Node
    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Fungsi untuk memasukkan nilai ke dalam tree
Node* insertNode(Node* root, int value) {
    // Jika tree kosong, buat node baru sebagai root
    if (root == NULL) {
        return new Node(value);
    }

    // Jika nilai yang dimasukkan lebih kecil, masukkan ke kiri
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    }
    // Jika nilai yang dimasukkan lebih besar atau sama, masukkan ke kanan
    else {
        root->right = insertNode(root->right, value);
    }

    return root;
}

// Fungsi untuk traversal pre-order (VLR)
void preOrder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Fungsi untuk traversal in-order (LVR)
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

// Fungsi untuk traversal post-order (LRV)
void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    Node* root = NULL; // Atau bisa juga menggunakan nullptr jika tersedia

    // Memasukkan bilangan yang diinput ke program
    int numbers[] = {18, 30, 29, 32, 33};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    // Memasukkan bilangan ke dalam tree
    for (int i = 0; i < n; ++i) {
        root = insertNode(root, numbers[i]);
    }

    // Menampilkan hasil traversal
    cout << "Traversal pre-order (VLR): ";
    preOrder(root);
    cout << endl;

    cout << "Traversal in-order (LVR): ";
    inOrder(root);
    cout << endl;

    cout << "Traversal post-order (LRV): ";
    postOrder(root);
    cout << endl;

    return 0;
}

