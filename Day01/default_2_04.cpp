#include <iostream>
#include <math.h>
using namespace std;

/*
*	����Ʈ �Ű������� ������ ������ ���� �� �����ʺ��� ������� �ۼ��Ѵ�.
*/

int coordinates(int x, int y = 0, int z = 0);	// default ���� �Լ����� ���𿡸� �ۼ�!!! 
int main() {

	// �ް����� ����Ʈ���� �� �����ʺ��� ȣ��ȴ� 
	cout << "(10,20,30): " << coordinates(10, 20, 30) << endl;	//(10,20,30): 0
	cout << "(10,20, def): " << coordinates(10, 20) << endl;	//(10,20, def): 0
	cout << "(10,def,def): " << coordinates(10) << endl;		//(10,def,def): 0

	return 0;
}

int coordinates(int x, int y, int z) {

	int res = 0;
    res = pow(x, 2) + pow(y, 2) + pow(z, 2);	// ����
	
	return sqrt(res);					//������
}