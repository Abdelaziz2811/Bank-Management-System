#pragma once

#include <iostream>
#include <vector>
#include <fStream>
#include "clsString.h"

using namespace std;

class clsCurrency {

private:

	enum enMode { EmptyMode = 0, UpdateMode = 1 };

	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	static clsCurrency _ConvertLineToCurrencyObject(string Line,string Separator = "#//#") {

		vector <string> vCurrencyData = clsString::Split(Line, Separator);

		return clsCurrency(enMode::UpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2], stof(vCurrencyData[3]));
	}

	static clsCurrency _GetEmptyCurrencyObject() {

		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}

	static vector <clsCurrency> _LoadCurrencyRecordFromFile() {

		fstream CurrencyFile;
		vector <clsCurrency> vCurrencies;

		CurrencyFile.open("Currencies.txt", ios::in);

		if (CurrencyFile.is_open()) {

			string Line;

			while (getline(CurrencyFile, Line)) {

				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				vCurrencies.push_back(Currency);
			}

			CurrencyFile.close();
		}
		return vCurrencies;
	}

	string _ConvertCurrencyRecordToLine(clsCurrency Currency, string Seperator = "#//#") {

		string DataLine;
	
		DataLine += Currency._Country + Seperator;
		DataLine += Currency._CurrencyCode + Seperator;
		DataLine += Currency._CurrencyName + Seperator;
		DataLine += to_string(Currency._Rate);

		return DataLine;
	}

	void _SaveCurrencyDataToFile(vector <clsCurrency> vCurrencies) {

		fstream CurrencyFile;

		CurrencyFile.open("Currencies.txt", ios::out);

		if (CurrencyFile.is_open()) {

			for (clsCurrency& Currency : vCurrencies) {

				string CurrencyDataLine = _ConvertCurrencyRecordToLine(Currency);

				CurrencyFile << CurrencyDataLine << endl;
			}

			CurrencyFile.close();
		}
	}

	void _Update() {

		vector <clsCurrency> vCurrencies = _LoadCurrencyRecordFromFile();

		for (clsCurrency& Currency : vCurrencies) {

			if (Currency.CurrencyCode() == _CurrencyCode) {

				Currency = *this;
			}
		}

		_SaveCurrencyDataToFile(vCurrencies);
	}

public:
	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate) {

		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	bool IsEmpty() {

		return _Mode == enMode::EmptyMode;
	}

	string Country() {

		return _Country;
	}

	string CurrencyCode() {

		return _CurrencyCode;
	}

	string CurrencyName() {

		return _CurrencyName;
	}

	float Rate() {

		return _Rate;
	}

	void UpdateRate(float NewRate) {

		_Rate = NewRate;
		_Update();
	}

	static clsCurrency FindByCode(string CurrencyCode) {

		CurrencyCode = clsString::UpperAllString(CurrencyCode);

		fstream CurrencyFile;

		CurrencyFile.open("Currencies.txt", ios::in);

		if (CurrencyFile.is_open()) {

			string Line;

			while (getline(CurrencyFile, Line)) {

				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);

				if (Currency.CurrencyCode() == CurrencyCode) {

					CurrencyFile.close();
					return Currency;
				}
			}
			return _GetEmptyCurrencyObject();
		}
	}

	static clsCurrency FindByCountry(string Country) {

		Country = clsString::UpperAllString(Country);

		fstream CurrencyFile;

		CurrencyFile.open("Currencies.txt", ios::in);

		if (CurrencyFile.is_open()) {

			string Line;

			while (getline(CurrencyFile, Line)) {

				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);

				if (clsString::UpperAllString(Currency.Country()) == Country) {

					CurrencyFile.close();
					return Currency;
				}
			}
			return _GetEmptyCurrencyObject();
		}
	}

	static bool IsCurrencyExist(string CurrencyCode) {

		clsCurrency Curreny = FindByCode(CurrencyCode);
		return (!Curreny.IsEmpty());
	}

	static vector <clsCurrency> GetCurrencies() {

		return _LoadCurrencyRecordFromFile();
	}

	float ConvertToUSD(float Amount) {

		return Amount / _Rate;
	}

	float ConvertToOtherCurrency(float Amount, clsCurrency CurrencyTo) {

		return ConvertToUSD(Amount) * CurrencyTo.Rate();
	}

};

