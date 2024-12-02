#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsUtil.h"

class clsClientListScreen : protected clsScreen {

private:
	static void _PrintClientRecord(clsClient Client) {

		cout << clsUtil::Tabs(1) << "| " << left << setw(15) << Client.AccountNumber();
		cout << "| " << left << setw(20) << Client.FullName();
		cout << "| " << left << setw(12) << Client.Phone;
		cout << "| " << left << setw(23) << Client.Email;
		cout << "| " << left << setw(10) << Client.PinCode;
		cout << "| " << left << setw(12) << Client.AccountBalance << " |\n";

	}

public:

	static void ShowClientsList() {

		vector <clsClient> vClients = clsClient::GetClientsList();

		string Title = "Clients List";
		string SubTitle = "  +++Clients List(" + to_string(vClients.size()) + ")+++";

		_DrawScreenHeader(Title, SubTitle);

		cout << clsUtil::Tabs(1) << "____________________________________________________";
		cout << "_____________________________________________________\n\n";
		cout << clsUtil::Tabs(1) << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(23) << "Email";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(12) << "Balance      |\n";
		cout << clsUtil::Tabs(1) << "___________________________________________________";
		cout << "______________________________________________________\n\n";

		if (vClients.size() == 0) {

			cout << "\t\t\t\tNo Clients Available in the system.\n";
		}
		else {

			for (clsClient& Client : vClients) {

				_PrintClientRecord(Client);
			}
		}

		cout << clsUtil::Tabs(1) << "___________________________________________________";
		cout << "______________________________________________________\n" << endl;
	}

};

