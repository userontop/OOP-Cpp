#include <iostream>
using namespace std;

class Nguoi{
	protected:
		string ten;
		int tuoi;
	public:
		void noiChuyen(){
			cout << "xin chao" << endl;
		}
};

class SinhVien:public Nguoi{
	//mac dinh se la private
	string masv;
	public:
		//contructor - tu dong chay
		SinhVien(){
			ten = "Tam";
			tuoi = 19;
			masv = "dth216136";
		}
		void xuat(){
			cout << ten << "-" << tuoi << "-" << masv << endl;
		}
};

int main(){
	Nguoi *g = new SinhVien;
	g->noiChuyen();
	((SinhVien*)g)->xuat();
//	SinhVien a;
//	a.xuat();
//	a.noiChuyen();
	return 0;
}


