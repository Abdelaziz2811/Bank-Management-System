#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"

class clsAddNewClientScreen : protected clsScreen {

private:
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

	static void _Print(clsClient Client) {

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
	static void AddNewClient() {

		_DrawScreenHeader("Add New Client");

		string AccountNumber = "";

		cout << "\nEnter Account Number : ";
		AccountNumber = clsInputValidate<string>::ReadString();

		while (clsClient::IsClientExist(AccountNumber)) {

			cout << "Account Number " << AccountNumber << " already exist, choose another one : ";
			AccountNumber = clsInputValidate<string>::ReadString();
		}

		clsClient NewClient = clsClient::GetAddNewClientObject(AccountNumber);

		_ReadClientInfo(NewClient);

		clsClient::enSaveResults SaveResult = NewClient.Save();

		switch (SaveResult)
		{
		case clsClient::enSaveResults::svFailedEmptyObject:

			cout << "\nError Acount was not saved beacause it is Empty\n";

			break;
		case clsClient::enSaveResults::svSucceded:

			cout << "\nAccount Added Successfuly :-)\n";
			_Print(NewClient);

			break;
		case clsClient::enSaveResults::svFailAccountNumberExist:

			cout << "\nError Acount was not saved, because it exist\n";

			break;
		default:
			break;
		}
	}

};

