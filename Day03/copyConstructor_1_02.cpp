#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

/*
*  ���� ������ �ǽ� 
*/
class Person {
private:
	char name[20];
	int age;
public:
	Person(const char* name, int age) {
		strcpy(this->name, name);
		this->age = age;
	}
	//��ü�� Person �ְԵǸ� ���� �ݺ��� ��������ڰ� �����Ǽ� �����߻�~!
	//������ �ϰ� �ֱ� ������ Person�� ���� ����Ǿ�� �ȵȴ�.
	//�ް������� ���������� ȣ��Ǹ� ��������ڰ� ȣ��ȴ�. 
	//�ް������� ��ü�� ������ ����  Const ���� ���·� �޾ƾ� �Ѵ�. => ��ü�� ������ ���� ������ ������ 
	//��ü�� �Է����� �ö��� ��� ������ �޾ƾ��Ѵ�.
	Person(const Person& other) {		//��������� // p��� �ӽð�ü�� ������ ���� �����ڰ�  
		printf("--copy constructor--\n");
		this->age = other.age;
		strncpy(this->name, other.name, strlen(other.name) + 1);
	}


	void printData() {
		printf("name: %s, age: %d\n", this->name, this->age);
		std::cout << "�̸�: " << name << ", ����: " << age << std::endl;
	}


};
int main() {

	Person p("ȫ����", 3);
	p.printData();

	Person p2(p);	//default ���� ������
	p.printData();
	return 0;
}
