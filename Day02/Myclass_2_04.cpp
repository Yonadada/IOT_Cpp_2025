/*
*  �����Ҵ��� ���� ������ ��� 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class MyClass {
private:
	mutable int id; //���ȭ �Լ��� ���氡���ϰ� �Ѵ�.
	int id;
	char* name;
	int age;

public:
	//MyClass() {}	// ����Ʈ ������
	~MyClass() {delete[] name;}	// �Ҹ��� --> ����Ʈ �����ڿ� ���������� '�ڵ�ȣ��' �ȴ�. �����Ҵ��� ��� ���� ���� �ۼ��� �ʿ� ����. ��ü�� �Ҹ��Ų��.
	MyClass(int _id, const char* _name, int _age);
	void printData() const; // �Լ��� �ش簴ü�� ��������� �������� �ʴ´ٴ� ���� ����, 
							// �Լ��� ��ü�� �����͸� �б⸸ �ϰ� �������� �ʴ´ٴ� ���� �����Ѵٴ� �ǹ�
							

};

MyClass::MyClass(int _id, const char* _name, int _age) {
	id = _id;
	age = _age;
	name = new char[strlen(_name) + 1];	// �����Ҵ�
	//name = _name		// �迭�� ������ �Ŀ� ���� �����ڸ� ����ϴ� ���� ���� �Ҵ��� �� ����.
	strcpy(name, _name);
}
void MyClass::printData() const{	// ��� ��� �Լ�(��� ������� ���ȭ ��Ų��)
	cout << "   id:   " << id << " ,  age:   " << age << " ,   name:   " << name << endl;
	//id = 2;
}



int main() {
	MyClass obj(1, "ȫ����", 3);
	obj.printData();
	
	return 0;
}