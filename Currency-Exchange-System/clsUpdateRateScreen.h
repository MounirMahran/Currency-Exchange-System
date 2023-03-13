#pragma once
#include "clsMainScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"
class clsUpdateRateScreen : protected clsMainScreen
{
private:
	static void _PrintCurrencyCard(clsCurrency Currency) {
		cout << "\n__________________________\n";
		cout << "\nCountry Name    : " << Currency.CountryName();
		cout << "\nCurrecny Code   : " << Currency.CurrencyCode();
		cout << "\nCurrency Name   : " << Currency.CurrencyName();
		cout << "\nCurrency Rate   : " << Currency.CurrencyRate();
		cout << "\n__________________________\n";
		cout << endl;
	}
public: 
	static void ShowUpdateRateScreen() {
		string Title = "Update Rate Screen";
		_ShowMainScreen(Title);

		string Code = clsInputValidate::ReadString("Please enter currency code");

		clsCurrency Currency = clsCurrency::FindByCode(Code);

		if (Currency.IsEmpty()) return;

		else {
			_PrintCurrencyCard(Currency);

			char Update = clsInputValidate::ReadCharacter("Are you sure you want to update it? Y/N");

			if (toupper(Update) == 'Y'){
				float NewRate = clsInputValidate::ReadFloatNumber("Please enter the new rate");
				Currency.UpdateCurrencyRate(NewRate);
				_PrintCurrencyCard(Currency);
			}

		}

	}
};

