#include <iostream>

/*
*	멤버초기화
*  1. 상수 멤버 변수 객체가 생성될때 
*  2. 참조변수 객체가 생성되기 전에 초기화
*  3. 객체를 멤버로 가지는 경우
*/

class ConstClass {
private:
	int m_value;
	const int m_value2; // 상수 멤버 변수는 객체가 생성될 때, 반드시 초기화가 되어야 한다. --> 콜론 초기화

public:
	ConstClass(int value, int value2) : m_value2(value2) {
		m_value = value; 
	} //초기화
	void showValue() {
		printf("m_value: %d\n, m_value2: %d\n", m_value, m_value2);
	}

};
class RefClass {	
private:
	int& ref;	//참조변수 역시 객체가 생성되기 전에 반드시 초기화가 이루어져야 한다.

public:
	RefClass(int& r) : ref(r) {}
	void showValue(){
		printf("ref: %d\n", ref);
	}

};

class Position {
private:
	int m_x;
	int m_y;
public:
	Position(int x, int y) {
		printf("Position 생성자!!\n");
		m_x = x, m_y = y;
	}
	void getData() {
		printf("m_x: %d, m_y: %d\n", m_x, m_y);
	}
};

class ObjClass { //obj객체가 만들어 지기 전에 position 이 만들어 있어야 해서 초기화를 통한 작업을 해야함
private:
	Position pos; //객체멤버변수 -> 객체를 멤버변수로 가진다 
public:
	ObjClass(int x, int y) : pos{ x,y } { printf("ObjClass constructor!!\n"); }
	void showValue() {
		pos.getData();
	}
	

};



int main() {
	ConstClass obj(10, 20);
	obj.showValue();

	int n = 50;
	RefClass obj2(n);
	obj.showValue();


	std::cout << "=============================" << std::endl;
	ObjClass o(3, 6);
	o.showValue();
	return 0;
}