#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

class clsDeleteClientScreen : protected clsScreen {

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
	static void DeleteClient() {

		_DrawScreenHeader("Delete Client");

		string AccountNumber;

		cout << "Enter account number : ";
		AccountNumber = clsInputValidate<string>::ReadString();

		while (!clsClient::IsClientExist(AccountNumber)) {

			cout << "Client with account number " << AccountNumber << " is not exist choose anoter one : ";
			AccountNumber = clsInputValidate<string>::ReadString();
		}

		clsClient Client = clsClient::Find(AccountNumber);
		_PrintClient(Client);

		cout << "\nAre you sure you want to delete this client y/n : ";
		char Answer = clsInputValidate<char>::ReadChar();

		if (Answer == 'y') {

			if (Client.Delete()) {

				cout << "\nClient Deleted successfuly :-)\n";
				_PrintClient(Client);
			}
			else {

				cout << "\nError Client was not Deleted\n";
			}
		}
	}

};

