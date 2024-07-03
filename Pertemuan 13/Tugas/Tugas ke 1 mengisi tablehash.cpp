#include <iostream>
#include <vector>

using namespace std;

int fungsiHash(int kunci, int ukuranTabel) {
    return kunci % ukuranTabel;
}

void sisipkanElemen(vector<int>& tabelHash, int elemen) {
    int indeks = fungsiHash(elemen, tabelHash.size());
    while (tabelHash[indeks] != -1) {
        indeks = (indeks + 1) % tabelHash.size();
    }
    tabelHash[indeks] = elemen;
}

void cetakTabelHash(const vector<int>& tabelHash) {
    cout << "Isi Tabel Hash:" << endl;
    for (int i = 0; i < tabelHash.size(); ++i) {
        cout << i << " --> ";
        if (tabelHash[i] == -1) {
            cout << "kosong" << endl;
        } else {
            cout << tabelHash[i] << endl;
        }
    }
}

bool cariElemen(const vector<int>& tabelHash, int elemen) {
    int indeks = fungsiHash(elemen, tabelHash.size());
    int awal = indeks;
    while (tabelHash[indeks] != -1) {
        if (tabelHash[indeks] == elemen) {
            return true;
        }
        indeks = (indeks + 1) % tabelHash.size();
        if (indeks == awal) {
            break;
        }
    }
    return false;
}

int main() {
    int ukuranTabel, jumlahElemen;
    cout << "Masukkan ukuran tabel hash: ";
    cin >> ukuranTabel;

    vector<int> tabelHash(ukuranTabel, -1);

    cout << "Masukkan jumlah elemen yang akan disisipkan: ";
    cin >> jumlahElemen;

    cout << "Masukkan " << jumlahElemen << " elemen:" << endl;
    for (int i = 0; i < jumlahElemen; ++i) {
        int elemen;
        cin >> elemen;
        sisipkanElemen(tabelHash, elemen);
    }

    cetakTabelHash(tabelHash);

    int kunciCari;
    cout << "Masukkan elemen yang ingin dicari dalam tabel hash: ";
    cin >> kunciCari;

    if (cariElemen(tabelHash, kunciCari)) {
        cout << kunciCari << " ditemukan dalam tabel hash" << endl;
    } else {
        cout << kunciCari << " tidak ditemukan dalam tabel hash" << endl;
    }

    return 0;
}

