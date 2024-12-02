#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
#include "Global.h"
#include "clsMainScreen.h"
#include "clsUtil.h"

class clsLoginScreen : protected clsScreen {

private:

	static bool _Login() {
		
		short TrialsToLogin = 3;

		bool LoginFail = false;

		string UserName, Password;

		do {

			if (LoginFail) {

				system("cls");
				_DrawScreenHeader("Login Screen");

				TrialsToLogin--;
				cout << "\t\t\t\t\tInvalid UserName/Password!\n";
				cout << "\t\t\t\t\tYou have " << TrialsToLogin << " Trial(s) left to login\n\n";
			}

			cout << "\t\t\t\t\tEnter UserName : ";
			UserName = clsInputValidate<string>::ReadString();

			cout << "\n\t\t\t\t\tEnter Password : ";
			Password = clsInputValidate<string>::ReadString();

			CurrentUser = clsUser::Find(UserName, Password);

			LoginFail = CurrentUser.IsEmpty();

		} while (LoginFail && TrialsToLogin > 1);

		if (!LoginFail) {

			CurrentUser.RegisterLogRecordToFile();

			clsMainScreen::ShowMainMenu();
			return true;
		}
		else
			return false;
	}
public:
	static bool LoginScreen() {

		system("cls");
		_DrawScreenHeader("Login Screen");
		return _Login();

	}
};

