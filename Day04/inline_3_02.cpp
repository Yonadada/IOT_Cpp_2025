/*
* ��ũ�δ� ��ó���Ⱑ ó��������, inline �Լ��� �����Ϸ��� ó���Ѵ�.
*/
#include <iostream>

#define SQUARE(x) ((x))*((x))	//��ũ�η� ���� 

inline int funct(int x) {	//�ζ����Լ��� ����
	return x * x;
}
int main() {

	std::cout << SQUARE(2) << std::endl;
	std::cout << funct(2) << std::endl;

	return 0;
}