/*
*  step 1. �̸��� ��ȭ��ȣ�� �����Ҵ� 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class Human {
private:
	char* pname;	//�������� �Ҵ��Ϸ��� ���� ������ �� �־�� �Ѵ�. �׷��� const ������ �ʴ´�.
	int age;		// ���� (�Ϲݺ���)
	char* ptel;		// ���� �Ҵ��� ��ȭ��ȣ ������

public:
	// ������: �̸�, ����, ��ȭ��ȣ�� �޾� ���� �Ҵ���.
	Human(const char* _name, int _age, const char* _ptel);// ������ ���� 

	// �Ҹ���: ���� �Ҵ�� �޸𸮸� ����
	~Human();// �Ҹ��� ����

	// ������ ����Լ� (��� ������ �������� �����Ƿ� const ���)
	void getData() const;	//����Լ�(��� �Լ�)
};


//������ ���� 
//�ʱ�ȭ ����Ʈ ��� 
// 1. ��� ������ �� ������ �ʱ�ȭ �� �� ���� => ��������ȭ
// 2. C++������ const ��� ������ ���� ����(&)�� �ʱ�ȭ ����Ʈ�� ����ؾ߸� �ʱ�ȭ ����
// 3. C++������ Ŭ���� ���ο� �ٸ� ��ü�� ��� ������ ���� ��, �ʱ�ȭ ����Ʈ�� �ݵ�� ���

Human::Human(const char* _name, int _age, const char* _ptel) : pname(nullptr), age(_age), ptel(nullptr)
// nullptr->������ �ʱ�ȭ ����Ʈ���� �����Ͱ� ��ȿ���� ���� �޸𸮸� ����Ű�� �ʵ��� �� �� �ִ�.
{
	try {	//  null ������ üũ�δ� new �����ڿ� ���� ����ó���� �� �� ����. -> try-catch �ַ�

		// ���� �Ҵ� (���ܹ߻� ����)
		pname = new char[strlen(_name) + 1];
		ptel = new char[strlen(_ptel) + 1]; // �޸𸮿� ���� ��ŭ �Ҵ�

		// �Ҵ�� �޸𸮿� ���ڿ� ����
		strcpy(pname, _name);
		strcpy(ptel, _ptel);
	
		//bad_alloc& e�� std::bad_alloc ���� ��ü�� �����ϴ� ����
		//C++���� new �����ڰ� �޸� �Ҵ翡 �����ϸ� std::bad_alloc ���ܸ� ������.
	} catch (bad_alloc& e) { // �����Ҵ� ���� �� ����ó��, ���� ��ü�� ��������(&)�� �޾ƾ� ������ ����  
		cout << "�޸� �Ҵ� ����: " << e.what() << endl;	// e.what()�� ����ϸ� ���� �޼��� Ȯ�ΰ���

		// ���ܰ� �߻����� �� �Ϻ� �޸𸮰� �̹� �Ҵ�Ǿ� ���� �� ����!
		delete[] pname;	//�̹� �Ҵ�� �޸𸮰� ������ ����
		delete[] ptel;	
		//* ù��° �Ҵ��� ����, �ι��� �Ҵ翡�� ���� �߻� ��, �Ҹ��ڰ� ������� ����
		//	�׷��� catch��Ͽ��� �̹� �Ҵ�� �� �����ϰ� �����ϱ� ����.


		// �����͸� 'nullptr'�� �����ؼ� �߸��� ���� ����
		// �����Ͱ� nullptr�� �ƴϸ�, ������ �޸𸮸� ����ų ���ɼ��� �ֱ⶧���� nullptr�� �ʱ�ȭ
		pname = nullptr;
		ptel = nullptr;
		age = 0;	// ���ܰ� �߻��ص� age���� �������� �� �ִ�. -> �����ϰ� ��(0)���� ���� 
	}
}//������ ����


// �������� �Ҵ�� �޸� ���� -> �ѹ� ������ �� �����͸� ���� ������, ������ ���� �Ǵ� ���� �߻����ɼ� 
// ���������� �������� nullptr�� �ʱ�ȭ �ؾ��Ѵ�.
// �����ϰ� �����ϱ� ����
Human::~Human() {
	if (pname) { //nullptr üũ : nullptr�� �ƴҶ��� delete[] ����	
		
		delete[] pname;
		pname = nullptr;	// ��� ��쿡 nullptr üũ�� �ʿ�
	}
	if (ptel) {
	
		delete[] ptel;
		ptel = nullptr;
	}
}

// ������ ��� �Լ�
// try-catch���� ���� pname,ptel�� nullptr�� ���, ���α׷��� �浹�ϰų� �̻��� �� ��µ� ���ɼ��� ����
// ����ó�� ��, �����ϰ� �����ϱ� ���� nullptr�� �ι� üũ
void Human::getData() const{ //�������� ����
	if (!pname || !ptel) { // not ������, pname�� nullptr�̸� true, �׷��� ������ false ��ȯ -> �����ϳ� true, true
		cout << "--������ �Ҵ��� ���� ���߽��ϴ�--" << endl;
		return;
	}
	cout << "�̸�: " << pname << ", ����: " << age << ", ��ȭ��ȣ: " << ptel;
}



int main() {
	// Human ��ü ���� 
	Human h("ȫ�浿", 30, "010-1234-1234");

	// ������ ��� 
	h.getData();

	return 0;
}