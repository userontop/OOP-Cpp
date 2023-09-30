
#include "stdafx.h"
#include "MathLib.h"
using namespace std;

class ThiSinh{
	private:
		char maSo[50];
		char name[50];
		char ketQua[32];
		float diemLT, diemTH, diemTB;
	public:
		void nhap();
		friend ostream& operator << (ostream &, ThiSinh &);
		void tinhTB();
		char* getMaSo();
		char* getName();
		float getDiemLT();
		float getDiemTH();
		
};

class MangThiSinh{
	private: 
		ThiSinh sv[100];
		int n;
	public:
//		friend istream& operator >> (istream &, MangThiSinh &);
//		friend ostream& operator << (ostream &, MangThiSinh &);
};


char* ThiSinh::getMaSo(){
	return this->maSo;
}
char* ThiSinh::getName(){
	return this->name;
}
float ThiSinh::getDiemLT(){
	return this->diemLT;
}
float ThiSinh::getDiemTH(){
	return this->diemTH;
}
void ThiSinh::nhap(){
	cout << "Nhap ms: ";
	gets(this->maSo);
	cout << "Nhap Ten: ";
	gets(this->name);
	cout << "Nhap diem ly thuyet: ";
	cin >> diemLT;
	cout << "Nhap diem TH: ";
	cin >> diemTH;
}

ostream &operator << (ostream &os, ThiSinh &sv){
	os <<< "Ma so: " << sv.getMaSo() << " - Ten: " << sv.getName() << " - Diem LT: " << sv.getDiemLT() << " - Diem TH: " << sv.getDiemTH();
	return os;
}

//istream &operator >> (istream &mis, MangThiSinh &msv);
//ostream &operator << (ostream &mos, MangThiSinh &msv);
