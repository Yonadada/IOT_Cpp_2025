#include <iostream>
using namespace std;
/*
* 
*/

class AClass {
private:
	int n1;
	int n2;
public:
	AClass(){}	// 명시적으로 디폴트 생성자를 만들어 봄. 입력값을 받지 않는 생성자는 자동으로 생긴다.

	//클래스가 private이기때문에 메서드 public의 set, get메서드를 통해 클래스에 접근해야함.
	void setData(int num1, int num2){
		n1 = num1;
		n2 = num2;
	}
	void getDage(){
		cout << "num1의 값은: " << n1 <<endl;
		cout << "num2의 값은: " << n2 <<endl;
	}
};

int main() {

	AClass obj;	// 입력값 없는 객체 생성됨 
	//AClass obj(100, 200); //에러발생! -> 입력 2개를 받는 생성자가 없기 때문에 에러!

	obj.setData(100, 200);
	obj.getDage();
	return 0;

}