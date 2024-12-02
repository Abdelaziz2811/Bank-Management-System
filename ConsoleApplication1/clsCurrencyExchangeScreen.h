#pragma once

#include "clsScreen.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"

class clsCurrencyExchangeScreen : public clsScreen {

private:
	enum enCurrenciesExchangeOptions {
		eCurrenciesList = 1, eFindCurrency = 2, eUpdateRate = 3,
		eCurrencyCalculator = 4, eMainMenu = 5
	};

	static short  _ReadCurrencyExchangeMenuOption() {

		cout << setw(37) << left << "" << "Choose what do you want to do [1 To 5] ";
		short Choice = clsInputValidate<short>::ReadNumberBetween(1, 5, "Invalid input enter number between 1 and 5 ");
		return Choice;
	}

	static void _GoBackToCurrencyExchangeMenu() {

		cout << "\nPress any key to go back to Currency Exchange menu...";
		system("pause > 0");
		ShowCurrencyExchangeMenu();
	}

	static void _ShowCurrenciesListScreen() {

		clsCurrenciesListScreen::ShowCurrenciesList();
	}

	static void _ShowFindCurrencyScreen() {

		clsFindCurrencyScreen::FindCurrency();
	}

	static void _ShowUpdateRateScreen() {

		clsUpdateCurrencyRateScreen::UpdateCurrencyRate();
	}

	static void _ShowCurrencyCalculatorScreen() {

		clsCurrencyCalculatorScreen::_CurrencyCalculator();
	}

	static void _PerformCurrencyExchangeOption(enCurrenciesExchangeOptions MainMenuOptions) {

		switch (MainMenuOptions)
		{
		case enCurrenciesExchangeOptions::eCurrenciesList:

			system("cls");
			_ShowCurrenciesListScreen();
			_GoBackToCurrencyExchangeMenu();

			break;
		case enCurrenciesExchangeOptions::eFindCurrency:

			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyExchangeMenu();

			break;
		case enCurrenciesExchangeOptions::eUpdateRate:

			system("cls");
			_ShowUpdateRateScreen();
			_GoBackToCurrencyExchangeMenu();

			break;
		case enCurrenciesExchangeOptions::eCurrencyCalculator:

			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyExchangeMenu();

			break;
		case enCurrenciesExchangeOptions::eMainMenu:
			break;
		default:
			break;
		}
	}
public:
	static void ShowCurrencyExchangeMenu() {

		system("cls");
		_DrawScreenHeader("Currency Exchange");

		cout << setw(37) << left << "" << "======================================" << endl;
		cout << setw(37) << left << "" << "    Currency Exchange Screen Menue" << endl;
		cout << setw(37) << left << "" << "======================================" << endl;
		cout << setw(37) << left << "" << "\t[1] Currencies List \n";
		cout << setw(37) << left << "" << "\t[2] Find Currency \n";
		cout << setw(37) << left << "" << "\t[3] Update Rate \n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator \n";
		cout << setw(37) << left << "" << "\t[5] Main Menu \n";
		cout << setw(37) << left << "" << "======================================" << endl;

		_PerformCurrencyExchangeOption((enCurrenciesExchangeOptions)_ReadCurrencyExchangeMenuOption());
	}

};

