#include <iostream>
using namespace std;
/*
*	������۷��� : ����� ������ �����ϴ�. -> const Ű���带 ���̸� 
*/

int main() {

	int n = 10;
	//int& ref = n;
	const int& ref = 10;		//������۷����� �����ϸ� ���ͷ��� ������ �� �ִ�.
								//�ӽð�ü�� ������ �� �ִ� ������ �����ȴ�. 

	cout << "ref: " << ref << endl;		//10

	return 0;
}