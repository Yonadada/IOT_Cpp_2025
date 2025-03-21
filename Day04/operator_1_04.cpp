/*
*	����Լ� ������ �����ε� : p1 operator ������(p2)  //operator ���� X
*	ex) p1 operator + (p2)
*/
#include <iostream>
class Myclass {
private: 
	int value;
public:
	Myclass(int n) : value(n) {}
	Myclass operator + (const Myclass& other) {		// ������ �����ε� 
		printf(" + overloading");
		return Myclass(value + other.value);	
	}
	void showMyclass() {
		printf("value: %d\n", value);
	}
};
#include <iostream>

int main() {
	Myclass obj(10);			//�ʱⰪ�� ������ ��ü ����
	obj.showMyclass();

	Myclass obj2(obj);			// obj�� �����ؼ� ��ü ����
	obj2.showMyclass();

	Myclass obj3 = obj2;		// obj�� �����ؼ� ��ü ����
	obj3.showMyclass();

	//Myclass obj4 = obj + obj2 + obj3;	// ��ü�� ���� ����� ������  ��ü ����
	Myclass obj4 = obj.operator+(obj2);
	obj4.showMyclass();

	return 0;
}