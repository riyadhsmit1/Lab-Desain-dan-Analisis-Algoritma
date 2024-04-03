#include <iostream>
using namespace std;

class Silsilah {
	protected:
		string orangtua = "albert wijaya dan jemy lim";
		string anakanak = "agatha wijaya dan jonathan wijaya";
		
		public:
			String cekSilsilah(){
				return "ayah bernama Albert Wijaya dan ibu bernama Jenny Lim";
				
			}
			
};

class Cucu: public Silsilah{
	protected:
	string cucu="Wilbert Tan dan Rayanza Wijaya";
	
	public:
	string cekAnak(){
		return "anak pertama keluarga Wijaya adalah agatha wijaya dan anak kedua dari keluarga Wijaya adalah jonathan wijaya"
	} 
};

class Anak: public Cucu{
	public:
		string lihatSilsilahnya(){
			return "silsilah keluarga wijaya";
		}
};

int main()
{
	Anak silsilahWijaya;
	cout<<silsilahWijaya.lihatSilsilahnya()<<endl;
	cout<<silsilahWijaya.cekSilsilah()<<endl;
	cout<<silsilahWijaya.cekAnak()<<endl;
	cout<<silsilahWijaya.cekCucu()<<endl;
	return 0;
}
