#include <iostream>	// ǥ�� ����� ���̺귯�� ����
#include "scope.h" // std ���ӽ����̽� ���


//������ ����
A::A(int aa) {	// -> std::cout << . ��, �������� ������ :: �� ���� ���� ����  
	a = aa;	// �Ű����� aa�� �޾� ��� ���� a�� ����
}

void A::AInfo() {
	std::cout << "a: " << a << std::endl;	// ��� ���� a�� �� ���
}


int main() {
	A a(10);	//A Ŭ�����ȿ� a��°�ü�� 10�� 
	a.AInfo();

	return 0;
}