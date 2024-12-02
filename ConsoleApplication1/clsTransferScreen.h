#pragma once

#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsTransferScreen : public clsScreen {

private:
	static void _PrintClient(clsClient Client) {

		cout << "\n\tClient Card\n";
		cout << "----------------------------------\n";
		cout << "Full Name   : " << Client.FullName() << endl;
		cout << "Acc. Number : " << Client.AccountNumber() << endl;
		cout << "Balance     : " << Client.AccountBalance << endl;
		cout << "----------------------------------\n";

	}

	static string _ReadAccountNumber() {

		string AccountNumber = "";

		cout << "\nPlease etner Account Number To Transfer From : ";
		AccountNumber = clsInputValidate<string>::ReadString();

		while (!clsClient::IsClientExist(AccountNumber)) {

			cout << "\nAccount Number is not found, enter another one : ";
			AccountNumber = clsInputValidate<string>::ReadString();
		}

		return AccountNumber;
	}
public:
	static void TransferCash() {

		_DrawScreenHeader("Transfer");
		
		clsClient SourceAccount = clsClient::Find(_ReadAccountNumber());
		_PrintClient(SourceAccount);

		clsClient DestinationAccount = clsClient::Find(_ReadAccountNumber());
		_PrintClient(DestinationAccount);

		double TransferAmount;
		cout << "\nPlease Enter Transfer amount : ";
		TransferAmount = clsInputValidate<double>::ReadNumber();

		while (TransferAmount > SourceAccount.AccountBalance) {

			cout << "Amount Exceeds the balance! Enter a valid amount.";
			TransferAmount = clsInputValidate<double>::ReadNumber();
		}

		char Answer = 'n';
		cout << "Are you sure you want to perform this operation y/n ? : ";
		Answer = clsInputValidate<char>::ReadChar();

		if (Answer == 'y') {

			if (SourceAccount.TransferCash(DestinationAccount, TransferAmount)) {

				cout << "\nTransfer Done successfuly.\n";
			}
			else {

				cout << "\nTransfer doesn't complete try another time.\n";
			}
			_PrintClient(SourceAccount);
			_PrintClient(DestinationAccount);
		}
		else {

			cout << "\nOperation cancelled.\n";
		}
	}

};

