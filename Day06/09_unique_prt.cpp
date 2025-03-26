#include <iostream>
using namespace std;
/*
	스마트 포인터 : 객체의 생명 주기를 객체에 맡김으로 프로그래머의 메모리 관리 부담을 줄여줌
	unique_ptr - 소유권을 독점적으로 관리하는 스마트 포인터(auto_ptr을 대체)

*/
class MyClass {
public:
	MyClass() { cout << "MyClass() 호출" << endl; }
	~MyClass() { cout << "~MyClass() 호출" << endl; }
};
int main() {
	unique_ptr<MyClass> ptr(new MyClass{});
	unique_ptr<MyClass> ptr2 = move(ptr);

	return 0;
}