/*
*  �����Ҵ��� ���� ������ ��� 
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
	MyClass() {}	// ����Ʈ ������
	~MyClass() {}	// �Ҹ��� --> ����Ʈ �����ڿ� ���������� '�ڵ�ȣ��' �ȴ�. �����Ҵ��� ��� ���� ���� �ۼ��� �ʿ� ����.
	MyClass(int _id, const char* _name, int _age) {
		id = _id;
		age = _age;
		name = new char[strlen(_name) + 1]; // 1. �����޸� �Ҵ�. ����+1-> ���ڿ��� �������� null��ġ �׷��� +1
		//name = _name;	// �迭�� ������ �Ŀ� ���� �����ڸ� ����Ͽ� ���� ���� �Ҵ��� �� ����.

		if (name != NULL) {

			strcpy(name, _name); // 2.strcpy (����, ����)
		}

	}

	void printData() {
		cout << "   id:   " << id << " ,  age:   " << age << " ,   name:   " << name << ends;
	}

};

int main() {
	MyClass obj(1, "ȫ����", 3);
	obj.printData();

	return 0;
}