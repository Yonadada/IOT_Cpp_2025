#include <iostream>
using namespace std;
/*
* 
*/

class AClass {
private:
	int n1;
	int n2;
public:
	AClass(){}	// ��������� ����Ʈ �����ڸ� ����� ��. �Է°��� ���� �ʴ� �����ڴ� �ڵ����� �����.

	//Ŭ������ private�̱⶧���� �޼��� public�� set, get�޼��带 ���� Ŭ������ �����ؾ���.
	void setData(int num1, int num2){
		n1 = num1;
		n2 = num2;
	}
	void getDage(){
		cout << "num1�� ����: " << n1 <<endl;
		cout << "num2�� ����: " << n2 <<endl;
	}
};

int main() {

	AClass obj;	// �Է°� ���� ��ü ������ 
	//AClass obj(100, 200); //�����߻�! -> �Է� 2���� �޴� �����ڰ� ���� ������ ����!

	obj.setData(100, 200);
	obj.getDage();
	return 0;

}