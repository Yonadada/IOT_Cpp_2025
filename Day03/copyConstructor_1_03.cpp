#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
/*
* 복사생성자 
*  name을 동적할당 받으면?
*/

class Person {
private:
	char* name;
	int age;
public:
	Person(const char* name, int age); // 동적할당
	Person(const Person& other); // 복사생성자(깊은 복사)
	~Person();	// 할당제거
	void printData() const;
};

//생성자 정의 
Person::Person(const char* name, int age) : name(nullptr), age(age) {

	try {
		//동적할당 발생 가능 
		this->name = new char[strlen(name) + 1]; // name 길이 만큼 

		//문자열 복사
		strcpy(this->name, name);
	}
	catch (std::bad_alloc& e){
		std::cout << "메모리 할당 실패" << e.what() << std::endl;
		
	//메모리 할당 제거(소멸자)
		this->name = nullptr;
		this->age = 0;
	}
}// 생성자 정의

//복사 생성자 정의
Person::Person(const Person& other) : name(nullptr), age(other.age) {
	printf("constructor call\n");
	try {
		this->name = new char[strlen(other.name) + 1];
		this->age = other.age;
		strncpy(this->name, other.name);
	}
	catch (std::bad_alloc& e) {
		std::cout << "메모리 할당 실패: " << e.what() << std::endl;
		this->name = nullptr;
		this->age = 0;
	}
}



Person::~Person() {
	if (name) {
		delete[] name;
		name = nullptr;
	}

}

void Person::printData() const{
	if (!name) {
		std::cout << "--데이터 할당 못받음--" << std::endl;
		return;
	}
	std::cout << "이름: " << name << "나이: " << age << std::endl;

}
int main() {

	Person p("홍요키", 6);

	p.printData();

	Person p2 = p;
	p2.printData();

	return 0;
}
/*
*  디폴트로 자동 제공받는 생성자 : 디폴트 생성자, 복사 생성자, 소멸자
*/