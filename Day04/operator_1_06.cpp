/*
	전역함수 오버로딩 : operator(p1,p2)
	1. public 선언
*/

#include <iostream>

class Point {
public:
	int x, y;
	Point(int ax, int ay) : x(ax), y(ay) {}
	Point operator+(const Point& other) {				//객체 + 객체
		return Point(x + other.x, y + other.y);
	}

	Point operator+(int n) {				//객체 + 정수
		return Point(x + n, y + n);
	}

	void showPoint() {
		printf("x: %d, y: %d\n", x, y);
	}
};
//연산자 오버로딩

//전역함수는 외부에
Point operator+(int n, const Point& other) {
	return Point(n + other.x, n + other.y);
}

int main() {

	
	Point a(10, 20);
	Point b(30, 40);
	Point c = a + b;
	Point d = a + 100;
	Point e = 200 + b;

	a.showPoint();
	b.showPoint();
	c.showPoint();
	d.showPoint();
	e.showPoint();

	return 0;
}