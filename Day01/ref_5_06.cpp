#include <iostream>

/*
*  출력인 경우: 참조변수
*/
//참조타입
int& func(int& ref) {
	ref++;

	return ref;  //-> Lvalue
	//return ref++;	//-> Rvalue

}
int main() {
	int n = 10;
	//int& ref = func(n); //참조로받는다.

	int ref = func(n); //일반변수로 받아도 된다.

	std::cout << ref << std::endl;

	return 0;
}