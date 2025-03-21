/*
	step03
	char 포인터의 name, int 타입의 age, 출력을 담당하는 showHuman()을 가지는 Human 클래스가 있다
	name을 동적 할당하고 나이30, 이름 홍명보인 man 객체를 생성하시오.
	man 객체를 복사하여 copyman 객체를 생성하시오.
	xman = man이 실행시키시오.
*/
#define _CRT_SECURE_NO_WARNINGS  // strcpy 같은 함수에서 보안 경고를 막아줌
#include <iostream>
#include <cstring>  // 문자열 관련 함수 (strlen, strcpy 등)를 쓰기 위한 헤더

// Human 클래스 정의
class Human {
private:
    char* name;  // 이름을 저장할 포인터
    int age;     // 나이

public:
    // 생성자: 이름과 나이를 초기화하고 이름은 동적 메모리 할당
    Human(const char* m_name = " ", int m_age = 0) : age(m_age) {
        name = new char[strlen(m_name) + 1];  // 필요한 만큼 메모리 할당
        strcpy(name, m_name);                 // 이름 복사
    }

    // 복사 생성자: 다른 객체로부터 값을 복사할 때 사용
    Human(const Human& other) : age(other.age) {
        printf("copy constructor!!!\n");
        name = new char[strlen(other.name) + 1];  // 새로운 메모리 할당
        strcpy(name, other.name);                // 이름 복사
    }

    // 소멸자: 객체가 사라질 때 호출되어 메모리 정리
    ~Human() {
        printf("delete Constructor~\n");
        delete[] name;  // 동적 할당된 메모리 해제
    }

    // 정보 출력 함수
    void showHuman() {
        printf("name: %s, age: %d\n", name, age);
    }

    // 대입 연산자 오버로딩: 이미 만들어진 객체에 다른 객체를 대입할 때
    Human& operator=(const Human& other);
};

// 대입 연산자 함수 정의
Human& Human::operator=(const Human& other) {
    if (this != &other) {  // 자기 자신이 아닌 경우에만 처리
        delete[] name;     // 기존 메모리 해제
        printf("operator overloading\n");

        // 새롭게 메모리 할당하고 복사
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        age = other.age;
    }
    return *this;  // 자기 자신을 참조로 리턴
}

// 메인 함수: 실제 실행되는 부분
int main() {
    Human man("홍명보", 30);   // 이름과 나이로 man 객체 생성
    man.showHuman();          // 출력: name: 홍명보, age: 30

    Human copyman(man);       // man을 복사해서 copyman 생성 (복사 생성자 호출)
    copyman.showHuman();      // 출력: name: 홍명보, age: 30

    Human xman = copyman;     // copyman을 복사해서 xman 생성 (복사 생성자 호출)
    xman.showHuman();         // 출력: name: 홍명보, age: 30

    return 0;  // 프로그램 종료
}