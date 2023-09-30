#include<stdio.h>
#include<math.h>
#include<string.h>
#include<conio.h>
#include<iostream>
#include<iomanip>

using namespace std;

const int MAX =100;

class GiaoDich{
	protected:
		char MaGD[6];
		float ThanhTien;
	public:
		GiaoDich();
		virtual void Nhap();
		void Xuat();
		virtual void TinhThanhTien()=0;
		virtual float getThanhTien();
		virtual char *getMGD();
};
GiaoDich::GiaoDich(){
	strcpy(MaGD, " ");
	ThanhTien=0;
}
void GiaoDich::Nhap(){
	fflush(stdin);
	cin.clear();
	cout<<"Nhap Ma giao dich: "<< endl; cin>>MaGD;
}
void GiaoDich::Xuat(){
	cout<<"- MaGD: "<<MaGD;
	cout<<"- Thanh tien: "<<ThanhTien;
}	
float GiaoDich::getThanhTien(){
	return ThanhTien;	
}
char *GiaoDich::getMGD(){
    return MaGD;
}
class GiaoDichVang:public GiaoDich{
	protected:
		int soluong;
		float dongia;
	    int loaivang;
	public:
		GiaoDichVang();
		void Nhap();
		void TinhThanhTien();
};
GiaoDichVang::GiaoDichVang(){
	soluong=0;
	dongia=0;
}
void GiaoDichVang::Nhap(){
	GiaoDich::Nhap();
	while(soluong<=0){
		cout<<"NHap so luong: "<< endl; cin>>soluong;
	};
	do{
		cout<<"Nhap Loai \n-1.SJC  \n-2.PNS \n-3.Loai vang khac \n.Chon trong(1/2/3): ";
		cin>>loaivang;
		if(loaivang == 1 || loaivang ==2){
			dongia= 5300000;
		}else{
			dongia= 4900000;
		}
	}while((loaivang<1) || (loaivang>3));
}

void GiaoDichVang::TinhThanhTien(){
    ThanhTien= soluong * dongia;
}
class GiaoDichTienTe:public GiaoDich{
	protected:
		float sotien;
		int loaitt;
		float tygia;
	public:
		GiaoDichTienTe();
		void Nhap();
		void TinhThanhTien();
};
GiaoDichTienTe::GiaoDichTienTe(){
	sotien=tygia=0;
}
void GiaoDichTienTe::Nhap(){
	GiaoDich::Nhap();
	while(sotien<=0){
		cout<<"Nhap so tien: "<< endl; cin>>sotien;
	}
	do{
		cout<<"Nhap Loai tien te \n-1.Euro \n-2.USD \n.Chon(1/2):  ";
		cin>>loaitt;
		if(loaitt==1){
			tygia=25000;
		}
		else if(loaitt==2){
		    tygia=23000;
		}
	}while((loaitt<1) || (loaitt<1));
}
void GiaoDichTienTe::TinhThanhTien(){
	if((loaitt==1)||(loaitt==2)){
		ThanhTien= sotien * tygia;
	}else{
		ThanhTien = sotien;
	}	
}
int main(){
	GiaoDich *gd[100];
	int n=0;
	int indexTien[100],indexVang[100];
	int v=0,t=0;
	cout<<setiosflags(ios::fixed)<<setprecision(1);
	char Loai, Chon;
	
	cout<<"Nhap thong tin cac loai giao dich: "<< endl;
	do{
		cout<<"Nhap GD Vang hay GD Tien(V/T): ";
		cin>>Loai;
		Loai= toupper(Loai);
		if(Loai=='V'){
			gd[n]= new GiaoDichVang;
			gd[n]->TinhThanhTien();
			indexVang[v++]=n;
		}else{
			gd[n]= new GiaoDichTienTe;
			indexTien[t++]=n;
		}
		gd[n++]->Nhap();
		cout<<"Tiep tuc(C/K): ";
		cin>>Chon;
		Chon= toupper(Chon);
		if((n==100)||(Chon=='K')){
			break;
		}	
	}while(1);
	
	
	cout<<"Thong tin vua nhap: ";
	for(int i=0;i<n;i++){
		gd[i]->TinhThanhTien();
		gd[i]->Xuat();
	}	
	
	if(v>0){
		float min=999999999;
		for(int i=0;i<v;i++){
			if(min>gd[indexVang[i]]->getThanhTien()){
				min=gd[indexVang[i]]->getThanhTien();
			}	
		}
		cout<<"Thanh tien thap nhat trong gdVang: "<<min<<endl;	
	}
	else{
		cout<<"Khong co giao dich nao ca! ";
}
	
	if(n>0){
		float tbc=0;
		for(int i=0;i<n;i++){
			tbc+=gd[i]->getThanhTien();
		}
		cout<<"Trung binh cong thanh tien: "<<tbc/n<< endl;	
	}else{
		cout<<"Khong co gd nao ca! "<< endl;
	}
	cout<<"Sap xep danh sach tang theo ma giao dich: "<< endl;
	GiaoDich *tpm;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(strcmp(gd[i]->getMGD(),gd[j]->getMGD())>=1){
				tpm =gd[i];
				gd[i]= gd[j];
				gd[j]= tpm;
			}	
		}	
	}
	for(int i=0;i<n;i++){
		gd[i]->TinhThanhTien();
		gd[i]->Xuat();
	}

	return 1;	
	
}
