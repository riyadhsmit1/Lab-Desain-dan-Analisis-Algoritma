#include <iostream>
using namespace std;

const int MAX_NODES = 100;
int tree[MAX_NODES];
int n = 0;

void insertNode(int x) {
    int curr = 0;
    while (true) {
        if (tree[curr] == -1) {
            tree[curr] = x;
            break;
        } else if (x < tree[curr]) {
            curr = 2 * curr + 1;
        } else {
            curr = 2 * curr + 2;
        }
    }
}

void inorderTraversal(int curr) {
    if (tree[curr] == -1) {
        return;
    }
    inorderTraversal(2 * curr + 1);
    cout << tree[curr] << " ";
    inorderTraversal(2 * curr + 2);
}

int main() {
    for (int i = 0; i < MAX_NODES; i++) {
        tree[i] = -1;
    }

    int x;
    char pilihan;

    do {
        cout << "Masukkan nilai pada binary tree: ";
        cin >> x;
        insertNode(x);

        cout << "Ingin memasukkan nilai lain (y/n)? ";
        cin >> pilihan;
    } while (pilihan == 'y' || pilihan == 'Y');

    cout << "In-order traversal: ";
    inorderTraversal(0);
    cout << endl;

    return 0;
}

