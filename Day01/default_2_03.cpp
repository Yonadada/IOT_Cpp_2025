#include <iostream>

/*
*	����Ʈ �Ű����� : 
*/

int func(int num = 10) {

	return num * num;
}

int main() {
	
	int res;
	res = func(10);
	std::cout << res << std::endl;  // 100

	res = func(0);
	std::cout << res << std::endl;	// 0

	res = func();					// �Է��� ������ ����Ʈ �Ű������� ����ȴ�.
	std::cout << res << std::endl;	// 100

	return 0;
}