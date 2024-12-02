#pragma once

#include <iostream>
#include "clsUser.h"
#include "clsScreen.h"
#include "clsUtil.h"

class clsUsersListScreen : protected clsScreen {
private:
	static void _PrintUserRecord(clsUser User) {

		cout << clsUtil::Tabs(1) << "| " << left << setw(15) << User.UserName;
		cout << "| " << left << setw(20) << User.FullName();
		cout << "| " << left << setw(12) << User.Phone;
		cout << "| " << left << setw(23) << User.Email;
		cout << "| " << left << setw(10) << User.Password;
		cout << "| " << left << setw(12) << User.Permissions << " |\n";

	}

public:
	static void ShowUsersList() {

		vector <clsUser> vUsers = clsUser::GetUsersList();

		string Title = "Users List";
		string SubTitle = "  +++Users List(" + to_string(vUsers.size()) + ")+++";

		_DrawScreenHeader(Title, SubTitle);

		cout << clsUtil::Tabs(1) << "____________________________________________________";
		cout << "_____________________________________________________\n\n";
		cout << clsUtil::Tabs(1) << "| " << left << setw(15) << "User Name";
		cout << "| " << left << setw(20) << "Full Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(23) << "Email";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(12) << "Permissions  |\n";
		cout << clsUtil::Tabs(1) << "___________________________________________________";
		cout << "______________________________________________________\n\n";

		if (vUsers.size() == 0) {

			cout << "\t\t\t\tNo Users Available in the system.\n";
		}
		else {

			for (clsUser& User : vUsers) {

				_PrintUserRecord(User);
			}
		}

		cout << clsUtil::Tabs(1) << "___________________________________________________";
		cout << "______________________________________________________\n" << endl;
	}

};

