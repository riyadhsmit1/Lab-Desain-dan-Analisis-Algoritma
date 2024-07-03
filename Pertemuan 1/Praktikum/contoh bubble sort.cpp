#include <iostream>
 
int data[10];
int n;
 
void tampil()
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "[" << data[i] << "] ";
    }
    std::cout << std::endl;
}
 
int main()
{
    std::cout << "ALGORITMA BUBBLE SORT" << std::endl;
    std::cout << "----------------------" << std::endl;
 
    // Menentukan banyaknya jumlah data
    std::cout << "Masukan Jumlah Data = ";
    std::cin >> n;
 
    std::cout << std::endl;
 
    // Input data
    for (int i = 0; i < n; i++)
    {
        std::cout << "Masukan Data Ke-" << i + 1 << " = ";
        std::cin >> data[i];
    }
 
    std::cout << std::endl;
    std::cout << "Proses Bubble Sort" << std::endl;
 
    tampil();
 
    // Proses sorting bubble
     
    // Perulangan pertama 1 s/d n(jumlah data), 
    //sebagai batas urutan data terkecil saat melakukan perbandingan data
    for (int i = 1; i < n; i++)
    {
        // perulangan kedua (n - 1) s/d nilai i yang sedang berjalan pada perulangan pertama,
        // berguna membandingkan nilai dari urutan data terbesar ke urutan data terkecil.
        for (int j = n - 1; j >= i; j--)
        {
            if (data[j] < data[j - 1])
            {
                // Tukar posisi data
                int t;
                t = data[j - 1];
                data[j - 1] = data[j];
                data[j] = t;
            }
        }
        tampil();
    }
    std::cout << std::endl;
    return 0;
}
