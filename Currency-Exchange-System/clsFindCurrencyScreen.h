#pragma once
#include "clsMainScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"

class clsFindCurrencyScreen : protected clsMainScreen
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

	static void _SearchByCode() {
		string Code = clsInputValidate::ReadString("Please enter currency code");

		clsCurrency Currency = clsCurrency::FindByCode(Code);

		if (Currency.IsEmpty()) cout << "Currency Not Found :-(" << endl;
		else {
			cout << "Currency Found :-)" << endl;
			_PrintCurrencyCard(Currency);
		}
		
	}

	static void _SearchByCountry() {
		string Country = clsInputValidate::ReadString("Please enter country name");

		clsCurrency Currency = clsCurrency::FindByCountry(Country);

		if (Currency.IsEmpty()) cout << "Currency Not Found :-(" << endl;
		else {
			cout << "Currency Found :-)" << endl;
			_PrintCurrencyCard(Currency);
		}

	}
public:
	static void ShowFindCurrencyScreen() {
		string Title = "Find Currency Screen";
		_ShowMainScreen(Title);

		cout << "Find by: [1] Code [2] Country" << endl;
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 2);

		switch (Choice)
		{
		case 1:
			_SearchByCode();
			break;

		case 2:
			_SearchByCountry();
			break;
		}
	}
};

