#include <iostream>
using namespace std;
/*
	reinterpret_cast
	포인터 -> 포인터, 포인터 -> 변수, 변수 -> 포인터로 하는 주로 포인터 관련 연산자
*/
int main() {
	int* ip = new int{ 10 };		 
	long lg = reinterpret_cast<long>(ip);			// int* --> long
	unsigned int ui = reinterpret_cast<int>(ip);	// int* --> unsinged int
	printf("ip: %d, lg: %d, ui: %d\n", ip, lg, ui);

	/* x86에서만 실행 가능*/
	// int* p = reinterpret_cast<int*>(lg);			// long --> int*
	int* p1 = reinterpret_cast<int*>(ui);			
	printf("p1: %d\n", *p1);			// 간접참조 사용


	int* p = new int{ 100 };
	char* pc = reinterpret_cast<char*>(p);
	printf("c: %d\n", *pc);						// int* --> char*

	//delete p;

	int* p2 = reinterpret_cast<int*>(pc);		// char* --> int*
	printf("p: %d", *p2);

	return 0;
}

char ch = 10;
int n = (int)ch;
