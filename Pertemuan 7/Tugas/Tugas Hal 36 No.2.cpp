#include <iostream>
#include <string>
#include <vector>

using namespace std;


struct Buku {
    string judul;
    int rakNomor;
};

int temukanRakBuku(const vector<Buku>& banyakBuku, const string& judul) {
    int kiri = 0;
    int kanan = banyakBuku.size() - 1;

    while (kiri <= kanan) {
        int tengah = kiri + (kanan - kiri) / 2;
        if (banyakBuku[tengah].judul == judul) {
            return banyakBuku[tengah].rakNomor;
        } else if (banyakBuku[tengah].judul < judul) {
            kiri = tengah + 1;
        } else {
            kanan = tengah - 1;
        }
    }


    return -1;
}

int main() {

    vector<Buku> perpustakaan = {
        {"Algoritma Pemrograman", 1},
        {"Struktur Data", 2},
        {"Pemrograman Berorientasi Objek", 3},
        {"Dasar-Dasar Pemrograman", 4},
        {"Jaringan Komputer", 5}
    };

    string judulBuku;
    cout << "Masukkan judul buku yang ingin Anda cari: ";
    getline(cin, judulBuku);

    int rakNomor = temukanRakBuku(perpustakaan, judulBuku);

    if (rakNomor != -1) {
        cout << "Buku dengan judul \"" << judulBuku << "\" berada di rak nomor " << rakNomor << endl;
    } else {
        cout << "Maaf, buku dengan judul \"" << judulBuku << "\" tidak ditemukan di perpustakaan." << endl;
    }

    return 0;
}

