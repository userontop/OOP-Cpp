#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <iomanip>
#include <iostream>
using namespace  std;

class NhanVien
{
	protected:
		char MSNV[10];
		char HoTenNV[50];
		char NgaySinh[12];
		//sua
		float TienLuong;
	public:
		NhanVien();
		virtual void Nhap();
		void Xuat();
		virtual void TinhTienLuong() = 0;
		
		char *getMSNV();
		char *getHoTenNV();
		char *getNgaySinh();
		float getTienLuong();
};

NhanVien::NhanVien()
{
	strcpy(MSNV,"");
	strcpy(HoTenNV,"");
	strcpy(NgaySinh,"");
	TienLuong = 0;
}

void NhanVien::Nhap()
{
	cout << "\nNhap ma so nhan vien    : "; cin >> MSNV;
	cout << "Nhap ho ten nhan vien   : "; cin >> HoTenNV;
	cout << "Nhap ngay sinh nhan vien: "; cin >> NgaySinh;
}

void NhanVien::Xuat()
{
	cout << "\nMSNV      : " << MSNV << endl;
	cout << "Ho ten    : " << HoTenNV << endl;
	cout << "Ngay sinh : " << NgaySinh << endl;
	cout << "Tien luong: " << this->TienLuong << endl;
	
}

char *NhanVien::getMSNV()
{
	return MSNV;
}

char *NhanVien::getHoTenNV()
{
	return HoTenNV;
}

char *NhanVien::getNgaySinh()
{
	return NgaySinh;
}

float NhanVien::getTienLuong()
{
	return TienLuong;
}

class NhanVienQuanLy:public NhanVien
{
	protected:
		float LCB;
		float HeSoLuong;
		float TienThuong;
	public:
		NhanVienQuanLy();
		void Nhap();
		void TinhTienLuong();
		float getTienThuong();
};

NhanVienQuanLy::NhanVienQuanLy()
{
	LCB = HeSoLuong = TienThuong = 0;
}

void NhanVienQuanLy::Nhap()
{
	NhanVien::Nhap();
	do
	{
		cout << "Nhap he so luong: [2.0 - 5.0]: "; cin >> HeSoLuong;
	}while(HeSoLuong < 2 || HeSoLuong > 5);
	
	do
	{
		cout << "Nhap tien thuong (< 3000000): "; cin >> TienThuong;
	}while(TienThuong > 3000000);
}

void NhanVienQuanLy::TinhTienLuong()
{
	LCB = 3000000;
	TienLuong = LCB * HeSoLuong + TienThuong;
}

float NhanVienQuanLy::getTienThuong()
{
	return TienThuong;
}

class NhanVienSanXuat:public NhanVien
{
	protected:
		float LCB;
		float TienCong1SP;
		float SoSanPham;
	public:
		NhanVienSanXuat();
		void Nhap();
		void TinhTienLuong();	
		float getSoSanPham();
};

NhanVienSanXuat::NhanVienSanXuat()
{
	LCB = TienCong1SP = SoSanPham = 0;
}

void NhanVienSanXuat::Nhap()
{
	NhanVien::Nhap();
	do
	{
		cout << "Nhap so san pham: "; cin >> SoSanPham;
	}while(SoSanPham > 400);
}

void NhanVienSanXuat::TinhTienLuong()
{
	LCB = 2400000;
	TienCong1SP = 10000;
	TienLuong = LCB + (SoSanPham * TienCong1SP);
}

float NhanVienSanXuat::getSoSanPham()
{
	return SoSanPham;
}

int main()
{
	NhanVien *nv[100]; int n = 0;
	char Chon, Loai;
	float tongsosp = 0, tongtienthuong = 0;
	int indexQL[100], indexSX[100];
	int q = 0, s = 0;
	cout << setiosflags(ios::fixed)<<setprecision(3);
	cout << "Nhap thong tin cho cac nhan vien: " << endl;
	do
	{
		cout << "\nQuan ly hay san xuat (Q/S)? ";
		cin >> Loai;	Loai = toupper(Loai);
		if(Loai == 'Q')
		{
			nv[n] = new NhanVienQuanLy;
			//tongtienthuong += nv[n]->getTienThuong();
//			((NhanVienQuanLy*)nv[n])->Nhap();
			indexQL[q++] = n;
		}
		else if(Loai == 'S')
		{
			nv[n] = new NhanVienSanXuat;
			//tongsosp += nv[n]->getSoSanPham();
//			((NhanVienSanXuat*)nv[n])->Nhap();
			indexSX[s++] = n;
		}
		nv[n++]->Nhap();
		cout<<"\nTiep tuc (C/K)? ";	cin>>Chon;
		Chon=toupper(Chon);
		if((n == 100) || (Chon == 'K'))
		{
			break;
		}
	}while(1);
	
	cout << "\nThong tin cua cac nhan vien vua nhap: " << endl;
	for(int i = 0; i < n; i++)
	{
		nv[i]->TinhTienLuong();
		nv[i]->Xuat();
	}
	
	//De le
	cout << "\nTong so san pham ma cac nhan vien san xuat da thuc hien: " << endl;
	int tongso = 0;
//	do{
//		s--;
//		tongso += ((NhanVienSanXuat*)nv[indexSX[s]])->getSoSanPham();
//	}while(not(s >= 0);

	for(int i = 0; i < s; i++){
		tongso += ((NhanVienSanXuat*)nv[indexSX[i]])->getSoSanPham();		
	}
	cout << tongso << endl;
	
	
	float maxluong = 0;
	for(int i = 0; i < n; i++)
	{
		if(nv[i]->getTienLuong() >= maxluong)
		{
			maxluong = nv[i]->getTienLuong();
		}
	}
	cout << "\nTien luong cao nhat cua cac nhan vien: " << maxluong << endl;
	
	char msct[10]; int d = 0;
	cout << "\nNhap ma so can tim: "; cin >> msct;
	for(int i = 0; i < n; i++)
	{
		if(stricmp(msct, nv[i]->getMSNV()) == 0)
		{
			nv[i]->Xuat();
			cout << endl;
			d++;
		}
	}
	if(d == 0)
	{
		cout << "\nKhong tim thay thong tin nhan vien co ma so can tim!" << endl;
	}
	
	
	
	//De chan
	cout << "\nTong tien thuong cua nhung nhan vien quan ly: " << endl;
	
	float tongtien = 0;
//	do{	
//		q--;
//		tongtien += ((NhanVienQuanLy*)nv[indexQL[q]])->getTienThuong();
//	}while(not(q >= 0));
//	
	for(int i = 0; i < q; i++){
		tongtien += ((NhanVienQuanLy*)nv[indexQL[i]])->getTienThuong();	
	}	

	cout << tongtien << endl;
	
	
	cout << "\nNhung nhan vien co luong cao hon trung binh luong cua cac nhan vien trong doanh nghiep: " << endl;
	float tongluong = 0;
	for(int i = 0; i < n; i++)
	{
		tongluong += nv[i]->getTienLuong();
	}
	for(int i = 0; i < n; i++)
	{
		if(nv[i]->getTienLuong() > (tongluong / n))
		{
			nv[i]->Xuat();
		}
	}
	
	cout << "\nSap xep danh sach tang dan theo ho ten: " << endl;
	NhanVien *temp;
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(stricmp(nv[i]->getHoTenNV(), nv[j]->getHoTenNV()) > 0)
			{
				temp = nv[i];
				nv[i] = nv[j];
				nv[j] = temp;
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		nv[i]->Xuat();
	}
	
	
	getch();
	return 1;
}

