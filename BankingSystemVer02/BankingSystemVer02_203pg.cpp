/*
	Bankcing System Ver 0.2
	�ۼ��� : ȫ����
	���� : Account Ŭ���� ����, ��ü ������ �迭 ����
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>			// �����(cout, cin) �ʿ���
#include <cstring>			//���ڿ��� �����ϰ� �ٷ�� ���� �ʿ�! -> strcpy, strlen

using namespace std;		// �ڵ带 ���ϰ� ������ 
const int NAME_LEN = 20;	//��� ���� //-> �̸� �ִ���� 20�ڷ� ���� 

// �Լ� ����
// Q. ����ڰ� �����ϴ� �Լ���, Ŭ���� ���� �Լ��� ������ �ٸ���?
// ����ڰ� �����ϴ� �Լ�-> � ���¿��� � ������ �����Ұ����� �����ϴ� ���� 
void ShowMenu();		//�޴����
void MakeAccount();		//���°����� ���� �Լ�
void DepositMoney();	//�� ��
void WithdrawMoney();	//�� ��
void ShowAllAccInfo();  //�ܾ���ȸ

// �޴� ������ ���� ����
// enum�� �������̶�� ���� ������ ������ ������ ������ �� ������ ������ �� ����ϴ� ���
// ��, �͸� enum�� ������ ���� ��� ���� 
enum {MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT}; 

//Account Ŭ����
class Account {
private:
	int accID;		//���¹�ȣ
	int balance;	//�� ��
	char* cusName;	//���̸� 
public:
	// ������(���¸����)
	// Ŭ���� ������ �Լ�(GetAccID(), Deposit(), Withdraw(), ShowAccInfo()) -> �� ����(��ü)�� ������ ����
	Account(int ID, int money, char* name) : accID(ID), balance(money) {
		cusName = new char[strlen(name) + 1];	//���ο� �޸𸮸� ���� �̸��� ���� 
		strcpy(cusName, name);	// �Է¹��� �̸��� ��������(name) -> cusName ����
	}
	// ������ȸ
	int GetAccID() { return accID; } //�Ϲ� �Լ� GetAccId()�� ����Ǹ� ��ȯ������ accID�� ����� ���� ��ȯ�ϰڴ�.
	// -> ���ٸ� ����ID ��ȸ�� �� ������. ��ü �ȿ� �ִ� accID �� ���� Ȯ���� ����� ���� 

	//�Ա� �Լ�
	void Deposit(int money) {
		balance += money;
	}

	// ��� �Լ�
	// 
	int Withdraw(int money) {	// ��ݾ� ��ȯ, ������ 0 ��ȯ 
		if (balance < money)
			return 0;

		balance -= money;
		return money;
	}

	// �������� �Լ�
	void ShowAccInfo() {
		cout << "����ID" << accID << endl;
		cout << "�� ��" << cusName << endl;
		cout << "�� ��" << balance << endl;
	}

	// �Ҹ���(�޸�����)
	// ������ ������ �޸� ������ �߻��� �� �ִ�.
	~Account() {
		delete[] cusName;	
	}

};// class Account ��

	Account* accArr[100];	//Account ������ ���� �迭
	int accNum = 0;		// ����� Account �� 


int main(void) {

	int choice;
	
	while (1) {
		ShowMenu();
		cout << "����: ";
		cin >> choice;
		cout << endl;

		switch (choice) {
		case MAKE:
			MakeAccount();
			break;
		case DEPOSIT:
			DepositMoney();
			break;
		case WITHDRAW:
			WithdrawMoney();
			break;
		case INQUIRE:
			ShowAllAccInfo();
			break;
		case EXIT:
			for (int i = 0; i < accNum; i++)
				delete accArr[i];
			return 0;
		default:
			cout << "Illegal selection.." << endl;
		}
	}
	return 0;
}

void ShowMenu(void) {
	cout << "-------Menu-------" << endl;
	cout << "1. ���°��� " << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void MakeAccount(void) {
	int id;
	char name[NAME_LEN];
	int balance;
	cout << "[���°���]" << endl;
	cout << "���� ID: "; cin >> id;
	cout << "�̸�: "; cin >> name;
	cout << "�Աݾ�: "; cin >> balance;
	cout << endl;

	accArr[accNum++] = new Account(id, balance, name);
}

void DepositMoney(void) {
	int money;
	int id;
	cout << "[��    ��]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "�Աݾ�: "; cin >> money;

	for (int i = 0; i < accNum; i++) 
	{
		if (accArr[i]->GetAccID() == id) 
		{
			accArr[i]->Deposit(money);
			cout << "�ԱݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID�Դϴ�" << endl << endl;
}

void WithdrawMoney(void) {
	int money;
	int id;
	cout << "[��   ��]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "��ݾ�: "; cin >> money;

	for (int i = 0; i < accNum; i++) 
	{
		if (accArr[i]->GetAccID() == id) 
		{
			if (accArr[i]->Withdraw(money) == 0) 
			{
				cout << "�ܾ׺���" << endl << endl;
				return;
			}
			cout << "��ݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�" << endl << endl;
}

void ShowAllAccInfo(void) {
	for (int i = 0; i < accNum; i++) {
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}
