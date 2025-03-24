#include <iostream>
#include <string.h>
/*
	Inheritance(상속)
	private, public, protected
	is a(무엇은 무엇이다), has a(소유) 관계가 성립해야 함
*/
class Human {// 부모클래스, 기초 클래스, 슈퍼클래스
private:
	char name[20];
	int age;
public:
	Human(const char*, int);
	void getData();
};
class Student : public Human {			// 자식클래스, 파생 클래스, 서브 클래스, 드라이버드 클래스
private:
	int studentID;
public:
	Student(const char* name, int age, int studentID);
	void showStudent();
};
Human::Human(const char* aname, int aage) {	// 외부에서 쓸 때는 클래스를 앞에 입력해줘야 함
	strcpy_s(name, aname);
	age = aage;
}
void Human::getData() {					// 타입은 클래스 앞에 적어줘야 함
	std::cout << "이름: " << name << ", 나이: " << age << std::endl;
}			
/* 상속 받은 멤버들은 상속한 부모클래스의 생성자에서 초기화를 한다 */
Student::Student(const char* aname, int aage, int astudentID) : Human(aname, aage){	// 속성을 모두 받아와야 함 
	// 부모 객체의 클래스가 생성되어 있어야 자식이 부모의 속성을 상속받을 수 있음 => 콜론 초기화로 부모의 속성 받아와야함!!
	//strcpy(name, aname);
	//age = aage;
	studentID = astudentID;
}
void Student::showStudent() {
	//std::cout << "이름: " << name << std::endl;		// 오류 발생
	std::cout << "학번: " << studentID << std::endl;
}

int main() {
	Human h("홍길동", 25);
	h.getData();

	Student h2{ "임꺽정", 30, 202502 };
	h2.getData();
	h2.showStudent();

	return 0;
}