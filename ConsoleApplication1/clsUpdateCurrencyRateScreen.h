#pragma once

#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsUpdateCurrencyRateScreen : public clsScreen {

private:
	static void _PrintCurrencyInfo(clsCurrency Currency) {

		cout << "\nCurrency Card : ";
		cout << "\n________________________________________\n\n";
		cout << "Country     : " << Currency.Country() << endl;
		cout << "Code        : " << Currency.CurrencyCode() << endl;
		cout << "Name        : " << Currency.CurrencyName() << endl;
		cout << "Rate(1$)    : " << Currency.Rate();
		cout << "\n________________________________________\n";
	}

	static float _ReadRate() {

		cout << "Enter the new rate : ";
		float NewRate = clsInputValidate<float>::ReadNumber();

		return NewRate;
	}

public:
	static void UpdateCurrencyRate() {

		_DrawScreenHeader("Update Rate");

		cout << "\nPlease enter currency code : ";
		string Code = clsInputValidate<string>::ReadString();

		while (!clsCurrency::IsCurrencyExist(Code)) {

			cout << "\nInvalid code, Please enter another one : ";
			Code = clsInputValidate<string>::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(Code);
		_PrintCurrencyInfo(Currency);

		cout << "\nAre you sure you want to update the rate of the " << Currency.CurrencyName() << " y/n ? ";
		char Answer = clsInputValidate<char>::ReadChar();

		if (Answer == 'y') {

			cout << "\nUpdate Currency Rate : ";
			cout << "\n______________________\n\n";
			
			Currency.UpdateRate(_ReadRate());

			cout << "\nRate Updated successfuly :-)\n";
			_PrintCurrencyInfo(Currency);
		}
		else {

			cout << "\nOperation cancelled.\n";
		}
	}
};

