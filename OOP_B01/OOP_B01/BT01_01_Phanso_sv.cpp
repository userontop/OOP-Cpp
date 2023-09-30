#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <iostream>
using namespace  std;
class PhanSo
{
public:
	int Tuso;
	int Mauso;
public:
	//Ham dung
	PhanSo();
	PhanSo(int, int);
	PhanSo(const PhanSo&);
	void Nhap();
	void Xuat();
	
	int Uscln(int a, int b);
	void RutGon();
	float GiatriPS();
	
	
	//Phuong thuc tinh toan
	PhanSo Cong(PhanSo ps);
	PhanSo Tru(PhanSo ps);
	PhanSo Nhan(PhanSo ps);
	PhanSo Chia(PhanSo ps);
	
	//Nhap - Xuat bang luong
	friend istream& operator >> (istream &is, PhanSo &p);
	friend ostream& operator << (ostream &os, PhanSo &p);
	
	//Toan tu gan 
	PhanSo operator= ( const PhanSo &p);
	
	//Cac phep toan dung Toan tu
	PhanSo operator+(PhanSo );
	PhanSo operator-(PhanSo );
	PhanSo operator*(PhanSo );
	PhanSo operator/(PhanSo );
	
	//Toan tu So sanh
	int operator > (PhanSo);
	int operator < (PhanSo);
	int operator >= (PhanSo);
	int operator <= (PhanSo);
	int operator == (PhanSo);
	int operator != (PhanSo);
	//Ham huy
//	~PhanSo(){
//		cout << "\nHam huy!" << endl;
//	}
//	
};

int main()
{
	PhanSo a,b,c;
	cout<<"\n Nhap phan so A "; cin >> a;
	cout<<"\n Phan so vua nhap "; a.Xuat();
	cout<<"\n Nhap phan so B "; b.Nhap();
	cout<<"\n Phan so vua nhap "; cout << b;
	
	a.RutGon(); b.RutGon();
	
	cout<<"\n A sau khi toi gian "; a.Xuat();
	cout<<"\n B sau khi toi gian "; b.Xuat();
	
	cout<<endl;
	cout << "\n Gia tri phan so A: " << a.GiatriPS();
	cout << "\n Gia tri phan so B: " << b.GiatriPS();
	c = a.Cong(b);
	cout << "\n Cong 2 phan so: " << c << endl;
	c = a.Tru(b);
	cout << "\n Tru hai phan so: " << c <<endl;
	c = a.Nhan(b);
	cout << "\n Nhan hai phan so: " << c << endl;
	c = a.Chia(b);
	cout << "\n Chia hai phan so: " << c << endl;
	if(a > b)
		cout << a << " > " << b << endl;
	else if(a == b)
		cout << a << " == " << b << endl;
	else
		cout << a << " < " << b << endl;
	c = a + b;
	cout << a << " + " << b << " = " << c << endl;
	c = a - b;
	cout << a << " - " << b << " = " << c << endl;
	c = a * b;
	cout << a << " * " << b << " = " << c << endl;
	c = a / b;
	cout << a << " / " << b << " = " << c << endl;
	getch();
	return 1;
}

PhanSo::PhanSo()
{
	Tuso = 0;	Mauso = 1;
}

PhanSo::PhanSo(const PhanSo &p)
{
	Tuso = p.Tuso;	Mauso = p.Mauso;
}

PhanSo::PhanSo(int t, int m)
{
	Tuso = t; Mauso = m;
}


void PhanSo::Nhap()
{
	cout<<"\n Nhap Tu so "; cin>>Tuso;
	cout<<"\n Nhap Mau so "; cin>>Mauso;
	while(Mauso==0)
	{
		cout<<"\n Mau so phai khac 0 - Nhap lai Mau so : ";cin>>Mauso;
	};
}

void PhanSo::Xuat()
{
	cout<<Tuso<<"/"<<Mauso<<" ";
}

float PhanSo::GiatriPS()
{
	return (float) (Tuso)/(float)(Mauso);
}

