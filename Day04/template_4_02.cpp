/*
*	���ø��� ����� �Լ����ǰ� �и��� �� ����.
*	���ø��� �Ϲ�ȭ�� Ư��ȭ�� �ְ�, 
*	���ø� ���� �ڿ��� �Լ��� �ٷ� �;��Ѵ�.
*/
#include <iostream>

template <typename T>	//���ø� ����(�Ϲ�ȭ) 
T func(T a, T b) {		//���ø� �Լ�
	std::cout << "type: T" << std::endl;
	return a + b;
}

template<>		// ���ø� Ư��ȭ-���ø� �Ϲ�ȭ ��, Ư���� Ÿ���� ó���� ���
int func<int>(int a, int b) {
	std::cout << "<int>" << std::endl;
	return a + b;
}


int main() {

	std::cout << func(10, 20) << std::endl;
	std::cout << func(10.5, 20.5) << std::endl;

	std::cout << func<double>(10.1, 20.2) << std::endl;
	std::cout << func<char>(10, 10) << std::endl;


	return 0;
}