/*
	�߻��ڷ����� �̿��ؼ� ���� �Ҵ�� ��ü�� ������ ���� �޸� ���� ��
	���� Ÿ���� �Ҹ��ڸ� ȣ��Ǿ� �޸� ������ �߻�
	���� ���� Ŭ������ �Ҹ��ڸ� �������� ����� ��Ÿ���� �Ҹ���ȣ���� �����Ѵ�.
*/

#include <iostream>  // ȭ�鿡 ����� �� ����ϴ� ����

// �θ� Ŭ���� ����
class CTest {
private:
	int num;  // ���ڸ� �����ϴ� ���� (��з� ������ ����)
public:
	// ������: ��ü�� ������� �� �����
	CTest(int anum) : num(anum) {
		std::cout << "CTest constructor" << std::endl;  // ������ �޽��� ���
	}

	// ���� �Լ�: ���߿� �ڽ� Ŭ�������� �ٽ� ������ �� ����
	virtual void vfunc() {
		std::cout << "CTest virtual function" << std::endl;
	}

	// �Ҹ���: ��ü�� ������ �� �����
	virtual ~CTest() {		//����Ҹ���
		std::cout << num << "CTest destructor" << std::endl;
	}

	// �׳� �Լ�: �̰� �ڽ� Ŭ�������� �ٽ� ������ ����
	void func() {
		std::cout << "CTest function()" << std::endl;
	}
};

// �ڽ� Ŭ���� ���� (CTest�� ��ӹ���)
class CTestSub : public CTest {
private:
	int subN;  // �ڽ� Ŭ�������� ����
public:
	// ������: �θ� �����ڵ� ���� ȣ���
	CTestSub(int an1, int an2) : CTest(an1), subN(an2) {
		std::cout << subN << "CTestSub constructor" << std::endl;
	}

	// �Ҹ���: ��ü�� ������ �� �����
	~CTestSub() {
		std::cout << subN << "CTestSub destructor" << std::endl;
	}

	// �θ��� ���� �Լ� �ٽ� ���� (�������̵�)
	void vfunc() {
		std::cout << "CTestSub function() override" << std::endl;
	}
};

// ���� �Լ�: ���α׷��� ���۵Ǵ� ��
int main() {

	// CTest Ŭ������ ��ü ����
	CTest obj(1);  // ������ �����
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	
	// CTestSub Ŭ������ ��ü ����
	CTestSub obj2(2, 22);  // �θ� ������ �� �ڽ� ������ ������ �����
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++" << std::endl;

	// CTest ��ü�� �Ϲ� �Լ��� ���� �Լ� ȣ��
	obj.func();   // �׳� �Լ�
	obj.vfunc();  // ���� �Լ� (�θ� ����)
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++" << std::endl;

	// CTestSub ��ü�� �Լ� ȣ��
	obj2.func();   // �θ� Ŭ�������� �������� �׳� �Լ�
	obj2.vfunc();  // �ڽ� Ŭ�������� �ٲ� �� ���� �Լ� (override)
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++" << std::endl;

	// �θ� Ŭ���� �����ͷ� �ڽ� ��ü �����
	CTest* ptr = new CTestSub(3, 33);  // new�� ���� �����ڸ� �ڵ����� �����

	// ptr�� ���� ��ü ����
	delete ptr;  // �θ� �����ͷ� �ڽ� ���� �� �ڽ� �Ҹ��ڰ� ȣ����� ���� (�߿�!)

	return 0;  // ���α׷� ����
}