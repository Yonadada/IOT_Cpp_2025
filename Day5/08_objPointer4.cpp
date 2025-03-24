#include <iostream>
class MyClass {
public:
	void show() {
		std::cout << "Hello!!" << std::endl;
	}
};
int main() {
	MyClass* ptr = nullptr;
	//printf("ptr: %p\n", *ptr);
	if (ptr != nullptr) ptr->show();
	else printf("ptr is null\n");

	ptr = new MyClass{};
	ptr->show();

	return 0;
}