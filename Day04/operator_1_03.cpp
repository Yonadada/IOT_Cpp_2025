/*
* ��ü�� ���ϴ� �Լ� : add()
* ������ �����Ѵ�.
* 
*/
#include <iostream>  // C++ ����� ��� ����� ���� ���

// Point Ŭ���� ����
class Point {
private:
	int x, y;  // x, y ��ǥ ���� �����ϴ� ��� ����

public:
	// ������(Constructor): ��ü�� ������ �� �ڵ����� ȣ���
	// �⺻���� 0���� �־��� ������ ���� ���̵� ���� ����
	Point(int ax = 0, int ay = 0) : x(ax), y(ay) {
		printf("Constructor call!!\n");
	}

	// �ٸ� Point ��ü�� �޾Ƽ� ���� ��ü�� �ٲٰ�, �ڱ� �ڽ��� ������ �����ϴ� �Լ�
	Point& add(const Point& other) {
		printf("add() call\n");

		// ���� ��ü�� x, y ���� �Ű������� ���� other�� ������ ���
		x = other.x;
		y = other.y;

		// �ڱ� �ڽ��� ������ ��ȯ (*this�� ���� ��ü�� ����Ŵ)
		return *this;
	}

	// x�� y ���� ����ϴ� �Լ�
	void showPoint() {
		printf("x: %d, y: %d\n", x, y);
	}
};

int main() {

	Point p(10, 20);    // (10, 20) ��ǥ�� ������ Point ��ü p ����
	Point p2(30, 40);   // (30, 40) ��ǥ�� ������ Point ��ü p2 ����

	std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;

	// add() �Լ��� p2�� ���� p�� �����ϰ�, �� ���(p ��ü �ڱ� �ڽ�)�� ������ ������
	// ���ϵ� ��ü�� p3�� ���� ����
	Point p3 = p.add(p2);

	// p3�� ��ǥ ��� �� p2�� ������ (30, 40)�� ��µ�
	p3.showPoint();

	return 0;  // ���α׷� ����
}