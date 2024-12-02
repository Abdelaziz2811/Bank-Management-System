#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"

using namespace std;

class clsLoginRegisterScreen : protected clsScreen {

private:
	static void _PrintLoginRecord(clsUser::stLoginRegisterRecord LoginRecord) {

		cout << clsUtil::Tabs(2) << "| " << left << setw(25) << LoginRecord.Date;
		cout << "| " << left << setw(20) << LoginRecord.UserName;
		cout << "| " << left << setw(12) << LoginRecord.Password;
		cout << "| " << left << setw(12) << LoginRecord.Permissions << " |\n";
	}

public:
	static void ShowLoginRegister() {

		vector <clsUser::stLoginRegisterRecord> vLoginRecods = clsUser::GetLoginRecords();

		string Title = "Login Register";
		string SubTitle = "   ---(" + to_string(vLoginRecods.size()) + ") Record(s)---";

		_DrawScreenHeader(Title, SubTitle);

		cout << clsUtil::Tabs(2) << " ___________________________________________________";
		cout << "__________________________\n\n";
		cout << clsUtil::Tabs(2) << "| " << left << setw(25) << "Date";
		cout << "| " << left << setw(20) << "User Name";
		cout << "| " << left << setw(12) << "Password";
		cout << "| " << left << setw(12) << "Permissions  |\n";
		cout << clsUtil::Tabs(2) << " __________________________________________________";
		cout << "___________________________\n\n";

		if (vLoginRecods.size() == 0) {

			cout << "\t\t\t\tLogin Register is Empty.\n";
		}
		else {

			for (clsUser::stLoginRegisterRecord& LoginRecord : vLoginRecods) {

				_PrintLoginRecord(LoginRecord);
			}
		}

		cout << clsUtil::Tabs(2) << " __________________________________________________";
		cout << "___________________________\n" << endl;
	}

};

