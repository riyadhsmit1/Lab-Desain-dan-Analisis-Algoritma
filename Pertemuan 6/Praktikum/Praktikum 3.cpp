#include <iostream>
using namespace std;

class Karyawan {
	private:
		int gaji;
		
	public:
		void setGaj(int s){
			gaji = s;
		}
		int getGaji(){
			return gaji;
		}
};

int main(){
	Karyawan myObj;
	
	myObj.setGaj(50000);
	cout << myObj.getGaji();
	
	return 0; 
}
