#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class clsFindUserScreen : protected clsScreen {
private:
	static void _PrintUser(clsUser User) {

		cout << "\n\t\tUser Card\n";
		cout << "----------------------------------------------\n";
		cout << "First Name  : " << User.FirstName << endl;
		cout << "Last Name   : " << User.LastName << endl;
		cout << "Full Name   : " << User.FullName() << endl;
		cout << "Email       : " << User.Email << endl;
		cout << "Phone       : " << User.Phone << endl;
		cout << "UserNme     : " << User.UserName << endl;
		cout << "Password    : " << User.Password << endl;
		cout << "Permissions : " << User.Permissions << endl;
		cout << "----------------------------------------------\n";

	}

public:
	static void FindUser() {

		_DrawScreenHeader("Find User");

		string UserName = "";

		cout << "\nPlease etner UserName : ";
		UserName = clsInputValidate<string>::ReadString();

		while (!clsUser::IsUserExist(UserName)) {

			cout << "\nUserName is not found, enter another one : ";
			UserName = clsInputValidate<string>::ReadString();
		}

		clsUser User = clsUser::Find(UserName);

		if (!User.IsEmpty()) {

			cout << "\nUser Found :-)\n";
			_PrintUser(User);
		}
		else {

			cout << "\nUser Was not found :-(\n";
		}
	}

};

