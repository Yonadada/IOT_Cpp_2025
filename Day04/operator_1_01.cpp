/*
	
*/
#include <iostream>
class Myclass {
private:
	int m_a, m_b;
	//const char* m_name;
public:
	Myclass(int a = 0, int b = 0, const char* name = nullptr) : m_a(a), m_b(b)/*, m_name(name)*/ { }
	void showMyclass() {
		std::cout << m_a << ", " << m_b << ", " /*<< m_name*/ << std::endl;
	}
};

int main() {

	//Myclass obj{ 1,2, "ȫ�浿" };
	//obj.showMyclass();
	
	//Myclass obj2;			// default ������ ���� ���� ȣ���Ϸ��� ���� �����ڿ��� �ʱⰪ �����.
	//obj2 = obj;				// num = 10;, ����Ʈ ���� �����ڸ� �⺻������ �������ش�. 
	//obj2.showMyclass();		// obj�� ��ü�� �ִ� ��������� �����ؼ� obj2�� ����
							//������ �����ε� ����� �ֱ� ������ ����

	Myclass obj{ 10,20 };
	Myclass obj2{ 30,40 };
	Myclass obj3 = obj + obj2;	// �����߻� ~! => ���ڳ��� ���� ������ ��밡��, ����� ���� Ŭ���� ������ �ڵ����� ������ 
	return 0;
}