#include <iostream>
using namespace std;

/*
*  ������ constructor
*  ������ ȣ��� ��ü�� ���������.
*  ��ü ������ ������ �´� �����ڰ� ������ ��ü�� �������� �ʴ´�
*  �����ڴ� �ʱ�ȭ ��ɿ� ����Ѵ�.
*  �����ڴ� �����ε��� �����ϴ�.
*  ���α׷��Ӱ� �����ڸ� �ۼ��ϸ� �� �̻� ����Ʈ �����ڴ� �������� �ʴ´�.
*/

class MyClass {
private:
	int m_num1;
	int m_num2;
	int m_num3;

public:	
	MyClass(){}						// �⺻������(default ������)
	
	MyClass(int num1, int num2) {	//������(�Է��� �ΰ� �޴�)
		m_num1 = num1;
		m_num2 = num2;
	}

	MyClass(int num3) {
		m_num3 = num3;
	}
	~MyClass(){} //�Ҹ���
	void printData() {
		cout << "���� MyClass�� �ν��Ͻ� �Դϴ�";
		cout << "  m_num1:  " << m_num1 << "  m_num2:  " << m_num2 <<   "m_num3:   " << m_num3 <<endl;
		
	}
};

int main() {

	MyClass obj;
	MyClass obj2(100, 200);
	MyClass obj3(130);

	obj2.printData();
	obj3.printData();

	return 0;
}