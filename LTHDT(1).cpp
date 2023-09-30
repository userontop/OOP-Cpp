#include <iostream>
#include <cstring>
#include <io.h>
#include <fcntl.h>
using namespace std;
class Student {
private:
	char ID[20];
	char name[100];
	int age;
	float mark;
	char address[100];
	char subject[100];
	char subName[100];
	float amount;
	// ham huy- ham khoi tao
	//ham khoi tao
public:
	Student();
	Student(char *name, int age);
	void showIdCard();
	void study(char *subject);
	void doExample(char* subjName);
	void payFee(float amount);
	void setID(char*);
	void setName(char*);
	void setAge(int);
	void setMark(float);
	void setAddress(char*);
	
	char* getID();
	char* getName();
	char* getAddress();
	int getAge();
	float getMark();
	//ham huy

	// ~Student(){
	// 	cout << "Call destructor" << endl;
	// }

};

Student::Student(){
		cout << "Call non para constructor" << endl;
		this->name[0] = '\0';
		this->ID[0] = '\0';
		//this or ko
		address[0] = '\0';
		age = 0;
		mark = 0; 	
	}
Student::Student(char *name, int age){
		cout << "Call 2 para constructor" << endl;
		strcpy(this->name, name); //strcpy_s: coppy( thuoc tinh, sl ky tu, tham so);
		this->ID[0] = '\0';
		//this or ko: su dung this de phan biet thuoc tinh vs tham so
		address[0] = '\0';
		this->age = age;//this->age la thuoc tinh, age la tham so
		mark = 0; 	
	}
void Student::showIdCard(){
	cout << "======================ID_Student======================"<< endl;
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "Mark: " << mark << endl;
	cout << "Address: " << address << endl;
	cout << "======================================================" << endl;
}
void Student::setID(char* id){
	strcpy(this->ID, id);
}
void Student::setName(char* Name){
	strcpy(this->name, Name);
}
void Student::setAge(int Age){
	this->age = Age;
}
void Student::setMark(float Mark){
	this->mark = Mark;
}
void Student::setAddress(char* Address){
	strcpy(this->address, Address);
}
char* Student::getID(){
	return this->ID;
}
char* Student::getName(){
	return this->name;
}
char* Student::getAddress(){
	return this->address;
}
int Student::getAge(){
	return this->age;
}
float Student::getMark(){
	return this->mark;
}
void Student::study(char *subject){
	
}
void Student::doExample(char *subjName){

}
void Student::payFee(float amount){

}

class Cat{
public:
	char name[100];
	int age;
	float weight;
	char color[100];
	char eyecolor[100];
	
	void move();
	void sleep();
	void eat();
	void speak();
	
};

int main(){
	char* name = new char[100];
	strcpy(name, "Ton Thien Tam");
	Student sv1;
	cout << "khoi tao trong" << endl;
	sv1.showIdCard();
//	Student s1;//goi ham khoi tao
	Student s2(name, 20); //goi ham tao 2 tham so
//	sv1.age = 20;
//	cout << "age: " << sv1.age << endl;
	cout << "khoi tao 2 tham so" << endl;
	s2.showIdCard();
	sv1.setAge(20);
	sv1.setName(name);
	sv1.setAddress("long xuyen");
	sv1.setID("A0234");
	sv1.setMark(8.3);
	cout << "dong goi du lieu" << endl;
	sv1.showIdCard();
	return 0;
}


