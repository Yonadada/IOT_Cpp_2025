#include <iostream>
/*
	상속 관계에서 객체 생성 및 소멸
*/
class SuperClass {
private:
	int num;
public:
	SuperClass(int anum) {				// 생성
		num = anum;
		std::cout << num << " SuperClass constructor" << std::endl;
	}
	~SuperClass(){						// 소멸
		std::cout << num << " SuperClass Destructor" << std::endl;
	}
};
class SubClass : public SuperClass {
private:
	int subNum;
public:
	SubClass(int an, int an2) : SuperClass(an) {
		subNum = an2;
		std::cout << subNum << " SubClass constructor" << std::endl;
	}
	~SubClass() {
		std::cout << subNum << " SubClass Desturctor" << std::endl;
};
int main() {
	SuperClass s{ 1 };
	std::cout << "---------------------------------" << std::endl;
	SubClass sub{ 2, 22 };

	return 0;
}
/*
	객체를 생성할 때 호출되는 생성자와 생성자의 실행은 다르다
	즉, 생성자의 호출과 생성자의 실행은 다르다.
	
	서브클래스 호출 -> 슈퍼클래스 생성 -> 서브클래스 생성 -> 서브클래스 소멸 -> 슈퍼클래스 소멸 
*/