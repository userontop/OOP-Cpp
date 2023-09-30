#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<iostream>
#include <iomanip>

using namespace std;

class HocSinh{
	private:
		char maso[12];
		char hoten[32];
		float DiemLiThuyet;
		float DiemThucHanh;
		float DiemTrungBinh;
		char ketqua[12];
	public:
		HocSinh();
		void nhap();
		void xuat();
		float getDiemLT();
		float getDiemTH();
		float getDiemTB();
		char* getMS();
		void tinhTB();
		void tinhKQ();
};
void HocSinh::nhap(){
	cout<<"Nhap ma so: ";fflush(stdin); gets(maso);//fflush
	cout<<"Nhap ho ten: "; gets(hoten);
	cout<<"Nhap diem li thuyet: "; cin>>DiemLiThuyet;
	cout<<"Nhap diem thuc hanh: "; cin>>DiemThucHanh;
	cin.ignore();
	tinhKQ();
	tinhTB();
}
void HocSinh::xuat(){
	cout<<"\nMa so: "<<maso;
	cout<<"\nHo ten: "<<hoten;
	cout<<"\nDiem li thuyet: "<<DiemLiThuyet;
	cout<<"\nDiem thuc hanh: "<<DiemThucHanh;
	cout<<"\nDiem trung binh: "<<DiemTrungBinh;
	cout<<"\nKet qua: "<<ketqua;
}
HocSinh::HocSinh(){
	this->maso[0] = '\0';
	this->hoten[0] = '\0';
	DiemLiThuyet=DiemThucHanh=DiemTrungBinh=0;
}
float HocSinh::getDiemLT()
{
	return DiemLiThuyet;
}
float HocSinh::getDiemTH()
{
	return DiemThucHanh;
}
float HocSinh::getDiemTB()
{
	return DiemTrungBinh;
}
char* HocSinh::getMS()
{
	return maso;
}
void HocSinh::tinhTB(){
	DiemTrungBinh=(DiemLiThuyet+DiemThucHanh*2)/3;
}
void HocSinh::tinhKQ(){
	if(getDiemTB()>=5){
		strcpy(ketqua,"dat");
	}else
		strcpy(ketqua,"khong dat");	
}

class MangHocSinh{
	private:
		HocSinh a[100];
		int n;
	public:
		void nhap();
		void xuat();
		void timKiemMS(char ms[]);
		float TBC();
		void sapXep();
};
void MangHocSinh::nhap(){
	cout<<"Nhap so luong hoc sinh: "; cin>>n;
	for(int i=0;i<n;i++){
		cout<<"\nHoc sinh thu["<<i<<"]: ";
		a[i].nhap();
	}	
}
void MangHocSinh::xuat(){
	for(int i=0;i<n;i++){
		a[i].xuat();
	}	
}
void MangHocSinh::timKiemMS(char ms[]){
	int dem=0;
	for(int i=0;i<n;i++){
		if((strcmp(ms,a[i].getMS()))==0){
			a[i].xuat();
			dem++;
		}	
	}if(dem==0){
		cout<<"khong co!";
	}	
}
float MangHocSinh::TBC(){
	float s=0;
	for(int i=0;i<n;i++){
		s=s+a[i].getDiemTB();
	}
	return (float)s/n;	
}
void MangHocSinh::sapXep(){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			HocSinh t;
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}	
	}	
}
int main(){
	MangHocSinh mhs;
	
	cout<<"\n1.Danh sach hoc sinh: ";
	mhs.nhap();
	
	cout<<"\n2.Xuat danh sach hoc sinh: ";
	mhs.xuat();
	
	cout<<"\n3. Nhap ms can tim: ";
	char ms[12];
	gets(ms);
	cin.ignore();
	mhs.timKiemMS(ms);
	
    cout<<"\n4.trung binh cong: "<<mhs.TBC();
    
    cout<<"\n5.Sap xep tang theo ht: ";
    mhs.sapXep();
	mhs.xuat();
    
    getch;
    return 1;
    
    
}
