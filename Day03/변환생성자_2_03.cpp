#include <iostream>

/*
	 ��ȯ������
	 �ٸ� Ÿ���� ��ü�� ��ȯ�� ��, ȣ��Ǵ� ������. �Է��� �Ѱ��� ������ ������
	 �Է��� �� �Ѱ��� ������ ������
*/
class Myclass {
private:
	int value;

public:
	explicit Myclass(int value) {
		printf("��ȯ ������ ȣ��!!\n");
		this->value = value;
	}

	void printMyclass() {
		printf("value: %d\n", value);
	}
}; //Myclass ��

int main() {

	//Myclass obj; // Myclass obj; -> obj ��ü�� ����� ���� �����ڰ� ���� ������ �����߻�~!
	//Myclass obj = 10; //��ȯ�� ���� int�� Myclass Ÿ������ �ٲ����. ��ȯ������ ȣ�� - ��ü�� ��ȯ�� �Ͼ
	//obj.printMyclass();	// ���������� ��ȯ�� �Ͼ�� ���� �����Ѵ�.

	Myclass obj2{ 10 };	//��ü �����Ҷ� �ʱⰪ�� �ִ� �ڵ忩�� ������ ���� �ʴ´�.
	obj2.printMyclass();

	return 0;
}