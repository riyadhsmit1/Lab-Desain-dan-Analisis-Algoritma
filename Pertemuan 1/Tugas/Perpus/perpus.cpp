#include <iostream>
using namespace std;

void selectSort(string arr[], int n) {
    for (int j = 0; j < n - 1; ++j) {
        int min = j;
        for (int k = j + 1; k < n; ++k) {
            if (arr[k] < arr[min]) {
                min = k;
            }
        }
     
        string temp = arr[j];
        arr[j] = arr[min];
        arr[min] = temp;

        cout << "Proses " << j + 1 << ": ";
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

int main() {

	cout << "-INPUT JUDUL BUKU PERPUSTAKAAN-\n";
    int n;
    cout << "\nMasukkan jumlah data: ";
    cin >> n;
    cin.ignore();

    string arr[n];

    cout << "Masukkan Judul Buku:\n";
    for (int j = 0; j < n; ++j) {
        cout << "Judul ke-" << j + 1 << ": ";
        getline(cin, arr[j]);
    } 

    cout << "\nJudul buku sebelum sorting: ";
    for (int j = 0; j < n; ++j) {
        cout << arr[j] << " ";
    }
    cout << endl << endl;

    selectSort(arr, n);

    cout << "\nJudul buku setelah sorting berdasarkan alfabet: \n";
    for (int j = 0; j < n; ++j) {
        cout << arr[j] << " , ";
    }
    cout << endl;

    return 0;
}
