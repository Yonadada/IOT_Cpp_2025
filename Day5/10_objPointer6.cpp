/*
	�ٿ�ĳ���� : �ڽ������ͷ� �θ� ��ü�� ����ų �� ����.
*/
#include <iostream>

class Base {
public:
	void show() { printf("Base Class"); }
};

class Derived : public Base {
public:
	void show() { printf("Derived Class"); }
};

int main() {
	
	Base bobj;
	Derived* dptr = nullptr;

	dptr = (Derived*)&bobj;
	dptr->show();

	return 0;

}	
//��ü�����ͷ� ��ü�� ���� -> // �θ� Ÿ���� �����ͷ� �ڽ� ��ü�� ���� 
// �߻�Ŭ������ ����� ���� �������
// �߻�Ŭ������ ��ü�� ���  ���� �� ����.


