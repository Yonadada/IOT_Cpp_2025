/*
*  동적할당을 통해 데이터 출력 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class MyClass {
private:
	int id;
	char* name;
	int age;

public:
	MyClass() {}	// 디폴트 생성자
	~MyClass() {}	// 소멸자 --> 디폴트 생성자와 마찬가지로 '자동호출' 된다. 동적할당할 경우 제외 별로 작성할 필요 없다.
	MyClass(int _id, const char* _name, int _age) {
		id = _id;
		age = _age;
		name = new char[strlen(_name) + 1]; // 1. 동적메모리 할당. 길이+1-> 문자열은 마지막에 null위치 그래서 +1
		//name = _name;	// 배열을 선언한 후에 대입 연산자를 사용하여 값을 직접 할당할 수 없다.

		if (name != NULL) {

			strcpy(name, _name); // 2.strcpy (복사, 원본)
		}

	}

	void printData() {
		cout << "   id:   " << id << " ,  age:   " << age << " ,   name:   " << name << ends;
	}

};

int main() {
	MyClass obj(1, "홍나다", 3);
	obj.printData();

	return 0;
}