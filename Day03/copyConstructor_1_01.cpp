/*
*	copyConstructor (복사생성자)
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Person {
private:
	char m_name[20];
	int m_age;

public:
	Person(const char* pname, int age) {
		printf("--Constructor call--\n");
		strcpy(m_name, pname);
		m_age = age;
	}

	void printPerson() {
		printf("name: %s, age: %d\n", m_name, m_age);
	}
};//Person 클래스 끝


int main() {

	Person p("홍길동", 30);
	p.printPerson();	//name: 홍길동, age: 30

	Person p2(p);		// p의 객체를 복사해서 호출 (복사생성자 호출) -> 복사생성자도 default로 생성된다
	p2.printPerson();	//name: 홍길동, age: 30

	Person p3 = p;
	p3.printPerson();	//name: 홍길동, age: 30

	return 0;
}