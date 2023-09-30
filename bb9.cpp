#include <iostream>
using namespace std;
class Nguoi{
	private: 
		string ten;
		int tuoi;
	public:
		//contructor
		Nguoi(){
			ten = "Nguyen Van A";
			tuoi = 25;
		}
		//destructor
		~Nguoi(){
			cout << "huy doi tuong" << endl;
		}
		void noiChuyen(){
			cout << "xin chao" << endl;
		}
		void xuat(){
			cout << ten << "_" << tuoi;
		}
};


int main(){
	Nguoi a;
	a.xuat();
	a.noiChuyen();
	return 0;
}
