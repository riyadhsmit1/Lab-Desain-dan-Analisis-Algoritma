#include <iostream>
#include <string>
using namespace std;

struct Barang {
    string nama;
    int harga;
};


int cariBarang(const Barang daftar[], int n, string barangDicari) {
    for (int i = 0; i < n; i++) {
        if (daftar[i].nama == barangDicari) {
            return i; 
        }
    }
    return -1;
}

int main() {
    Barang daftarBarang[5] = {
        {"Buku", 5000},
        {"Pensil", 1000},
        {"Pulpen", 2000},
        {"Penghapus", 500},
        {"Penggaris", 1500}
    };

    int n = 5; 
    string barangDicari;
    cout << "Masukkan nama barang yang ingin dicari: ";
    getline(cin, barangDicari);

    int posisi = cariBarang(daftarBarang, n, barangDicari);

    if (posisi != -1) {
        cout << "Barang " << barangDicari << " ditemukan dengan harga Rp" << daftarBarang[posisi].harga << endl;
    } else {
        cout << "Maaf, barang " << barangDicari << " tidak ditemukan dalam daftar" << endl;
    }

    return 0;
}
