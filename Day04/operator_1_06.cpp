/*
	�����Լ� �����ε� : operator(p1,p2)
	1. public ����
*/

#include <iostream>

class Point {
public:
	int x, y;
	Point(int ax, int ay) : x(ax), y(ay) {}
	Point operator+(const Point& other) {				//��ü + ��ü
		return Point(x + other.x, y + other.y);
	}

	Point operator+(int n) {				//��ü + ����
		return Point(x + n, y + n);
	}

	void showPoint() {
		printf("x: %d, y: %d\n", x, y);
	}
};
//������ �����ε�

//�����Լ��� �ܺο�
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