#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<iostream>
#include<iomanip>
#include<math.h>

using namespace std;

const int MAX =100;

class LoaiSach{
	protected:
		char MaSach[32];
		char NgayNhap[32];
		float DonGia;
		int SoLuong;
		char NXB[32];
		float ThanhTien;
	public:
		LoaiSach();
		virtual void Nhap();
		void Xuat();
		virtual void TinhTien()=0;
		virtual float getThanhTien();
		virtual float getDonGia();
		virtual char *getNXB();
};
LoaiSach::LoaiSach(){
	strcpy(MaSach, "");
	strcpy(NgayNhap, "");
	strcpy(NXB, "");
	SoLuong=0;
	ThanhTien=0;
	DonGia=0;
}
void LoaiSach::Nhap(){
	fflush(stdin);
	cin.clear();
	cout<<"Nhap ma sach: "<< endl; cin.getline(MaSach, MAX);
	cout<<"Nhap ngay(ngay-thang-nam): "<< endl; cin.getline(NgayNhap, MAX);
	cout<<"Nhap nha xuat ban: "<< endl; cin.getline(NXB, MAX);
	fflush(stdin);
	cin.clear();
	cout<<"Nhap don gia: ";cin>>DonGia;
	cout<<"Nhap so luong: ";cin>>SoLuong;
}
void LoaiSach::Xuat(){
	cout<<" \n -ma sach: "<< MaSach;
	cout<<" ngay(ngay-thang-nam): "<<NgayNhap<< endl;
	cout<<" nha xuat ban: "<< NXB<< endl;
	cout<<" don gia: "<<DonGia<< endl;
	cout<<" so luong: "<<SoLuong<< endl;
	cout<<" thanh tien: "<<ThanhTien<< endl;
}
float LoaiSach::getThanhTien(){
	return ThanhTien;
}
char* LoaiSach::getNXB(){
	return NXB;
}
float LoaiSach::getDonGia(){
	return DonGia;
}
class SachGiaoKhoa:public LoaiSach{
	protected:
		int TinhTrang;
	public:
		SachGiaoKhoa();
		void Nhap();
		void TinhTien();
};
SachGiaoKhoa::SachGiaoKhoa(){
	TinhTrang=0;		
}
void SachGiaoKhoa::Nhap(){
	LoaiSach::Nhap();
	cout<<"Nhap tinh trang(1.moi/2.cu): "<< endl; cin>>TinhTrang;
	while((TinhTrang!=1)&&(TinhTrang!=2)){
		cout<<"Nhap lai tinh trang(1.moi/2.cu): "<< endl; 
		cout<<"Moi ban nhap lai! ";
		cin>>TinhTrang;	
	};	
		TinhTien();
}
void SachGiaoKhoa::TinhTien(){
    if(TinhTrang==1){
    	ThanhTien= SoLuong * DonGia;
    }else{
    	ThanhTien= SoLuong * DonGia*(50/100);
	}	

}
class SachTK:public LoaiSach{
	protected:
		float Thue;
	public:
		SachTK();
		void Nhap();
		void TinhTien();
};
SachTK::SachTK(){
	Thue=0;
}
void SachTK::Nhap(){
	LoaiSach::Nhap();
	cout<<"Nhap thue(tu thue 5%-20% don gia): "<< endl;
	cin>>Thue;
	while((Thue<5)||(Thue>20)){
		cout<<"Nhap lai thue(tu thue 5%-20% don gia): "<< endl;
		cout<<"Moi ban nhap lai! ";
		cin>>Thue;
	}	
	TinhTien();	
}
void SachTK::TinhTien(){
	ThanhTien= SoLuong*DonGia+ Thue;
}
int main(){
	LoaiSach *ls[100];
	int n=0;
	int indexK[100], indexT[100];
	char Loai, Chon;
	cout<<setiosflags(ios::fixed)<<setprecision(1);
	int k=0, t=0;
	cout<<"Nhap thong tin loai sach: ";
	do{
		cout<<"Sach giao khoa hay Sach tham khoa(K/T): "<< endl;
		cin>>Loai;
		Loai= toupper(Loai);
		if(Loai=='K'){
			ls[n]= new SachGiaoKhoa;

			indexK[k++]==n;
		}
		else{
			ls[n]= new SachTK;
			indexT[t++]==n;
		}
		ls[n++]->Nhap();
		cout<<"Tiep tuc(C/K): "<<endl;
		cin>>Chon;
		Chon= toupper(Chon);
		if((n==100)||(Chon=='K')){
			break;
		}	
	}while(1);
	
	cout<<"Thong tin cac loai sach: "<< endl;
for(int i=0;i<n;i++){
		ls[i]->Xuat();
	}
	
	cout<<"\n--------------------------\n"<< endl;
	if(k>0){
		float tong=0;
		for(int i=0;i<k;i++){
			tong+= ls[indexK[i]]->getThanhTien();
		}
		cout<<"Tong thanh tien sach giao khoa: "<<tong<< endl;	
	}
	if(t>0){
		float ttong=0;
		for(int i=0;i<t;i++){
			ttong+= ls[indexT[i]]->getThanhTien();
		}
		cout<<"Tong thanh tien sach tham khao: "<<ttong<< endl;	
	}
	
	return 1;	
}
