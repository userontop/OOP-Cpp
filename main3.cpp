#include "ThiSinh.cpp"
#include <iostream>
#include <string.h>
#include <conio.h>
#include <iomanip>
#include<windows.h>
using namespace std;
int main(){

	MangThiSinh mts;
	cout << "Nhap n Thi sinh: ";
	mts.setN();
	cout << "Nhap thong tin sinh vien: " << endl;
	mts.nhap();
	system("cls");
	mts.xuat();
	getch();
	return 0;
}

