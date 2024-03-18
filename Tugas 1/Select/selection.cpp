#include <iostream>
using namespace std;

void selectSort(int arr[], int n) {
    for (int j = 0; j < n - 1; ++j) {
        int min = j;
        for (int k = j + 1; k < n; ++k) {
            if (arr[k] < arr[min]) {
                min = k;
            }
        }
        
        int temp = arr[j];
        arr[j] = arr[min];
        arr[min] = temp;

        cout << "Iterasi " << j + 1 << ": ";
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Masukkan jumlah elemen: ";
    cin >> n;

    int arr[n];

    cout << "Masukkan nilai elemen:\n";
    for (int j = 0; j < n; ++j) {
        cout << j + 1 << ": ";
        cin >> arr[j];
    }

    cout << "\ndata sebelum sorting: ";
    for (int j = 0; j < n; ++j) {
        cout << arr[j] << " ";
    }
    cout << endl << endl;

    selectSort(arr, n);

    cout << "\ndata setelah sorting: ";
    for (int j = 0; j < n; ++j) {
        cout << arr[j] << " ";
    }
    cout << endl;

    return 0;
}
