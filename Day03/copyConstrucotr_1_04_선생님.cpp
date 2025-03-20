#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
/*
   deep copy 복사 생성자
   동적할당 받은 경우 복사하는 객체도 동적 할당 받아서 별개로 복사하여 저장이 되어야 한다
*/
class Person {
private:
    char* name;
    int age;
public:
    Person(const char* pname, int p_age) {
        printf("constructor call!\n");
        name = new char[strlen(pname) + 1];         // 동적할당
        strcpy(name, pname);
        age = p_age;
    }
    Person(const Person& per) {
        printf("copy constructor!!\n");
        name = new char[strlen(per.name) + 1];
        // 복사생성자에서도 heap 영역 할당 받아서 값을 복사해서 집어 넣어야 함
        strncpy(this->name, per.name, strlen(per.name) + 1);
        this->age = per.age;
    }
    ~Person() {   // 소멸자
        delete[] this->name;
    }
    void printPerson() {
        cout << "name: " << name << ", age: " << age << endl;
    }
};


int main() {

    Person p("이순신", 50);
    p.printPerson();

    Person p2(p);
    p2.printPerson();

    Person p3(p);
    p3.printPerson();

    return 0;
};

/*
   디폴트로 자동으로 제공받는 생성자: 디폴트 생성자, 복사 생성자, 소멸자
*/