#include <iostream>
using namespace std;
/*
* 
*/


class CTime {
private:
	int m_hour{ 0 };	//����ð� �ʱ�ȭ
	int m_min{ 0 };
	int m_sec{ 0 };

public:

	CTime() { cout << "�⺻ ������ ȣ��" << endl; } // ����Ʈ ������ 
	//�ð� �����ϴ� �ް��Լ�
	
	// �޼��� �ʱ�ȭ�� ��� �κп� 
	CTime(int h, int m, int s) :m_hour(h), m_min(m), m_sec(s)	// �ݷ� �ʱ�ȭ, �̴ϼȶ����� ����Ʈ 
														// �ʱ�ȭ ����Ʈ�� ����ϸ� ��ü�� ������ �� �ٷ� ���� ���� ����
	{//����Ǵ� �ڵ�
		cout << "�Է� 3�� �޴� ������ ȣ�� >> " << endl;	
		//m_hour = h;
		//m_min = m;
		//m_sec = s;
	}
	void setTime(int hour, int min, int sec) {
		m_hour = hour;
		m_min = min;
		m_sec = sec;
	}

	void showTime() const {
		printf("���� �ð���: %d:%d:%d �Դϴ�\n", m_hour, m_min, m_sec);
	}
};

int main() {

	//CTime now; --> �����߻� 
	CTime now = CTime(); // �Լ� ȣ�⸸���� ��ü ���� 
	now.showTime();
	
	//CTime t(15, 30, 30);
	//CTime t = { 12,12,12 };
	CTime t{ 10,11,12 };// t��� ��ü�� �����ʰ� ���ÿ� �����͸� 10,11,12 ��´�.
	t.showTime();
	return 0;
}