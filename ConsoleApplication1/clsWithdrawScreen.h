#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

class clsWithdrawScreen : protected clsScreen {

private:
	static void _PrintClient(clsClient Client) {

		cout << "\n\t\tClient Card\n";
		cout << "----------------------------------------------\n";
		cout << "First Name  : " << Client.FirstName << endl;
		cout << "Last Name   : " << Client.LastName << endl;
		cout << "Full Name   : " << Client.FullName() << endl;
		cout << "Email       : " << Client.Email << endl;
		cout << "Phone       : " << Client.Phone << endl;
		cout << "Acc. Number : " << Client.AccountNumber() << endl;
		cout << "Password    : " << Client.PinCode << endl;
		cout << "Balance     : " << Client.AccountBalance << endl;
		cout << "----------------------------------------------\n";

	}

public:
	static void Withdraw() {

		_DrawScreenHeader("WithDraw");

		string AccountNumber = "";

		cout << "\nPlease etner Account Number : ";
		AccountNumber = clsInputValidate<string>::ReadString();

		while (!clsClient::IsClientExist(AccountNumber)) {

			cout << "\nAccount Number is not found, enter another one : ";
			AccountNumber = clsInputValidate<string>::ReadString();
		}

		clsClient Client = clsClient::Find(AccountNumber);
		_PrintClient(Client);

		double Amount;
		cout << "\nPlease Enter Withdraw amount : ";
		Amount = clsInputValidate<double>::ReadNumber();

		char Answer = 'n';
		cout << "Are you sure you want to Withdraw the amount " << Amount << " y/n : ";
		Answer = clsInputValidate<char>::ReadChar();

		if (Answer == 'y') {

			if (Client.WithDraw(Amount)) {

				cout << "\nAmount Withdraw successfuly.\n";
				cout << "\nNew Balance is : " << Client.AccountBalance << endl;
			}
			else {

				cout << "\nYou cannot withdraw, Insuffecient Balance!\n";
				cout << "\nAmount to withdraw : " << Amount << endl;
				cout << "\nYour balance : " << Client.AccountBalance << endl;
			}
		}
		else {

			cout << "\nOperation cancelled.\n";
		}
	}

};

