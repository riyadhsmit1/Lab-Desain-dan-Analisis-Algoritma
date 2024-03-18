#include <iostream>
using namespace std;

void insertSort(int arr[], int n) {
    for (int j = 1; j < n; ++j) {
        int key = arr[j];
        int k = j - 1;
        
        while (k >= 0 && arr[k] > key) {
            arr[k + 1] = arr[k];
            k = k - 1;
        }
        arr[k + 1] = key;

        cout << "Proses " << j << ": ";
        for (int j = 0; j < n; ++j) {
            cout << arr[j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Masukkan banyak data: ";
    cin >> n;
    cout<<endl;

    int arr[n];

    cout << "Masukkan data:\n" << endl;
    for (int j = 0; j < n; ++j) {
        cout << "data ke - " << j+1 << ": ";
        cin >> arr[j];
    }

    cout << "\ndata sebelum sorting: ";
    for (int j = 0; j < n; ++j) {
        cout << arr[j] << " ";
    }
    cout << endl << endl;

    insertSort(arr, n);

    cout << "\ndata setelah sorting: ";
    for (int j = 0; j < n; ++j) {
        cout << arr[j] << " ";
    }
    cout << endl;

    return 0;
}
