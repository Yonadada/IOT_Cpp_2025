#include <iostream>

/*
*  ����� ���: ��������
*/
//����Ÿ��
int& func(int& ref) {
	ref++;

	return ref;  //-> Lvalue
	//return ref++;	//-> Rvalue

}
int main() {
	int n = 10;
	//int& ref = func(n); //�����ι޴´�.

	int ref = func(n); //�Ϲݺ����� �޾Ƶ� �ȴ�.

	std::cout << ref << std::endl;

	return 0;
}