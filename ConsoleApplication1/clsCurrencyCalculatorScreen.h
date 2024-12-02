#pragma once

#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"

class clsCurrencyCalculatorScreen : public clsScreen {

private:
	static void _PrintCurrencyInfo(clsCurrency Currency) {

		cout << "\n________________________________________\n\n";
		cout << "Country     : " << Currency.Country() << endl;
		cout << "Code        : " << Currency.CurrencyCode() << endl;
		cout << "Name        : " << Currency.CurrencyName() << endl;
		cout << "Rate(1$)    : " << Currency.Rate();
		cout << "\n________________________________________\n";
	}

	static clsCurrency _GetCurrency(string Message) {

		cout << Message;
		string Code = clsInputValidate<string>::ReadString();

		while (!clsCurrency::IsCurrencyExist(Code)) {

			cout << "\nInvalid code, Please enter another one : ";
			Code = clsInputValidate<string>::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(Code);

		return Currency;
	}

	static float _ReadAmount() {

		cout << "\nEnter amount to exchange : ";
		float Amount = clsInputValidate<float>::ReadNumber();

		return Amount;
	}

public:
	static void _CurrencyCalculator() {
		
		char Answer;

		do {

			system("cls");

			_DrawScreenHeader("Currency Calculator");

			clsCurrency CurrencyFrom = _GetCurrency("Enter Currency code to exchange from : ");
			clsCurrency CurrencyTo = _GetCurrency("\nEnter Currency code to exchange to : ");

			float Amount = _ReadAmount();

			cout << "\nConvert From : ";
			_PrintCurrencyInfo(CurrencyFrom);

			if (CurrencyTo.CurrencyCode() == "USD") {

				cout << "\nConvert To : ";
				_PrintCurrencyInfo(CurrencyTo);

				printf("\n%.f %s = %.3f %s\n", Amount, CurrencyFrom.CurrencyCode().c_str(),
					CurrencyFrom.ConvertToUSD(Amount), CurrencyTo.CurrencyCode().c_str());
			}
			else {

				cout << "\nConvert To : ";
				_PrintCurrencyInfo(CurrencyTo);

				printf("\n%.f %s = %.3f %s\n", Amount, CurrencyFrom.CurrencyCode().c_str(),
					CurrencyFrom.ConvertToOtherCurrency(Amount, CurrencyTo), CurrencyTo.CurrencyCode().c_str());

			}

			cout << "\nDo you want to perform another calculation ? y/n : ";
			Answer = clsInputValidate<char>::ReadChar();

		} while (Answer == 'y');
	}

};

