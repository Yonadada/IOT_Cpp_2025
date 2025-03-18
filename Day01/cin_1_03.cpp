#include <iostream>
using namespace std;

/*
*  cin - 입력을 담당하는 객체
*/

int main() {

	int inVal, inVal2;

	cout << "숫저 입력 >>";
	cin >> inVal;
	cin >> inVal2;
	cout << "inVal: " << inVal;
	cout << "두수의 합: " << inVal + inVal2 << endl;


	return 0;
}
/*
* 함수의 다형성
* - 함수 오버로딩(함수의 다중정의) -> 함수를 여러개 정의
* - 함수 오버라이딩(함수의 재정의) -> 상속(부모로부터 물려받음) => 부모로부터 물려받은 함수를 내가 다시 정의하겠다
*/

// 함수명, 함수메개변수를 통해
// 함수이름과 함수메개변수가 같아야 같은 함수로 취급 => c++
//* 메개변수 개수, 타입이 함수를 구별하는 기준!!