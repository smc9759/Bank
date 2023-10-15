#pragma once
#include <iostream>
#include <cstring>

using namespace std;

const int NAME_LEN = 20;



//class BankAccount;

class Bank {
	//BankAccount bankAccount[100];
	int nTotal_Account;
public:
};

class BANK_MENU {
public:
	enum {
		MAKE = 1,
		DEPOSIT,
		WITHDRAW,
		INFO,
		EXIT
	};
};

class BankAccount 
{
	int AccNo;
	char* ClientName;
	int   money;
	static int num_of_accounts;

public:

	BankAccount() : AccNo(0), money(0)
	{

	}

	BankAccount(int AccNo, const char* ClientName, int money)
	{
		this->AccNo = AccNo;

		int len = strlen(ClientName) + 1;
		this->ClientName = new char[len];
		strcpy(this->ClientName, ClientName);

		this->money = money;
	}
	void ShowMenu();
	void SelectMenu();
	void Make_Acc();
	void Deposit(int money);
	void WithDraw(int money);
	void CInit(int id, const char* name, int money);
	void PrintAccInfo(); 

	int getAccNo() {
		return AccNo;
	}
	void setAccNo(int id) {
		AccNo = id;
	}
	char* getClientName() {
		return ClientName;
	}
	void setClientName(const char* name) {
		int len = strlen(name) + 1;
		ClientName = new char[len];
		strcpy(ClientName, name);
	}
	int getMoney() {
		return money;
	}
	void setMoney(int money) {
		this->money = money;
	}
	~BankAccount() {
		delete[]ClientName;
	}
};


BankAccount* Account[100];
int nTotal_Account = 0;

//BankAccount::num_of_accounts = 0;