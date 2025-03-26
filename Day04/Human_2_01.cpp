/* - Ŭ����, ������, ���� ������, �Ҹ��� -
	step03
	char �������� name, int Ÿ���� age, ����� ����ϴ� showHuman()�� ������ Human Ŭ������ �ִ�
	name�� ���� �Ҵ��ϰ� ����30, �̸� ȫ���� man ��ü�� �����Ͻÿ�.
	man ��ü�� �����Ͽ� copyman ��ü�� �����Ͻÿ�.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>  // c��Ÿ�� ���ڿ� �Լ�(strlen, strcpy) ����ϱ� ���� ���

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
    //Human �� ������ �Լ��ϱ� �̸��� Ŭ���� �̸��� �Ȱ��ƾ� �ؿ�.
    //const Human& other �� �̰� ������ ���, �� man�̿���!
    //other�� �츮�� ���Ƿ� ���� �̸��̿���. "�����ؿ� ���"�� ���ؿ�.

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
    Human man("ȫ��", 30);   //man ��ü ����
    man.showHuman();
    
    Human copyman(man);       // man�� �����ؼ� copyman�� �����.
    copyman.showHuman();

    /*Human xman;
    xman = copyman;
    xman.showHuman();*/
    return 0;
}
