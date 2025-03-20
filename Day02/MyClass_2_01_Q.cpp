#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//2.생성자를 만들어서 //3. 메모리에 동적할당

class MyClass {
private:
	int id;
	char name[20];	//char* name; 동적할당을 받으면 
	int age;

public:
	void setData(int n, const char* ps, int n2) {
		id = n;
		age = n2;
		//주소 = rvalue
		//name = ps; --> x , name은 배열의 주소이기 때문에 값을 줄 수 없다!
		strcpy(name, ps); // strcpy -> 문자열 복사. ps값을 name 복사한다.
		/*name[0] = 'a';
		name[1] = 'b'*/
		
	}

	void getData() {
		cout << "   id:   " << id << "   name:   " << name << "   age:   " << age << endl;
	}
};

int main() {
	MyClass obj;
	obj.setData(1, "김철수", 20);
	obj.getData();

	return 0;
}