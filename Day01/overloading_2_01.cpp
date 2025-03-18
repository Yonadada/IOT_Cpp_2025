#include <iostream>
using namespace std;

/*
* 함수의 다형성
* - 함수 오버로딩(함수의 다중정의) -> 함수를 여러개 정의
* - 함수 오버라이딩(함수의 재정의) -> 상속(부모로부터 물려받음) => 부모로부터 물려받은 함수를 내가 다시 정의하겠다
*/

// 함수명, 함수메개변수를 통해
// 함수이름과 함수메개변수가 같아야 같은 함수로 취급 => c++
//* 메개변수 개수, 타입이 함수를 구별하는 기준!!


/*
*  함수 오버로딩 : 이름은 같은데 매개변수의 타입이나 개수가 다르면 다름 함수이다!!
*/


int func() {

	return 10;
}

int func(char c) { // c에서는 동일한 이름X / C++에서는 가능 -> 메게변수, 자료형 타입 구분하기 때문

	return c; 
}

int func(int n) {
	
	return 10 + n;
}

int func(int n1, int n2) {

	return n1 + n2;
}

//char func(char c) { // 에러발생 ~~!!! => 함수이름, 함수메개변수와 자료형타입이 같은게 이미 있어서 
//	
//	return c;
//}




int main() {

	cout << func() << endl;	// 10
	cout << func('a') << endl; // 97
	cout << func(10) << endl;	//20
	cout << func(10, 20) << endl; //30

	return 0;
}