#include <iostream>
using namespace std;
/*
*  메모리 동적 할당 : new - delete
*  new 포인터 = new 자료형(크기)
*  new는 생성자를 호출한다. 즉, new는 객체를 생성시킨다.
*  객체를 생성하기 위해서는 생성자 호출이 있어야 한다.
*/
int main() {

	int size;
	int* pary;

	//int* pn = new int;  //-> 힙영역에 int 크기로 동적 할당을 받는다.
	//delete pn;	// 동적영역 할당 메모리를 끊는다.
	cout << "크기 >> ";
	cin >> size;

	pary = new int[size]; //int형 타입의 연속적인 사이즈를 만들어라
	pary[0] = 1;
	pary[1] = 2;
	*(pary + 2) = 3;
	
	//출력
	cout << pary[0] << ", " << pary[1] << ", " << *(pary + 2) << endl;
	delete[] pary;



	return 0;
}