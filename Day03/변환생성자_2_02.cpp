#include <iostream>
/*
	
*/
class Time {
private:
	int hour;
	int min;
	int sec;
public:
	Time(){}				//디폴트 생성자
	Time(int abssec) {		//변환생성자
		hour = abssec / 3600;
		min = (abssec / 60) % 60;
		sec = abssec % 60;
	}
	void printTime()
	{
		printf("현재시간은 %d시 %d분 %d초 입니다.\n", hour, min, sec);
	}

};
int main() {
	Time now = 9999;
	//Time now(6311);
	now.printTime();

	return 0;
}