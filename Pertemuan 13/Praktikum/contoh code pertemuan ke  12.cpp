#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

int storage[1024];
int i = 0;
int hdt_boundary;

void tambah_linear_probing(int n) {
    bool inserted = false;
    int hash;
    i = 0;

    while ((!inserted) && (i < hdt_boundary)) {
        hash = (n % hdt_boundary) + i;
        if (storage[hash] == 0) {
            storage[hash] = n;
            inserted = true;
        } else {
            ++i;
            cout << "Terjadi tabrakan di " << hash << endl;
        }
    }

    if (i == 0) {
        cout << "Langsung" << endl;
    }
    cout << "Isi hash[" << hash << "] dengan " << n << endl;
    cout << "===================================================================" << endl;
}

void tambah_quadric_probing(int n) {
    bool inserted = false;
    int hash;
    i = 0;

    while ((!inserted) && (i < hdt_boundary)) {
        hash = (n % hdt_boundary) + (i * i);
        if (storage[hash] == 0) {
            storage[hash] = n;
            inserted = true;
        } else {
            ++i;
            cout << "Terjadi tabrakan di " << hash << endl;
        }
    }

    if (i == 0) {
        cout << "Langsung" << endl;
    }
    cout << "Isi hash[" << hash << "] dengan " << n << endl;
    cout << "=======================================" << endl;
}

bool isPrima(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int prima_atas(int n) {
    if (n % 2 == 0)
        n = n + 1;
    else
        n = n + 2;

    while (!isPrima(n)) {
        n += 2;
    }
    return n;
}

int prima_bawah() {
    int n = hdt_boundary;
    if (n % 2 == 0)
        n = n - 1;
    else
        n = n - 2;

    while (!isPrima(n)) {
        n -= 2;
    }
    return n;
}

void tambah_double_hashing(int n) {
    cout << "=================================================================" << endl;
    cout << "Double hashing..." << endl;
    int hash;
    int hash2 = prima_bawah();
    bool inserted = false;
    i = 0;

    while ((!inserted) && (i < hdt_boundary)) {
        hash = ((n % hdt_boundary) + i * ((n % hash2) + 1)) % hdt_boundary;

        if (storage[hash] == 0) {
            storage[hash] = n;
            inserted = true;
        } else {
            ++i;
            cout << "Terjadi tabrakan di " << hash << endl;
        }
    }

    if (i == 0) {
        cout << "Langsung" << endl;
    }
    cout << "Isi hash[" << hash << "] dengan " << n << endl;
    cout << "==================================================================" << endl;
}

void cetak(int n) {
    cout << endl;
    cout << "Output program : " << endl;
    for (int a = 0; a < hdt_boundary; ++a) {
        cout << "hash[" << a << "] = " << storage[a] << endl;
    }
}

int getRandomNumberFromRange(int min, int max) {
    return min + (rand() % (max - min + 1));
}

int main() {
    int n, random_number;
    char pilihan;
    string cara;

    srand((unsigned)time(0));

    cout << "Masukan jumlah data : ";
    cin >> n;
    cout << "Kami menggunakan metode open addressing ada 3 cara, pilih salah satu dengan memilih a, b, atau c : " << endl;
    cout << "a. Linear Probing" << endl;
    cout << "b. Quadratic Probing" << endl;
    cout << "c. Double Hashing" << endl;
    cout << "Pilih a, b, atau c ? " << endl;
    cin >> pilihan;
    cout << endl << endl << "Proses pemasukan data ke hashtable " << endl;

    hdt_boundary = prima_atas(n);
    for (int a = 0; a < n; ++a) {
        random_number = getRandomNumberFromRange(1, n);

        switch(pilihan) {
            case 'a':
                tambah_linear_probing(random_number);
                cara = "Linear Probing";
                break;
            case 'b': 
                tambah_quadric_probing(random_number);
                cara = "Quadratic Probing";
                break;
            case 'c': 
                tambah_double_hashing(random_number);
                cara = "Double Hashing";
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                return 1;
        }
    }


    cetak(n);
    cout << "Diatas adalah hasil output Hashtable dengan cara \"" << cara << "\"" << endl; 
    switch(pilihan) {
        case 'a':
            cout << "h(k) = (k mod " << hdt_boundary << ") + i" << endl;
            break;
        case 'b': 
            cout << "h(k) = (k mod " << hdt_boundary << ") + i*i" << endl;
            break;
        case 'c': 
            cout << "h1(k) = k mod " << hdt_boundary << endl;
            cout << "h2(k) = ( h1(k) + i*(k mod " << prima_bawah() << " + 1) ) mod " << hdt_boundary << endl; 
            break;
    }

    return 0;
}

