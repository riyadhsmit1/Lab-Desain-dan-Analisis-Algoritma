#include <iostream>
#include <string>
using namespace std;

class Mahasiswa {
private:
    string nama;
    string nim;

public:
    Mahasiswa() {
        nama = "";
        nim = "";
    }
    void setData(string _nama, string _nim) {
        nama = _nama;
        nim = _nim;
    }
    void displayData() {
        cout << "Nama: " << nama << endl;
        cout << "NIM: " << nim << endl;
        cout << endl;
    }
};

int main() {
    Mahasiswa mahasiswa[14]; 
    int jumlahMahasiswa;
    cout << "Masukkan jumlah mahasiswa (maksimal 14): ";
    cin >> jumlahMahasiswa;
    cin.ignore(); 
    if (jumlahMahasiswa > 14 || jumlahMahasiswa <= 0) {
        cout << "Jumlah mahasiswa tidak valid!" << endl;
        return 1;
    }
    for (int i = 0; i < jumlahMahasiswa; ++i) {
        string nama, nim;
        cout << "Masukkan nama mahasiswa : " << i + 1 << endl;
        cout << "Nama: ";
        getline(cin, nama);
        cout << "NPM Mahasiswa: ";
        getline(cin, nim);

        mahasiswa[i].setData(nama, nim);
    }

    cout << "\nData mahasiswa yang telah dimasukkan:" << endl;
    for (int i = 0; i < jumlahMahasiswa; ++i) {
        cout << "Mahasiswa ke-" << i + 1 << endl;
        mahasiswa[i].displayData();
    }

    return 0;
}

