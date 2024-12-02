#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

using namespace std;

class clsAddNewUserScreen : protected clsScreen {

private:
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

	static void _Print(clsUser User) {

		cout << "\n\t\tUser Card\n";
		cout << "----------------------------------------------\n";
		cout << "First Name  : " << User.FirstName << endl;
		cout << "Last Name   : " << User.LastName << endl;
		cout << "Full Name   : " << User.FullName() << endl;
		cout << "Email       : " << User.Email << endl;
		cout << "Phone       : " << User.Phone << endl;
		cout << "User Name   : " << User.UserName << endl;
		cout << "Password    : " << User.Password << endl;
		cout << "Permission  : " << User.Permissions << endl;
		cout << "----------------------------------------------\n";

	}

public:
	static void AddNewUser() {

		_DrawScreenHeader("Add New User");

		string UserName = "";

		cout << "\nEnter User Name : ";
		UserName = clsInputValidate<string>::ReadString();

		while (clsUser::IsUserExist(UserName)) {

			cout << "User Name '" << UserName << "' already exist, choose another one : ";
			UserName = clsInputValidate<string>::ReadString();
		}

		clsUser NewUser = clsUser::GetAddNewUserObject(UserName);

		_ReadUserInfo(NewUser);

		clsUser::enSaveResults SaveResult = NewUser.Save();

		switch (SaveResult)
		{
		case clsUser::enSaveResults::svFailedEmptyObject:

			cout << "\nError User was not saved beacause it is Empty\n";

			break;
		case clsUser::enSaveResults::svSucceded:

			cout << "\nUser Added Successfuly :-)\n";
			_Print(NewUser);

			break;
		case clsUser::enSaveResults::svFailUserNameExist:

			cout << "\nError User was not saved, because it exist\n";

			break;
		default:
			break;
		}
	}

};


