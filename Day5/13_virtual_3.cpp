/*
	추상자료형을 이용해서 동적 할당된 객체를 참조할 때는 메모리 해제 시
	참조 타입의 소멸자만 호출되어 메모리 누수가 발생
	따라서 상위 클래스의 소멸자를 가상으로 만들어 실타입의 소멸자호출을 유도한다.
*/

#include <iostream>  // 화면에 출력할 때 사용하는 도구

// 부모 클래스 정의
class CTest {
private:
	int num;  // 숫자를 저장하는 변수 (비밀로 감춰져 있음)
public:
	// 생성자: 객체가 만들어질 때 실행됨
	CTest(int anum) : num(anum) {
		std::cout << "CTest constructor" << std::endl;  // 생성자 메시지 출력
	}

	// 가상 함수: 나중에 자식 클래스에서 다시 정의할 수 있음
	virtual void vfunc() {
		std::cout << "CTest virtual function" << std::endl;
	}

	// 소멸자: 객체가 삭제될 때 실행됨
	virtual ~CTest() {		//가상소멸자
		std::cout << num << "CTest destructor" << std::endl;
	}

	// 그냥 함수: 이건 자식 클래스에서 다시 만들지 않음
	void func() {
		std::cout << "CTest function()" << std::endl;
	}
};

// 자식 클래스 정의 (CTest를 상속받음)
class CTestSub : public CTest {
private:
	int subN;  // 자식 클래스만의 변수
public:
	// 생성자: 부모 생성자도 같이 호출됨
	CTestSub(int an1, int an2) : CTest(an1), subN(an2) {
		std::cout << subN << "CTestSub constructor" << std::endl;
	}

	// 소멸자: 객체가 삭제될 때 실행됨
	~CTestSub() {
		std::cout << subN << "CTestSub destructor" << std::endl;
	}

	// 부모의 가상 함수 다시 정의 (오버라이딩)
	void vfunc() {
		std::cout << "CTestSub function() override" << std::endl;
	}
};

// 메인 함수: 프로그램이 시작되는 곳
int main() {

	// CTest 클래스의 객체 생성
	CTest obj(1);  // 생성자 실행됨
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	
	// CTestSub 클래스의 객체 생성
	CTestSub obj2(2, 22);  // 부모 생성자 → 자식 생성자 순서로 실행됨
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++" << std::endl;

	// CTest 객체의 일반 함수와 가상 함수 호출
	obj.func();   // 그냥 함수
	obj.vfunc();  // 가상 함수 (부모 버전)
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++" << std::endl;

	// CTestSub 객체의 함수 호출
	obj2.func();   // 부모 클래스에서 물려받은 그냥 함수
	obj2.vfunc();  // 자식 클래스에서 바꿔 쓴 가상 함수 (override)
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++" << std::endl;

	// 부모 클래스 포인터로 자식 객체 만들기
	CTest* ptr = new CTestSub(3, 33);  // new를 쓰면 생성자만 자동으로 실행됨

	// ptr로 만든 객체 삭제
	delete ptr;  // 부모 포인터로 자식 삭제 → 자식 소멸자가 호출되지 않음 (중요!)

	return 0;  // 프로그램 종료
}