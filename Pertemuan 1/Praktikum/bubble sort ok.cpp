#include <iostream>
using namespace std;
 
int data[10];
int n;
 
void tampil()
{
    for (int i = 0; i < n; i++)
    {
        cout << " " << data[i] << " ";
    }
    cout << endl;
}
 
int main()
{
    cout << "ALGORITMA BUBBLE SORT" << std::endl;
    cout << "----------------------" << std::endl;
 
    cout << "Masukan Jumlah Data = ";
    cin >> n;
 
    cout << std::endl;
 
    for (int i = 0; i < n; i++)
    {
        cout << "Masukan Data Ke-" << i + 1 << " = ";
        cin >> data[i];
    }
 
    cout << endl;
    cout << "Proses Bubble Sort" << endl;
 
    tampil();
 
    for (int i = 1; i < n; i++)
    {

        for (int j = n - 1; j >= i; j--)
        {
            if (data[j] < data[j - 1])
            {
                int t;
                t = data[j - 1];
                data[j - 1] = data[j];
                data[j] = t;
            }
        }
        tampil();
    }
	
	cout << "\nArray setelah diurutkan: ";
	tampil();
	
    cout << endl;
    
    return 0;
}
