#include <iostream>

namespace aName {
	void func() {
		printf("aName::func()\n");
	}
}

namespace bName {
	void func() {
		printf("bName::func()\n");
	}
}

namespace cName {
	void func() {
		printf("cName::func()\n");
	}
}


using namespace cName; //using 사용하여 namespace cName을 선언해서 main에 func()

int main() {

	aName::func();	//aName::func()
	bName::func();	//bName::func()
	func();	//cName::func()

	return 0;
}