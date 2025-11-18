//#pragma once
//
//#include "clsScreen.h"
//#include "clsInputValidate.h"
//#include "clsCurrency.h"
//
//class clsUpdateCurrencyRate :protected clsScreen
//{
//private:
//
//	static void _PrintCurrency(clsCurrency Currency)
//	{
//		cout << "\nCurrency Card:\n";
//		cout << "_____________________________\n";
//		cout << "\nCountry    : " << Currency.Country();
//		cout << "\nCode       : " << Currency.CurrencyCode();
//		cout << "\nName       : " << Currency.CurrencyName();
//		cout << "\nRate(1$) = : " << Currency.Rate();
//
//		cout << "\n_____________________________\n";
//
//	}
//
//	static float _ReadNewRate()
//	{
//		float Rate = 0;
//		cout << "\n\nUpdate Currency Rate:";
//		cout << "\n_____________________";
//		cout << "\nEnter New Rate: ";
//
//		Rate = clsInputValidate::ReadFloatNumber();
//
//		return Rate;
//	}
//public:
//	static void ShowUpdateCurrencyRateScreen()
//	{
//
//		_DrawScreenHeader("\t Update Currency Screen ");
//
//		string CurrencyCode = "";
//
//		cout << "\Please Enter Currency Code: ";
//		CurrencyCode = clsInputValidate::ReadString();
//
//		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
//
//		if (Currency.IsEmpty())
//		{
//			cout << "\nCurrency Not Found :-(";
//			return;
//		}
//
//		_PrintCurrency(Currency);
//
//		char Answer = 'n';
//
//		cout << "\nAre you sure you want to update the rate of this currency y/n? ";
//		cin >> Answer;
//
//		if (Answer == 'y' || Answer == 'Y')
//		{
//			Currency.UpdateRate(_ReadNewRate());
//
//			cout << "\nCurrency Rate Updated Successfully :-)\n";
//
//			_PrintCurrency(Currency);
//		}
//	}
//};
//


#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsUpdateCurrencyRateScreen :protected clsScreen

{
private:

    static float _ReadRate()
    {
        cout << "\nEnter New Rate: ";
        float NewRate = 0;

        NewRate = clsInputValidate::ReadFloatNumber();
        return NewRate;
    }

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

public:

    static void ShowUpdateCurrencyRateScreen()
    {

        _DrawScreenHeader("\tUpdate Currency Screen");

        string CurrencyCode = "";

        cout << "\nPlease Enter Currency Code: ";
        CurrencyCode = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "\nCurrency is not found, choose another one: ";
            CurrencyCode = clsInputValidate::ReadString();
        }

        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        _PrintCurrency(Currency);

        cout << "\nAre you sure you want to update the rate of this Currency y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            cout << "\n\nUpdate Currency Rate:";
            cout << "\n____________________\n";

            Currency.UpdateRate(_ReadRate());

            cout << "\nCurrency Rate Updated Successfully :-)\n";
            _PrintCurrency(Currency);


        }

    }
};


