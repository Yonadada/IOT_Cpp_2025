/*

*/
#include <iostream>

class AAA {
private:
	static int static_a;	// static 멤버 변수
	int n;

public:
	AAA(int n);		// static 멤버변수에 접근하려면(수정) static 멤버 함수를 통해 접근하는 것이 가장 좋다!
	static void setStatic_a(int a);	//static 멤버 함수 -> static 멤버함수는 객체별로 새로만들어지지 않고 공유
	void print();
};

int AAA::static_a = 100; // static 멤버변수 초기화 
//-> 바꾸기 위해서 setStatic_a() 필요


AAA::AAA(int n) {
	this->n = n;
}
void AAA::print() {
	printf("static_a: %d, b: %d\n", static_a, n);
}

void AAA::setStatic_a(int a) {
	static_a = a;
	//n = 0;		// 일반 멤버의 접근은 허용되지 않고, static 멤버의 사용만 가능하다 
}




int main() {
	AAA obj1(10), obj2(20);
	obj1.print();
	obj2.print();

	
	return 0;
}
