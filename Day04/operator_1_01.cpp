/*
	
*/
#include <iostream>
class Myclass {
private:
	int m_a, m_b;
	//const char* m_name;
public:
	Myclass(int a = 0, int b = 0, const char* name = nullptr) : m_a(a), m_b(b)/*, m_name(name)*/ { }
	void showMyclass() {
		std::cout << m_a << ", " << m_b << ", " /*<< m_name*/ << std::endl;
	}
};

int main() {

	//Myclass obj{ 1,2, "홍길동" };
	//obj.showMyclass();
	
	//Myclass obj2;			// default 생성자 선언 없이 호출하려면 위의 생성자에서 초기값 줘야함.
	//obj2 = obj;				// num = 10;, 디폴트 대입 연산자를 기본적으로 제공해준다. 
	//obj2.showMyclass();		// obj의 객체에 있는 멤버변수를 복사해서 obj2를 생성
							//연산자 오버로딩 기능이 있기 때문에 가능

	Myclass obj{ 10,20 };
	Myclass obj2{ 30,40 };
	Myclass obj3 = obj + obj2;	// 에러발생 ~! => 숫자끼리 같은 연산자 사용가능, 사용자 정의 클래스 끼리는 자동으로 못더함 
	return 0;
}