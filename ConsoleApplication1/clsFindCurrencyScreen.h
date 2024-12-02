#pragma once

#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsFindCurrencyScreen : public clsScreen {

private:
	static short _ReadChoice() {

		short Choice;

		cout << "Find By [1] code or [2] country ? ";
		Choice = clsInputValidate<short>::ReadNumberBetween(1, 2, "Invalid input enter number between 1 and 2 ");

		return Choice;
	}

	static void _PrintCurrencyInfo(clsCurrency Currency) {

		cout << "\nCurrency Card : ";
		cout << "\n________________________________________\n\n";
		cout << "Country     : " << Currency.Country() << endl;
		cout << "Code        : " << Currency.CurrencyCode() << endl;
		cout << "Name        : " << Currency.CurrencyName() << endl;
		cout << "Rate(1$)    : " << Currency.Rate();
		cout << "\n________________________________________\n";
	}

	static void _ShowResults(clsCurrency Currency) {

		if (!Currency.IsEmpty()) {

			cout << "\nCurrency Found :-)\n";
			_PrintCurrencyInfo(Currency);
		}
		else
			cout << "\nCurrency Not Found :-(\n";
	}

public:
	static void FindCurrency() {

		_DrawScreenHeader("Find Currency");

		short Choice = _ReadChoice();	

		if (Choice == 1) {

			cout << "\nPlease enter currency code : ";
			string Code = clsInputValidate<string>::ReadString();

			clsCurrency Currency = clsCurrency::FindByCode(Code);

			_ShowResults(Currency);
		}
		else {

			cout << "\nPlease enter country : ";
			string Country = clsInputValidate<string>::ReadString();

			clsCurrency Currency = clsCurrency::FindByCountry(Country);
			
			_ShowResults(Currency);
		}
	}

};

