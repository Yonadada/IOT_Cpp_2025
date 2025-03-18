#include <iostream>
using namespace std;

void chFunc(int* _n) {

	*_n = 20;

}

int main() {

	int n = 10;
	cout << "호출 전 n: " << n << endl;

	chFunc(&n);

	cout << "호출 후 n: " << n << endl;

	return 0;
}

