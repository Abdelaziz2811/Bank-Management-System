#pragma once

#include <iostream>
#include <string>
#include "InterfaceCommunication.h"

using namespace std;

class clsPerson : public InterfaceCommunication {

private:
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;

public:
	clsPerson(string FirstName, string LastName, string Email, string Phone) {

		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_Phone = Phone;
	}

	void SetFirstName(string FirstName) {

		_FirstName = FirstName;
	}
	string GetFirstName() {

		return _FirstName;
	}
	__declspec(property(get = GetFirstName, put = SetFirstName))string FirstName;


	void SetLastName(string LastName) {

		_LastName = LastName;
	}
	string GetLastName() {

		return _LastName;
	}
	__declspec(property(get = GetLastName, put = SetLastName))string LastName;

	void SetEmail(string Email) {

		_Email = Email;
	}
	string GetEmail() {

		return _Email;
	}
	__declspec(property(get = GetEmail, put = SetEmail))string Email;

	void SetPhone(string Phone) {

		_Phone = Phone;
	}
	string GetPhone() {

		return _Phone;
	}
	__declspec(property(get = GetPhone, put = SetPhone))string Phone;

	string FullName() {

		return _FirstName + " " + _LastName;
	}

	void SendEmail(string Title, string Body) {

		//send emil will be here
	}

	void SendFax(string Title, string Body) {

		//send fax will be here
	}

	void SendSMS(string Title, string Body) {

		//send sms will be here
	}

};

