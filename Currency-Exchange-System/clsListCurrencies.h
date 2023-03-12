#pragma once
#include "clsMainScreen.h"
#include "clsCurrency.h"

class clsListCurrencies : protected clsMainScreen
{
private:

	static void _PrintOneCurrency(clsCurrency Currency) {
		cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.CountryName();
		cout << "| " << setw(8) << left << Currency.CurrencyCode();
		cout << "| " << setw(45) << left << Currency.CurrencyName();
		cout << "| " << setw(10) << left << Currency.CurrencyRate();
		cout << endl;
	}

	static void _PrintCurrencies(vector <clsCurrency> vCurrencies) {
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
		cout << "| " << left << setw(8) << "Code";
		cout << "| " << left << setw(45) << "Name";
		cout << "| " << left << setw(10) << "Rate/(1$)";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;

		for (clsCurrency& Currency : vCurrencies) _PrintOneCurrency(Currency);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;
	}


public:
	static void ShowCurrenciesList() {
		string Title = "List Currencies Screen";
		_ShowMainScreen(Title);
		_PrintCurrencies(clsCurrency::_LoadCurrenciesFromFile());
	}
};

