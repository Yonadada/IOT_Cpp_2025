/*
	연산자 오버로딩(다중정의)

*/

#include <iostream>

class Point {
public:
	int x, y;
	//디폴트 메개변수 설정
	Point(int ax = 0, int ay = 0) : x{ ax }, y(ay)
	{
		printf("constructor call!!\n");
	}

	void showPoint() {
		printf("x: %d, y: %d\n", x, y);
	}

	Point add(const Point& other) {
		printf("add() call \n");
		return Point(x + other.x, y + other.y); //동일한 타입끼리 연산
	}
};
int main() {

	Point obj(10, 20);
	obj.showPoint();

	Point obj2(30, 40);
	obj2.showPoint();

	Point obj3;
	obj3 = obj.add(obj2);
	obj3.showPoint();

	return 0;
}
