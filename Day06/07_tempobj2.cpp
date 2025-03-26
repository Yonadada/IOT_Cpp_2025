#include <iostream>
using namespace std;
/*
	
*/
class MyClass {
private:
	int num;
public:
	MyClass(int n) : num(n) {
		cout << num << " constructor" << endl;
	}
	~MyClass() { cout << num << " destructor" << endl; }
	void setData(int n) { num = n; }
};
int main() {
	
	// MyClass* ptr = &MyClass{ 10 };
	// MyClass& obj2 = MyClass{ 20 };			// 임시 객체는 참조를 사용할 수 없음

	MyClass obj = MyClass{ 10 };				// 10 constructor
	obj.setData(20);							// 생성된 후에 값이 바뀌고 소멸됨 20 destructor

	MyClass&& obj2 = MyClass{ 20 };
	obj2.setData(22);

	const MyClass obj3 = MyClass{ 30 };
	//obj3.setData(33); 오류 발생!				// 상수 참조를 하므로 값 변경이 불가함

	cout << "bye ~~ " << endl;

	return 0;
}