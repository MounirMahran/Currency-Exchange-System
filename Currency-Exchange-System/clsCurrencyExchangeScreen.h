#pragma once
#include "clsMainScreen.h"
#include "clsInputValidate.h"
#include "clsListCurrencies.h"
#include "clsFindCurrencyScreen.h"

class clsCurrencyExchangeScreen : protected clsMainScreen
{
private:
	enum enCurrenciesMenuOptions{ListCurrencies = 1, FindCurrency = 2, UpdateRate = 3, CurrCalc = 4};

	static short _ReadUserInput() {
		cout << "\t\t\t\tPlease Choose what to do [1] -> [4]   ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 4);
		return Choice;
	}

	static void _ListCurrenciesScreen() {
		system("cls");
		//cout << "List Currencies code will be here" << endl;
		clsListCurrencies::ShowCurrenciesList();
	}

	static void _FindCurrencyScreen() {
		system("cls");
		//cout << "Find Currency code will be here" << endl;
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _UpdateRateScreen() {
		system("cls");
		cout << "Update rate code will be here" << endl;
	}

	static void _CurrecnyCalculatorScreen() {
		system("cls");
		cout << "Currency calculator will be here" << endl;
	}

	static void _PerformCurrenciesMenuOptions(enCurrenciesMenuOptions Choice) {
		switch (Choice)
		{
		case clsCurrencyExchangeScreen::ListCurrencies:
			_ListCurrenciesScreen();
			system("pause");
			ShowCurrencyExchangeScreen();
			break;
		case clsCurrencyExchangeScreen::FindCurrency:
			_FindCurrencyScreen();
			system("pause");
			ShowCurrencyExchangeScreen();
			break;
		case clsCurrencyExchangeScreen::UpdateRate:
			_UpdateRateScreen();
			system("pause");
			ShowCurrencyExchangeScreen();
			break;
		case clsCurrencyExchangeScreen::CurrCalc:
			_CurrecnyCalculatorScreen();
			system("pause");
			ShowCurrencyExchangeScreen();
			break;
		}
	}

public:
	static void ShowCurrencyExchangeScreen() {
		system("cls");
		string Title = "Currency Exchange Screen";
		_ShowMainScreen(Title);
		cout << "\t\t\t   ==========================================\n";
		cout << "\t\t\t\t    Currency Exchange Menu\n";
		cout << "\t\t\t   ==========================================\n";
		cout << "\t\t\t\t[1] List Currencies \n";
		cout << "\t\t\t\t[2] Find Currency    \n";
		cout << "\t\t\t\t[3] Update Rate     \n";
		cout << "\t\t\t\t[4] Currency Calculator\n";
		cout << "\t\t\t   ==========================================\n";
		cout << endl;
		_PerformCurrenciesMenuOptions((enCurrenciesMenuOptions)_ReadUserInput());
	}
};

