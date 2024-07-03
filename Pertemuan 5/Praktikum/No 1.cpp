#include <iostream>
using namespace std;

void insert(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
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

void insertSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        insertSort(arr, left, mid);
        insertSort(arr, mid + 1, right);
        insert(arr, left, mid, right);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = { 38, 27, 43, 3, 9, 82, 10 };
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    cout << "Array sebelum diurutkan:" << endl;
    printArray(arr, arrSize);

    insertSort(arr, 0, arrSize - 1);

    cout << "Array setelah diurutkan:" << endl;
    printArray(arr, arrSize);

    return 0;
}
