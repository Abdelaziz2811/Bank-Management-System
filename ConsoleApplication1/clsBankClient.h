#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsPerson.h"
#include "clsString.h"
#include "clsDate.h"
#include "Global.h"

using namespace std;

class clsClient : public clsPerson {

private:
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;
	bool _MarkForDelete = false;

	string _AccountNumber;
	string _PinCode;
	double _AccountBalance;

	static clsClient _ConvertLineToUserObject(string Line, string Seperator = "#//#") {

		vector <string> vClientData;
		vClientData = clsString::Split(Line, Seperator);

		return clsClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3]
			, vClientData[4], vClientData[5], stof(vClientData[6]));
	}
	
	static clsClient _GetEmptyClientObject() {

		return clsClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static vector <clsClient> _LoadClientsDataFromFile() {

		vector <clsClient> vClients;
		fstream ClientsFile;
		
		ClientsFile.open("Clients.txt", ios::in);

		if (ClientsFile.is_open()) {

			string Line;
			while (getline(ClientsFile, Line)) {

				clsClient Client = _ConvertLineToUserObject(Line);
				vClients.push_back(Client);
			}
			ClientsFile.close();
		}
		return vClients;
	}

	static string _ConvertClientObjectToLine(clsClient Client, string Seperator = "#//#") {

		string DataLine;

		DataLine += Client.FirstName + Seperator;
		DataLine += Client.LastName + Seperator;
		DataLine += Client.Email + Seperator;
		DataLine += Client.Phone + Seperator;
		DataLine += Client.AccountNumber() + Seperator;
		DataLine += Client.PinCode + Seperator;
		DataLine += to_string(Client.AccountBalance);
		
		return DataLine;
	}

	static void _SaveClientDataToFile(vector <clsClient> vClients) {

		fstream ClientsFile;
		ClientsFile.open("Clients.txt", ios::out);

		if (ClientsFile.is_open()) {

			string DataLine;
			for (clsClient& C : vClients) {

				if (C._MarkForDelete == false) {

					DataLine = _ConvertClientObjectToLine(C);
					ClientsFile << DataLine << endl;
				}
			}

			ClientsFile.close();
		}
	}

	void _Update() {

		vector <clsClient> _vClients;
		_vClients = _LoadClientsDataFromFile();

		for (clsClient& C : _vClients) {

			if (C.AccountNumber() == AccountNumber()) {

				C = *this;
				break;
			}
		}
		_SaveClientDataToFile(_vClients);
	}

	void _AddDataLineToFile(string DataLine) {

		fstream ClientsFile;
		ClientsFile.open("Clients.txt", ios::out | ios::app);

		if (ClientsFile.is_open()) {

			ClientsFile << DataLine << endl;

			ClientsFile.close();
		}
	}

	void _AddNew() {

		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}

	string _PrepareTransferLogLine(clsClient DestinationAccount, double TransferAmount, string Seperator = "#//#") {

		string TransferLogLine;

		TransferLogLine += clsDate::GetSystemDateString() + Seperator;
		TransferLogLine += _AccountNumber + Seperator;
		TransferLogLine += DestinationAccount.AccountNumber() + Seperator;
		TransferLogLine += to_string(TransferAmount) + Seperator;
		TransferLogLine += to_string(AccountBalance) + Seperator;
		TransferLogLine += to_string(DestinationAccount.AccountBalance) + Seperator;
		TransferLogLine += CurrentUser.UserName;

		return TransferLogLine;
	}

	void _RegisterTransferLog(clsClient DestinationAccount, double TransferAmount) {

		fstream TransferLogFile;
		string TransferLogDataLine = _PrepareTransferLogLine(DestinationAccount, TransferAmount);

		TransferLogFile.open("TransferLog.txt", ios::out | ios::app);

		if (TransferLogFile.is_open()) {

			TransferLogFile << TransferLogDataLine << endl;

			TransferLogFile.close();
		}
	}

	struct stTransferLog;

	static stTransferLog _ConvertTransferLogsToRecord(string Line, string Seperator = "#//#") {

		vector <string> vTransferLogData = clsString::Split(Line, Seperator);

		stTransferLog TransferLog;

		TransferLog.Date = vTransferLogData[0];
		TransferLog.SourceAccount = vTransferLogData[1];
		TransferLog.DestinationAccount = vTransferLogData[2];
		TransferLog.Amount = stod(vTransferLogData[3]);
		TransferLog.SourceBalance = stod(vTransferLogData[4]);
		TransferLog.DestinationBalance = stod(vTransferLogData[5]);
		TransferLog.User = vTransferLogData[6];

		return TransferLog;
	}

	static vector <stTransferLog> _LoadTransferLogsFromFile() {
		
		vector <stTransferLog> vTransferLogs;
		fstream TransferLogFile;

		TransferLogFile.open("TransferLog.txt", ios::in);

		if (TransferLogFile.is_open()) {

			string Line;
			while (getline(TransferLogFile, Line)) {

				stTransferLog TransferLog = _ConvertTransferLogsToRecord(Line);
					vTransferLogs.push_back(TransferLog);
			}
			TransferLogFile.close();
		}
		return vTransferLogs;
	}

public:
	clsClient(enMode Mode, string FirstName, string LastName, string Email, string Phone
		, string AccountNumber, string PinCode, float AccountBalance)
		: clsPerson(FirstName, LastName, Email, Phone) {

		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	struct stTransferLog {

		string Date;
		string SourceAccount;
		string DestinationAccount;
		double Amount;
		double SourceBalance;
		double DestinationBalance;
		string User;
	};

	string AccountNumber() {

		return _AccountNumber;
	}

	void SetPincode(string PinCode) {

		_PinCode = PinCode;
	}
	string GetPinCode() {

		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPincode))string PinCode;

	void SetAccountBalance(double AccountBalance) {

		_AccountBalance = AccountBalance;
	}
	double GetAccountBalance() {

		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance))double AccountBalance;

	bool IsEmpty() {

		return _Mode == enMode::EmptyMode;
	}

	static clsClient Find(string AccountNumber) {

		vector <clsClient> vClients;

		fstream ClientsFile;
		ClientsFile.open("Clients.txt", ios::in);

		if (ClientsFile.is_open()) {

			string Line;
			while (getline(ClientsFile, Line)) {

				clsClient Client = _ConvertLineToUserObject(Line);
				if (Client.AccountNumber() == AccountNumber) {

					ClientsFile.close();
					return Client;
				}
				vClients.push_back(Client);
			}
			ClientsFile.close();
		}
		return _GetEmptyClientObject();
	}
	static clsClient Find(string AccountNumber, string PinCode) {

		vector <clsClient> vClients;

		fstream ClientsFile;
		ClientsFile.open("Clients.txt", ios::in);

		if (ClientsFile.is_open()) {

			string Line;
			while (getline(ClientsFile, Line)) {

				clsClient Client = _ConvertLineToUserObject(Line);
				if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode) {

					ClientsFile.close();
					return Client;
				}
				vClients.push_back(Client);
			}
			ClientsFile.close();
		}
		return _GetEmptyClientObject();
	}

	static bool IsClientExist(string AccountNumber) {

		clsClient Client = Find(AccountNumber);
		return (!Client.IsEmpty());
	}

	enum enSaveResults { svFailedEmptyObject = 0, svSucceded = 1, svFailAccountNumberExist = 3 };

	enSaveResults Save() {

		switch (_Mode)
		{
		case enMode::EmptyMode:

			return enSaveResults::svFailedEmptyObject;

			break;
		case enMode::UpdateMode:

			_Update();

			return enSaveResults::svSucceded;

			break;
		case enMode::AddNewMode:

			if (clsClient::IsClientExist(_AccountNumber)) {

				return enSaveResults::svFailAccountNumberExist;
			}
			else {

				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceded;
			}

			break;
		default:
			break;
		}
	}

	static clsClient GetAddNewClientObject(string AccountNumber) {

		return clsClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	bool Delete() {

		vector <clsClient> _vClients;
		_vClients = _LoadClientsDataFromFile();

		for (clsClient& C : _vClients) {

			if (C.AccountNumber() == _AccountNumber) {

				C._MarkForDelete = true;
				break;
			}
		}

		_SaveClientDataToFile(_vClients);
		*this = _GetEmptyClientObject();

		return true;
	}

	static vector <clsClient> GetClientsList() {

		return _LoadClientsDataFromFile();
	}

	static double GetTotalBalances() {

		vector <clsClient> vClients = _LoadClientsDataFromFile();
		double TotalBalance = 0;

		for (clsClient& Client : vClients) {

			TotalBalance += Client.AccountBalance;
		}

		return TotalBalance;
	}

	void Deposit(double Amount) {

		_AccountBalance += Amount;
		Save();
	}

	bool WithDraw(double Amount) {

		if (Amount > _AccountBalance) {

			return false;
		}
		else {

			_AccountBalance -= Amount;
			Save();
			return true;
		}
	}

	bool TransferCash(clsClient& DestinationAccount, double TransferAmount) {

		if (TransferAmount > _AccountBalance)
			return false;

		WithDraw(TransferAmount);
		DestinationAccount.Deposit(TransferAmount);

		_RegisterTransferLog(DestinationAccount, TransferAmount);

		return true;
	}

	static vector <stTransferLog> GetTransferLogs() {

		return _LoadTransferLogsFromFile();
	}


};

