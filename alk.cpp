#include<string.h>
#include<iostream>
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
		char hoTen[32];
		char ngaySinh[32];
		float tienLuong;
	public:
		NhanVien(){
			strcpy(maSo,"");
			strcpy(hoTen,"");
			strcpy(ngaySinh,"");
			tienLuong = 0;
		}					
		char *getMaSo();
		char *getHoTen();
		float getTienLuong();
		void setTienLuong(float l);
		virtual void nhap();
		void xuat();
		virtual void tinhTienLuong() = 0;
};



class NhanVienSanXuat:public NhanVien{
	private:
		int soLuong;
	public:
		NhanVienSanXuat(){
		this->soLuong = 0;
		}
		int getSoLuong();
		void nhap();
		void tinhTienLuong();
	
};




class NhanVienQuanLy:public NhanVien{
	private:
		float heSoLuong;
		float tienThuong;
	public:
		NhanVienQuanLy(){
			this->heSoLuong = this->tienThuong = 0;
		}
		float getTienThuong();
		void nhap();
		void tinhTienLuong();
		
};

//NhanVien
void NhanVien::nhap(){
	cout << "Ma So Nhan Vien: "; cin >> this->maSo; cin.ignore();
	cout << "Ho Ten Nhan Vien: "; cin.getline(this->hoTen, 32);
	cout << "Ngay sinh: "; cin >> this->ngaySinh;
}

float NhanVien::getTienLuong(){
	return this->tienLuong;
}

char *NhanVien::getMaSo(){
	return this->maSo;
}

char *NhanVien::getHoTen(){
	return this->hoTen;
}

void NhanVien::setTienLuong(float l){
	this->tienLuong = l;
}

void NhanVien::xuat(){
	cout << "Ma So: " << this->maSo << endl;
	cout << "Ho Ten: " << this->hoTen << endl;
	cout << "Ngay Sinh: " << this->ngaySinh << endl;
	cout << "Tien Luong: " << this->tienLuong  << " Nghin dong"<< endl;
}



//QuanLy
void NhanVienQuanLy::nhap(){
	NhanVien::nhap();
	do{
	cout << "He So Luong(2.0 to 5.0): "; cin >> this->heSoLuong;
	}while(not(this->heSoLuong >= 2 && this->heSoLuong <= 5));
	cout << "Tien Thuong(nghin): "; cin >> this->tienThuong;
	this->tinhTienLuong();
}

void NhanVienQuanLy::tinhTienLuong(){
	float tam = 0;
	tam = LCBQL * this->heSoLuong + this->tienThuong;
	this->setTienLuong(tam);
}

float NhanVienQuanLy::getTienThuong(){
	return this->tienThuong;
}



//SanXuat
void NhanVienSanXuat::nhap(){
	NhanVien::nhap();
	cout << "So San Pham: "; cin >> this->soLuong;
	this->tinhTienLuong();
}

void NhanVienSanXuat::tinhTienLuong(){
	float tam = 0;
	tam = LCBSX + (this->soLuong * SP);
	this->setTienLuong(tam);
}

int NhanVienSanXuat::getSoLuong(){
	return this->soLuong;
}


int main(){
	NhanVien *nv[MAX];
	char loai, chon;
	int dSQL[MAX], dSSX[MAX];
	int n = 0, q = 0, s = 0;
	cout << "Nhap Nhan Vien: " << endl;
	do{
		cout << "Nhap Loai Nhan Vien(Q/S): "; cin >> loai;
		if(toupper(loai) == 'Q'){
			nv[n] = new NhanVienQuanLy;
			dSQL[q++] = n;
		}
		else if(toupper(loai) == 'S'){
			nv[n] = new NhanVienSanXuat;
			dSSX[s++] = n;
		}
		else cout << "Khong Hop le!";
		nv[n++]->nhap();
		cout << "\n";
		cout << "Tiep Tuc(C/K): "; cin >> chon;
		if(toupper(chon) == 'K' || n == 100)
			break;
		
	}while(1);
	
	cout << "Xuat DS Nhan Vien: " << endl;
	for(int i = 0; i < n; i++){
		cout << i + 1 << "/" << "\n";
		nv[i]->xuat();
		
	}
	
	//May chan:
	cout << "May chan: " << endl;
	int tongSP = 0;
	for( int i = 0; i < s; i++){
		tongSP += ((NhanVienSanXuat*)nv[dSSX[i]])->getSoLuong();
	}
	cout << "Tong so san pham ma nhan vien san xuat thuc hien: " << tongSP << endl;
	
	float max = nv[0]->getTienLuong();
	for( int i = 1; i < n; i++){
		if(max < nv[i]->getTienLuong())
			max = nv[i]->getTienLuong();
	}
	cout << "Tien luong cao nhat cua cac nhan vien: " << max << " Nghin dong."<< endl;
	
	char ms[10];
	cout << "Nhap ma so can tim: "; cin >> ms; cin.ignore();
	cout << "Nhan Vien co ma so can tim: " << endl;
	for(int i = 0; i < n; i++){
		if(stricmp(ms, nv[i]->getMaSo()) == 0){
			nv[i]->xuat();
			cout << "\n";
			break;
		}
	}
	//May le
	float tongTT = 0;
	for(int i = 0; i < q; i++){
		tongTT += ((NhanVienQuanLy*)nv[dSQL[i]])->getTienThuong();
	}
	cout << "Tong tien thuong cua nhung nhan vien quan ly: " << tongTT << " Nghin dong" << endl;
	
	float tBLuong = 0, tongLuong = 0;
	for(int i = 0; i < n; i++){
		tongLuong += nv[i]->getTienLuong();
	}
	tBLuong = tongLuong / n;
	cout << "Cac nhan vien co luong cao hon tBLuong: " << endl;
	for(int i = 0; i < n; i++){
		if(nv[i]->getTienLuong() > tBLuong){
			nv[i]->xuat();
			cout << "\n" << endl;
		}
	}
	
	NhanVien *tam;
	for(int i = 0; i < n-1; i++){
		for(int j = i + 1; j < n; j++){
			if(stricmp(nv[i]->getHoTen(), nv[j]->getHoTen()) == 1){
				tam = nv[i];
				nv[i] = nv[j];
				nv[j] = tam;
			}
		}
	}
	cout << "DS nhan vien duoc sap xep tang dan theo ho ten: " << endl;
	for(int i = 0; i < n; i++){
		cout << i + 1 << "/" << endl;
		nv[i]->xuat();
	}
	getch();
	return 0;	
}


