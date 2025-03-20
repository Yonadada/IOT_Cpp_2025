/*
	StaticTest Ŭ������ ����µ� ��������δ� 
	�̸�, ��ȭ��ȣ, �ּ�, ȸ����ȣ(cnt)�� ������.
	3�� �Է��� �޴� �����ڸ� �ۼ��Ѵ�.
	��, ȸ����ȣ�� �ڵ����� ������ų ���̴�.
	showmember - ��� ��� �޼��带 �����Ͻÿ�

*/
#define _CRT_SECURE_NO_WARININGS
#include <iostream>

class StaticTest {
private:
	char* uName;
	char* uTel;
	char* uAddr;
	int cnt;
public:
	StaticTest(const char* uName, const char* uTel, const char* uAddr, int cnt);
	~StaticTest();
	void showmember() const;

};

StaticTest::StaticTest(const char* uName, const char* uTel, const char* uAddr) :
	uName(nullptr), uTel(nullptr), uAddr(nullptr), age(age)
{
	try {
		this->uName = new char[strlen(uName) + 1];
		this->uTel = new char[strlen(uTel) + 1];
		this->uAddr = new char[strlen(uAddr) + 1];

		strcpy(this->uName, uName);
		strcpy(this->uTel, uTel);
		strcpy(this->uAddr, uAddr);
	}
	catch(std::bad_alloc& e){
		std::cout << "�޸� �Ҵ� ����" << e.what() << std::endl;
	}
	// �޸� �Ҵ� �Ҹ� 
	this->uName = nullptr;
	this->uTel = nullptr;
	this->uAddr = nullptr;
	this->cnt = 0;

}

StaticTest::~StaticTest() {
	delete[] 
}


StaticTest::showmember() {
	std::cout << "ȸ����ȣ: " << cnt << std::endl;
	printf("�̸�: %s, ��ȭ��ȣ: %s, �ּ�: %s\n", uName, uTel, uAddr);
}


int main() {
	StaticTest m1("ȫ����","010-1234-5678", "�λ� ������");
	m1.showmember();

	StaticTest m2("ȫ��Ű","010-2222-2222", "�λ� ������");
	m2.showmember();
	
	StaticTest m3("ȫ����","010-3333-3333", "�λ� ������");
	m3.showmember();


	return 0;
}