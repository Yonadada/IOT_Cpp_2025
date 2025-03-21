/*
	step03
	char �������� name, int Ÿ���� age, ����� ����ϴ� showHuman()�� ������ Human Ŭ������ �ִ�
	name�� ���� �Ҵ��ϰ� ����30, �̸� ȫ���� man ��ü�� �����Ͻÿ�.
	man ��ü�� �����Ͽ� copyman ��ü�� �����Ͻÿ�.
	xman = man�� �����Ű�ÿ�.
*/
#define _CRT_SECURE_NO_WARNINGS  // strcpy ���� �Լ����� ���� ��� ������
#include <iostream>
#include <cstring>  // ���ڿ� ���� �Լ� (strlen, strcpy ��)�� ���� ���� ���

// Human Ŭ���� ����
class Human {
private:
    char* name;  // �̸��� ������ ������
    int age;     // ����

public:
    // ������: �̸��� ���̸� �ʱ�ȭ�ϰ� �̸��� ���� �޸� �Ҵ�
    Human(const char* m_name = " ", int m_age = 0) : age(m_age) {
        name = new char[strlen(m_name) + 1];  // �ʿ��� ��ŭ �޸� �Ҵ�
        strcpy(name, m_name);                 // �̸� ����
    }

    // ���� ������: �ٸ� ��ü�κ��� ���� ������ �� ���
    Human(const Human& other) : age(other.age) {
        printf("copy constructor!!!\n");
        name = new char[strlen(other.name) + 1];  // ���ο� �޸� �Ҵ�
        strcpy(name, other.name);                // �̸� ����
    }

    // �Ҹ���: ��ü�� ����� �� ȣ��Ǿ� �޸� ����
    ~Human() {
        printf("delete Constructor~\n");
        delete[] name;  // ���� �Ҵ�� �޸� ����
    }

    // ���� ��� �Լ�
    void showHuman() {
        printf("name: %s, age: %d\n", name, age);
    }

    // ���� ������ �����ε�: �̹� ������� ��ü�� �ٸ� ��ü�� ������ ��
    Human& operator=(const Human& other);
};

// ���� ������ �Լ� ����
Human& Human::operator=(const Human& other) {
    if (this != &other) {  // �ڱ� �ڽ��� �ƴ� ��쿡�� ó��
        delete[] name;     // ���� �޸� ����
        printf("operator overloading\n");

        // ���Ӱ� �޸� �Ҵ��ϰ� ����
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        age = other.age;
    }
    return *this;  // �ڱ� �ڽ��� ������ ����
}

// ���� �Լ�: ���� ����Ǵ� �κ�
int main() {
    Human man("ȫ��", 30);   // �̸��� ���̷� man ��ü ����
    man.showHuman();          // ���: name: ȫ��, age: 30

    Human copyman(man);       // man�� �����ؼ� copyman ���� (���� ������ ȣ��)
    copyman.showHuman();      // ���: name: ȫ��, age: 30

    Human xman = copyman;     // copyman�� �����ؼ� xman ���� (���� ������ ȣ��)
    xman.showHuman();         // ���: name: ȫ��, age: 30

    return 0;  // ���α׷� ����
}