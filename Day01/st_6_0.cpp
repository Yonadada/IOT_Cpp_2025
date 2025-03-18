/*
*  c++ 클래스 타입
*
*/

#include <iostream>

class Human {
public: // 객체지향이 가지고 있는 정보은닉 특징때문에 public을 붙여주면 외부에서 내부 접근 가능, 만약 public이 없다면 접근 못함! 
	char name[20];
	int age;
	char job[10];

	Human() {}	//디폴트 생성자 -> 출력이 없으며 클래스 이름과 같다.

	void showHuman() { // c++은 멤버함수 + 멤버변수 

		printf("name:  %s, age: %d, job: %s", name, age, job);
	}

};



int main() {

	Human h = { "김철수", 30, "백수" };
	//showHuman(h);

	h.showHuman(); //. 연산자를 이용해 showHuman에 접근 

	return 0;
}