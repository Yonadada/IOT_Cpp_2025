#include <iostream>
using namespace std;
/*
*	moveConstructor(�̵�������)
* 
*/

int main() {
	int n = 10;
	int& rn = n;		//���۷���, �Ϲ�����
	const int& ra = 10;					// l -value ����

	//int rrn = 10; // ����� ���� �Ұ��� 
	int&& rrn = 10; // R-value ���� 

	cout << n << ", " << rn << ", " << ra << ", " << rrn << endl;

	return 0;
}