#include <iostream>
using namespace std;
/*
*   ����� ���: �Ϲݺ���
*/

int func(int& anum){

	anum++;
	return anum;

}

int main() {
	int num = 10;
	//int& res = func(num); // �����߻�~! res�� anum�� �Ǵٸ� �����̰�, �Լ��� ����Ǹ� anum�� �����µ� �װ� �����Ѵٴ� ���� ���� �ȵȴ�, �������� �����߻�
	const int& res = func(num); //-> const �ӽð�ü�� ������ �� �ִ� ������ ���� �����Ǵ� �̸��� ���̸� �ȴ�
	cout << res << endl;	//11
	
	return 0;
}
