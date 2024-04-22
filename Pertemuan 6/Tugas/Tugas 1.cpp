#include<iostream>
using namespace std;

class Mahasiswa{
	private:
		string fakultas;
		string status;
		string jurusan;
		string nama;
		int umur;
	public:
		void setFakultas(string a){
			fakultas = a;
		}
		
		void setStatus(string b){
			status = b;
		}
		
		void setUmur(int c){
			umur = c;
		}
		
		void setNama(string d){
			nama = d;
		}
		
		void setJurusan(string e){
			jurusan = e;
		}
		
		string getFakultas(){
			return fakultas;
		}
		
		string getNama(){
			return nama;
		}
		
		string getStatus(){
			return status;
		}
		
		string getJurusan(){
			return jurusan;
		}
		
		int getUmur(){ 
			return umur;
		}
		
};

int main(){

	const int MAX = 10;
	Mahasiswa mhs[MAX];
	
	int Umur; 
	string Nama, Jurusan, Status, Fakultas; 
	
	int Jumlah;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> Jumlah;
    cin.ignore();
	
	for (int i = 0; i < Jumlah; ++i) {
		cout << "Mahasiswa ke - " << i+1 << endl;
		cout<<"Masukkan status mahasiswa: ";
		cin >> Status;
		cin.ignore();
		cout<<"Masukkan nama mahasiswa: ";
		getline(cin, Nama);
		cout<<"Masukkan Umur mahasiswa: ";
		cin >> Umur;
		cin.ignore();
		cout<<"Masukkan jurusan mahasiswa: ";
		getline(cin, Jurusan);
		cout<<"Masukkan fakultas mahasiswa: ";
		getline(cin, Fakultas);
		
		mhs[i].setStatus(Status);
		mhs[i].setNama(Nama);
		mhs[i].setUmur(Umur); 
		mhs[i].setJurusan(Jurusan);
		mhs[i].setFakultas(Fakultas);
		
		cout << endl;
	}
	
	cout << "\nData Mahasiswa:" << endl;
    for (int i = 0; i < Jumlah; ++i) {
    	cout << "\nMahasiswa ke - "<< i + 1 << endl;
		cout<<"Status: "<<mhs[i].getStatus()<<endl;
		cout<<"Nama: "<<mhs[i].getNama()<<endl;
		cout<<"Umur: "<<mhs[i].getUmur()<<endl;
		cout<<"Jurusan: "<<mhs[i].getJurusan()<<endl;
		cout<<"Fakultas: "<<mhs[i].getFakultas()<<endl;
		
		cout << "========================="<<endl;
	}
	
	return 0;
	
}

