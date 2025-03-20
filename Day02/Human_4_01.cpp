/*
*  step 1. 이름과 전화번호는 동적할당 
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class Human {
private:
	char* pname;	//동적으로 할당하려면 값을 변경할 수 있어야 한다. 그래서 const 붙이지 않는다.
	int age;		// 나이 (일반변수)
	char* ptel;		// 동적 할당할 전화번호 포인터

public:
	// 생성자: 이름, 나이, 전화번호를 받아 동적 할당함.
	Human(const char* _name, int _age, const char* _ptel);// 생성자 선언 

	// 소멸자: 동적 할당된 메모리를 해제
	~Human();// 소멸자 선언

	// 데이터 출력함수 (멤버 변수를 수정하지 않으므로 const 사용)
	void getData() const;	//출력함수(상수 함수)
};


//생성자 정의 
//초기화 리스트 사용 
// 1. 멤버 변수를 더 빠르게 초기화 할 수 있음 => 성능최적화
// 2. C++에서는 const 멤버 변수와 참조 변수(&)는 초기화 리스트를 사용해야만 초기화 가능
// 3. C++에서는 클래스 내부에 다른 객체를 멤버 변수로 가질 때, 초기화 리스트를 반드시 사용

Human::Human(const char* _name, int _age, const char* _ptel) : pname(nullptr), age(_age), ptel(nullptr)
// nullptr->생성자 초기화 리스트에서 포인터가 유효하지 않은 메모리를 가리키지 않도록 할 수 있다.
{
	try {	//  null 포인터 체크로는 new 연산자에 대한 예외처리를 할 수 없다. -> try-catch 주로

		// 동적 할당 (예외발생 가능)
		pname = new char[strlen(_name) + 1];
		ptel = new char[strlen(_ptel) + 1]; // 메모리에 길이 만큼 할당

		// 할당된 메모리에 문자열 복사
		strcpy(pname, _name);
		strcpy(ptel, _ptel);
	
		//bad_alloc& e는 std::bad_alloc 예외 객체를 참조하는 변수
		//C++에서 new 연산자가 메모리 할당에 실패하면 std::bad_alloc 예외를 던진다.
	} catch (bad_alloc& e) { // 동적할당 실패 시 예외처리, 예외 객체는 보통참조(&)를 받아야 성능이 향상됨  
		cout << "메모리 할당 실패: " << e.what() << endl;	// e.what()을 사용하면 예외 메세지 확인가능

		// 예외가 발생했을 때 일부 메모리가 이미 할당되어 있을 수 있음!
		delete[] pname;	//이미 할당된 메모리가 있으면 해제
		delete[] ptel;	
		//* 첫번째 할당은 성공, 두번재 할당에서 예외 발생 시, 소멸자가 실행되지 않음
		//	그래서 catch블록에서 이미 할당된 걸 안전하게 해지하기 위함.


		// 포인터를 'nullptr'로 설정해서 잘못된 접근 방지
		// 포인터가 nullptr이 아니면, 삭제된 메모리를 가르킬 가능성이 있기때문에 nullptr로 초기화
		pname = nullptr;
		ptel = nullptr;
		age = 0;	// 예외가 발생해도 age값이 남아있을 수 있다. -> 안전하게 값(0)으로 설정 
	}
}//생성자 정의


// 동적으로 할당된 메모리 해제 -> 한번 해제를 한 포인터를 이중 해제시, 비정상 종료 또는 오류 발생가능성 
// 이중해제를 막기위해 nullptr로 초기화 해야한다.
// 안전하게 동작하기 위함
Human::~Human() {
	if (pname) { //nullptr 체크 : nullptr이 아닐때만 delete[] 실행	
		
		delete[] pname;
		pname = nullptr;	// 모든 경우에 nullptr 체크가 필요
	}
	if (ptel) {
	
		delete[] ptel;
		ptel = nullptr;
	}
}

// 데이터 출력 함수
// try-catch문을 통해 pname,ptel이 nullptr인 경우, 프로그램이 충돌하거나 이상한 값 출력될 가능성이 있음
// 예외처리 후, 안전하게 종료하기 위해 nullptr을 두번 체크
void Human::getData() const{ //참조건이 먼저
	if (!pname || !ptel) { // not 연산자, pname이 nullptr이면 true, 그렇지 않으면 false 반환 -> 둘중하나 true, true
		cout << "--데이터 할당을 받지 못했습니다--" << endl;
		return;
	}
	cout << "이름: " << pname << ", 나이: " << age << ", 전화번호: " << ptel;
}



int main() {
	// Human 객체 생성 
	Human h("홍길동", 30, "010-1234-1234");

	// 데이터 출력 
	h.getData();

	return 0;
}