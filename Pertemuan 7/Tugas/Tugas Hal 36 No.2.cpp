#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Struktur data untuk menyimpan informasi buku
struct Buku {
    string judul;
    int rakNomor;
};

// Fungsi untuk mencari buku menggunakan binary search
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

    // Jika buku tidak ditemukan, return -1
    return -1;
}

int main() {
    // Inisialisasi data buku di perpustakaan
    vector<Buku> perpustakaan = {
        {"Algoritma Pemrograman", 1},
        {"Struktur Data", 2},
        {"Pemrograman Berorientasi Objek", 3},
        {"Dasar-Dasar Pemrograman", 4},
        {"Jaringan Komputer", 5}
    };

    // Input judul buku yang ingin dicari
    string judulBuku;
    cout << "Masukkan judul buku yang ingin Anda cari: ";
    getline(cin, judulBuku);

    // Melakukan pencarian menggunakan binary search
    int rakNomor = temukanRakBuku(perpustakaan, judulBuku);

    // Menampilkan hasil pencarian
    if (rakNomor != -1) {
        cout << "Buku dengan judul \"" << judulBuku << "\" berada di rak nomor " << rakNomor << endl;
    } else {
        cout << "Maaf, buku dengan judul \"" << judulBuku << "\" tidak ditemukan di perpustakaan." << endl;
    }

    return 0;
}

