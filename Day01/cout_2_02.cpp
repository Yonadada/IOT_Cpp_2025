#include <iostream>
/*
* 
*/
int main() {
	int num = 100;	//-> C 스타일 변수 선언
	int num2(200);	//->C++ 스타일 변수 선언. int 클래스의 객체 num2를 2000으로 초기화 

	std::cout << num << std::endl;	//100
	std::cout << num2 << std::endl;	//200

	return 0;
}