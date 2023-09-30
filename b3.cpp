#include<iostream>
using namespace std;
class SoPhuc{
	private:
		int pthuc;
		int ao;
	public:
		SoPhuc(){
			pthuc = 5;
			ao = 3;
		}
		void xuat(){
			cout << pthuc << "," << ao << endl;
		}
		friend void Cong2sophuc(SoPhuc a, SoPhuc b); // co the goi phan thuc va ao ma khong can ke thua
};

void Cong2sophuc(SoPhuc a, SoPhuc b){
	SoPhuc c;
	c.pthuc = a.pthuc + b.pthuc;
	c.ao = a.ao + b.ao;
	c.xuat();
}
int main(){
	SoPhuc a, b, c;
	Cong2sophuc(a,b);
	return 0;
}
