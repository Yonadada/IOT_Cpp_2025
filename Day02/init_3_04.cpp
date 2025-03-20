#include <iostream>

/*
*	����ʱ�ȭ
*  1. ��� ��� ���� ��ü�� �����ɶ� 
*  2. �������� ��ü�� �����Ǳ� ���� �ʱ�ȭ
*  3. ��ü�� ����� ������ ���
*/

class ConstClass {
private:
	int m_value;
	const int m_value2; // ��� ��� ������ ��ü�� ������ ��, �ݵ�� �ʱ�ȭ�� �Ǿ�� �Ѵ�. --> �ݷ� �ʱ�ȭ

public:
	ConstClass(int value, int value2) : m_value2(value2) {
		m_value = value; 
	} //�ʱ�ȭ
	void showValue() {
		printf("m_value: %d\n, m_value2: %d\n", m_value, m_value2);
	}

};
class RefClass {	
private:
	int& ref;	//�������� ���� ��ü�� �����Ǳ� ���� �ݵ�� �ʱ�ȭ�� �̷������ �Ѵ�.

public:
	RefClass(int& r) : ref(r) {}
	void showValue(){
		printf("ref: %d\n", ref);
	}

};

class Position {
private:
	int m_x;
	int m_y;
public:
	Position(int x, int y) {
		printf("Position ������!!\n");
		m_x = x, m_y = y;
	}
	void getData() {
		printf("m_x: %d, m_y: %d\n", m_x, m_y);
	}
};

class ObjClass { //obj��ü�� ����� ���� ���� position �� ����� �־�� �ؼ� �ʱ�ȭ�� ���� �۾��� �ؾ���
private:
	Position pos; //��ü������� -> ��ü�� ��������� ������ 
public:
	ObjClass(int x, int y) : pos{ x,y } { printf("ObjClass constructor!!\n"); }
	void showValue() {
		pos.getData();
	}
	

};



int main() {
	ConstClass obj(10, 20);
	obj.showValue();

	int n = 50;
	RefClass obj2(n);
	obj.showValue();


	std::cout << "=============================" << std::endl;
	ObjClass o(3, 6);
	o.showValue();
	return 0;
}