#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class clsUpdateUserScreen : protected clsScreen {

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

	static int _ReadUserPermissionsToSet() {

		int Permissions = 0;
		char Answer;

		cout << "\nDo you want to give full access y/n? : ";
		Answer = clsInputValidate<char>::ReadChar();
		if (Answer == 'y') {

			return -1;
		}

		cout << "\nDo you want to give access to : \n";

		cout << "Show Clients List y/n ? ";
		Answer = clsInputValidate<char>::ReadChar();
		if (Answer == 'y') {

			Permissions += clsUser::enPermissions::pClientsList;
		}

		cout << "Add New Clients y/n ? ";
		Answer = clsInputValidate<char>::ReadChar();
		if (Answer == 'y') {

			Permissions += clsUser::enPermissions::pAddNewClient;
		}

		cout << "Delete Clients y/n ? ";
		Answer = clsInputValidate<char>::ReadChar();
		if (Answer == 'y') {

			Permissions += clsUser::enPermissions::pDeleteClient;
		}

		cout << "Update Clients y/n ? ";
		Answer = clsInputValidate<char>::ReadChar();
		if (Answer == 'y') {

			Permissions += clsUser::enPermissions::pUpdateClient;
		}

		cout << "Find Clients y/n ? ";
		Answer = clsInputValidate<char>::ReadChar();
		if (Answer == 'y') {

			Permissions += clsUser::enPermissions::pFindClient;
		}

		cout << "Transactions Menu y/n ? ";
		Answer = clsInputValidate<char>::ReadChar();
		if (Answer == 'y') {

			Permissions += clsUser::enPermissions::pShowTransactionsMenu;
		}

		cout << "Manage Users y/n ? ";
		Answer = clsInputValidate<char>::ReadChar();
		if (Answer == 'y') {

			Permissions += clsUser::enPermissions::pManageUsers;
		}

		cout << "Show Login Register y/n ? ";
		Answer = clsInputValidate<char>::ReadChar();
		if (Answer == 'y') {

			Permissions += clsUser::enPermissions::pShowLoginRegister;
		}

		return Permissions;
	}

	static void _ReadUserInfo(clsUser& User) {

		cout << "\nEnter first name : ";
		User.FirstName = clsInputValidate<string>::ReadString();
		cout << "\nEnter last name : ";
		User.LastName = clsInputValidate<string>::ReadString();
		cout << "\nEnter Email : ";
		User.Email = clsInputValidate<string>::ReadString();
		cout << "\nEnter Phone : ";
		User.Phone = clsInputValidate<string>::ReadString();
		cout << "\nEnter Password : ";
		User.Password = clsInputValidate<string>::ReadString();
		cout << "\nEnter User Permissions : ";
		User.Permissions = _ReadUserPermissionsToSet();

	}

public:
	static void UpdateUser() {

		_DrawScreenHeader("Update User");

		string UserName = "";

		cout << "\nPlease etner UserName : ";
		UserName = clsInputValidate<string>::ReadString();

		while (!clsUser::IsUserExist(UserName)) {

			cout << "\nUserName is not found, enter another one : ";
			UserName = clsInputValidate<string>::ReadString();
		}

		clsUser User = clsUser::Find(UserName);
		_PrintUser(User);

		cout << "\nAre you sure you want to update this User y/n ";
		char Answer = clsInputValidate<char>::ReadChar();

		if (Answer == 'y') {

			cout << "\nUpdate User Info : ";
			cout << "\n-----------------------\n";

			_ReadUserInfo(User);

			clsUser::enSaveResults SaveResult = User.Save();

			switch (SaveResult)
			{
			case clsUser::enSaveResults::svFailedEmptyObject:

				cout << "\nError User was not Updated beacause it is Empty\n";

				break;
			case clsUser::enSaveResults::svSucceded:

				cout << "\nUser Updated Successfuly :-)\n";
				_PrintUser(User);

				break;
			default:
				break;
			}
		}
	}

};

