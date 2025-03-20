#include <iostream>

/*
	 변환생성자
	 다른 타입의 객체로 변환될 때, 호출되는 생성자. 입력을 한개만 가지는 생성자
	 입력을 단 한개만 가지는 생성자
*/
class Myclass {
private:
	int value;

public:
	explicit Myclass(int value) {
		printf("변환 생성자 호출!!\n");
		this->value = value;
	}

	void printMyclass() {
		printf("value: %d\n", value);
	}
}; //Myclass 끝

int main() {

	//Myclass obj; // Myclass obj; -> obj 객체를 만들어 내는 생성자가 없기 때문에 에러발생~!
	//Myclass obj = 10; //변환을 통해 int가 Myclass 타입으로 바뀌었다. 변환생성자 호출 - 객체의 변환이 일어남
	//obj.printMyclass();	// 묵시적으로 변환이 일어나는 것을 방지한다.

	Myclass obj2{ 10 };	//객체 생성할때 초기값을 주는 코드여서 오류가 나지 않는다.
	obj2.printMyclass();

	return 0;
}