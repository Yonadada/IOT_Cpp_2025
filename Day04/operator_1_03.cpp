/*
* 객체를 더하는 함수 : add()
* 참조를 리턴한다.
* 
*/
#include <iostream>  // C++ 입출력 기능 사용을 위한 헤더

// Point 클래스 정의
class Point {
private:
	int x, y;  // x, y 좌표 값을 저장하는 멤버 변수

public:
	// 생성자(Constructor): 객체가 생성될 때 자동으로 호출됨
	// 기본값을 0으로 주었기 때문에 인자 없이도 생성 가능
	Point(int ax = 0, int ay = 0) : x(ax), y(ay) {
		printf("Constructor call!!\n");
	}

	// 다른 Point 객체를 받아서 현재 객체를 바꾸고, 자기 자신을 참조로 리턴하는 함수
	Point& add(const Point& other) {
		printf("add() call\n");

		// 현재 객체의 x, y 값을 매개변수로 받은 other의 값으로 덮어씀
		x = other.x;
		y = other.y;

		// 자기 자신을 참조로 반환 (*this는 현재 객체를 가리킴)
		return *this;
	}

	// x와 y 값을 출력하는 함수
	void showPoint() {
		printf("x: %d, y: %d\n", x, y);
	}
};

int main() {

	Point p(10, 20);    // (10, 20) 좌표를 가지는 Point 객체 p 생성
	Point p2(30, 40);   // (30, 40) 좌표를 가지는 Point 객체 p2 생성

	std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;

	// add() 함수는 p2의 값을 p에 복사하고, 그 결과(p 객체 자기 자신)를 참조로 리턴함
	// 리턴된 객체로 p3를 복사 생성
	Point p3 = p.add(p2);

	// p3의 좌표 출력 → p2와 동일한 (30, 40)이 출력됨
	p3.showPoint();

	return 0;  // 프로그램 종료
}