/*

*/
#include <iostream>

class AAA {
private:
	static int static_a;	// static ��� ����
	int n;

public:
	AAA(int n);		// static ��������� �����Ϸ���(����) static ��� �Լ��� ���� �����ϴ� ���� ���� ����!
	static void setStatic_a(int a);	//static ��� �Լ� -> static ����Լ��� ��ü���� ���θ�������� �ʰ� ����
	void print();
};

int AAA::static_a = 100; // static ������� �ʱ�ȭ 
//-> �ٲٱ� ���ؼ� setStatic_a() �ʿ�


AAA::AAA(int n) {
	this->n = n;
}
void AAA::print() {
	printf("static_a: %d, b: %d\n", static_a, n);
}

void AAA::setStatic_a(int a) {
	static_a = a;
	//n = 0;		// �Ϲ� ����� ������ ������ �ʰ�, static ����� ��븸 �����ϴ� 
}




int main() {
	AAA obj1(10), obj2(20);
	obj1.print();
	obj2.print();

	
	return 0;
}
