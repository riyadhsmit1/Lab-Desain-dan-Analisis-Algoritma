#include <iostream>
using namespace std;

class BangunDatar {
public:
    virtual void get_data() = 0;
    virtual void display_area() = 0;
};

class PersegiPanjang : public BangunDatar {
private:
    double panjang;
    double lebar;

public:
    void get_data() override {
        cout << "Menghitung Luas Persegi Panjang" << endl;
        cout << "Panjang = ";
        cin >> panjang;
        cout << "Lebar   = ";
        cin >> lebar;
    }

    void display_area() override {
        double luas = panjang * lebar;
        cout << "Luas Persegi Panjang = " << luas << endl;
    }
};

class Persegi : public BangunDatar {
private:
    double sisi;

public:
    void get_data() override {
        cout << "Menghitung Luas Persegi" << endl;
        cout << "Sisi  = ";
        cin >> sisi;
    }

    void display_area() override {
        double luas = sisi * sisi;
        cout << "Luas Persegi  = " << luas << endl;
    }
};

class Segitiga : public BangunDatar {
private:
    double alas;
    double tinggi;

public:
    void get_data() override {
        cout << "Menghitung Luas Segitiga" << endl;
        cout << "Alas   = ";
        cin >> alas;
        cout << "Tinggi = ";
        cin >> tinggi;
    }

    void display_area() override {
        double luas = 0.5 * alas * tinggi;
        cout << "Luas Segitiga = " << luas << endl;
    }
};

int main() {

    PersegiPanjang panjang;
    Persegi segi;
    Segitiga tiga;

    panjang.get_data();
    segi.get_data();
    tiga.get_data();

    panjang.display_area();
    segi.display_area();
    tiga.display_area();

    return 0;
}

