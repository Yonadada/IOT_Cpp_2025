/*
*  문제 
*	MyClass obj(10, 20);
MyClass obj2(20, 30);
MyClass obj3 = obj.add(obj2);
MyClass obj4 = obj.operator + (obj3);
실행시키기
*/

#include <iostream>  // 화면에 출력하기 위해 필요한 코드

// MyClass라는 설계도(클래스)를 만든다
class MyClass {
private:
int x, y;  // 두 개의 숫자 저장할 공간

public:
// 객체를 만들 때 x와 y를 초기화해주는 생성자
MyClass(int a, int b) : x(a), y(b) {}

// 다른 객체를 더해서 새로운 객체를 만들어주는 함수
MyClass add(const MyClass& other) {
	return MyClass(this->x + other.x, this->y + other.y);
}

// + 연산자를 사용할 수 있도록 해주는 함수 (오버로딩)
MyClass operator+(const MyClass& other) {
	return MyClass(this->x + other.x, this->y + other.y);
}

// int 값을 더할 수 있도록 해주는 함수 (오버로딩)
MyClass operator+(int value) {
	return MyClass(this->x + value, this->y + value);
}

// 현재 객체의 x, y 값을 화면에 보여주는 함수
void showMyClass() {
	std::cout << "x: " << x << ", y: " << y << std::endl;
}
};

int main() {
MyClass obj(10, 20);      // x=10, y=20인 객체 생성
MyClass obj2(20, 30);     // x=20, y=30인 객체 생성

MyClass obj3 = obj.add(obj2);  // obj와 obj2를 더한 새로운 객체 생성 (x=30, y=50)
MyClass obj4 = obj.operator+(obj3);  // obj와 obj3를 더한 새로운 객체 생성 (x=40, y=70)
MyClass obj5 = obj4 + 100;  // obj4에 100을 더한 새로운 객체 생성 (x=140, y=170)  // obj4.operator + (100);
//Q. 200 + obj4는 왜 안되나? 


obj.showMyClass();   // obj 값 출력: x: 10, y: 20
obj2.showMyClass();  // obj2 값 출력: x: 20, y: 30
obj3.showMyClass();  // obj3 값 출력: x: 30, y: 50
obj4.showMyClass();  // obj4 값 출력: x: 40, y: 70
obj5.showMyClass();  // obj5 값 출력: x: 140, y: 170

return 0;  // 프로그램 끝!
}

// 오버로딩 할 수 없는 연산자:
// ::, ., *, sizeof