#include <iostream>
using namespace std;
class MyClass {
private:
	int num;
public:
	void setNum(int n) { num = n; }
	void print() const{
		cout << "Before: " << num;
		// num++; -> const 메서드이기 때문에 값 변경 불가능
		const_cast<MyClass*>(this)->num--;
		// const된 것 해지하고 포인터로 접근해 num 값 -1 
		cout << " After: " << num << endl;
 	}
};
int main() {
	MyClass obj;
	obj.setNum(10);
	obj.print();

	return 0;
}