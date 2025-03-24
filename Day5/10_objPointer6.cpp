/*
	다운캐스팅 : 자식포인터로 부모 객체를 가르킬 수 없다.
*/
#include <iostream>

class Base {
public:
	void show() { printf("Base Class"); }
};

class Derived : public Base {
public:
	void show() { printf("Derived Class"); }
};

int main() {
	
	Base bobj;
	Derived* dptr = nullptr;

	dptr = (Derived*)&bobj;
	dptr->show();

	return 0;

}	
//객체포인터로 객체에 접근 -> // 부모 타입의 포인터로 자식 객체에 접근 
// 추상클래스는 상속을 위해 만들어짐
// 추상클래스는 객체를 상속  받을 수 없다.


