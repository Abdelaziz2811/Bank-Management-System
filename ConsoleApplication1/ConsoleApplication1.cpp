#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "clsLoginScreen.h"

using namespace std;

int main() {

	while (true) {

		if (!clsLoginScreen::LoginScreen()) {

			cout << "\n\t\t\t\t\tYour are locked! try another time.\n";
			break;
		}
		
	}

	return 0;
}

