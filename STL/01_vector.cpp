#include <iostream>
#include <vector>		// vetor 헤더파일 포함
using namespace std;
/*
	Vector
*/
int main() {

	/*std::*/vector<int> v;		// 빈 벡터 객체 생성
	vector<int> v1{ 10 };		// 원소 10을 갖는 벡터 생성
	vector<int> v2(5);			// 원소 0으로 초기화된 크기 5의 백터 생성
	vector<int> v3 = { 1, 2, 3, 4, 5, 6 };	// 원소 6개를 갖는 벡터 생성

	cout << "arr size: " << v.size() << endl;	// 0
	cout << "v1 size: " << v1.size() << endl;	// 1
	cout << "v2 size: " << v2.size() << endl;	// 5
	cout << "v3 size: " << v3.size() << endl;	// 6

	for (int i = 0; i < 5; i++) {
		printf("v2[%d]: %d   ", i, v2[i]);		// 벡터 원소 값 출력 (기본값 0으로 초기화)
	}
	cout << endl;
	for (auto i : v3) {					// 범위기반 for문 -> 인덱스 사용 불가!
		//cout << v3[i] << endl;

		cout << i << endl;
	}
	/* begin()과 end()는 iterator(반복자) 타입을 반환(포인터처럼 동작) */
	cout << "v3의 첫번째 요소값: " << *v3.begin() << endl;		// * 간접참조
	cout << "v3의 마지막 요소값: " << *(v3.end() - 1) << endl;	// -1 !!




	return 0;
}
/*
	vector.size() : 원소 크기(갯수)를 반환
	vector.begin() : 벡터의 첫 번째 원소를 가리키는 반복자 반환
	vector.end() : 벡터의 끝을 가리키는 반복자 반환
*/