/*
*  c++ Ÿ���� ����ü
*
*/

#include <iostream>

typedef struct human {
	char name[20];
	int age;
	char job[10];
	
	void showHuman() { // c++�� ����Լ� + ������� 

		printf("name:  %s, age: %d, job: %s", name, age, job);
	}

} Human;



int main() {

Human h = { "��ö��", 30, "���" };
//showHuman(h);
	
h.showHuman(); //. �����ڸ� �̿��� showHuman�� ���� 

	return 0;
}