#include <iostream>
using namespace std;
/*
* �ٸ� �Լ��� ����� ���������� ���� �ٲٴ� ���
* ���۷��� - �� �ٸ� �̸�, ������ �ʴ� ������
*/

void chFunc(int& rn) {	//���۷���(��������)����

	rn = 20;

}
int main() {

	int n = 10;
	cout << "ȣ�� �� n: " << n << endl;

	chFunc(n);

	cout << "ȣ�� �� n: " << n << endl;

	return 0;
}
