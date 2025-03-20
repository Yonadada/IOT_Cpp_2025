#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

/*
*  복사 생성자 실습 
*/
class Person {
private:
	char name[20];
	int age;
public:
	Person(const char* name, int age) {
		strcpy(this->name, name);
		this->age = age;
	}
	//객체로 Person 주게되면 무한 반복의 복사생성자가 생성되서 에러발생~!
	//참조를 하고 있기 때문에 Person의 값이 변경되어서는 안된다.
	//메개변수가 참조변수로 호출되면 복사생성자가 호출된다. 
	//메개변수로 객체를 전달할 때는  Const 참조 형태로 받아야 한다. => 객체로 받으면 무한 루프에 빠진다 
	//객체가 입력으로 올때는 상수 참조로 받아야한다.
	Person(const Person& other) {		//복사생성자 // p라는 임시객체를 복사한 복사 생성자가  
		printf("--copy constructor--\n");
		this->age = other.age;
		strncpy(this->name, other.name, strlen(other.name) + 1);
	}


	void printData() {
		printf("name: %s, age: %d\n", this->name, this->age);
		std::cout << "이름: " << name << ", 나이: " << age << std::endl;
	}


};
int main() {

	Person p("홍나다", 3);
	p.printData();

	Person p2(p);	//default 복사 생성자
	p.printData();
	return 0;
}
