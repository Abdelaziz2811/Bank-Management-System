#pragma once

#include <iostream>
#include "clsUser.h"
#include "clsDate.h"
#include "Global.h"

using namespace std;

class clsScreen {

protected:
	static void _DrawScreenHeader(string Title, string SubTitle = "") {

		cout << "\t\t\t\t\t_______________________________\n";
		cout << "\n\t\t\t\t\t\t  " << Title << endl;
		if (SubTitle != "") {

			cout << "\n\t\t\t\t\t   " << SubTitle << endl;
		}
		cout << "\t\t\t\t\t_______________________________\n";

		if (CurrentUser.UserName != "") {

			cout << "\n\t\t\t\t\tUser : " << CurrentUser.UserName;
		}
		cout << "\n\t\t\t\t\tDate : " << clsDate::DateToString(clsDate::GetSystemDate()) << "\n" << endl;
	}

	static bool CheckAccessRights(clsUser::enPermissions Permission) {

		if (!CurrentUser.CheckAccessPermission(Permission)) {

			cout << "\t\t\t\t\t_________________________________________\n\n";
			cout << "\t\t\t\t\t    Access Denied! Contact Your Admin\n";
			cout << "\t\t\t\t\t_________________________________________\n";
			return false;
		}
		else {

			return true;
		}
	}
};

