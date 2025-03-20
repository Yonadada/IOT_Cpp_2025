#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
/*
* ��������� 
*  name�� �����Ҵ� ������?
*/

class Person {
private:
	char* name;
	int age;
public:
	Person(const char* name, int age); // �����Ҵ�
	Person(const Person& other); // ���������(���� ����)
	~Person();	// �Ҵ�����
	void printData() const;
};

//������ ���� 
Person::Person(const char* name, int age) : name(nullptr), age(age) {

	try {
		//�����Ҵ� �߻� ���� 
		this->name = new char[strlen(name) + 1]; // name ���� ��ŭ 

		//���ڿ� ����
		strcpy(this->name, name);
	}
	catch (std::bad_alloc& e){
		std::cout << "�޸� �Ҵ� ����" << e.what() << std::endl;
		
	//�޸� �Ҵ� ����(�Ҹ���)
		this->name = nullptr;
		this->age = 0;
	}
}// ������ ����

//���� ������ ����
Person::Person(const Person& other) : name(nullptr), age(other.age) {
	printf("constructor call\n");
	try {
		this->name = new char[strlen(other.name) + 1];
		this->age = other.age;
		strncpy(this->name, other.name);
	}
	catch (std::bad_alloc& e) {
		std::cout << "�޸� �Ҵ� ����: " << e.what() << std::endl;
		this->name = nullptr;
		this->age = 0;
	}
}



Person::~Person() {
	if (name) {
		delete[] name;
		name = nullptr;
	}

}

void Person::printData() const{
	if (!name) {
		std::cout << "--������ �Ҵ� ������--" << std::endl;
		return;
	}
	std::cout << "�̸�: " << name << "����: " << age << std::endl;

}
int main() {

	Person p("ȫ��Ű", 6);

	p.printData();

	Person p2 = p;
	p2.printData();

	return 0;
}
/*
*  ����Ʈ�� �ڵ� �����޴� ������ : ����Ʈ ������, ���� ������, �Ҹ���
*/