/*
	실습
	01 + 복사생성자도 만들기
	- 출력을 참조로 주는 형태
*/

#include <iostream>

class Point {
public:
	int x, y;
	Point(int ax = 0, int ay = 0) : x(ax), y(ay) { printf("constructor\n"); }
	Point(const Point& other) {
		printf("copy constructor\n");
		x = other.x;
		y = other.y;
	}
	const Point& add(const Point& other) {	//참조형태로 리턴 시켜준다.
		printf("add()\n");
		return Point(x + other.x, y + other.y); //임시객체가 생성되어 Point bj3에 대입 ,
										//객체를 리턴시킬 때도 생성자 호출 가능 
	}

	void showPrint() {
		printf("x: %d, y: %d", x, y);
	}

};

int main() {

	Point obj(10, 20);
	//obj.showPrint();

	Point obj2(30, 40);
	//obj2.showPrint();

	//Point obj3;
	Point obj3 = obj.add(obj2);
	obj3.showPrint();
	

	return 0;
}
