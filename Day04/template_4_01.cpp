/*
*	함수 템플릿 : 여러 자료형을 템플릿 인자로 받아서 함수 내부에 활용한다.
*	- 이점 : 객체지향이 가지고 있는 특징 중, 다형성과 재활용 장점을 가지고 있다.
*/
#include <iostream>

//int Add(int a, int b) {
//	return a + b;
//}
//double Add(double a, double b) {
//	return a + b;
//}

//=======템플릿 적용======
template <typename T>
T Add(T a, T b) {
	return a + b;
}


int main() {

	std::cout << Add(10, 20) << std::endl;
	std::cout << Add(1.1, 2.2) << std::endl;

	return 0;
}