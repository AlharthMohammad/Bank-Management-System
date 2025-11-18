//#pragma once
//
//#include"clsScreen.h"
//#include"clsInputValidate.h"
//#include"clsBankClient.h"
//
//class clsTransferScreen :protected clsScreen
//{
//private:
//
//	static void _PrintCLientCard(clsBankClient Client)
//	{
//		cout << "\n\nClient Card";
//		cout << "\n____________________________\n";
//		cout << "\nFull Name   : " << Client.FullName();
//		cout << "\nAcc. Number : " << Client.AccountNumber();
//		cout << "\nBalance     : " << Client.AccountBalance;
//		cout << "\n____________________________\n\n";
//	}
//
//public:
//	static void ShowTransferScreen()
//	{
//		string AccountNumber;
//
//		cout << "\nPlease Enter Account Number to Transfer From: ";
//		AccountNumber = clsInputValidate::ReadString();
//
//		clsBankClient SenderClient = clsBankClient::Find(AccountNumber);
//
//		while (SenderClient.IsEmpty())
//		{
//			cout << "\nAccount Number does Not Exist, Enter Another One: ";
//			AccountNumber = clsInputValidate::ReadString();
//			SenderClient = clsBankClient::Find(AccountNumber);
//		}
//
//		_PrintCLientCard(SenderClient);
//
//		cout << "\nPlease Enter Account Number to Transfer To: ";
//		AccountNumber = clsInputValidate::ReadString();
//
//		clsBankClient ReciverClient = clsBankClient::Find(AccountNumber);
//
//		while (ReciverClient.IsEmpty())
//		{
//			cout << "\nAccount Number does Not Exist, Enter Another One: ";
//			AccountNumber = clsInputValidate::ReadString();
//			ReciverClient = clsBankClient::Find(AccountNumber);
//		}
//
//		_PrintCLientCard(ReciverClient);
//
//		float Amount = 0;
//
//		cout << "\nEnter Transfer Amount? ";
//		Amount = clsInputValidate::ReadFloatNumber();
//
//		while (Amount > SenderClient.AccountBalance)
//		{
//			cout << "\nAmount Exceeds the available Balance, Enter another Amount? ";
//			Amount = clsInputValidate::ReadFloatNumber();
//		}
//
//		char Answer = 'n';
//
//		cout << "\nAre you sure you want to perform this operation? y/n? ";
//		cin >> Answer;
//
//		if (Answer == 'y' || Answer == 'Y')
//		{
//			cout << "\nTransfer done successfuly\n";
//
//			SenderClient.AccountBalance -= Amount;
//			SenderClient.Save();
//			_PrintCLientCard(SenderClient);
//
//			ReciverClient.AccountBalance += Amount;
//			ReciverClient.Save();
//			_PrintCLientCard(ReciverClient);
//		}
//	}
//};
//


#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsTransferScreen :protected clsScreen
{

private:
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________\n";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

    static string _ReadAccountNumber()
    {
        string AccountNumber;
        cout << "\nPlease Enter Account Number to Transfer From: ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        return AccountNumber;
    }

    static float ReadAmount(clsBankClient SourceClient)
    {
        float Amount;

        cout << "\nEnter Transfer Amount? ";

        Amount = clsInputValidate::ReadFloatNumber();

        while (Amount > SourceClient.AccountBalance)
        {
            cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
            Amount = clsInputValidate::ReadDblNumber();
        }
        return Amount;
    }

public:

    static void ShowTransferScreen()
    {

        _DrawScreenHeader("\tTransfer Screen");

        clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());

        _PrintClient(SourceClient);

        clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());

        _PrintClient(DestinationClient);

        float Amount = ReadAmount(SourceClient);


        cout << "\nAre you sure you want to perform this operation? y/n? ";
        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            if (SourceClient.Transfer(Amount, DestinationClient, CurrentUser.UserName))
            {
                cout << "\nTransfer done successfully\n";
            }
            else
            {
                cout << "\nTransfer Faild \n";
            }
        }

        _PrintClient(SourceClient);
        _PrintClient(DestinationClient);


    }

};



//class clsTransferScreen :protected clsScreen
//{
//private:
//
//	static string _ReadAccountNumber(string Message)
//	{
//		string AccountNumbr = "";
//
//		cout << endl << Message;
//		AccountNumbr = clsInputValidate::ReadString();
//
//		while (clsBankClient::Find(AccountNumbr).IsEmpty())
//		{
//			cout << "\nAccount Number not found, Enter another one : ";
//			AccountNumbr = clsInputValidate::ReadString();
//		}
//
//		return AccountNumbr;
//	}
//
//	static float _ReadAmount(clsBankClient SourseClinet)
//	{
//		float Amount = 0;
//
//		cout << "\nEnter Amount : ";
//		Amount = clsInputValidate::ReadFloatNumber();
//
//		while (Amount > SourseClinet.AccountBalance)
//		{
//			cout << "\nAmount exced the avalibal balance, Enter a new balance : ";
//			Amount = clsInputValidate::ReadFloatNumber();
//		}
//
//		return Amount;
//	}
//
//public:
//	static void ShowTransferScreen()
//	{
//		_DrawScreenHeader("\t Transfer Screen");
//
//		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber("Enter Account Number To Transfer From : "));
//
//		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber("Enter Account Numbrer to Transfer To : "));
//
//		float Amount = _ReadAmount(SourceClient);
//
//		SourceClient.Transfer(Amount, DestinationClient);
//
//
//
//	}
//};
