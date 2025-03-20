/*
	�ǽ�
	01 + ��������ڵ� �����
	- ����� ������ �ִ� ����
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
	const Point& add(const Point& other) {	//�������·� ���� �����ش�.
		printf("add()\n");
		return Point(x + other.x, y + other.y); //�ӽð�ü�� �����Ǿ� Point bj3�� ���� ,
										//��ü�� ���Ͻ�ų ���� ������ ȣ�� ���� 
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
