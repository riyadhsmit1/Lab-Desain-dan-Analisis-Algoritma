#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Pelanggan {
    string nama;
    int nomorTiket;
};

int main() {
    queue<Pelanggan> antrianTiket;
    int nomorTiketBerikutnya = 1;
    int pilihan;
    string nama;

    do {
        cout << "\nMenu Loket Tiket:\n";
        cout << "1. Tambahkan Pelanggan ke Antrian\n";
        cout << "2. Layani Pelanggan\n";
        cout << "3. Tampilkan Antrian\n";
        cout << "4. Keluar\n";
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama pelanggan: ";
                cin >> nama;
                antrianTiket.push({ nama, nomorTiketBerikutnya++ });
                cout << "Pelanggan " << nama << " ditambahkan ke antrian dengan nomor tiket " << nomorTiketBerikutnya - 1 << "." << endl;
                break;
            case 2:
                if (antrianTiket.empty()) {
                    cout << "Tidak ada pelanggan yang dilayani." << endl;
                } else {
                    Pelanggan pelangganDilayani = antrianTiket.front();
                    antrianTiket.pop();
                    cout << "Melayani pelanggan " << pelangganDilayani.nama << " dengan nomor tiket " << pelangganDilayani.nomorTiket << "." << endl;
                }
                break;
            case 3:
                if (antrianTiket.empty()) {
                    cout << "Antrian kosong." << endl;
                } else {
                    cout << "Antrian saat ini:" << endl;
                    queue<Pelanggan> antrianSementara = antrianTiket;
                    while (!antrianSementara.empty()) {
                        Pelanggan pelanggan = antrianSementara.front();
                        antrianSementara.pop();
                        cout << "Pelanggan " << pelanggan.nama << ", Nomor Tiket " << pelanggan.nomorTiket << endl;
                    }
                }
                break;
            case 4:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 4);

    return 0;
}

