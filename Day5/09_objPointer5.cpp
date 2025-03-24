/*
	상속에서 객체 포인터
	부모타입의 포인터로 자식타입의 객체를 가르키면 객체가 부모타입으로 업캐스팅된다. 
*/
//부모클래스와 자식클래스간의 동일한 메서드가 존재한다.

#include <iostream>
class Base {
public:
	void show() { printf("Base Class!!"); }
};

class Derived : public Base {		
public:
	void show() { printf("Edrived Class\n"); }		// 오버라이딩(재정의)
};
int main() {

	Base* bptr = nullptr;
	Derived* dptr = nullptr;

	Derived obj;	// 파생클래스 객체 선언/?
	dptr = &obj;
	dptr->show();

	bptr = &obj;	//부모타입의 포인터로 자식타입의 객체를 가리킨다(Upcasting)

	bptr->show();
	bptr->Derived::show();

	return 0;
}