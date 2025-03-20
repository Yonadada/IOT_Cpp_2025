#include <iostream>
	// malloc()을 사용하기 위한 헤더
using namespace std;

/*
* 동적 할당 받을 크기를 입력받고 원소를 저장하여 출력하시오.
*/

int main() {
	int size; // 배열 크기 변수
	int* p; // 정수형 포인터

	// 사용자로부터 크기 입력받기
	cout << "크기>> ";
	cin >> size;

	// 동적 메모리 할당 (올바른 크기 계산)
	p = (int*)malloc(size * sizeof(int)); // size개 정수를 저장할 크기 할당
	 // 형변환
	


	// 메모리 할당 실패 확인
	if (p == NULL) {
		cout << "메모리 할당 실패!" << endl;
		return -1;
	}
	// 원소 입력
	cout << size << "개의 원소 입력>> ";
	for (int i = 0; i < size; i++) {
		cin >> p[i]; // 입력받기
	}
	// 원소 출력
	cout << "입력한 원소: ";
	for (int i = 0; i < size; i++) {
		cout << p[i] << " ";
	}

	cout << endl;

	// 동적 메모리 해제
	delete[] p;

	return 0;
}