#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//2.�����ڸ� ���� //3. �޸𸮿� �����Ҵ�

class MyClass {
private:
	int id;
	char name[20];	//char* name; �����Ҵ��� ������ 
	int age;

public:
	void setData(int n, const char* ps, int n2) {
		id = n;
		age = n2;
		//�ּ� = rvalue
		//name = ps; --> x , name�� �迭�� �ּ��̱� ������ ���� �� �� ����!
		strcpy(name, ps); // strcpy -> ���ڿ� ����. ps���� name �����Ѵ�.
		/*name[0] = 'a';
		name[1] = 'b'*/
		
	}

	void getData() {
		cout << "   id:   " << id << "   name:   " << name << "   age:   " << age << endl;
	}
};

int main() {
	MyClass obj;
	obj.setData(1, "��ö��", 20);
	obj.getData();

	return 0;
}