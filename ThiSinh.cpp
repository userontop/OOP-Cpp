
#include <string.h>	
#include <conio.h>
#include <iostream>
using namespace std;

class ThiSinh{
	private:
		char maSo[50];
		char name[50];
		char ketQua[32];
		float diemLT, diemTH, diemTB;
	public:
		void nhap();
		void xuat();
		void tinhTB();
		char* getMaSo();
		char* getName();
		float getDiemLT();
		float getDiemTH();
		void ketqua();
};

class MangThiSinh{
	private: 
		ThiSinh sv[100];
		int n;
	public:
		void nhap();
		int getN();
		void setN();
		void xuat();
};


//Thisinh
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
	cout << "Nhap ms: "; fflush(stdin);
	gets(this->maSo);
	cout << "Nhap Ten: "; fflush(stdin);
	gets(this->name);
	cout << "Nhap diem ly thuyet: ";
	cin >> diemLT;
	cout << "Nhap diem TH: ";
	cin >> diemTH;
	tinhTB();
	this->ketqua();
}

void ThiSinh::xuat(){
	cout << "Ma so: " << maSo << " - Ten: " << name << " - Diem LT: " << this->diemLT << " - Diem TH: " << this->diemTH << " - DiemTB" << this->diemTB << " - Ket Qua: " << this->ketQua << endl;
}
void ThiSinh::tinhTB(){
	this->diemTB = (this->diemLT + this->diemTH*2)/3;
}
void ThiSinh::ketqua(){
	if(this->tinhTB() >= 5)
		strcpy(this->ketQua, "Dat");
	else 
		strcpy(this->ketQua, "khong dat");
}

//mangthisinh:

int MangThiSinh::getN(){
	return this->n;
}
void MangThiSinh::setN(){
	cin >> n;
}
void MangThiSinh::nhap(){
	for(int i = 0; i < n; i++){
		cout << "Nhap sv" << i + 1 << ": " << endl;
		sv[i].nhap();
	}
}
void MangThiSinh::xuat(){
	for(int i = 0; i < n; i++){
		cout << "Sv " << i + 1 << ": " << endl;	
		sv[i].xuat();
	}
}
