/*
*	멤버함수 연산자 오버로딩 : p1 operator 연산자(p2)  //operator 생략 X
*	ex) p1 operator + (p2)
*/
#include <iostream>
class Myclass {
private: 
	int value;
public:
	Myclass(int n) : value(n) {}
	Myclass operator + (const Myclass& other) {		// 연산자 오버로딩 
		printf(" + overloading");
		return Myclass(value + other.value);	
	}
	void showMyclass() {
		printf("value: %d\n", value);
	}
};
#include <iostream>

int main() {
	Myclass obj(10);			//초기값을 가지는 객체 생성
	obj.showMyclass();

	Myclass obj2(obj);			// obj를 복사해서 객체 생성
	obj2.showMyclass();

	Myclass obj3 = obj2;		// obj를 복사해서 객체 생성
	obj3.showMyclass();

	//Myclass obj4 = obj + obj2 + obj3;	// 객체를 더한 결과를 가지고  객체 생성
	Myclass obj4 = obj.operator+(obj2);
	obj4.showMyclass();

	return 0;
}