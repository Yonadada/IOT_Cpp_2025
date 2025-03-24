/*
	Virtual class - ���� �����ڸ� ������ �޼��带 ���� ���� �Լ��� �ϸ�,
					�� ���� ���� �Լ��� ������ Ŭ����
				  - �߻� Ŭ������ ��ü�� ������ �� ����.
*/
#include <iostream>

class Cinterface { // ��ü�� ������ �� ����
public :
	Cinterface() { std::cout << "Cinterface constructor" << std::endl; } 
	virtual void getData() const = 0;			//���� ���� �Լ�
};

class CinSub : public Cinterface {
public:
	CinSub() { std::cout << "CinSub constructor " << std::endl; }
	void getData() const override {	// ���� ���� �Լ��� �����Ǹ� �ؾ߸� Cinterface ��ü�� �� �� �ִ�.
		std::cout << "Pure Virtual Function()" << std::endl;
	}
};


int main() {

	//Cinterface obj;	// �߻�Ŭ������ ���� �����Լ��� ������ ������ ��ü�� ���� x
	CinSub obj;
	obj.getData();
	
	return 0;
}