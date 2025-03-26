#include <iostream>
using namespace std;
/*
	dynamic_cast를 이용하여 다운캐스팅할 경우는 가상함수가 있어야 함
*/

class Super {
public:
	virtual void func() { cout << "Super::func()" << endl; }		// 가상함수 
	void func1() { cout << "Super::func1()" << endl; }
	void fx() { cout << "Super::fx()" << endl; }
};
class Sub : public Super {		// Super 클래스 상속 받음
public:
	void func() { cout << "Sub::func()" << endl; }
	void func2() { cout << "Sub::func2()" << endl; }
	void fx() { cout << "Sub::fx()" << endl; }
};
int main() {

	Super* sp = new Super{};
	sp->func();
	sp->func1();
	sp->fx();
	cout << "------------------UpCasting---------------------"<< endl;
	Super* sp2 = new Sub{};
	sp2->func();		// Super 클래스의 func()에 virtual 사용시 자식 클래스의 func() 호출됨
	sp2->func1();
	sp2->fx();
	//sp2->func2();  오류발생!! -> 자식 클래스 내의 함수에 접근 불가
	cout << "------------------Downcasting---------------------" << endl;
	// 가상함수 virtual이 없다면 downcasting이 일어나지 않음
	Sub* sp3 = dynamic_cast<Sub*>(sp2);		// 부모 클래스를 자식 클래스 타입으로 다운캐스팅
	sp3->func();
	sp3->func1();		// super
	sp3->func2();
	sp3->fx();
	
	delete sp;
	delete sp2;

	return 0;
}