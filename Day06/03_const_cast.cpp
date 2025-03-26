#include <iostream>
/*
	const_cast : const 선언을 해지
*/
int main() {
	int num = 10;
	std::cout << ++num << std::endl;

	const int num2 = 10;	
	//std::cout << ++num2 << std::endl;  오류 발생!! const 상수화 -> 값 변경 불가

	int* np = const_cast<int*>(&num2);
	*np = *np + 1;
	std::cout << "num2: " << num2 << std::endl;

	const char str[] = "orange";
	char* cp = const_cast<char*>(str);
	cp[0] = 'O';
	std::cout << str << std::endl;

	return 0;
}