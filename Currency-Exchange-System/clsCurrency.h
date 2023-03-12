#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "clsString.h"
using namespace std;

class clsCurrency
{
private:
	enum enMode { enEmptyMode = 0, enUpdateMode = 1 };
	
	enMode _Mode;
	string _CountryName;
	string _CurrencyCode;
	string _CurrencyName;
	float _CurrencyRate;

	static clsCurrency _ConvertLineToCurrencyObject(string Line) {
		vector <string> vObject;

		vObject = clsString::Split(Line, "#//#");

		return clsCurrency(enMode::enUpdateMode, vObject[0], vObject[1], vObject[2], stoi(vObject[3]));

	}

	static string _ConvertCurrencyObjectToLine(clsCurrency Currency) {
		string Line = "";
		string Separator = "#//#";

		Line += Currency.CountryName();
		Line += Separator;
		Line += Currency.CurrencyCode();
		Line += Separator;
		Line += Currency.CurrencyName();
		Line += Separator;
		Line += to_string(Currency.CurrencyRate());

		return Line;
	}

	static clsCurrency _GetEmptyCurrencyObject() {
		return clsCurrency(enMode::enEmptyMode, "", "", "", 0);
	}

	static vector <clsCurrency> _LoadCurrenciesFromFile() {
		vector <clsCurrency> vCurrencies;
		fstream MyFile;

		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open()) {
			string Line = "";

			while (getline(MyFile, Line)) {
				vCurrencies.push_back(_ConvertLineToCurrencyObject(Line));
			}

			MyFile.close();
		}
		return vCurrencies;
	}

	void _SaveCurrenciesToFile(vector <clsCurrency> vCurrencies) {
		fstream MyFile;

		MyFile.open("Currencies.txt", ios::out);

		if (MyFile.is_open()) {

			for (clsCurrency Currency : vCurrencies) {
				MyFile << _ConvertCurrencyObjectToLine(Currency) << endl;
			}

			MyFile.close();
		}
	}

	void _Update() {
		vector <clsCurrency> vCurrencies = _LoadCurrenciesFromFile();

		for (clsCurrency& Currency : vCurrencies) {
			if (Currency.CurrencyCode() == CurrencyCode()) {
				Currency = *this;
				break;
			}
		}

		_SaveCurrenciesToFile(vCurrencies);
	}

public:
	clsCurrency(enMode Mode, string CountryName, string CurrencyCode, string CurrencyName, float CurrencyRate) {
		_Mode = Mode;
		_CountryName = CountryName;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_CurrencyRate = CurrencyRate;
		}

	string CountryName() {
		return _CountryName;
	}

	string CurrencyCode() {
		return _CurrencyCode;
	}

	string CurrencyName() {
		return _CurrencyName;
	}

	float CurrencyRate() {
		return _CurrencyRate;
	}

	void UpdateCurrencyRate(float NewRate) {
		_CurrencyRate = NewRate;
		_Update();
	}

	bool IsEmpty() {
		return _Mode == enMode::enEmptyMode;
	}

	static clsCurrency FindByCode(string CurrencyCode) {
		vector <clsCurrency> vCurrencies = _LoadCurrenciesFromFile();

		CurrencyCode = clsString::UpperAllString(CurrencyCode);

		for (clsCurrency Currency : vCurrencies) {
			if (Currency.CurrencyCode() == CurrencyCode) {
				return Currency;
			}
		}
		return _GetEmptyCurrencyObject();
	}

	static clsCurrency FindByCountry(string CountryName) {
		vector <clsCurrency> vCurrencies = _LoadCurrenciesFromFile();

		CountryName = clsString::LowerAllString(CountryName);
		CountryName = clsString::UpperFirstLetterOfEachWord(CountryName);

		for (clsCurrency Currency : vCurrencies) {
			if (Currency.CountryName() == CountryName) {
				return Currency;
			}
		}
		return _GetEmptyCurrencyObject();
	}








};

