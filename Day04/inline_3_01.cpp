/*
	inline
*/

#include <iostream>

#define ADD(a, b) #a "+" #b	 // 매크로 함수 // #은 문자열로 출력 
#define	PI			3.14
#define MSG(x,y,z)  x ## y ## z

int main() {

	printf("ADD(a,b): %s\n", ADD(10,20));
	printf("MSG(x, y, z): %s\n", MSG("macro + ", "operator +", "test"));

	return 0;
}