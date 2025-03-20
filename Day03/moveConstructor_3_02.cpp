#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

/*
*  �̵�������(T&&)
* r-value reference �� �Ƕ�̵�� �޴� �̵� ������ 
*/

using namespace std;

class Human {
private:
	char name[10];
	int age;

public:
	// �Է�2�� �޴� ������
	Human(const char* name, int age) {
		printf("�Է� 2�� �޴� ������ ȣ��");
		strcpy(this->name, name); // name�� ����
		this->age = age; // age�� �ʱ�ȭ
	}
	// ��������� -> �����ϴ� �����͸� �����ؼ� ������ 
	Human(const Human& other) {	
		printf("���� ������ ȣ��\n");
		strcpy(this->name, other.name);
		this->age = other.age;
	}
	
	// �̵������������ؾ� �� ���� �����͸� �̵����ѹ��� -> ���̻� �޸𸮸� �������� ����
	Human(Human&& other) noexcept {	// �̵������ڿ����� noexcept ��� -> ���� �߻��� ���� 
		printf("�̵� ������ ȣ��\n");
		strcpy(this->name, other.name);
		this->age = other.age;
		//other.name[0] = '\0'; // �̵� �� ���� ��ü�� name�� �ʱ�ȭ -> �����͸� �̵����ѹ��ȱ� ������ ���� ���� ��ü�� 0���� �ʱ�ȭ��Ŵ
		other.age = 0; // �̵� �� ���� ��ü�� age�� �ʱ�ȭ
	}

	void printHuman() {
		printf("name: %s, age: %d\n", this->name, this->age);
	}
};

int main(){
	Human h1("ȫ����", 1);
	h1.printHuman();

	Human h2(h1);
	h2.printHuman(); 
	
	Human h3(std::move(h1)); //
	h3.printHuman();// �̵������� ȣ��
	h1.printHuman();

	return 0;
}
