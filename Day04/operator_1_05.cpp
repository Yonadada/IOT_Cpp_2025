/*
*  ���� 
*	MyClass obj(10, 20);
MyClass obj2(20, 30);
MyClass obj3 = obj.add(obj2);
MyClass obj4 = obj.operator + (obj3);
�����Ű��
*/

#include <iostream>  // ȭ�鿡 ����ϱ� ���� �ʿ��� �ڵ�

// MyClass��� ���赵(Ŭ����)�� �����
class MyClass {
private:
int x, y;  // �� ���� ���� ������ ����

public:
// ��ü�� ���� �� x�� y�� �ʱ�ȭ���ִ� ������
MyClass(int a, int b) : x(a), y(b) {}

// �ٸ� ��ü�� ���ؼ� ���ο� ��ü�� ������ִ� �Լ�
MyClass add(const MyClass& other) {
	return MyClass(this->x + other.x, this->y + other.y);
}

// + �����ڸ� ����� �� �ֵ��� ���ִ� �Լ� (�����ε�)
MyClass operator+(const MyClass& other) {
	return MyClass(this->x + other.x, this->y + other.y);
}

// int ���� ���� �� �ֵ��� ���ִ� �Լ� (�����ε�)
MyClass operator+(int value) {
	return MyClass(this->x + value, this->y + value);
}

// ���� ��ü�� x, y ���� ȭ�鿡 �����ִ� �Լ�
void showMyClass() {
	std::cout << "x: " << x << ", y: " << y << std::endl;
}
};

int main() {
MyClass obj(10, 20);      // x=10, y=20�� ��ü ����
MyClass obj2(20, 30);     // x=20, y=30�� ��ü ����

MyClass obj3 = obj.add(obj2);  // obj�� obj2�� ���� ���ο� ��ü ���� (x=30, y=50)
MyClass obj4 = obj.operator+(obj3);  // obj�� obj3�� ���� ���ο� ��ü ���� (x=40, y=70)
MyClass obj5 = obj4 + 100;  // obj4�� 100�� ���� ���ο� ��ü ���� (x=140, y=170)  // obj4.operator + (100);
//Q. 200 + obj4�� �� �ȵǳ�? 


obj.showMyClass();   // obj �� ���: x: 10, y: 20
obj2.showMyClass();  // obj2 �� ���: x: 20, y: 30
obj3.showMyClass();  // obj3 �� ���: x: 30, y: 50
obj4.showMyClass();  // obj4 �� ���: x: 40, y: 70
obj5.showMyClass();  // obj5 �� ���: x: 140, y: 170

return 0;  // ���α׷� ��!
}

// �����ε� �� �� ���� ������:
// ::, ., *, sizeof