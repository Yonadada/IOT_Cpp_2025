#include <iostream>
using namespace std;
/* 
	상속관계에서 이니셜라이즈 사용하기
*/

class Car {
private:
	int gasolineGauge;
public:
	Car(int ag) : gasolineGauge(ag){}			// 콜론 초기화
	int getGasGauge() { return gasolineGauge; }
};
class HybridCar : public Car {
private:
	int electricGauge;
public:
	HybridCar(int ag, int ae) :Car(ag), electricGauge(ae) {}
	int getElecGauge() { return electricGauge; }
};
class HybridWaterCar : HybridCar {
	int waterGauge;
public:
	HybridWaterCar(int ag, int ae, int aw) : HybridCar(ag, ae), waterGauge(aw) {}
	void showGauge() {
		cout << "잔여 가솔린: " << getGasGauge() << endl;
		cout << "잔여 전기량: " << getElecGauge() << endl;
		cout << "잔여 워터량: " << waterGauge << endl;
	} 
};
int main() {

	HybridWaterCar hwc(10, 20, 30);
	hwc.showGauge();

	return 0;
}