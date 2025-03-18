#include <iostream>
using namespace std;
/*
*   출력인 경우: 일반변수
*/

int func(int& anum){

	anum++;
	return anum;

}

int main() {
	int num = 10;
	//int& res = func(num); // 에러발생~! res는 anum의 또다른 별명이고, 함수가 실행되면 anum이 끝났는데 그걸 참조한다는 것은 말이 안된다, 없어져서 에러발생
	const int& res = func(num); //-> const 임시객체를 저장할 수 있는 공간이 만들어서 참조되는 이름을 붙이면 된다
	cout << res << endl;	//11
	
	return 0;
}
