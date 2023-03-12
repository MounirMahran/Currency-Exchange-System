#include <iostream>
#include "clsCurrency.h"


using namespace std;


int main()
{
	cout << "Hello world" << endl;
	clsCurrency Currency = clsCurrency::FindByCountry("eGypt");
	cout << Currency.CountryName() << endl;
	cout << "Hello world" << endl;

}
