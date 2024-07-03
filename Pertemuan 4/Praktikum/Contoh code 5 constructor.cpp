#include <iostream>
#include <string>
using namespace std;

class Mahasiswa {
	public:
		Mahasiswa (string nama, int umur)
		:nama_(nama), umur_(umur) {
			cout << "Constructor Mahaiswa"<<endl;
		}
		~Mahasiswa() {
			cout<<"==Contih Destructor Mahasiswa=="<<endl;
		}
		void TampilkanBiodata(){
			cout<<"Nama: "<< nama_ <<endl;
			cout<<"Umur: "<< umur_ <<endl;
		}
		
		private:
			string nama_;
			int umur_;
};

int main() {
	
	Mahasiswa msh("Katarina", 20);
	msh.TampilkanBiodata();
	}
	

