#include <iostream>
/*
	按眉 悼利 积己
*/
class AClass {
public:
	void showAClass () {
		std::cout << "Dynamically created object" << std::endl;
	}

};
int main() {

	AClass* ptr = new AClass{};				// 按眉 悼利 且寸
	ptr->showAClass();
	
	delete ptr;								// 悼利 皋葛府 秦力

	return 0;
}