#include <cstring>
#include <iostream>
#include <io.h>
#include <fcntl.h>
using namespace std;

class Person {
private:
    char surName[20];
    char firstName[20];
    char lastName[20];
    char sex[3];
    int age;
    char address[100];
    char mobile[11];
public:
    Person();
    Person(char *sur, char* first, char* last, char* SEX, int age, char* add, char* mobi);
    void showID();
    void setSurName(char*);
    void setFirstName(char*);
    void setLastName(char*);
    void setAge(int);
    void setSex(char*);
    void setAddress(char*);
    void setMobile(char*);

    char* getSurName();
    char* getFirstName();
    char* getLastName();
    char* getSex();
    float getAge();
    char* getAddress();
    char* getMobile();

};
    Person::Person(){
        this->surName[0] = '\0';
        this->firstName[0] = '\0';
        this->lastName[0] = '\0';
        this->age = 0;
        this->address[0] = '\0';
        this->sex[0] = '\0';
        this->mobile[0] = '\0';
    }

    Person::Person(char *sur, char *first, char *last, char *SEX, int age, char *add, char *mobi){
        strcpy(this->surName, sur);
        strcpy(this->firstName, first);
        strcpy(this->lastName, last);
        strcpy(this->sex, SEX);
        strcpy(this->address, add);
        strcpy(this->mobile, mobi);
        this->age = age;
    }

    void Person::showID(){
        cout << "===============================ID===============================" << endl;
        cout << "SurName: " << surName << endl << "FirstName: " << firstName << endl << "LastName: " << lastName << endl << "Sex: " << sex << endl << "Age: " << age << endl << "Address: " << address << endl << "Mobile: " << mobile << endl;
    }

    void Person::setSurName(char* sur){
        strcpy(this->surName, sur);
    }
    void Person::setFirstName(char* first){
        strcpy(this->firstName, first);
    }
    void Person::setLastName(char* last){
        strcpy(this->lastName, last);
    }
    void Person::setAge(int age){
        this->age = age;
    }
    void Person::setSex(char* sex){
        strcpy(this->sex, sex);
    }
    void Person::setAddress(char* address){
        strcpy(this->address, address);
    }
    void Person::setMobile(char* mobi){
        strcpy(this->mobile, mobi);
    }

    char* Person::getSurName(){
        return this->surName;
    }
    char* Person::getFirstName(){
        return this->firstName;
    }
    char* Person::getLastName(){
        return this->lastName;
    }
    char* Person::getSex(){
        return this->sex;
    }
    float Person::getAge(){
        return this->age;
    }
    char* Person::getAddress(){
        return this->address;
    }
    char* Person::getMobile(){
        return this->mobile;
    }

int main(){

    return 0;
}