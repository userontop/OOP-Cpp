#include <iostream>

using namespace std;

int t = 12;

main(){
	int a = 32;
	while(a != ::t)
		if(a > t)
			a-= t;
		else
			t-= a;
	
	cout << a << endl;
	
	cout << t << endl;
}
