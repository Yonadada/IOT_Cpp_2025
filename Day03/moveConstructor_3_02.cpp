#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

/*
*  이동생성자(T&&)
* r-value reference 를 피라미드로 받는 이동 생성자 
*/

using namespace std;

class Human {
private:
	char name[10];
	int age;

public:
	// 입력2개 받는 생성자
	Human(const char* name, int age) {
		printf("입력 2개 받는 생성자 호출");
		strcpy(this->name, name); // name을 복사
		this->age = age; // age를 초기화
	}
	// 복사생성자 -> 참조하는 데이터를 복사해서 가져옴 
	Human(const Human& other) {	
		printf("복사 생성자 호출\n");
		strcpy(this->name, other.name);
		this->age = other.age;
	}
	
	// 이동생성자참조해야 할 원본 데이터를 이동시켜버림 -> 더이상 메모리를 차지하지 않음
	Human(Human&& other) noexcept {	// 이동생성자에서만 noexcept 사용 -> 예외 발생을 차단 
		printf("이동 생성자 호출\n");
		strcpy(this->name, other.name);
		this->age = other.age;
		//other.name[0] = '\0'; // 이동 후 원본 객체의 name을 초기화 -> 데이터를 이동시켜버렸기 때문에 기존 원본 객체를 0으로 초기화시킴
		other.age = 0; // 이동 후 원본 객체의 age를 초기화
	}

	void printHuman() {
		printf("name: %s, age: %d\n", this->name, this->age);
	}
};

int main(){
	Human h1("홍새벽", 1);
	h1.printHuman();

	Human h2(h1);
	h2.printHuman(); 
	
	Human h3(std::move(h1)); //
	h3.printHuman();// 이동생성자 호출
	h1.printHuman();

	return 0;
}
