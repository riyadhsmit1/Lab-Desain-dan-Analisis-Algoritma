#include <iostream>
using namespace std;

void show(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1); 

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main()
{
    int size;
    cout << "Masukkan banyaknya data: ";
    cin >> size;

    int arr[size];

    cout << "Masukkan nilai: ";
    for (int i = 0; i < size; ++i)
    {
        cout << "\n";
        cin >> arr[i];
    }

    int lower_bound; // Nilai awal atau batas bawah
    cout << "Masukkan nilai awal: ";
    cin >> lower_bound;

    // Menambahkan nilai awal ke array
    int newArr[size + 1];
    newArr[0] = lower_bound;
    for (int i = 0; i < size; ++i)
    {
        newArr[i + 1] = arr[i];
    }

    quickSort(newArr, 0, size);
    cout << "Sorted array:\n";
    show(newArr, size + 1);
    return 0;
}

