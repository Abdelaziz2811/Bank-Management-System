#pragma once

#include "clsScreen.h"
#include "clsUtil.h"
#include "clsBankClient.h"

class clsTransferLogScreen : protected clsScreen {

private:
	static void _PrintTransferLog(clsClient::stTransferLog TransferLog) {

		cout << clsUtil::Tabs(1) << "| " << left << setw(25) << TransferLog.Date;
		cout << "| " << left << setw(8) << TransferLog.SourceAccount;
		cout << "| " << left << setw(8) << TransferLog.DestinationAccount;
		cout << "| " << left << setw(10) << TransferLog.Amount;
		cout << "| " << left << setw(12) << TransferLog.SourceBalance;
		cout << "| " << left << setw(12) << TransferLog.DestinationBalance;
		cout << "| " << left << setw(8) << TransferLog.User << "|\n";
		
	}

public:
	static void ShowTransferLogs() {

		vector <clsClient::stTransferLog> vTransferLogs = clsClient::GetTransferLogs();

		string Title = "Transfer Logs";
		string SubTitle = "   ---(" + to_string(vTransferLogs.size()) + ") Record(s)---";

		_DrawScreenHeader(Title, SubTitle);

		cout << clsUtil::Tabs(1) << " ____________________________________________________";
		cout << "____________________________________________\n\n";
		cout << clsUtil::Tabs(1) << "| " << left << setw(25) << "Date";
		cout << "| " << left << setw(8) << "s.Acct";
		cout << "| " << left << setw(8) << "d.Acct";
		cout << "| " << left << setw(10) << "Amount";
		cout << "| " << left << setw(12) << "s.Balance";
		cout << "| " << left << setw(12) << "d.Balance";
		cout << "| " << left << setw(8) << "User    |\n";
		cout << clsUtil::Tabs(1) << " ____________________________________________________";
		cout << "____________________________________________\n\n";

		if (vTransferLogs.size() == 0) {

			cout << "\t\t\t\tTransfer Log is empty.\n";
		}
		else {

			for (clsClient::stTransferLog& TransferLog : vTransferLogs) {

				_PrintTransferLog(TransferLog);
			}
		}

		cout << clsUtil::Tabs(1) << " ____________________________________________________";
		cout << "____________________________________________\n" << endl;
	}

};

