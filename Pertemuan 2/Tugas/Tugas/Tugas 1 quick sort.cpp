#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int l, int h) {
    int pivot = arr[h];
    int i = l - 1;

    for (int j = l; j < h; j++) {
        if (arr[j] >= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[h]);
    return i + 1;
}

void quickSort(int arr[], int l, int h) {
    if (l < h) {
        int pivotIndex = partition(arr, l, h);

        quickSort(arr, pivotIndex + 1, h);
        quickSort(arr, l, pivotIndex - 1);
    }
}

void view(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] ={67, 90, 87, 34, 45, 11, 16, 42, 61, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Data yang akan di sort: ";
    view (arr, n);

	cout << "Quick Sort: " << endl ;
    for (int i = 0; i < n - 1; i++) {
        quickSort(arr, 0, i);
        view(arr, n);
    }

    cout << "Data setelah diurutkan: ";
    view(arr, n);

    return 0;
}
