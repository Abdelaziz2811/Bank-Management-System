#pragma once

#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include "clsDate.h"
#include "clsUtil.h"

using namespace std;

class clsUser : public clsPerson {

private:
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;
	bool _MarkForDelete = false;

	string _UserName;
	string _Password;
	int _Permissions;

	static clsUser _ConvertLineToUserObject(string Line, string Seperator = "#//#") {

		vector <string> vUserData;
		vUserData = clsString::Split(Line, Seperator);

		return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2], vUserData[3]
			, vUserData[4], clsUtil::DecryptText(vUserData[5], 5), stoi(vUserData[6]));
	}

	static clsUser _GetEmptyUserObject() {

		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static vector <clsUser> _LoadUsersDataFromFile() {

		vector <clsUser> vUsers;
		fstream UsersFile;

		UsersFile.open("Users.txt", ios::in);

		if (UsersFile.is_open()) {

			string Line;
			while (getline(UsersFile, Line)) {

				clsUser User = _ConvertLineToUserObject(Line);
				vUsers.push_back(User);
			}
			UsersFile.close();
		}
		return vUsers;
	}

	static string _ConvertUserObjectToLine(clsUser User, string Seperator = "#//#") {

		string DataLine;

		DataLine += User.UserName + Seperator;
		DataLine += User.FirstName + Seperator;
		DataLine += User.LastName + Seperator;
		DataLine += User.Email + Seperator;
		DataLine += User.Phone + Seperator;
		DataLine += clsUtil::EncryptText(User.Password, 5) + Seperator;
		DataLine += to_string(User.Permissions);

		return DataLine;
	}

	static void _SaveUserDataToFile(vector <clsUser> vUsers) {

		fstream UsersFile;
		UsersFile.open("Users.txt", ios::out);

		if (UsersFile.is_open()) {

			string DataLine;
			for (clsUser& User : vUsers) {

				if (User._MarkForDelete == false) {

					DataLine = _ConvertUserObjectToLine(User);
					UsersFile << DataLine << endl;
				}
			}

			UsersFile.close();
		}
	}

	void _Update() {

		vector <clsUser> _vClients;
		_vClients = _LoadUsersDataFromFile();

		for (clsUser& C : _vClients) {

			if (C.UserName == UserName) {

				C = *this;
				break;
			}
		}
		_SaveUserDataToFile(_vClients);
	}

	void _AddDataLineToFile(string DataLine) {

		fstream ClientsFile;
		ClientsFile.open("Users.txt", ios::out | ios::app);

		if (ClientsFile.is_open()) {

			ClientsFile << DataLine << endl;

			ClientsFile.close();
		}
	}

	void _AddNew() {

		_AddDataLineToFile(_ConvertUserObjectToLine(*this));
	}

	string _PrepareLoginRecord(string Seperator = "#//#") {

		string DataLine;
		string Date = clsDate::GetSystemDateString();

		DataLine += Date + Seperator;
		DataLine += _UserName + Seperator;
		DataLine += clsUtil::EncryptText(_Password, 5) + Seperator;
		DataLine += to_string(_Permissions);

		return DataLine;
	}

	struct stLoginRegisterRecord;

	static stLoginRegisterRecord _ConvertLoginLineToRecod(string LoginLine, string Seperator = "#//#") {

		vector <string> vLoginDataLine = clsString::Split(LoginLine, Seperator);

		stLoginRegisterRecord LoginRecord;

		LoginRecord.Date = vLoginDataLine[0];
		LoginRecord.UserName = vLoginDataLine[1];
		LoginRecord.Password = clsUtil::DecryptText(vLoginDataLine[2], 5);
		LoginRecord.Permissions = stoi(vLoginDataLine[3]);

		return LoginRecord;
	}

	static vector <stLoginRegisterRecord> _LoadLoginRecordsFromFile() {

		vector <stLoginRegisterRecord> vLoginRecords;
		fstream LogRecordsFile;

		LogRecordsFile.open("LoginRecords.txt", ios::in);

		if (LogRecordsFile.is_open()) {

			string Line;
			while (getline(LogRecordsFile, Line)) {

				stLoginRegisterRecord LoginRecord = _ConvertLoginLineToRecod(Line);
				vLoginRecords.push_back(LoginRecord);
			}
			LogRecordsFile.close();
		}
		return vLoginRecords;
	}

public:
	clsUser(enMode Mode, string UserName, string FirstName, string LastName, string Email, string Phone
		, string Password, int Permissions)
		: clsPerson(FirstName, LastName, Email, Phone) {

		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
	}

	enum enPermissions {
		pAll = -1, pClientsList = 1, pAddNewClient = 2, pDeleteClient = 4, pUpdateClient = 8
		, pFindClient = 16, pShowTransactionsMenu = 32, pManageUsers = 64, pShowLoginRegister = 128
	};

	struct stLoginRegisterRecord {

		string Date;
		string UserName;
		string Password;
		int Permissions;
	};

	void SetUserName(string UserName) {

		_UserName = UserName;
	}
	string GetUserName() {

		return _UserName;
	}

	__declspec(property(get = GetUserName, put = SetUserName))string UserName;

	void SetPassword(string Password) {

		_Password = Password;
	}
	string GetPassword() {

		return _Password;
	}

	__declspec(property(get = GetPassword, put = SetPassword))string Password;

	void SetPermissions(int Permissions) {

		_Permissions = Permissions;
	}
	int GetPermissions() {

		return _Permissions;
	}

	__declspec(property(get = GetPermissions, put = SetPermissions))int Permissions;

	bool IsEmpty() {

		return _Mode == enMode::EmptyMode;
	}

	bool MarkedForDeleted() {

		return _MarkForDelete;
	}

	static clsUser Find(string UserName) {

		vector <clsUser> vUsers;

		fstream UserFile;
		UserFile.open("Users.txt", ios::in);

		if (UserFile.is_open()) {

			string Line;
			while (getline(UserFile, Line)) {

				clsUser User = _ConvertLineToUserObject(Line);
				if (User.UserName == UserName) {

					UserFile.close();
					return User;
				}
				vUsers.push_back(User);
			}
			UserFile.close();
		}
		return _GetEmptyUserObject();
	}
	static clsUser Find(string UserName, string Password) {

		vector <clsUser> vUsers;

		fstream UserFile;
		UserFile.open("Users.txt", ios::in);

		if (UserFile.is_open()) {

			string Line;
			while (getline(UserFile, Line)) {

				clsUser User = _ConvertLineToUserObject(Line);
				if (User.UserName == UserName && User.Password == Password) {

					UserFile.close();
					return User;
				}
				vUsers.push_back(User);
			}
			UserFile.close();
		}
		return _GetEmptyUserObject();
	}

	static bool IsUserExist(string UserName) {

		clsUser User = Find(UserName);
		return (!User.IsEmpty());
	}

	enum enSaveResults { svFailedEmptyObject = 0, svSucceded = 1, svFailUserNameExist = 3 };

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

			if (clsUser::IsUserExist(_UserName)) {

				return enSaveResults::svFailUserNameExist;
			}
			else {

				_AddNew();
				//after user added successfuly we need to set the new mode.
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceded;
			}

			break;
		default:
			break;
		}
	}

	static clsUser GetAddNewUserObject(string UserName) {

		return clsUser(enMode::AddNewMode, UserName, "", "", "", "", "", 0);
	}

	bool Delete() {

		vector <clsUser> _vUsers;
		_vUsers = _LoadUsersDataFromFile();

		for (clsUser& User : _vUsers) {

			if (User.UserName == _UserName) {

				User._MarkForDelete = true;
				break;
			}
		}

		_SaveUserDataToFile(_vUsers);
		*this = _GetEmptyUserObject();

		return true;
	}

	static vector <clsUser> GetUsersList() {

		return _LoadUsersDataFromFile();
	}

	bool CheckAccessPermission(enPermissions Permission) {

		if (this->Permissions == enPermissions::pAll) {

			return true;
		}

		if ((Permission & this->Permissions) == Permission) {

			return true;
		}
		else {

			return false;
		}
	}

	void RegisterLogRecordToFile() {

		fstream LogRecordsFile;
		string LoginRecord = _PrepareLoginRecord();

		LogRecordsFile.open("LoginRecords.txt", ios::out | ios::app);

		if (LogRecordsFile.is_open()) {

			LogRecordsFile << LoginRecord << endl;

			LogRecordsFile.close();
		}
	}

	static vector <stLoginRegisterRecord> GetLoginRecords() {

		return _LoadLoginRecordsFromFile();
	}

};
