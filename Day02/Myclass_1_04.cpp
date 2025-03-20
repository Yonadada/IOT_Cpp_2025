#include <iostream>
using namespace std;

class MyClass {
private:
	int id;
	char name[20];
	int age;

public:
	MyClass obj(){}	// ±âº» »ý¼ºÀÚ
	void setData(int id, char name[], int age) {
		int id = id;
		char name = name[];
		int age = age;

		strncpy(name, sizeof(name), )
	}



	void getData() {
		cout << "id: " << id;
		cout << "name: " << name;
		cout << "age: " << age << endl;
	}
};

int main() {

	MyClass obj;
	obj.setData(1, "±èÃ¶¼ö", 20);
	obj.getData();

	return 0;
}