/*
	Bankcing System Ver 0.2
	작성자 : 홍여원
	내용 : Account 클래스 정의, 객체 포인터 배열 적용
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>			// 입출력(cout, cin) 필요함
#include <cstring>			//문자열을 복사하고 다루기 위해 필요! -> strcpy, strlen

using namespace std;		// 코드를 편하게 쓰려고 
const int NAME_LEN = 20;	//상수 선언 //-> 이름 최대글자 20자로 지정 

// 함수 선언
// Q. 사용자가 선택하는 함수와, 클래스 내부 함수는 무엇이 다른가?
// 사용자가 선택하는 함수-> 어떤 계좌에서 어떤 동작을 실행할건지를 결정하는 역할 
void ShowMenu();		//메뉴출력
void MakeAccount();		//계좌개설을 위한 함수
void DepositMoney();	//입 금
void WithdrawMoney();	//출 금
void ShowAllAccInfo();  //잔액조회

// 메뉴 선택을 위한 선언
// enum은 열거형이라는 뜻을 가지고 있으면 연관된 값들을 한 곳에서 정의할 때 사용하는 기능
// 즉, 익명 enum은 변수명 없이 사용 가능 
enum {MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT}; 

//Account 클래스
class Account {
private:
	int accID;		//계좌번호
	int balance;	//잔 액
	char* cusName;	//고객이름 
public:
	// 생성자(계좌만들기)
	// 클래스 내부의 함수(GetAccID(), Deposit(), Withdraw(), ShowAccInfo()) -> 각 계좌(객체)의 동작을 수행
	Account(int ID, int money, char* name) : accID(ID), balance(money) {
		cusName = new char[strlen(name) + 1];	//새로운 메모리를 만들어서 이름을 저장 
		strcpy(cusName, name);	// 입력받은 이름을 원본에서(name) -> cusName 복사
	}
	// 계좌조회
	int GetAccID() { return accID; } //일반 함수 GetAccId()가 실행되면 반환값으로 accID에 저장된 값을 반환하겠다.
	// -> 없다면 계좌ID 조회를 할 수없다. 객체 안에 있는 accID 를 직접 확인할 방법이 없음 

	//입금 함수
	void Deposit(int money) {
		balance += money;
	}

	// 출금 함수
	// 
	int Withdraw(int money) {	// 출금액 반환, 부족시 0 반환 
		if (balance < money)
			return 0;

		balance -= money;
		return money;
	}

	// 계좌정보 함수
	void ShowAccInfo() {
		cout << "계좌ID" << accID << endl;
		cout << "이 름" << cusName << endl;
		cout << "잔 액" << balance << endl;
	}

	// 소멸자(메모리정리)
	// 지우지 않으면 메모리 누수가 발생할 수 있다.
	~Account() {
		delete[] cusName;	
	}

};// class Account 끝

	Account* accArr[100];	//Account 저장을 위한 배열
	int accNum = 0;		// 저장된 Account 수 


int main(void) {

	int choice;
	
	while (1) {
		ShowMenu();
		cout << "선택: ";
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
	cout << "1. 계좌개설 " << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void MakeAccount(void) {
	int id;
	char name[NAME_LEN];
	int balance;
	cout << "[계좌개설]" << endl;
	cout << "계좌 ID: "; cin >> id;
	cout << "이름: "; cin >> name;
	cout << "입금액: "; cin >> balance;
	cout << endl;

	accArr[accNum++] = new Account(id, balance, name);
}

void DepositMoney(void) {
	int money;
	int id;
	cout << "[입    금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "입금액: "; cin >> money;

	for (int i = 0; i < accNum; i++) 
	{
		if (accArr[i]->GetAccID() == id) 
		{
			accArr[i]->Deposit(money);
			cout << "입금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID입니다" << endl << endl;
}

void WithdrawMoney(void) {
	int money;
	int id;
	cout << "[출   금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "출금액: "; cin >> money;

	for (int i = 0; i < accNum; i++) 
	{
		if (accArr[i]->GetAccID() == id) 
		{
			if (accArr[i]->Withdraw(money) == 0) 
			{
				cout << "잔액부족" << endl << endl;
				return;
			}
			cout << "출금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다" << endl << endl;
}

void ShowAllAccInfo(void) {
	for (int i = 0; i < accNum; i++) {
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}
