// why 복사 생성자가 필요할까?
// 이유 -> 그냥 복사하면 겉으로만 복사(얕은 복사)가 되기 때문이다!
// ex) char* name 처럼 포인터로 동적 메모리를 할당한 경우, 그냥 복사하면 
//  포인터 값만 복사돼고 즉, 같은 메모리 주소를 가리키게 된다.

// 즉, 1.얕은 복사로 인한 문제를 막기위해 포인터를 안전하게 복사하기 위해 사용
// 2. 다른 객체와 메모리 공유를 x, 객체를 완전히 독립적으로 만들기 위해서 사용
// 3. 객체를 함수로 넘기거나 반환할 때 복사 생성자가 자동으로 호출된다.


// 복사 생성자가 호출되는 상황
// 함수의 매개변수로 객체를 전달할 때(값 전달)
// 함수가 객체를 반환할 때 (값 변환)

/* - 클래스, 생성자, 복사 생성자, 소멸자 -
	step03
	char 포인터의 name, int 타입의 age, 출력을 담당하는 showHuman()을 가지는 Human 클래스가 있다
	name을 동적 할당하고 나이30, 이름 홍명보인 man 객체를 생성하시오.
	man 객체를 복사하여 copyman 객체를 생성하시오.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>  // c스타일 문자열 함수(strlen, strcpy) 사용하기 위한 헤더

//사람(Human)을 표현하는 클래스
class Human {
private:
    char* name;  // 사람의 이름을 저장할 변수 (문자열이니까 char* 사용, 나중에 new로 메모리 할당할 예정)
    int age;     // 사람의 나이
public:
    // 생성자: 객체가 만들어질 때 자동으로 호출되는 함수
    // const char* m_name : 이름으로 사용할 문자열
    // int m_age = 0: 나이 (기본값은 0)
    Human(const char* m_name, int m_age = 0) : age(m_age) {

        // 이름을 위한 메모리 공간을 문자열 길이 + 1 만큼 동적 할당함 (문자열 끝에 \0 포함)
        name = new char[strlen(m_name) + 1];
        // name에 m_name 문자열을 복사함 (문자 하나하나 똑같이 복사됨)
        strcpy(name, m_name);

        // 위에서 age는 초기화 리스트에서 이미 넣었기 때문에 여기선 다시 안 해도 됨!
        // age = age --> (x)
        
    }
    //Human → 생성자 함수니까 이름은 클래스 이름과 똑같아야 해요.
    //const Human& other → 이게 복사할 대상, 즉 man이에요!
    //other는 우리가 임의로 붙인 이름이에요. "복사해올 대상"을 뜻해요.

    // 복사 생성자: 다른 Human 객체를 복사해서 새로운 객체를 만들 때 호출되는 함수
    Human(const Human& other) : age(other.age) {    // other는 복사할 대상(man)
        printf("copy constructor!!!\n");

        // 이름도 복사해야 하므로, 문자열 길이만큼 새 메모리 공간을 만들고
        name = new char[strlen(other.name) + 1];
        // 복사 대상의 이름을 현재 객체에 그대로 복사
        strcpy(name, other.name);
       
    }
    // 소멸자: 객체가 삭제될 때 자동으로 호출됨 (메모리 정리용)
    ~Human() {
        printf("delete Constructor~\n");

        // new로 할당한 메모리는 delete로 꼭 정리해야 함 (안 그러면 메모리 누수 생김!)
        delete[] name;
    }
    //사람 정보를 출력하는 함수
    void showHuman() { 
        printf("name: %s, age: %d\n", name, age);
    }
};

int main() {
    // "홍명보", 나이 30인 사람 객체 man을 생성함 → 생성자 호출
    Human man("홍명보", 30);   //man 객체 생성

    // man의 정보 출력
    man.showHuman();
    // man 객체를 복사해서 copyman 객체를 새로 만듦 → 복사 생성자 호출됨
    Human copyman(man);       // man을 복사해서 copyman을 만든다.
    // copyman의 정보도 출력 (man과 같은 정보가 출력되어야 함)
    copyman.showHuman();

    // 아래는 대입 연산자(=) 예시인데, 아직 operator= 안 만들어서 주석 처리함
     /*
     Human xman;
     xman = copyman;
     xman.showHuman();
     */

     // main 함수 끝나면 man과 copyman 객체는 자동으로 소멸되고 소멸자가 호출됨
    return 0;
}
