/*
*	객체를 더하는 함수: add()
*	객체를 리턴시킨다.
*/
#include <iostream>
class Point {
public:
	int x, y;
	Point(int ax = 0, int ay = 0) : x(ax), y(ay) {
		printf("constructor\n");
	}

	void showPoint() {
		printf("x: %d, y: %d\n", x, y);
	}

	Point(const Point& other) {
		printf("copy constructor\n");
		x = other.x;
		y = other.y;
	}
	Point add(const Point& other) {
		printf("add()\n");
		return Point(x + other.x, y + other.y);
	}
};
int main() {

	Point p(10, 20);
	Point p2(30, 40);
	std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	Point p3;
	p3 = p.add(p2);
	p3.showPoint();

	return 0;
}