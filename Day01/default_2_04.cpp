#include <iostream>
#include <math.h>
using namespace std;

/*
*	디폴트 매개변수를 여러개 적용할 때는 맨 오른쪽부터 순서대로 작성한다.
*/

int coordinates(int x, int y = 0, int z = 0);	// default 값은 함수원형 선언에만 작성!!! 
int main() {

	// 메개변수 디폴트값은 맨 오른쪽부터 호출된다 
	cout << "(10,20,30): " << coordinates(10, 20, 30) << endl;	//(10,20,30): 0
	cout << "(10,20, def): " << coordinates(10, 20) << endl;	//(10,20, def): 0
	cout << "(10,def,def): " << coordinates(10) << endl;		//(10,def,def): 0

	return 0;
}

int coordinates(int x, int y, int z) {

	int res = 0;
    res = pow(x, 2) + pow(y, 2) + pow(z, 2);	// 제곱
	
	return sqrt(res);					//제곱근
}