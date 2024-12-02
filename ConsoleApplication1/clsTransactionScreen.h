#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"

using namespace std;

class clsTransactionScreen : protected clsScreen {

private:
	enum enTransactionMenu {
		eDeposit = 1, eWithDraw = 2, eTotalBalance = 3, eTransfer = 4, eTransferLog = 5, eMainMenu = 6
	};

	static short  _ReadTransactionsMenuOption() {

		cout << setw(37) << left << "" << "Choose what do you want to do [1 To 6] ";
		short Choice = clsInputValidate<short>::ReadNumberBetween(1, 6, "Invalid input enter number between 1 and 6 ");
		return Choice;
	}

	static void _GoBackToTransactionsMenu() {

		cout << "\nPress any key to go back to Transaction Menu...";
		system("pause > 0");
		ShowTransactionsMenu();
	}

	static void _ShowDepositScreen() {

		clsDepositScreen::Deposit();
	}

	static void _ShowWithdrawScreen() {

		clsWithdrawScreen::Withdraw();
	}

	static void _ShowTotalBalanceScreen() {

		clsTotalBalancesScreen::ShowTotalBalances();
	}

	static void _ShowTransferScreen() {

		clsTransferScreen::TransferCash();
	}

	static void _ShowTransferLogScreen() {

		clsTransferLogScreen::ShowTransferLogs();
	}

	static void _PerformTransactionsMenuOption(enTransactionMenu TransactionsMenuOptions) {

		switch (TransactionsMenuOptions)
		{
		case clsTransactionScreen::eDeposit:

			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionsMenu();

			break;
		case clsTransactionScreen::eWithDraw:

			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionsMenu();

			break;
		case clsTransactionScreen::eTotalBalance:

			system("cls");
			_ShowTotalBalanceScreen();
			_GoBackToTransactionsMenu();

			break;
		case clsTransactionScreen::eTransfer:

			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionsMenu();

			break;
		case clsTransactionScreen::eTransferLog:

			system("cls");
			_ShowTransferLogScreen();
			_GoBackToTransactionsMenu();

			break;
		case clsTransactionScreen::eMainMenu:

			/*the compiler will go back to _PerformMainMenuOption(enMainMenuOptions MainMenuOptions) function
			  and complete compilation because we did not call here _GoBackToTransactionsMenu() function
			  so the excution of function _ShowTransactionMenu() is complete then it will move to the
			  next line in (Switch case) wich contains _GoBackToMainMenu() that will call MainMenu.
			*/
			break;
		default:
			break;
		}
	}

public:
	static void ShowTransactionsMenu() {

		system("cls");
		_DrawScreenHeader("Transaction");

		cout << setw(37) << left << "" << "======================================" << endl;
		cout << setw(37) << left << "" << "\t\tTransaction Menu" << endl;
		cout << setw(37) << left << "" << "======================================" << endl;
		cout << setw(37) << left << "" << "\t[1] Deposit \n";
		cout << setw(37) << left << "" << "\t[2] Withdraw \n";
		cout << setw(37) << left << "" << "\t[3] Total Balance \n";
		cout << setw(37) << left << "" << "\t[4] Transfer \n";
		cout << setw(37) << left << "" << "\t[5] Transfer Log \n";
		cout << setw(37) << left << "" << "\t[6] Main Menu \n";
		cout << setw(37) << left << "" << "======================================" << endl;

		_PerformTransactionsMenuOption((enTransactionMenu)_ReadTransactionsMenuOption());
	}

};

