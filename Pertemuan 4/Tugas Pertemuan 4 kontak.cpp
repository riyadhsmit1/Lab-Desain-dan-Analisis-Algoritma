#include <iostream>
#include <string>
using namespace std;

class Kontak {
private:
    string identitas;
    string number;

public:
    Kontak() {
        identitas = "";
        number = "";
    }
    Kontak(string namaKontak, string nomorKontak) {
        identitas = namaKontak;
        number = nomorKontak;
    }
    ~Kontak() {   
    }
    void masukkanKontak(string namaKontak, string nomorKontak) {
        identitas = namaKontak;
        number = nomorKontak;
    }
    void tampilkanKontak() {
        cout << "Nama : " << identitas << endl;
        cout << "Nomor Telepon : " << number << endl;
    }
};

int main() {
    cout << "Masukkan Kontak (maksimal 10 kontak): " << endl;
    Kontak daftarKontak[10];
    int jumlahKontak = 0;
    char tambahKontak;

    do {
        string namaKontak;
        string nomorKontak;

        cout << "Masukkan nama kontak: ";
        getline(cin, namaKontak);

        cout << "Masukkan nomor telepon kontak: ";
        getline(cin, nomorKontak);

        daftarKontak[jumlahKontak] = Kontak(namaKontak, nomorKontak);
        jumlahKontak++;

        cout << "Tambahkan kontak lagi? (y/n): ";
        cin >> tambahKontak;
        cin.ignore();
    } while (jumlahKontak < 10 && (tambahKontak == 'y' || tambahKontak == 'Y'));

    cout << "Daftar Kontak:" << endl;
    for (int i = 0; i < jumlahKontak; ++i) {
        cout << "Kontak ke-" << i + 1 << endl;
        daftarKontak[i].tampilkanKontak();
    }

    return 0;
}
