#include <iostream>

/*
	 ��ȯ������
	 �ٸ� Ÿ���� ��ü�� ��ȯ�� ��, ȣ��Ǵ� ������. �Է��� �Ѱ��� ������ ������
*/
class Myclass {
private:
	int value;

public:
	Myclass(int value) {
		printf("��ȯ ������ ȣ��!!\n");
		this->value = value;
	}

	void printMyclass() {
		printf("value: %d\n", value);
	}
}; //Myclass ��

int main() {

	//Myclass obj; // Myclass obj; -> obj ��ü�� ����� ���� �����ڰ� ���� ������ �����߻�~!
	Myclass obj = 10; //��ȯ�� ���� int�� Myclass Ÿ������ �ٲ����.
	obj.printMyclass();

	Myclass obj2{ 10 };
	obj2.printMyclass();

	return 0;
}