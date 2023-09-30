//Mang cac doi tuong 
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <iostream>
using namespace  std;

class Thisinh
{
	private:
		char Maso[12];
		char Hoten[40];
		float Diemlt, Diemth, Dtb;
		char Ketqua[12];
	public:
		Thisinh(); 
		void Nhap();
		void tinhDTB();
		void tinhKQ();
		float getDiemLT();
		float getDiemTH();
		float getDiemTB();
		void Xuat();
		char* getMS();
		
};
Thisinh::Thisinh()
{
	strcpy(Maso," ");
	strcpy(Hoten," ");
	Diemlt=Diemth=Dtb=0;
}
void Thisinh::Nhap(){
	cout<<"Nhap ma so: "; gets(Maso);
	cout<<"Nhap ho ten: "; gets(Hoten);
	cout<<"Nhap diem li thuyet: "; cin>>Diemlt;
	cout<<"Nhap diem thuc hanh: "; cin>>Diemth;
	cin.ignore();
	tinhDTB();
	tinhKQ();
	
}
void Thisinh::tinhDTB(){
	Dtb=(Diemlt+Diemth)*2/3;
}
void Thisinh::tinhKQ(){
	if(getDiemTB()>=5){
		strcpy(Ketqua,"Dat");
	}else{
		strcpy(Ketqua,"Khong dat");
	}	
}
void Thisinh::Xuat(){
	cout<<"\n-Ma so: "<<Maso;
	cout<<"-Ho ten: "<<Hoten;
	cout<<"-Diem li thuyet: "<<Diemlt;
	cout<<"-Diem thuc hanh: "<<Diemth;
	cout<<"-Diem trung binh: "<<Dtb;
	cout<<"-Ket qua: "<<Ketqua;
}
float Thisinh::getDiemLT(){
	return Diemlt;
}
float Thisinh::getDiemTH(){
	return Diemth;
}
float Thisinh::getDiemTB(){
	return Dtb;
}
char* Thisinh::getMS(){
	return Maso;
}	
	
class MangThisinh
{
	private:
		Thisinh a[100];
		int n;
	public:
		void Nhap();
		void Xuat();
		void lieKe();
		float tbc();
		void timThongTinSV(char ms[32]);
		void sapXepTangTheoHoTen();
		
		
		
		
};


int main()
{
	MangThisinh mThisinh;
	
	
	cout<<"Nhap thong tin cac Thi sinh: ";
	mThisinh.Nhap();
	
	cout<<"Thong tin cac Thi sinh: ";
	mThisinh.Xuat();
	
	cout<<"Thi sinh co dth va dlt >=7: ";
	mThisinh.lieKe();
	
	char ms[32];
	cout<<"\nNhap ma so thi sinh can tim: "; gets(ms);
	cout<<"Thi vua duoc tim la: ";
	mThisinh.timThongTinSV(ms);
	
	cout<<"Trung binh cong diem thi sinh: "<<mThisinh.tbc() << endl;
	
	cout<<"Xap sep tang dan theo ho ten: \n";
	mThisinh.sapXepTangTheoHoTen();
	mThisinh.Xuat();

	
	getch();
	return 1;

}

void MangThisinh::Nhap()
{
	cout <<"\nSo luong Thi sinh : "; cin >> n;
	cin.ignore();
	for (int i=0;i<n;i++)
	{
		cout<<"Nhap Thi sinh thu "<<i+1<<" : "<<endl;
		a[i].Nhap();
	}
}
void MangThisinh::Xuat()
{
	for (int i=0;i<n;i++)
	{
		a[i].Xuat();
		cout << " ";
	}
}
void MangThisinh::lieKe()
{
	int dem=0;
	for(int i=0;i<n;i++){
		if(a[i].getDiemLT()>=7 &&a[i].getDiemTH()>=7){
			a[i].Xuat();
			cout<<"\n";
			dem++;
		}	
	}if(dem==0){
		cout<<"khong co!";
	}	
}
float MangThisinh::tbc(){
	float s=0;
	for(int i=0;i<n;i++){
		s=s+a[i].getDiemTB();
	}
	return (float) s/n;
}
void MangThisinh::timThongTinSV(char ms[32])
{

	int dem=0;
	for(int i=0;i<n;i++){
		if((strcmp(ms,a[i].getMS()))==0){
			a[i].Xuat();
			cout<<"\n";
			dem++;
		}	
	}if(dem==0){
		cout<<"khong co!";
	}
}	
void MangThisinh::sapXepTangTheoHoTen(){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i].getMS()>a[j].getMS()){
				Thisinh t= a[i];
				a[i]=a[j];
				a[j]=t;
			}	
		}	
	}
}
