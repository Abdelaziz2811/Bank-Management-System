#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsUtil.h"

using namespace std;

class clsTotalBalancesScreen : protected clsScreen {

private:
	static void _PrintClientBalances(clsClient Client) {

		cout << clsUtil::Tabs(3) << "| " << left << setw(15) << Client.AccountNumber();
		cout << "| " << left << setw(30) << Client.FullName();
		cout << "| " << left << setw(12) << Client.AccountBalance << " |\n";

	}

public:

	static void ShowTotalBalances() {

		_DrawScreenHeader("Total Balances");

		vector <clsClient> vClients = clsClient::GetClientsList();

		cout << "\n" << clsUtil::Tabs(5) << "     +++Clients List(" << vClients.size() << ")+++\n";
		cout << clsUtil::Tabs(3) << "__________________________________";
		cout << "______________________________\n\n";
		cout << clsUtil::Tabs(3) << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(30) << "Client Name";
		cout << "| " << left << setw(12) << "Balance      |\n";
		cout << clsUtil::Tabs(3) << "__________________________________";
		cout << "______________________________\n\n";

		if (vClients.size() == 0) {

			cout << "\tNo Clients Available in the system.\n";
		}
		else {

			for (clsClient& Client : vClients) {

				_PrintClientBalances(Client);
			}

			cout << clsUtil::Tabs(3) << "__________________________________";
			cout << "______________________________\n" << endl;

			double TotalBalance = clsClient::GetTotalBalances();

			cout << clsUtil::Tabs(3) << "\t\t    Total Balances = " << TotalBalance << endl;
			cout << clsUtil::Tabs(3) << "\t  [" << clsUtil::NumberToText(TotalBalance) << "]" << endl;
		}
	}

};

