#include "Header.h"


void BankAccount::ShowMenu() {


	cout << "-----Menu-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;

	SelectMenu();
}
void BankAccount::SelectMenu()
{
	int input;
	cout << "����: ";

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
	cout << "[���°���]" << endl;
	cout << "���� ID: "; cin >> id;

	cout << "�� ��: "; cin >> name;


	cout << "�Աݾ�: "; cin >> money;
	cout << endl;

	//Account[nTotal_Account].BankAccount(id, name, money);
	nTotal_Account++;
}
void BankAccount::CInit(int id, const char* name, int money) {
	AccNo = id;
	this->money = money;

	strcpy(ClientName, name);

}

void BankAccount::Deposit() {
	int id, money;
	
	cout << "[��    ��]" << endl;
	cout << "����ID: "; cin >> id;

	cout << "�Աݾ�: "; cin >> money;


	cout << "�ԱݿϷ�"; 
	cout << endl;
}
void BankAccount::WithDraw() {

}
void BankAccount::PrintAccInfo() {
	cout << "����ID: " << AccNo << endl;
	cout << "�� ��: " << ClientName << endl;
	cout << "�� ��: " << money << endl;

}

void CShowMenu() {

	cout << "-----Menu-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;

}

void CMake() {

	int id, money;
	char name[NAME_LEN];
	cout << "[���°���]" << endl;
	cout << "���� ID: "; cin >> id;

	cout << "�� ��: "; cin >> name;


	cout << "�Աݾ�: "; cin >> money;
	cout << endl;

	Account[nTotal_Account].CInit(id, name, money);
	nTotal_Account++;

}

void CDeposit() {
	int id, money;

	cout << "[��    ��]" << endl;
	cout << "����ID: "; cin >> id;

	cout << "�Աݾ�: "; cin >> money;

	for (int i = 0; i < nTotal_Account; i++) {
		if (Account[i].AccNo == id){
			Account[i].money += money;
			cout << "�ԱݿϷ�";
		}
	}
	cout << endl;
}

void CWithDraw() {

}

void CInfo() {

}

int main()
{
	int choice;
	bool m_bExit = false;

	do{
		CShowMenu();
		cout << "����: ";
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
			//CWithDraw();
		}
		case BANK_MENU::INFO:
		{
			//CInfo();
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