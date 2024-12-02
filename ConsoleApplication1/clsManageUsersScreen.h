#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUsersListScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

using namespace std;

class clsManageUsersScreen : protected clsScreen {

private:
	enum enManageUsersMenuOptions {
		eUsersList = 1, eAddNewUser = 2, eDeleteUser = 3,
		eUpdateUser = 4, eFindUser = 5, eMainMenu = 6
	};

	static short  _ReadManageUsersMenuOption() {

		cout << setw(37) << left << "" << "Choose what do you want to do [1 To 6] ";
		short Choice = clsInputValidate<short>::ReadNumberBetween(1, 6, "Invalid input enter number between 1 and 6 ");
		return Choice;
	}

	static void _GoBackToManageUsersMenu() {

		cout << "\nPress any key to go back to Manage users menu...";
		system("pause > 0");
		ShowManageUsersMenu();
	}

	static void _ShowUsersListScreen() {

		clsUsersListScreen::ShowUsersList();
	}

	static void _ShowAddNewUserScreen() {

		clsAddNewUserScreen::AddNewUser();
	}

	static void _ShowDeleteUserScreen() {

		clsDeleteUserScreen::DeleteUser();
	}

	static void _ShowUpdateUserScreen() {

		clsUpdateUserScreen::UpdateUser();
	}

	static void _ShowFindUserScreen() {

		clsFindUserScreen::FindUser();
	}

	static void _PerformManageUsersMenuOption(enManageUsersMenuOptions MainMenuOptions) {

		switch (MainMenuOptions)
		{
		case clsManageUsersScreen::eUsersList:

			system("cls");
			_ShowUsersListScreen();
			_GoBackToManageUsersMenu();

			break;
		case clsManageUsersScreen::eAddNewUser:

			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUsersMenu();

			break;
		case clsManageUsersScreen::eDeleteUser:

			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersMenu();

			break;
		case clsManageUsersScreen::eUpdateUser:

			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUsersMenu();

			break;
		case clsManageUsersScreen::eFindUser:

			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersMenu();

			break;
		case clsManageUsersScreen::eMainMenu:

			/*the compiler will go back to _PerformMainMenuOption(enMainMenuOptions MainMenuOptions) function
			  and complete compilation because we did not call here _GoBackToManageUsersMenu() function
			  so the excution of function _ShowManageUsersMenu() is complete then it will move to the
			  next line in (Switch case) wich contains _GoBackToMainMenu() that will call MainMenu.
			*/

			break;
		default:
			break;
		}
	}
public:
	static void ShowManageUsersMenu() {

		system("cls");
		_DrawScreenHeader("Manage Users");

		cout << setw(37) << left << "" << "======================================" << endl;
		cout << setw(37) << left << "" << "\t\tManage Users Menue" << endl;
		cout << setw(37) << left << "" << "======================================" << endl;
		cout << setw(37) << left << "" << "\t[1] Show Users List \n";
		cout << setw(37) << left << "" << "\t[2] Add New User \n";
		cout << setw(37) << left << "" << "\t[3] Delete User \n";
		cout << setw(37) << left << "" << "\t[4] Update User \n";
		cout << setw(37) << left << "" << "\t[5] Find User \n";
		cout << setw(37) << left << "" << "\t[6] Main Menu \n";
		cout << setw(37) << left << "" << "======================================" << endl;

		_PerformManageUsersMenuOption((enManageUsersMenuOptions)_ReadManageUsersMenuOption());
	}
};

