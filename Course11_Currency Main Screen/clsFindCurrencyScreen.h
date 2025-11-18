//#pragma once
//
//#include"clsScreen.h"
//#include"clsInputValidate.h"
//#include "clsCurrency.h"
//
//class clsFindCurrencyScreen :protected clsScreen
//{
//private:
//	enum enOption { eFindByCode = 1, eFindByCountry = 2 };
//	static short _ReadOption()
//	{
//		cout << "\nFind By: [1] Code or [2] Country ? ";
//
//		short Option = clsInputValidate::ReadShortNumberBetween(1, 2, "Enter Number Between 1 to 2 ? ");
//		return Option;
//	}
//
//	static clsCurrency _FindByCode()
//	{
//		string CurrencyCode = "";
//		cout << "\nPlease Enter Currency Code: ";
//		CurrencyCode = clsInputValidate::ReadString();
//		return clsCurrency::FindByCode(CurrencyCode);
//	}
//
//	static clsCurrency _FindByCountry()
//	{
//		string CountryName = "";
//		cout << "\nPlease Enter Currency Code: ";
//		CountryName = clsInputValidate::ReadString();
//		return clsCurrency::FindByCountry(CountryName);
//	}
//
//	static void _PrintCurrencyRecordCard(clsCurrency Currency)
//	{
//		cout << "\nCurrency Card:";
//		cout << "\n____________________________________\n";
//		cout << "\nCountry    : " << Currency.Country();
//		cout << "\nCode<<     : " << Currency.CurrencyCode();
//		cout << "\nName       : " << Currency.CurrencyName();
//		cout << "\nRate(1$) = : " << Currency.Rate();
//		cout << "\n____________________________________\n";
//	}
//
//public:
//	static void ShowFindCurrencyScreen()
//	{
//		_DrawScreenHeader("\t  Find Currency Screen");
//
//		enOption Option = (enOption)_ReadOption();
//
//		clsCurrency Currency = (Option == enOption::eFindByCode ? _FindByCode() : _FindByCountry());
//
//		if (Currency.IsEmpty())
//		{
//			cout << "\nCurrency Not Found :-(\n";
//		}
//		else
//		{
//			cout << "\nCurrency Found :-)\n";
//			_PrintCurrencyRecordCard(Currency);
//		}
//	}
//};
//


#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsFindCurrencyScreen :protected clsScreen
{

private:
    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();

        cout << "\n_____________________________\n";

    }

    static void _ShowResults(clsCurrency Currency)
    {
        if (!Currency.IsEmpty())
        {
            cout << "\nCurrency Found :-)\n";
            _PrintCurrency(Currency);
        }
        else
        {
            cout << "\nCurrency Was not Found :-(\n";
        }
    }

public:

    static void ShowFindCurrencyScreen()
    {

        _DrawScreenHeader("\t  Find Currency Screen");

        cout << "\nFind By: [1] Code or [2] Country ? ";
        short Answer = 1;

        cin >> Answer;

        if (Answer == 1)
        {
            string CurrencyCode;
            cout << "\nPlease Enter CurrencyCode: ";
            CurrencyCode = clsInputValidate::ReadString();
            clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
            _ShowResults(Currency);
        }
        else
        {
            string Country;
            cout << "\nPlease Enter Country Name: ";
            Country = clsInputValidate::ReadString();
            clsCurrency Currency = clsCurrency::FindByCountry(Country);
            _ShowResults(Currency);
        }






    }

};


