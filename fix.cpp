#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<iomanip>
using namespace std;

#define MAX 100
#define LCBQL 3000
#define LCBSX 2400
#define SP 10

class NhanVien{
	private:
		char maSo[10];
		char hoTen[50];
		char ngaySinh[32];
		float tienLuong;
	public:

		NhanVien();
		virtual void nhap();
		char *getMaSo();
		char *getHoTen();
		float getTienLuong();
		void setTienLuong(float l);
		void xuat();
		virtual void tinhTienLuong() = 0;
};


NhanVien::NhanVien(){
	strcpy(maSo,"");
	strcpy(hoTen,"");
	strcpy(ngaySinh,"");
	tienLuong = 0;
}




int main(){
			cout << setiosflags(ios::fixed)<<setprecision(3);
	getch();
	return 0;
}

