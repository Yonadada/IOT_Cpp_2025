#include <iostream>
using namespace std;
/*
*	변수 초기화 
*/


int main() {

	int num = 3;		 // 복사 초기화
	int num2(30);		 // 직접 초기화
	int num3{ 300 };	 // 중괄호 직접 초기화
	int num4 = { 3000 }; // 중괄호 복사 초기화

	int x = 3.14;	// 암묵적으로 컴파일러가 암묵적으로 형변환
	int x1{ 3.14 };	// 중괄호는 암묵적인 형변환 xx

	cout << num << endl;	//3
	cout << num2 << endl;	//30
	cout << num3 << endl;	//300
	cout << num4 << endl;	//3000
	cout << x << endl;		//3
	cout << x1 << endl;		//에러발생!


	return 0;
}