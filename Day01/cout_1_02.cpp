#include <iostream>
using namespace std; //using 사용해서 namespace std객체를 선언
/*
* 
*/

int main() {

	int num = 100;
	char str[100] = "홍여원";
	double d = 3.14;

	std::cout << "abcdefg"; 

	std::cout << num << std::endl;	//abcdefg100

	std::cout << str << std::endl;	//홍여원

	cout << d << endl;	//3.14
		return 0;
}