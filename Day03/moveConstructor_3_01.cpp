#include <iostream>
using namespace std;
/*
*	moveConstructor(이동생성자)
* 
*/

int main() {
	int n = 10;
	int& rn = n;		//레퍼런스, 일반참조
	const int& ra = 10;					// l -value 참조

	//int rrn = 10; // 상수는 참조 불가능 
	int&& rrn = 10; // R-value 참조 

	cout << n << ", " << rn << ", " << ra << ", " << rrn << endl;

	return 0;
}