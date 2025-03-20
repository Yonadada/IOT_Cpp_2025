/*
*  동적할당을 통해 데이터 출력 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class MyClass {
private:
	mutable int id; //상수화 함수를 변경가능하게 한다.
	int id;
	char* name;
	int age;

public:
	//MyClass() {}	// 디폴트 생성자
	~MyClass() {delete[] name;}	// 소멸자 --> 디폴트 생성자와 마찬가지로 '자동호출' 된다. 동적할당할 경우 제외 별로 작성할 필요 없다. 객체를 소멸시킨다.
	MyClass(int _id, const char* _name, int _age);
	void printData() const; // 함수가 해당객체의 멤버변수를 수정하지 않는다는 것을 보장, 
							// 함수가 객체의 데이터를 읽기만 하고 수정하지 않는다는 것을 보장한다는 의미
							

};

MyClass::MyClass(int _id, const char* _name, int _age) {
	id = _id;
	age = _age;
	name = new char[strlen(_name) + 1];	// 동적할당
	//name = _name		// 배열을 선언한 후에 대입 연산자를 사용하는 값을 직접 할당할 수 없다.
	strcpy(name, _name);
}
void MyClass::printData() const{	// 상수 멤버 함수(모든 멤버들을 상수화 시킨다)
	cout << "   id:   " << id << " ,  age:   " << age << " ,   name:   " << name << endl;
	//id = 2;
}



int main() {
	MyClass obj(1, "홍나다", 3);
	obj.printData();
	
	return 0;
}