#pragma once
#include "clsMainScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"


class clsCurrencyCalculatorScreen : protected clsMainScreen
{
private:
	static float _ConvertUsdToCurrency(clsCurrency& Currency, float Amount) {
		
		return Amount * Currency.CurrencyRate();
	}

	static float _ConvertCurrencyToUsd(clsCurrency& Currency, float Amount) {

		return Amount / Currency.CurrencyRate();
	}

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
	static void ShowCurrencyCalculatorScreen() {
		string Title = "Currency Calculator Screen";
		_ShowMainScreen(Title);

		string Currency1Code = clsInputValidate::ReadString("Please enter Currency1 code");

		clsCurrency Currency1 = clsCurrency::FindByCode(Currency1Code);

		while (Currency1.IsEmpty()) {
			Currency1Code = clsInputValidate::ReadString("Code is not true, please enter a valid code");
			Currency1 = clsCurrency::FindByCode(Currency1Code);
		}

		//////////////////////////////////

		string Currency2Code = clsInputValidate::ReadString("Please enter Currency2 code");

		clsCurrency Currency2 = clsCurrency::FindByCode(Currency2Code);

		while (Currency2.IsEmpty()) {
			Currency2Code = clsInputValidate::ReadString("Code is not true, please enter a valid code");
			Currency2 = clsCurrency::FindByCode(Currency1Code);
		}

		/////////////////////////////////

		float Amount = clsInputValidate::ReadFloatNumber("Please enter amount");


		if (Currency2.CurrencyCode() == "USD") {
			_PrintCurrencyCard(Currency1);
			cout << endl;
			cout << Amount << " " << Currency1.CurrencyCode() << " = " << _ConvertCurrencyToUsd(Currency1, Amount) <<" "<<Currency2.CurrencyCode();
			cout << endl;

		}
		else {
			_PrintCurrencyCard(Currency1);
			cout << endl;
			_PrintCurrencyCard(Currency2);
			cout << endl;
			cout << Amount << " " << Currency1.CurrencyCode() << " = " << _ConvertUsdToCurrency(Currency2, _ConvertCurrencyToUsd(Currency1, Amount)) << " " << Currency2.CurrencyCode();
			cout << endl;
		}

	}
};

