/*
*	copyConstructor (���������)
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
};//Person Ŭ���� ��


int main() {

	Person p("ȫ�浿", 30);
	p.printPerson();	//name: ȫ�浿, age: 30

	Person p2(p);		// p�� ��ü�� �����ؼ� ȣ�� (��������� ȣ��) -> ��������ڵ� default�� �����ȴ�
	p2.printPerson();	//name: ȫ�浿, age: 30

	Person p3 = p;
	p3.printPerson();	//name: ȫ�浿, age: 30

	return 0;
}