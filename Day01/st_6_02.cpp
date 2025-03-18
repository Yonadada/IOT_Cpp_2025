/*
*  c++ 타입의 구조체
*
*/

#include <iostream>

typedef struct human {
	char name[20];
	int age;
	char job[10];
	
	void showHuman() { // c++은 멤버함수 + 멤버변수 

		printf("name:  %s, age: %d, job: %s", name, age, job);
	}

} Human;



int main() {

Human h = { "김철수", 30, "백수" };
//showHuman(h);
	
h.showHuman(); //. 연산자를 이용해 showHuman에 접근 

	return 0;
}