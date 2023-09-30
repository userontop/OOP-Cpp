#include<iostream>// cout , cin
#include<string.h>// strcmp ...
#include<math.h>//sqrt...
#include<conio.h>//getch()
using namespace std;
#define MAX 100
#define LCB 1150000
class MangNhanVien{
	private:
		NhanVien *nv[MAX];
		int n;
		char loai, chon;
	public:
		void xuat();
		void nhap();
};

class NhanVien{
	private:
		char maSo[6];
		char ten[32];
		float luong;
	public:
		NhanVien();
		virtual void tinhLuong() = 0;
		void xuat();
		virtual void nhap();
		float getLuong();
		
};

class BienChe:public NhanVien{
	private:
		float heSoLuong;	
		float heSoPhuCap;
	public:
		BienChe();
		void tinhLuong();
		void nhap();
};

class HopDong:public NhanVien{
	private:
		float tienCong;
		float ngayCong;
	public:
		HopDong();
		void tinhLuong();
		void nhap();
};
//Mang Nhan Vien:
void MangNhanVien::nhap(){
	cout << "Nhap thong tin cho cac Nhan Vien: " << endl;
	do{
		do{
			cout << "Phan loai Bien Che or Hop Dong (B/H): ";
			cin >> this->loai; loai = toupper(loai);
			if(loai = 'B')
				nv[n] = new BienChe;
			else if(loai = 'H')
				nv[n] = new HopDong;
			else 
				cout << "Gia tri khong hop le!" << endl;
		}while(loai = 'B' || loai = 'H')
		nv[n++]->nhap();
		cout << "Them (Y/N)"; cin >> this->chon;
		this->chon = toupper(chon);
		if(N = 100 || Chon = 'N')
			break;
	}while(1)
}

void MangNhanVien::xuat(){
	for(int i = 0; i < n; i++){
	}
}


//Nhan VIen:
NhanVien::NhanVien(){
	strcpy(maSo, "");
	strcpy(ten, "");
	luong = 0;
}

BienChe::BienChe(){
	this->heSoLuong = this->heSoPhuCap = 0;
}

HopDong::HopDong(){
	this->ngayCong = this->tienCong = 0;
}

void NhanVien::nhap(){
	cout << "Ma so: "; cin >> this->maSo;
	cin.ignore(); //xoa dau enter truoc khi nhap
	cout << "Ten: "; cin.getline(this->ten, 32);
}

float NhanVien::getLuong(){
	return this->luong;
}

void NhanVien::Xuat(){
	cout << "Ma so: " << this->maSo << "-" << "Ten: " << this->ten << "-" << "Luong: " << this->luong << endl;
}

//Bien CHe
void BienChe::nhap(){
	do{
		cout << "He so luong: "; cin >> this->heSoLuong;
		if (not(this->heSoLuong >= 1 && this->heSoLuong <= 13)){
			cout << " Gia tri khong hop le!" << endl;
		}
	}while(this->heSoLuong >= 1 && this->heSoLuong <= 13);
	
	do{
		cout << "He so phu cap: "; cin >> this->heSoPhuCap;
		if (not(this->heSoPhuCap >= 0 && this->heSoPhuCap <= 2)){
			cout << " Gia tri khong hop le!" << endl;
		}
	}while(this->heSoPhuCap >= 0 && this->heSoPhuCap <= 2);
}

void BienChe::tinhLuong(){
	return this->getLuong() = LCB * (this->heSoLuong + this->heSoPhuCap);
	
}

// Hop Dong:

void HopDong::nhap(){
	cout << "Ngay cong: "; cin >> this->ngayCong;
	cout << "Tien cong: "; cin >> this->tienCong;
	if(this->ngayCong >= 24)
		this->tienCong *= 1.2;
}

void HopDong::tinhLuong(){
	return this->getLuong() = this->tienCong * this->ngayCong;
}
int main(){
	
	
	
	getch();
	return 0;
}


