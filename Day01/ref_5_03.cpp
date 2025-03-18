#include <iostream>
using namespace std;
/*
*	레퍼런스 - 선언과 동시에 반드시 초기화해야만 한다.
*/
int main() {
	int num = 10, num2 = 100;
	int& ref = num;	//num의 메모리 공간에 ref라는 별명이 붙는다.
	int* pn = &num;
	//int& rref;	//에러발생~!! 사용 선언과 동시에 초기화가 되어야함.
	//rref = ref;
	int& rref = ref; //num의 별명1.ref, 2.rref
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