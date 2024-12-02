#pragma once

#include "clsScreen.h"
#include "clsCurrency.h"

class clsCurrenciesListScreen : public clsScreen {

private:
	static void _PrintCurrencyRecord(clsCurrency Currency) {

		cout << clsUtil::Tabs(1) << "| " << left << setw(30) << Currency.Country();
		cout << "| " << left << setw(6) << Currency.CurrencyCode();
		cout << "| " << left << setw(40) << Currency.CurrencyName();
		cout << "| " << left << setw(15) << Currency.Rate() << " |\n";

	}

public:
	static void ShowCurrenciesList() {

		vector <clsCurrency> vCurrencies = clsCurrency::GetCurrencies();

		string Title = "Currencies List";
		string SubTitle = "   +++(" + to_string(vCurrencies.size()) + ") Currency+++";

		_DrawScreenHeader(Title, SubTitle);

		cout << clsUtil::Tabs(1) << " ____________________________________________________";
		cout << "_______________________________________________\n\n";
		cout << clsUtil::Tabs(1) << "| " << left << setw(30) << "Country";
		cout << "| " << left << setw(6) << "Code";
		cout << "| " << left << setw(40) << "Currency Name";
		cout << "| " << left << setw(15) << "Rate/(1$)       |\n";
		cout << clsUtil::Tabs(1) << " ___________________________________________________";
		cout << "________________________________________________\n\n";

		if (vCurrencies.size() == 0) {

			cout << "\t\t\t\tNo Currencies Available in the system.\n";
		}
		else {

			for (clsCurrency& Currency : vCurrencies) {

				_PrintCurrencyRecord(Currency);
			}
		}

		cout << clsUtil::Tabs(1) << " ___________________________________________________";
		cout << "________________________________________________\n" << endl;
	}

};

