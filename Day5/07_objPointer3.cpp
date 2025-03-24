#include <iostream>
class MyClass {
public:
	int value;	// 클래스 멤버 변수, 값 저장용
	
	//MyClass() {};
	MyClass(int v = 0) : value(v) {}	// 콜론 초기화
	void showMyClass() {
		std::cout << "value: " << value << std::endl;
	}
};
int main() {
	
	// 동적으로 MyClass 객체를 생성하고, value 10으로 초기화
	MyClass* ptr = new MyClass{ 10 };
	// 객체의 멤버 함수 호출 : value 출력
	ptr->showMyClass();
	printf("value: %d\n", ptr->value);

	// 동적으로 할당한 객체를 메모리에서 해제
	delete ptr;

	MyClass obj{};		// 0이라는 초기값 가지면서 obj 생성됨
	// obj 객체의 주소를 ptr에 저장
	ptr = &obj;			
		
	// ptr을 사용해서 객체의 멤버 함수 호출
	ptr->showMyClass();		// 객체 ptr이 가리키는 주소에서 showMyClass 호출
	(*ptr).showMyClass();   // 포인터를 역참조하여 showMyClass 호출

	printf("value: %d\n", ptr->value);

	return 0;
}