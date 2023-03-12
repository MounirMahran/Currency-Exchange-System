#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class clsMainScreen
{
protected:
	
	static void _ShowMainScreen(string Title) {
		system("cls");
		cout  << "\t\t\t\t_________________________________\n\n";
		cout <<"\t\t\t           " << Title << "\n";
		cout  << "\t\t\t\t_________________________________\n\n";


	}
};

