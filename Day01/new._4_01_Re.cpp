#include <iostream>
	// malloc()�� ����ϱ� ���� ���
using namespace std;

/*
* ���� �Ҵ� ���� ũ�⸦ �Է¹ް� ���Ҹ� �����Ͽ� ����Ͻÿ�.
*/

int main() {
	int size; // �迭 ũ�� ����
	int* p; // ������ ������

	// ����ڷκ��� ũ�� �Է¹ޱ�
	cout << "ũ��>> ";
	cin >> size;

	// ���� �޸� �Ҵ� (�ùٸ� ũ�� ���)
	p = (int*)malloc(size * sizeof(int)); // size�� ������ ������ ũ�� �Ҵ�
	 // ����ȯ
	


	// �޸� �Ҵ� ���� Ȯ��
	if (p == NULL) {
		cout << "�޸� �Ҵ� ����!" << endl;
		return -1;
	}
	// ���� �Է�
	cout << size << "���� ���� �Է�>> ";
	for (int i = 0; i < size; i++) {
		cin >> p[i]; // �Է¹ޱ�
	}
	// ���� ���
	cout << "�Է��� ����: ";
	for (int i = 0; i < size; i++) {
		cout << p[i] << " ";
	}

	cout << endl;

	// ���� �޸� ����
	delete[] p;

	return 0;
}