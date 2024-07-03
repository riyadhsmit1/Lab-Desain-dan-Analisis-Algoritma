#include <iostream>
using namespace std;

struct node {
    char data;
    node *kiri;
    node *kanan;
};

node *akar = nullptr;

void addNode(node **akar, char isi) {
    if (*akar == nullptr) {
        node *baru = new node;
        baru->data = isi;
        baru->kiri = nullptr;
        baru->kanan = nullptr;
        *akar = baru;
    }
}

void preOrder(node *akar) {
    if (akar != nullptr) {
        std::cout << akar->data << " ";
        preOrder(akar->kiri);
        preOrder(akar->kanan);
    }
}

void inOrder(node *akar) {
    if (akar != nullptr) {
        inOrder(akar->kiri);
        std::cout << akar->data << " ";
        inOrder(akar->kanan);
    }
}

void postOrder(node *akar) {
    if (akar != nullptr) {
        postOrder(akar->kiri);
        postOrder(akar->kanan);
        std::cout << akar->data << " ";
    }
}

int main() {
    char abjad;
    std::cout << "\n\n\tPosisi Awal Tree:\n\n";
    std::cout << "\t       R\n\t      / \\\n\t     A   E\n\t    /\n\t   S\n\t  / \\\n\t I   T\n\n";
    addNode(&akar, abjad = 'R');
    addNode(&akar->kiri, abjad = 'A');
    addNode(&akar->kanan, abjad = 'E');
    addNode(&akar->kiri->kiri, abjad = 'S');
    addNode(&akar->kiri->kiri->kiri, abjad = 'I');
    addNode(&akar->kiri->kiri->kanan, abjad = 'T');
    std::cout << "Tampilan PreOrder  : ";
    preOrder(akar);
    std::cout << "\nTampilan InOrder   : ";
    inOrder(akar);
    std::cout << "\nTampilan PostOrder : ";
    postOrder(akar);
    return 0;
}