PhanSo PhanSo::Cong(PhanSo ps)
{
	
	PhanSo tam;
	tam.Tuso=Tuso*ps.Mauso+Mauso*ps.Tuso;
	tam.Mauso=Mauso*ps.Mauso;
	RutGon();
	return tam;
}
PhanSo PhanSo::Tru(PhanSo ps)
{
	PhanSo tam;
	tam.Tuso=Tuso*ps.Mauso-Mauso*ps.Tuso;
	tam.Mauso=Mauso*ps.Mauso;
	RutGon();
	return tam;
}
PhanSo PhanSo::Nhan(PhanSo ps)
{
	PhanSo tam;
	tam.Tuso=Tuso*ps.Tuso;
	tam.Mauso=Mauso*ps.Mauso;
	RutGon();
	return tam;
}
PhanSo PhanSo::Chia(PhanSo ps)
{
	PhanSo tam;
	tam.Tuso=Tuso*ps.Mauso;
	tam.Mauso=Mauso*ps.Tuso;
	RutGon();
	return tam;
}

//int k= Uscln(Tuso,Mauso);
int PhanSo::Uscln(int a, int b)
{	
	a = abs(a);
	b = abs(b);
	while(a != b){
		if(a > b)
			a -= b;
		else
			b -= a;
	}
	return a;
}


void PhanSo::RutGon()
{
	if(this->Mauso < 0){
		this->Tuso *= -1;
		this->Mauso *= -1;
	}
	int k = Uscln(Tuso,Mauso);
	if(this->Tuso == 0){
		Mauso = Mauso/k;
	}
	else{
		Tuso = Tuso/k;
		Mauso = Mauso/k;
	}
}
istream& operator >> (istream &is, PhanSo &p){
	cout << "\n Tu so: ";
	is >> p.Tuso;
	cout << " Mau so: ";
	is >> p.Mauso;
	return is;
}
ostream& operator << (ostream &os, PhanSo &p){
	os << p.Tuso << "/" << p.Mauso;
	return os;
}

PhanSo PhanSo::operator = (const PhanSo &p)
{
	this->Tuso = p.Tuso;
	this->Mauso = p.Mauso;
	return *this;
}

PhanSo PhanSo::operator + (PhanSo p)
{
	PhanSo tam;
	tam.Tuso = Tuso*p.Mauso+Mauso*p.Tuso;
	tam.Mauso = Mauso*p.Mauso;
	tam.RutGon();
	return tam;
}
PhanSo PhanSo::operator - (PhanSo p)
{
	PhanSo tam;
	tam.Tuso = Tuso*p.Mauso-Mauso*p.Tuso;
	tam.Mauso = Mauso*p.Mauso;
	tam.RutGon();
	return tam;
}
PhanSo PhanSo::operator * (PhanSo p)
{
	PhanSo tam;
	tam.Tuso = Tuso*p.Tuso;
	tam.Mauso = Mauso*p.Mauso;
	tam.RutGon();
	return tam;
}
PhanSo PhanSo::operator / (PhanSo p)
{
	PhanSo tam;
	tam.Tuso = Tuso*p.Mauso;
	tam.Mauso = Mauso*p.Tuso;
	tam.RutGon();
	return tam;
}


int PhanSo::operator > (PhanSo p)
{
	if( GiatriPS() > p.GiatriPS())
		return 1;
	else
		return 0;
}
int PhanSo::operator < (PhanSo p)
{
	if( GiatriPS() < p.GiatriPS())
		return 1;
	else
		return 0;
}

int PhanSo::operator >= (PhanSo p)
{
	if( GiatriPS() >= p.GiatriPS())
		return 1;
	else
		return 0;
}
int PhanSo::operator <= (PhanSo p)
{
	if( GiatriPS() <= p.GiatriPS())
		return 1;
	else
		return 0;
}
int PhanSo::operator == (PhanSo p)
{
	if( GiatriPS() == p.GiatriPS())
		return 1;
	else
		return 0;
}
int PhanSo::operator != (PhanSo p)
{
	if( GiatriPS() != p.GiatriPS())
		return 1;
	else
		return 0;
}




