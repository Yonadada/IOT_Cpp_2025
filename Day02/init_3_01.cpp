#include <iostream>
using namespace std;
/*
*	���� �ʱ�ȭ 
*/


int main() {

	int num = 3;		 // ���� �ʱ�ȭ
	int num2(30);		 // ���� �ʱ�ȭ
	int num3{ 300 };	 // �߰�ȣ ���� �ʱ�ȭ
	int num4 = { 3000 }; // �߰�ȣ ���� �ʱ�ȭ

	int x = 3.14;	// �Ϲ������� �����Ϸ��� �Ϲ������� ����ȯ
	int x1{ 3.14 };	// �߰�ȣ�� �Ϲ����� ����ȯ xx

	cout << num << endl;	//3
	cout << num2 << endl;	//30
	cout << num3 << endl;	//300
	cout << num4 << endl;	//3000
	cout << x << endl;		//3
	cout << x1 << endl;		//�����߻�!


	return 0;
}