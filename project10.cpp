#include <bits/stdc++.h> 
using namespace std;
#include "ClsString.h"
#include "ClsDate.h"
#include "ClsUtil.h"
#include "ClsInputValidate.h"
#include "clsBankClient.h"
#include"clsCLIENT.h"
void ReadClientData(clsBankClient & Client)
{
    cout << "\nEnter FirstName: ";
  //  Client.;

    cout << "\nEnter LastName: ";
    Client .LastName= ClsInputValidate::ReadString();

    cout << "\nEnter Email: ";
    Client.Email = ClsInputValidate::ReadString();

    cout << "\nEnter Phone: ";
    Client.Phone = ClsInputValidate::ReadString();

    cout << "\nEnter PinCode: ";
    Client.PinCode = ClsInputValidate::ReadString();

    cout << "\nEnter AccountBalance: ";
    Client.AccountBalance = float_t (ClsInputValidate::ReadDblNumber());
}
void UpdateClient() {
    string Accountnum = "";
    cout << "\nPlease Enter client Account Number: ";
    Accountnum =  ClsInputValidate::ReadString();
    while (!clsBankClient::IsClientExist(Accountnum))
    {
        cout << "\nAccount number is not found, choose another one: ";
        Accountnum  = ClsInputValidate::ReadString();

    }
    clsBankClient client1 = clsBankClient::Find(Accountnum);
    client1.Print();
    cout << "\n\nUpdate Client Info:";
    cout << "\n____________________\n";
    ReadClientData(client1);
    clsBankClient::enSave SaveResult;
    SaveResult = client1.save();
    switch (SaveResult)
    {
    case clsBankClient::svEmptyObject :
        cout << "\nError account was not saved because it's Empty";
        break;
    case clsBankClient::saveSuccessed :
        cout << "\nAccount Updated Successfully :-)\n";
        client1.Print();
        break;
    default:
        break;
    }
}
int main()
{
   UpdateClient();



	/*clsCLIENT client = clsCLIENT::find("A109","1234");
	client.Print();
	clsCLIENT client2 = clsCLIENT::find("A104", "1234");
	client2.Print();*/
	//clsBankClient client1 = clsBankClient::Find("A109" , "1234");
//cout<< clsBankClient::IsClientExist("A101");

	//client1.Print();
}
