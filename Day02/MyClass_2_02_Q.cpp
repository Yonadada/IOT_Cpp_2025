#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

/*
*  �����ڸ��� ������ ���
*/

class MyClass {
private:
	int id;
	char name[20];	
	int age;

public:
	MyClass(int n, const char* ps, int n2) {
		id = n;
		age = n2;
		strcpy(name, ps);

	}

	void printData() {
		cout << "   id:   " << id << "   name:   " << name << "   age:   " << age << endl;
	}
};

int main() {
	MyClass obj(1, "ȫ��Ű", 5);
	obj.printData();

	return 0;
}