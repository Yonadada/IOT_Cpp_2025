#include <iostream>
using namespace std;
/*
* 
*/


class CTime {
private:
	int m_hour{ 0 };	//현재시간 초기화
	int m_min{ 0 };
	int m_sec{ 0 };

public:

	CTime() { cout << "기본 생성자 호출" << endl; } // 디폴트 생성자 
	//시간 설정하는 메개함수
	
	// 메서드 초기화를 헤드 부분에 
	CTime(int h, int m, int s) :m_hour(h), m_min(m), m_sec(s)	// 콜론 초기화, 이니셜라이즈 리스트 
														// 초기화 리스트를 사용하면 객체가 생성될 때 바로 값을 설정 가능
	{//실행되는 코드
		cout << "입력 3개 받는 생성자 호출 >> " << endl;	
		//m_hour = h;
		//m_min = m;
		//m_sec = s;
	}
	void setTime(int hour, int min, int sec) {
		m_hour = hour;
		m_min = min;
		m_sec = sec;
	}

	void showTime() const {
		printf("현재 시간은: %d:%d:%d 입니다\n", m_hour, m_min, m_sec);
	}
};

int main() {

	//CTime now; --> 에러발생 
	CTime now = CTime(); // 함수 호출만으로 객체 생성 
	now.showTime();
	
	//CTime t(15, 30, 30);
	//CTime t = { 12,12,12 };
	CTime t{ 10,11,12 };// t라는 객체가 생성됨과 동시에 데이터를 10,11,12 담는다.
	t.showTime();
	return 0;
}