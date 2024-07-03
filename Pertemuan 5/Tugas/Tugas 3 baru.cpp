#include <iostream>

using namespace std;

class Calculator {
private:
    int angka1;
    int angka2;

public:
    void setAngka1(int a) {
        angka1 = a;
    }

    void setAngka2(int b) {
        angka2 = b;
    }

    int getAngka1() {
        return angka1;
    }

    int getAngka2() {
        return angka2;
    }

    int penambahan() {
        return angka1 + angka2;
    }

    int pengurangan() {
        return angka1 - angka2;
    }

    int perkalian() {
        return angka1 * angka2;
    }

    float pembagian() {
        if (angka2 != 0)
            return static_cast<float>(angka1) / angka2;
        else {
            cout << "Error: Pembagian oleh nol tidak dapat dilakukan." << endl;
            return 0;
        }
    }
};

int main() {
    Calculator calc;
    int angka1, angka2;

    cout << "Masukkan angka pertama: ";
    cin >> angka1;
    calc.setAngka1(angka1);

    cout << "Masukkan angka kedua: ";
    cin >> angka2;
    calc.setAngka2(angka2);

    cout << "Hasil penambahan: " << calc.penambahan() << endl;
    cout << "Hasil pengurangan: " << calc.pengurangan() << endl;
    cout << "Hasil perkalian: " << calc.perkalian() << endl;
    cout << "Hasil pembagian: " << calc.pembagian() << endl;

    return 0;
}
