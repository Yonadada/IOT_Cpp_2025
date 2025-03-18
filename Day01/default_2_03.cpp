#include <iostream>

/*
*	디폴트 매개변수 : 
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

	res = func();					// 입력이 없으면 디폴트 매개변수가 적용된다.
	std::cout << res << std::endl;	// 100

	return 0;
}