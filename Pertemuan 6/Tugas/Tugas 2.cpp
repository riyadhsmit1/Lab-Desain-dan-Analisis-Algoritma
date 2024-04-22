#include <iostream>
#include <string>
using namespace std;

class Kendaraan {
protected:
    string merek;
    string jumlahpintu;
    int tahunproduksi;

public:
    Kendaraan(string Merek, int TahunProduksiMobil, string jumlahPintuMobil) {
        merek = Merek;
        tahunproduksi = TahunProduksiMobil;
        jumlahpintu = jumlahPintuMobil;
    }

    virtual void info() {
        cout << "Merek: " << merek << endl;
        cout << "Jumlah Pintu: " << jumlahpintu << endl;
        cout << "Tahun: " << tahunproduksi << endl;
    }
};

class Mobil : public Kendaraan {

public:
    Mobil(string Merek, int TahunProduksiMobil, string jumlahPintuMobil)
        : Kendaraan(Merek, TahunProduksiMobil, jumlahPintuMobil) {}
		

    void info() {
        cout << "\nMobil" << endl;
        Kendaraan::info();
    }
};

int main() {
    string merek, jumlahpintu;
    int tahunproduksi;

    cout << "Masukkan merek mobil: ";
    cin >> merek;

    cout << "Masukkan jumlah pintu mobil: ";
    cin >> jumlahpintu;

    cout << "Masukkan tahun mobil: ";
    cin >> tahunproduksi;

    Mobil mobil1(merek, tahunproduksi, jumlahpintu);
    mobil1.info();

    return 0;
}

