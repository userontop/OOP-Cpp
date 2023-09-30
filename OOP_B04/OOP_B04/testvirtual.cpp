
#include<iostream>
#include<string.h>
using namespace std;

class lop1{
	public:
		int *a, *b;
		virtual int cong();
};

class lop2:public lop1{
	public:
		int cong(){
			return *a - *b;
		}
};

class lop3:public lop1{
	public:
		int cong(){
			return *a * *b;
		}
};


int lop1::cong(){
	int c = *a + *b;
	return c;
}



int main(){
	lop1 *t;
	int *c;
	cin >> *c;
	cout << "tong cua lop 1: " << t->cong() << endl;
	lop2 t2;
	cout << "tong cua lop 2: " << t2.cong() << endl;	
	lop3 t3;
	cout << "tong cua lop 3: " << t3.cong() << endl;		
	return 0;
}

//
//
//#include<iostream>
//#include<conio.h>
//using namespace std;
//class sun
//{
//    public:
//      virtual void showcty()
//      {
//                cout<<"\n  Hien thi sun:";
//      }
//      void display()
//      {
//              cout<<"\n  Trung bay sun:" ;
//      }
//};
// 
//class kethua:public sun
//{
//   public:
//      void display()
//      {
//              cout<<"\n  Trung bay sun1:";
//      }
//      void showcty()
//      {
//              cout<<"\n  Hien thi sun1:";
//      }
//};
// 
//int main()
//{
//   
//   sun obj1;
//   sun *p;
//   cout<<"\n P tro toi sun:\n"  ;
// 
//   p=&obj1;
//   p->display();
//   p->showcty();
// 
//   cout<<"\n\n P tro toi sun1:\n";
//   kethua obj2;
//   p=&obj2;
//   p->display();
//   p->showcty();
//   return 0;
//}

