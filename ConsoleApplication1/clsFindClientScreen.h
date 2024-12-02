#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

using namespace std;

class clsFindClientScreen : protected clsScreen{

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
	static void FindClient() {

		_DrawScreenHeader("Find Client");

		string AccountNumber = "";

		cout << "\nPlease etner Account Number : ";
		AccountNumber = clsInputValidate<string>::ReadString();

		while (!clsClient::IsClientExist(AccountNumber)) {

			cout << "\nAccount Number is not found, enter another one : ";
			AccountNumber = clsInputValidate<string>::ReadString();
		}

		clsClient Client = clsClient::Find(AccountNumber);

		if (!Client.IsEmpty()) {

			cout << "\nClient Found :-)\n";
			_PrintClient(Client);
		}
		else {

			cout << "\nClient Was not found :-(\n";
		}
	}
};

