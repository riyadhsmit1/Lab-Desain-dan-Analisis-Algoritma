#include <iostream>
#include <string>
using namespace std;

class Mahasiswa {
private:
    string nama[2];
    int usia[2];
    float ipk[2];

public:
    void setNama(string a, int index) {
        nama[index] = a;
    }
    void setUsia(int b, int index) {
        usia[index] = b;
    }
    void setIPK(float c, int index) {
        ipk[index] = c;
    }
    string getNama(int index) {
        return nama[index];
    }
    int getUsia(int index) {
        return usia[index];
    }
    float getIPK(int index) {
        return ipk[index];
    }
};

int main() {
    int nilai;

    cout << "Masukkan jumlah data: ";
    cin >> nilai;

    Mahasiswa ms;

    string nama[nilai];
    int usia[nilai];
    float ipk[nilai];

    for (int i = 0; i < nilai; i++) {
        cout << "Nama: ";
        cin >> nama[i];
        cout << "Usia: ";
        cin >> usia[i];
        cout << "IPK: ";
        cin >> ipk[i];
        cout << endl;
    }

    for (int i = 0; i < nilai; i++) {
        ms.setNama(nama[i], i);
        ms.setUsia(usia[i], i);
        ms.setIPK(ipk[i], i);
    }

    for (int i = 0; i < nilai; i++) {
        cout << "Nama Mahasiswa: " << ms.getNama(i) << endl;
        cout << "Umur: " << ms.getUsia(i) << endl;
        cout << "IPK: " << ms.getIPK(i) << endl;
    }

    return 0;
}

