#include <string.h>
#include <iostream>
#include <math.h>
#include <malloc.h>
#include <stdlib.h>
using namespace std;

class PhanSo {
	private:
		int mauso;
		int tuso;
	public:
		PhanSo operator +(PhanSo &);
		PhanSo operator- (PhanSo &);
		PhanSo operator* (PhanSo &);
		PhanSo operator/ (PhanSo &);
		int operator > (PhanSo );
		int operator < (PhanSo );
		int operator >= (PhanSo );
		int operator <= (PhanSo );
		int operator == (PhanSo );
		int operator != (PhanSo );
		PhanSo operator= (const PhanSo &);
		friend istream& operator >> (istream &, PhanSo&);
		friend ostream& operator << (ostream &, PhanSo&);
		float giaTriPS();
		void nhap();
		void xuat();
		int getMauso();
		int getTuso();
		int UCLN(int a, int b);
		PhanSo rutGon();
};
class MangPhanSo{
	private:
		int n;
		PhanSo p[100];
	public:
	void nhapPS();
	void xuatPS();
	void congPS();
};
	int PhanSo::getMauso(){
		return this->mauso;
	}
	int PhanSo::getTuso(){
		return this->tuso;
	}
	void PhanSo::nhap(){
		cout << "nhap tu:";
		cin >> tuso;
		cout << "nhap mau: ";
		cin >> mauso;
	}
	PhanSo PhanSo::rutGon(){
		int k = this->UCLN(this->mauso, this->tuso);
		this->tuso /= k;
		this->mauso /= k;
	}
	
	void MangPhanSo::nhapPS(){
		cout << "nhap so luong phan so: ";
		cin >> n;
		for(int i = 0; i < n; i++){
			cout << "Phan so " << i << ": " << endl;
			this->p[i].nhap();
			p[i].rutGon();
		}
	}
	void PhanSo::xuat(){
		cout << tuso << "/" << mauso << endl;
	}
	void MangPhanSo::xuatPS(){
		for (int i = 0; i < n; i ++){
			cout << "Phan so " << i << ": "; this->p[i].xuat();
		}
	}
	//UCLN la so ma n chia het:
	int PhanSo::UCLN(int a, int b){
		abs(a);
		abs(b);
		while (a != b)
			if(a > b)
				a -= b;
			else 
				b -= a;
		return a;
	}
	float PhanSo::giaTriPS(){
		return this->tuso / this->mauso;
	}
	PhanSo PhanSo::operator +(PhanSo &p){
		PhanSo p1;
		p1.mauso = this->mauso * p.mauso;
		p1.tuso = this->tuso * p.mauso + p.tuso * this->mauso;
		p1.rutGon();
		return p1;
	}
	
	PhanSo PhanSo::operator- (PhanSo &p){
		PhanSo p1;		
		p1.mauso = this->mauso * p.mauso;
		p1.tuso = this->tuso * p.mauso - p.tuso * this->mauso;
		p1.rutGon();
		return p1;
	}
	PhanSo PhanSo::operator* (PhanSo &p){
		PhanSo p1;
		p1.mauso = this->mauso * p.mauso;
		p1.tuso = this->tuso * p.tuso;
		p1.rutGon();
		return p1;
	}
	PhanSo PhanSo::operator/ (PhanSo &p){
		PhanSo p1;
		p1.mauso = this->mauso * p.tuso;
		p1.tuso = this->tuso * p.mauso;
		p1.rutGon();
		return p1;
	}
	istream &operator >> (istream &is, PhanSo &p){
		cout << "nhap phan so : " << endl;
		cout << "tu: ";
		is >> p.tuso;
		cout << "mau: ";
		is >> p.mauso;
		return is;
	}
	ostream &operator << (ostream &os, PhanSo &p){
		os << p.tuso << "/" << p.mauso ;
		return os;
	}
	PhanSo PhanSo::operator =(const PhanSo &p){
		tuso = p.tuso;
		mauso = p.mauso;
		return *this;
	}
	int PhanSo::operator > (PhanSo p){
		if(this->giaTriPS() > p.giaTriPS())
			return 1;
		else 
			return 0;
	}
	int PhanSo::operator < (PhanSo p){
	if(this->giaTriPS() < p.giaTriPS())
		return 1;
	else 
		return 0;
	}
	int PhanSo::operator >= (PhanSo p){
	if(this->giaTriPS() >= p.giaTriPS())
		return 1;
	else 
		return 0;
	}
	int PhanSo::operator <= (PhanSo p){
	if(this->giaTriPS() <= p.giaTriPS())
		return 1;
	else 
		return 0;
	}	
	int PhanSo::operator == (PhanSo p){
	if(this->giaTriPS() == p.giaTriPS())
		return 1;
	else 
		return 0;
	}
	int PhanSo::operator != (PhanSo p){
		if(this->giaTriPS() != p.giaTriPS())
			return 1;
		else 
			return 0;
	}
	void MangPhanSo::congPS(){
		PhanSo tam = p[0];
		for(int i = 1; i < n; i++){
			tam = tam + p[i];
		}
		tam.xuat();	
	}
	
	int main(){
 		PhanSo p1, p2, p3, p4;
 		system("cls");
 		MangPhanSo p;
		p.nhapPS();
		p.xuatPS();
//		p2.nhap();
//		p1.nhap();
//		p3 = p1 + p2;
//		p3.xuat();
//		cin >> p4;
//		p4.xuat();
		p.congPS();
		return 0;
	}
		

