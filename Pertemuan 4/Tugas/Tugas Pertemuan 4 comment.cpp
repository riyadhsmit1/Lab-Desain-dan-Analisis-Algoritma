#include <iostream>
using namespace std;

class contoh { //Mendefinisikan kelas contoh yang memiliki satu atribut private bernama nilai 
	private: //anggota tersebut hanya dapat diakses dari dalam kelas itu sendiri
		int nilai;
	public: //dapat diakses dari mana saja di dalam program C++, baik itu dari fungsi main atau dari kelas atau fungsi lain.
		contoh (int z){// mengambil satu argumen bertipe int dan digunakan untuk menginisialisasi nilai atribut nilai
			nilai = z;
		}
		
		int getNum(){ //engembalikan nilai atribut nilai
			return nilai; 
		}
};

int main(){ 
	contoh obj(10); //akan menginisialisasi nilai atribut nilai dengan nilai 10.
	cout << "nilai yang diinput: "<<obj.getNum()<<endl; //memanggil output
	
	return 0;
}


