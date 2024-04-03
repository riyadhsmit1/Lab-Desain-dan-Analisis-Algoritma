#include <iostream>
#include <string>
using namespace std;

class Biodata {
private:
    string nama;
    int umur;
    string alamat;

public:
    Biodata(string _nama, int _umur, string _alamat) {
        nama = _nama;
        umur = _umur;
        alamat = _alamat;
        cout << "Informasi Biodata anda : " << endl;
    }

    void displayInfo() {
        cout << "Nama: " << nama << endl;
        cout << "Umur: " << umur << " tahun" << endl;
        cout << "Alamat: " << alamat << endl;
    }
};

int main() {
    string inputNama;
    int inputUmur;
    string inputAlamat;

    cout << "Masukkan nama: ";
    getline(cin, inputNama);

    cout << "Masukkan umur: ";
    cin >> inputUmur;
    cin.ignore(); 
  
    cout << "Masukkan alamat: ";
    getline(cin, inputAlamat);
    cout<<endl;

    Biodata biodata(inputNama, inputUmur, inputAlamat);
    biodata.displayInfo();

    return 0;
}

