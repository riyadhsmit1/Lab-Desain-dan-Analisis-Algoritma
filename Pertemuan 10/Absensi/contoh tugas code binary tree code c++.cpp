#include <iostream>
using namespace std;

struct node {
    char data;
    node *kiri;
    node *kanan;
};

node *akar = NULL;

void addNode(node **akar, char isi) {
    if (*akar == NULL) {
        node *baru = new node;
        baru->data = isi;
        baru->kanan = NULL;
        baru->kiri = NULL;
        *akar = baru;
    }
}

void preOrder(node *akar) {
    if (akar != NULL) {
        cout << akar->data << " ";
        preOrder(akar->kanan);
        preOrder(akar->kiri);
    }
}

void inOrder(node *akar) {
    if (akar != NULL) {
        inOrder(akar->kanan);
        cout << akar->data << " ";
        inOrder(akar->kiri);
    }
}

void postOrder(node *akar) {
    if (akar != NULL) {
        postOrder(akar->kanan);
        postOrder(akar->kiri);
        cout << akar->data << " ";
    }
}

int main() {
    char abjad;
    cout << "\n\n\tPosisi Awal Tree:\n\n";
    cout << "\t       R\n\t      / \\\n\t     A   E\n\t    /\n\t   S\n\t  / \\\n\t I   T\n\n";
    addNode(&akar, abjad = 'E');
    addNode(&akar->kanan, abjad = 'S');
    addNode(&akar->kiri, abjad = 'T');
    addNode(&akar->kanan->kanan, abjad = 'I');
    addNode(&akar->kanan->kanan->kanan, abjad = 'R');
    addNode(&akar->kanan->kanan->kiri, abjad = 'A');
    cout << "Tampilan PreOrder  : ";
    preOrder(akar);
    cout << "\nTampilan InOrder   : ";
    inOrder(akar);
    cout << "\nTampilan PostOrder : ";
    postOrder(akar);
    return 0;
}


