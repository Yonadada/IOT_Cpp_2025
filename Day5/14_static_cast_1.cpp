/*
	기본 자료형의 형변환으로 컴파일 타임에 타입을 변환
*/

#include <iostream>

int main() {

	char ch;
	int i = 100;
	float f = 3.14;
	double d;

	ch = static_cast<char>(i);		// int --> char 변환 
	std::cout << ch << std::endl;
	ch = (char)i;
	std::cout << ch << std::endl;

	d = static_cast<double>(f);
	std::cout << d << std::endl;

	i = static_cast<int>(d);
	std::cout << i << std::endl;
	
	std::cout << typeid(ch).name() << std::endl;		//자료형의 타입을 알고 싶을때 typeid 사용
	std::cout << typeid(d).name() << std::endl;

	return 0;
}
/*
	static_cast<type-id>(expression)
*/