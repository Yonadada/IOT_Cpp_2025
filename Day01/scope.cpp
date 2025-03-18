#include <iostream>	// 표준 입출력 라이브러리 포함
#include "scope.h" // std 네임스페이스 사용


//생성자 정의
A::A(int aa) {	// -> std::cout << . 즉, 범위지정 스코프 :: 를 통해 접근 가능  
	a = aa;	// 매개변수 aa를 받아 멤버 변수 a에 저장
}

void A::AInfo() {
	std::cout << "a: " << a << std::endl;	// 멤버 변수 a의 값 출력
}


int main() {
	A a(10);	//A 클래스안에 a라는객체에 10을 
	a.AInfo();

	return 0;
}