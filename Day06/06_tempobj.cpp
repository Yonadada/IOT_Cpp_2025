#include <iostream>
using namespace std;

class MyClass {
private:
	int num;
public:
	MyClass(int n) : num(n) {
		cout << num << " constructor" << endl;
	}
	~MyClass() { cout << num << " destructor" << endl; }
};
int main() {

	MyClass obj{ 10 };
	MyClass obj2 = MyClass{ 20 };
	MyClass{ 30 };	// 임시 객체 (이름 없는 객체) -> 다음 항에서 바로 사라짐
	 

	cout << "Bye ~ " << endl;

	return 0;
}