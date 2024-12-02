#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionScreen.h"
#include "clsManageUsersScreen.h"
#include "Global.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrencyExchangeScreen.h"

using namespace std;

class clsMainScreen : protected clsScreen {

private:
	enum enMainMenuOptions {
		eClientsList = 1, eAddNewClient = 2, eDeleteClient = 3, eUpdateClient = 4
		, eFindClient = 5, eShowTransactionsMenu = 6, eManageUsers = 7, eLoginRegister = 8, eCurrencyExchange = 9, eExit = 10
	};

	static short _ReadMainMenuOption() {

		cout << setw(37) << left << "" << "Choose what do you want to do [1 To 10] ";
		short Choice = clsInputValidate<short>::ReadNumberBetween(1, 10, "Invalid input enter number between 1 and 10 ");
		return Choice;
	}

	static void _GoBackToMainMenu() {

		cout << "\nPress any key to go back to main menu...";
		system("pause > 0");
		ShowMainMenu();
	}

	static void _ShowClientsScreen() {

		if (!CheckAccessRights(clsUser::enPermissions::pClientsList)) {

			return;
			/*If the user doesn't have permission, the function returns immediately (exits)
			without doing anything else.*/
		}
		clsClientListScreen::ShowClientsList();
	}

	static void _ShowAddNewClientScreen() {

		if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient)) {

			return;
			/*If the user doesn't have permission, the function returns immediately (exits)
			without doing anything else.*/
		}
		clsAddNewClientScreen::AddNewClient();
	}

	static void _ShowDeleteClientScreen() {

		if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient)) {

			return;
			/*If the user doesn't have permission, the function returns immediately (exits)
			without doing anything else.*/
		}
		clsDeleteClientScreen::DeleteClient();
	}

	static void _ShowUpdateClientScreen() {

		if (!CheckAccessRights(clsUser::enPermissions::pUpdateClient)) {

			return;
			/*If the user doesn't have permission, the function returns immediately (exits)
			without doing anything else.*/
		}
		clsUpdateClientScreen::UpdateClient();
	}

	static void _ShowFindClientScreen() {

		if (!CheckAccessRights(clsUser::enPermissions::pFindClient)) {

			return;
			/*If the user doesn't have permission, the function returns immediately (exits)
			without doing anything else.*/
		}
		clsFindClientScreen::FindClient();
	}

	static void _ShowTransactionMenu() {

		if (!CheckAccessRights(clsUser::enPermissions::pShowTransactionsMenu)) {

			return;
			/*If the user doesn't have permission, the function returns immediately (exits)
			without doing anything else.*/
		}
		clsTransactionScreen::ShowTransactionsMenu();
	}

	static void _ShowManageUsersMenu() {

		if (!CheckAccessRights(clsUser::enPermissions::pManageUsers)) {

			return;
			/*If the user doesn't have permission, the function returns immediately (exits)
			without doing anything else.*/
		}
		clsManageUsersScreen::ShowManageUsersMenu();
	}

	static void _ShowLoginRegisterScreen() {

		if (!CheckAccessRights(clsUser::enPermissions::pShowLoginRegister)) {

			return;
			/*If the user doesn't have permission, the function returns immediately (exits)
			without doing anything else.*/
		}
		clsLoginRegisterScreen::ShowLoginRegister();
	}

	static void _ShowCurrencyExchangeScreen() {

		clsCurrencyExchangeScreen::ShowCurrencyExchangeMenu();
	}

	static void _Logout() {

		CurrentUser = clsUser::Find("", "");
	}

	static void _PerformMainMenuOption(enMainMenuOptions MainMenuOptions) {

		switch (MainMenuOptions)
		{
		case clsMainScreen::eClientsList:

			system("cls");
			_ShowClientsScreen();
			_GoBackToMainMenu();

			break;
		case clsMainScreen::eAddNewClient:

			system("cls");
			_ShowAddNewClientScreen();
			_GoBackToMainMenu();

			break;
		case clsMainScreen::eDeleteClient:

			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenu();

			break;
		case clsMainScreen::eUpdateClient:

			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenu();

			break;
		case clsMainScreen::eFindClient:

			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenu();

			break;
		case clsMainScreen::eShowTransactionsMenu:

			system("cls");
			_ShowTransactionMenu();
			_GoBackToMainMenu();

			break;
		case clsMainScreen::eManageUsers:

			system("cls");
			_ShowManageUsersMenu();
			_GoBackToMainMenu();

			break;
		case clsMainScreen::eLoginRegister:

			system("cls");
			_ShowLoginRegisterScreen();
			_GoBackToMainMenu();

			break;
		case clsMainScreen::eCurrencyExchange:

			system("cls");
			_ShowCurrencyExchangeScreen();
			_GoBackToMainMenu();

			break;
		case clsMainScreen::eExit:

			system("cls");
			_Logout();

			break;
		default:
			break;
		}
	}

public:
	static void ShowMainMenu() {

		system("cls");
		_DrawScreenHeader("Main Screen");

		cout << setw(37) << left << "" << "======================================" << endl;
		cout << setw(37) << left << "" << "\t\t  Main Menue" << endl;
		cout << setw(37) << left << "" << "======================================" << endl;
		cout << setw(37) << left << "" << "\t[1] Show Client List \n";
		cout << setw(37) << left << "" << "\t[2] Add New Client \n";
		cout << setw(37) << left << "" << "\t[3] Delete Client \n";
		cout << setw(37) << left << "" << "\t[4] Update Client \n";
		cout << setw(37) << left << "" << "\t[5] Find Client \n";
		cout << setw(37) << left << "" << "\t[6] Transactions \n";
		cout << setw(37) << left << "" << "\t[7] Manage Users \n";
		cout << setw(37) << left << "" << "\t[8] Login Register \n";
		cout << setw(37) << left << "" << "\t[9] Currency Exchange \n";
		cout << setw(37) << left << "" << "\t[10] Logout \n";
		cout << setw(37) << left << "" << "======================================" << endl;

		_PerformMainMenuOption((enMainMenuOptions)_ReadMainMenuOption());
	}

};

