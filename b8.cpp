#include<iostream>
using namespace std;

class Sinhvien{
	private://thuoc tinh -> dac diem
		string masv;
		string ten;
		int tuoi;
	public://phuong thuc -> cac hanh dong ...
		Sinhvien(){
			masv = "d100";
			ten = "Ton Thien Tam";
			tuoi = 19;
		}	
		void noiChuyenTrongGio(){
			cout << "noi nhieu." << endl;
		}
		void choiGame(){
			cout << "Choi Game." << endl;
		}
		void hoc(){
			cout << "Hoc tot" << endl;
		}
		void xuat(){
			cout << masv << "\t" << ten << "\t" << tuoi << endl;
		}
};

int main(){
	Sinhvien a;
//	a.Sinhvien();
	a.hoc();
	a.noiChuyenTrongGio();
	a.choiGame();
	a.xuat();
	return 0;
}
