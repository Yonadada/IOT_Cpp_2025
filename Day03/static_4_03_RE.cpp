/*
	StaticTest 클래스를 만드는데 멤버변수로는 
	이름, 전화번호, 주소, 회원번호(cnt)를 가진다.
	3개 입력을 받는 생성자를 작성한다.
	단, 회원번호는 자동으로 증가시킬 것이다.
	showmember - 출력 담당 메서드를 구현하시오

*/
#define _CRT_SECURE_NO_WARININGS
#include <iostream>

class StaticTest {
private:
	char* uName;
	char* uTel;
	char* uAddr;
	int cnt;
public:
	StaticTest(const char* uName, const char* uTel, const char* uAddr, int cnt);
	~StaticTest();
	void showmember() const;

};

StaticTest::StaticTest(const char* uName, const char* uTel, const char* uAddr) :
	uName(nullptr), uTel(nullptr), uAddr(nullptr), age(age)
{
	try {
		this->uName = new char[strlen(uName) + 1];
		this->uTel = new char[strlen(uTel) + 1];
		this->uAddr = new char[strlen(uAddr) + 1];

		strcpy(this->uName, uName);
		strcpy(this->uTel, uTel);
		strcpy(this->uAddr, uAddr);
	}
	catch(std::bad_alloc& e){
		std::cout << "메모리 할당 실패" << e.what() << std::endl;
	}
	// 메모리 할당 소멸 
	this->uName = nullptr;
	this->uTel = nullptr;
	this->uAddr = nullptr;
	this->cnt = 0;

}

StaticTest::~StaticTest() {
	delete[] 
}


StaticTest::showmember() {
	std::cout << "회원번호: " << cnt << std::endl;
	printf("이름: %s, 전화번호: %s, 주소: %s\n", uName, uTel, uAddr);
}


int main() {
	StaticTest m1("홍여원","010-1234-5678", "부산 연제구");
	m1.showmember();

	StaticTest m2("홍요키","010-2222-2222", "부산 연제구");
	m2.showmember();
	
	StaticTest m3("홍여원","010-3333-3333", "부산 연제구");
	m3.showmember();


	return 0;
}