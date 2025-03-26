/* - 클래스, 생성자, 복사 생성자, 소멸자 -
	step03
	char 포인터의 name, int 타입의 age, 출력을 담당하는 showHuman()을 가지는 Human 클래스가 있다
	name을 동적 할당하고 나이30, 이름 홍명보인 man 객체를 생성하시오.
	man 객체를 복사하여 copyman 객체를 생성하시오.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>  // c스타일 문자열 함수(strlen, strcpy) 사용하기 위한 헤더

class Human {
private:
    char* name;
    int age;
public:
    Human(const char* m_name, int m_age = 0) : age(m_age) {
        name = new char[strlen(m_name) + 1];
        strcpy(name, m_name);
        age = age;
        
    }
    //Human → 생성자 함수니까 이름은 클래스 이름과 똑같아야 해요.
    //const Human& other → 이게 복사할 대상, 즉 man이에요!
    //other는 우리가 임의로 붙인 이름이에요. "복사해올 대상"을 뜻해요.

    Human(const Human& other) : age(other.age) {
        printf("copy constructor!!!");
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
       
    }
    ~Human() {
        printf("delete Constructor~");
        delete[] name;
    }
    void showHuman() {
        printf("name: %s, age: %d\n", name, age);
    }
};

int main() {
    Human man("홍명보", 30);   //man 객체 생성
    man.showHuman();
    
    Human copyman(man);       // man을 복사해서 copyman을 만든다.
    copyman.showHuman();

    /*Human xman;
    xman = copyman;
    xman.showHuman();*/
    return 0;
}
