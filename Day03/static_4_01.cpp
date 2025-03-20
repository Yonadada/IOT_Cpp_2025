/*
	static - Ŭ���� �����(this �����Ͱ� ����)
	��ü���� �����Ѵ�.
*/
// ��ü �����  VS Ŭ���� ��� => ������ �˾Ƴ���!!!!
#include <iostream>

class StaticTest {
public:
	int n;
	static int static_n;	// static ��� ����
	StaticTest();
	void print();
};

int StaticTest::static_n = 10;	// static  ������� �ʱ�ȭ�� �ݵ�� Ŭ���� �ܺο��� �̷�������� .

//������ 
StaticTest::StaticTest() {
	n = 20;
	static_n = 10;
}
void StaticTest::print() {
	std::cout << "Static_n: " << static_n << "n: " << n << std::endl;
}


int main() {

	StaticTest ob1, ob2;
	ob1.print();
	ob2.print();

	ob2.static_n = 1000;
	ob2.n = 50;
	ob2.print();
	ob1.print();

	return 0;
}
