#include <iostream>
using namespace std;

class Mahasiswa{
	private:
		int usia[2];
		float ipk[2];
		string nama[2];
		
	public:
		void setNama(string a){
			nama[2] = a;
		}
		void setUsia(int b){
			usia[2] = b;
		}
		void setIPK(float c){
			ipk[2] = c;
		}
		string getNama(){
			return nama[2];
		}
		int getUsia(){
			return usia[2];
		}
		float getIPK(){
			return ipk[2];
		}	
};

int main(){
	Mahasiswa ms;
	
	int nilai;
	
	cout << "masukan jumlah data : ";
	cin>>nilai;
	
	string nama[nilai];
	int usia[nilai];
	float ipk[nilai];
	
	for (int i=0; i<nilai; i++)
	{
		cout <<"nama : ";
		cin >> nama[nilai];
		cout <<"usia : ";
		cin >> usia[nilai];
		cout <<"ipk : ";
		cin >> ipk[nilai];
		cout<<endl;
	}
	ms.setNama(nama[nilai]);
	ms.setUsia(usia[nilai]);
	ms.setIPK(ipk[nilai]);
	
	for(int i = 0; i<nilai; i++) {
	
	cout<<"nama mahasiswa: "<<ms.getNama()<<endl;
	cout<<"umur: "<<ms.getUsia()<<endl;
	cout<<"ipk: "<<ms.getIPK()<<endl;
	}
}
