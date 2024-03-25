#include <iostream>
using namespace std;

void merge(int arr[], int kiri, int tengah, int kanan) {
    int n1 = tengah - kiri + 1;
    int n2 = kanan - tengah;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[kiri + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[tengah + 1 + j];

    int i = 0, j = 0, k = kiri;
    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int kiri, int kanan) {
    if (kiri < kanan) {

        int tengah = kiri + (kanan - kiri) / 2;

        cout << "Memecah : ";
        for (int i = kiri; i <= tengah; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        mergeSort(arr, kiri, tengah);

        cout << "Memecah : ";
        for (int i = tengah + 1; i <= kanan; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        mergeSort(arr, tengah + 1, kanan);

        cout << "Menggabungkan: ";
        merge(arr, kiri, tengah, kanan);
        for (int i = kiri; i <= kanan; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arr[] = {46, 12, 64, 24, 1, 56, 25, 67, 78, 96};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Data awal: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;

    cout << "Proses Sort:\n";
    mergeSort(arr, 0, n-1);

    cout << "Data setelah diurutkan: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
