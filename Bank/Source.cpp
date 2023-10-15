#include "Header.h"


void BankAccount::ShowMenu() {


	cout << "-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;

	SelectMenu();
}
void BankAccount::SelectMenu()
{
	int input;
	cout << "선택: ";

	cin >> input;

	switch (input)
	{
	case BANK_MENU::MAKE:
	{
		Make_Acc();
		break;
	}
	case BANK_MENU::DEPOSIT:
	{
		//deposit();
	}
	case BANK_MENU::INFO:
	{
		PrintAccInfo();
		break;
	}
	}
}


void BankAccount::Make_Acc() {
	int id, money;
	char name[NAME_LEN];
	cout << "[계좌개설]" << endl;
	cout << "계좌 ID: "; cin >> id;

	cout << "이 름: "; cin >> name;


	cout << "입금액: "; cin >> money;
	cout << endl;

	//Account[nTotal_Account].BankAccount(id, name, money);
	nTotal_Account++;
}
void BankAccount::CInit(int id, const char* name, int money) {
	AccNo = id;
	this->money = money;

	int len = strlen(name) + 1;
	ClientName = new char[len];
	strcpy(ClientName, name);

}

void BankAccount::Deposit(int money) {
	this->money += money;
}
void BankAccount::WithDraw(int money) {
	if (this->money < money) {
		cout << "잔액부족" << endl;
		return;
	}
	this->money -= money;

	cout << "출금완료" << endl;
	return;
}
void BankAccount::PrintAccInfo() {
	cout << "계좌ID: " << AccNo << endl;
	cout << "이 름: " << ClientName << endl;
	cout << "잔 액: " << money << endl;

}

void CShowMenu() {

	cout << "-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;

}

void CMake() {

	int id, money;
	char name[NAME_LEN];
	cout << "[계좌개설]" << endl;
	cout << "계좌 ID: "; cin >> id;

	cout << "이 름: "; cin >> name;


	cout << "입금액: "; cin >> money;
	cout << endl;

	Account[nTotal_Account++] = new BankAccount(id, name, money);

}

void CDeposit() {
	int id, money;

	cout << "[입    금]" << endl;
	cout << "계좌ID: "; cin >> id;

	cout << "입금액: "; cin >> money;

	for (int i = 0; i < nTotal_Account; i++) {
		if (Account[i]->getAccNo() == id) {
			Account[i]->Deposit(money);
			cout << "입금완료";
		}
	}
	cout << endl;
}

void CWithDraw() {
	int id, money;

	cout << "[출   금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "출금액: "; cin >> money;

	for (int i = 0; i <nTotal_Account; i++) {
		if (Account[i]->getAccNo() == id) {
			Account[i]->WithDraw(money);
			return;
		}

	}
	cout << "ID 재확인" << endl;
}

void CInfo() {
	cout << "[전체 계좌정보 출력]" << endl;
	cout << endl;
	for (int i = 0; i<nTotal_Account; i++)
	{
		cout << "계좌ID: " << Account[i]->getAccNo() << endl;
		cout << "이 름: " << Account[i]->getClientName() << endl;
		cout << "잔 액: " << Account[i]->getMoney() << endl;
		cout << endl;
	}
}

int main()
{
	int choice;
	bool m_bExit = false;

	do {
		CShowMenu();
		cout << "선택: ";
		cin >> choice;

		switch (choice)
		{
		case BANK_MENU::MAKE:
		{
			CMake();
			break;
		}
		case BANK_MENU::DEPOSIT:
		{
			CDeposit();
			break;
		}
		case BANK_MENU::WITHDRAW:
		{
			CWithDraw();
			break;
		}
		case BANK_MENU::INFO:
		{
			CInfo();
			break;
		}
		case BANK_MENU::EXIT:
		{
			m_bExit = true;
		}
		}
	} while (!m_bExit);

	return 0;
}