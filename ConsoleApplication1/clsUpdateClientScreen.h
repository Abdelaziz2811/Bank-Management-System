#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

class clsUpdateClientScreen : protected clsScreen {

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

	static void _ReadClientInfo(clsClient& Client) {

		cout << "\nEnter first name : ";
		Client.FirstName = clsInputValidate<string>::ReadString();
		cout << "\nEnter last name : ";
		Client.LastName = clsInputValidate<string>::ReadString();
		cout << "\nEnter Email : ";
		Client.Email = clsInputValidate<string>::ReadString();
		cout << "\nEnter Phone : ";
		Client.Phone = clsInputValidate<string>::ReadString();
		cout << "\nEnter Pin code : ";
		Client.PinCode = clsInputValidate<string>::ReadString();
		cout << "\nEnter Account balance : ";
		Client.AccountBalance = clsInputValidate<float>::ReadNumber();

	}

public:
	static void UpdateClient() {

		_DrawScreenHeader("Update Client");

		string AccountNumber = "";

		cout << "\nPlease etner Account Number : ";
		AccountNumber = clsInputValidate<string>::ReadString();

		while (!clsClient::IsClientExist(AccountNumber)) {

			cout << "\nAccount Number is not found, enter another one : ";
			AccountNumber = clsInputValidate<string>::ReadString();
		}

		clsClient Client = clsClient::Find(AccountNumber);
		_PrintClient(Client);

		cout << "\nAre you sure you want to update this client y/n ";
		char Answer = clsInputValidate<string>::ReadChar();

		if (Answer == 'y') {

			cout << "\nUpdate Client Info : ";
			cout << "\n-----------------------\n";

			_ReadClientInfo(Client);

			clsClient::enSaveResults SaveResult = Client.Save();

			switch (SaveResult)
			{
			case clsClient::enSaveResults::svFailedEmptyObject:

				cout << "\nError Acount was not Updated beacause it is Empty\n";

				break;
			case clsClient::enSaveResults::svSucceded:

				cout << "\nAccount Updated Successfuly :-)\n";

				break;
			default:
				break;
			}
		}
	}

};

