#include<iostream>
using namespace std;

void swap(int arr[], int pos1, int pos2){ //Ini adalah definisi fungsi bernama swap, yang mengambil sebuah array arr dan dua indeks pos1 dan pos2.
	int temp;
	temp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = temp;
}

int partition(int arr[], int low, int high, int pivot){ //Ini adalah definisi fungsi partition yang akan digunakan dalam algoritma quicksort. 
													    //Fungsi ini membagi array menjadi dua bagian, di mana satu bagian memiliki elemen yang lebih kecil dari pivot dan bagian lainnya memiliki elemen yang lebih besar.				
	int i = low; //Deklarasi dan inisialisasi variabel i dan j dengan nilai low.
	int j = low;
	
	while(i <= high){  //Looping yang melakukan iterasi dari low hingga high
		if(arr[i] > pivot){ //memeriksa apakah elemen di posisi i lebih besar dari pivot. 	
			i++;			//Jika ya, maka i ditingkatkan. Jika tidak, maka fungsi swap dipanggil untuk menukar elemen arr[i] dan arr[j], dan i serta j ditingkatkan.	
		}
		else{
			swap(arr,i,j);
			i++;
			j++;
		}
	}
	return j-1;
}


void quickSort(int arr[], int low, int high){
	if(low < high){
		
		int pivot = arr[high]; //Memilih elemen terakhir dari array sebagai pivot.
		int pos = partition(arr, low, high, pivot); //Memanggil fungsi partition untuk membagi array dan mendapatkan posisi pivot yang benar.
		
	
		quickSort(arr, low, pos-1);
		quickSort(arr, pos+1, high);
	}
}

int main(){

	int n;
	
	cout << "Tentukan panjang array : ";
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	quickSort(arr, 0, n - 1);

	cout << "Berikut adalah array yang telah di sortir : ";
	for(int i = 0; i < n; i++){
		cout << arr[i] << "\t";
	}
}
