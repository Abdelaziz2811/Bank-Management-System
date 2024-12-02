#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

using namespace std;

class clsDeleteUserScreen : protected clsScreen {

private:
	static void _PrintUser(clsUser User) {

		cout << "\n\t\tUser Card\n";
		cout << "----------------------------------------------\n";
		cout << "First Name  : " << User.FirstName << endl;
		cout << "Last Name   : " << User.LastName << endl;
		cout << "Full Name   : " << User.FullName() << endl;
		cout << "Email       : " << User.Email << endl;
		cout << "Phone       : " << User.Phone << endl;
		cout << "User Name   : " << User.UserName << endl;
		cout << "Password    : " << User.Password << endl;
		cout << "Permissions : " << User.Permissions << endl;
		cout << "----------------------------------------------\n";

	}

public:
	static void DeleteUser() {

		_DrawScreenHeader("Delete User");

		string UserName;

		cout << "Enter UserName : ";
		UserName = clsInputValidate<string>::ReadString();

		while (!clsUser::IsUserExist(UserName)) {

			cout << "User with UserName '" << UserName << "' is not exist choose anoter one : ";
			UserName = clsInputValidate<string>::ReadString();
		}

		clsUser User = clsUser::Find(UserName);
		_PrintUser(User);

		cout << "\nAre you sure you want to delete this user y/n : ";
		char Answer = clsInputValidate<char>::ReadChar();

		if (Answer == 'y') {

			if (User.Delete()) {

				cout << "\nUser Deleted successfuly :-)\n";
				_PrintUser(User);
			}
			else {

				cout << "\nError User was not Deleted\n";
			}
		}
	}
};

