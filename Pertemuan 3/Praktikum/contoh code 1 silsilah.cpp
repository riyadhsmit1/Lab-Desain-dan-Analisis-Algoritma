#include <iostream>
#include <string>
using namespace std;

class Silsilah {
protected:
    string orangtua = "Albert Wijaya dan Jenny Lim";
    string anakanak = "Agatha Wijaya dan Jonathan Wijaya";

public:
    string cekSilsilah() {
        return "Ayah bernama " + orangtua + " dan Ibu bernama " + anakanak;
    }
};

class Cucu : public Silsilah {
protected:
    string cucu = "Wilbert Tan dan Rayanza Wijaya";

public:
    string cekAnak() {
        return "Anak pertama keluarga Wijaya adalah " + anakanak + " dan anak kedua dari keluarga Wijaya adalah " + orangtua;
    }
};

class Anak : public Cucu {
public:
    string lihatSilsilahnya() {
        return "Silsilah keluarga Wijaya";
    }
};

int main() {
    Anak silsilahWijaya;
    cout << silsilahWijaya.lihatSilsilahnya() << endl;
    cout << silsilahWijaya.cekSilsilah() << endl;
    cout << silsilahWijaya.cekAnak() << endl;
    return 0;
}

