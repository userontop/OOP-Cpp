/*
1. Su dong goi.
2. Tinh ke thua.
	- lop dan xuat?
	- Lop co so?
	- Da ke thua, don ke thua.
3. Tinh da hinh: 
*/
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
int main(){
	int n;
	cout << "nhap n: " << endl;
	cin >> n;
	int *p;
	p = new int[n];
//	for( int i = 0; i < n; i++){
//		cout << "Nhap phan tu thu: " << i+1 << endl;
//		cin >> *(p + i);
//	}
	srand((unsigned)time(NULL));
	for(int i = 0; i < n; i++){
		*(p+i) = rand()%99 + 1;
	}
	
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			if (*(p+i) > *(p + j))
			swap(*(p+i), *(p+j));
		}
	}
	
	for( int i = 0; i < n; i++){
		cout << *(p + i) << "\t";
	}
	return 0;
}
