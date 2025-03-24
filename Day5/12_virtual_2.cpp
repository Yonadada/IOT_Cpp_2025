/*
	Virtual class - 순수 지정자를 가지는 메서드를 순수 가상 함수라 하며,
					이 순수 가상 함수를 가지는 클래스
				  - 추상 클래스는 객체를 생성할 수 없다.
*/
#include <iostream>

class Cinterface { // 객체를 생성할 수 없음
public :
	Cinterface() { std::cout << "Cinterface constructor" << std::endl; } 
	virtual void getData() const = 0;			//순수 가상 함수
};

class CinSub : public Cinterface {
public:
	CinSub() { std::cout << "CinSub constructor " << std::endl; }
	void getData() const override {	// 순수 가상 함수를 재정의를 해야만 Cinterface 객체를 할 수 있다.
		std::cout << "Pure Virtual Function()" << std::endl;
	}
};


int main() {

	//Cinterface obj;	// 추상클래스는 순수 가상함수를 들고오기 때문에 객체를 생성 x
	CinSub obj;
	obj.getData();
	
	return 0;
}