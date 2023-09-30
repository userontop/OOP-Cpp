#include <iostream>
using namespace std;
class Hinh{
	public:
		virtual void ve(){
			cout << "Ve Hinh" << endl;
		}
};

class HinhTron:public Hinh{
	int r;
	public:
		void ve(){
			cout << "Ve hinh Tron" << endl;
		}
};

class HinhChuNhat:public Hinh{
	int d, r;
	public:
		void ve(){
			cout << "Ve hinh chu nhat" << endl;
		}
};

int main(){
	Hinh *h = new HinhTron;
	Hinh *g = new Hinh;
	Hinh *c = new HinhChuNhat;
	g->ve();
	h->ve();
	c->ve();
	return 0;
}
