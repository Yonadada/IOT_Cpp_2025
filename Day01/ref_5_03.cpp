#include <iostream>
using namespace std;
/*
*	���۷��� - ����� ���ÿ� �ݵ�� �ʱ�ȭ�ؾ߸� �Ѵ�.
*/
int main() {
	int num = 10, num2 = 100;
	int& ref = num;	//num�� �޸� ������ ref��� ������ �ٴ´�.
	int* pn = &num;
	//int& rref;	//�����߻�~!! ��� ����� ���ÿ� �ʱ�ȭ�� �Ǿ����.
	//rref = ref;
	int& rref = ref; //num�� ����1.ref, 2.rref
	rref = num2;
	cout << rref << ", " << num2 << endl;


	num++;
	ref++;
	(*pn)++;

	cout << "num++: " << num << endl;
	cout << "ref++: " << ref << endl;
	cout << "*(pn)++: " << *pn << endl;	//*(pn)++: 13s

	cout << "&num: " << &num << endl;	//&num: 0000006A6195F4E4
	cout << "&ref: " << &ref << endl;	//&ref: 000000105E50F564	





	return 0;
}