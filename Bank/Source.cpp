#include "Header.h"


void ShowMenu() {


	cout << "-----Menu-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;

}
void BankAccount::SelectMenu(int input)
{
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

	BankAccount(id, name, money);

	ShowMenu();
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

BankAccount Account[100];
int acc_num = 0;

int main()
{
	int choice;

	while (1) {
		ShowMenu();
		cout << "����: ";

		cin >> choice;

		switch (choice) 
		{
		case BANK_MENU::MAKE:
		{
			//Make_Acc();
			break;
		}
		case BANK_MENU::DEPOSIT:
		{
			//deposit();
		}
		case BANK_MENU::INFO:
		{
			//PrintAccInfo();
			break;
		}
		}
	}
	return 0;
}