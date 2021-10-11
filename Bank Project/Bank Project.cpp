#include<iostream>
#include <windows.h>
#include <string>
using namespace std;
int k = 0;
struct inf
{
	int ac_num;
	string ac_name;
	char type;
	long long amount;
};

void setConsoleColor(WORD c)          //I searched for it on google
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void timer(int sec)                  // //I searched for it on google
{
	Sleep(sec * 1000);
}
void heart()                           //I searched for it on google
{
	int s = 1;
	char c = 3;
	while (s <= 1)
	{
		cout << c;
		s++;
	}
}
bool stupid(inf f[10000])
{
	bool ex = false;                                // to make sure no one can enter this function unless he had an account
	for (size_t i = 0; i < 10000; i++)
	{
		if ((f[i].type == 'c' || f[i].type == 's') && f[i].ac_name != "0") // the () was the problem
		{
			ex = true;
			break;
		}
	}
	if (ex == false)
		return false;
	else
		return true;


}
int check_numberExistence(inf f[10000], int num)
{
	int i, value;
	bool flag = false;
	for (i = 0; i < 10000; i++)
	{
		//cout << "1";
		if (num == f[i].ac_num) //i hope the problem with 0 will End  // if flag=true means user enter an exist num 
		{
			flag = true;
			value = i;
			break;
		}

	}
	while (flag == false)
	{
		setConsoleColor(5);
		cout << "This Account Number is not Exist ! , Enter another one : ";
		setConsoleColor(7);
		cin >> num;
		for (i = 0; i < 10000; i++)
		{
			if (num == f[i].ac_num)
			{
				flag = true;
				value = i;
				break;
			}

		}
	}

	return value;

}
int check_type(inf f[10000], char t)
{
	while (t != 's' && t != 'c' && t != 'S' && t != 'C')
	{
		setConsoleColor(5);
		cout << "Please Enter C or S ";
		setConsoleColor(7);
		cin >> t;
	}
	return t;
}
int check_amount(inf f[10000], char t, int am)
{

	if (t == 's')
	{
		while (am < 500)
		{
			setConsoleColor(5);
			cout << "Intial amount for saving must be at leat 500 pound ,Enter amount : " << endl;
			setConsoleColor(7);
			cin >> am;
		}
	}
	else if (t == 'c')
	{
		while (am < 1000)
		{
			setConsoleColor(5);
			cout << "Intial amount for current must be at leat 1000 pound ,Enter amount : " << endl;
			setConsoleColor(7);
			cin >> am;
		}
	}
	return am;
}
void create_new(inf f[10000])//1
{
	int num, final = 0;
	bool check = false, check0 = false;
	cout << "Enter The Account No. : ";
	cin >> num;
	for (size_t i = 0; i < 10000; i++)
	{
		if (num == f[i].ac_num && f[i].ac_name != "0")   // if bool check still = false then this num is accepted and it will not enter while loop // i have a problem with the second condition of if :((((((((((((
		{
			check = true;
			//cout << "WTf";
			break;
		}
	}
	//if (check == false)
	while (check)         // if bool check=true thats mean this No. is already used so while will cin value and then test it 
	{
		check = false;
		setConsoleColor(5);
		cout << "This Ac No. is already used , try another one : ";
		setConsoleColor(7);
		cin >> num;
		for (size_t i = 0; i < 10000; i++)
		{
			if (num == f[i].ac_num)
			{
				check = true;
				break;
			}
		}
		if (check == false)
		{
			break;
		}
	}

	for (size_t i = 0; i < 10000; i++) // this 'for loop' to check if there is an empty place (result from close an account) before using k so if check0=true that's mean there is an empty place
	{
		if (f[i].ac_num == 0 && f[i].ac_name == "0")       // gg the problem was that i forget to put 2 '=' :(
		{
			check0 = true;
			final = i;
			break;
		}
	}
	if (check0) // check0=true means there is an empty place 
	{
		cout << endl << endl;
		f[final].ac_num = num;
		cin.ignore();
		cout << "Enter Name : ";
		getline(cin, f[final].ac_name);
		cout << endl;
		cout << "Enter Type : ";
		cin >> f[final].type;
		f[final].type = check_type(f, f[final].type);
		cout << endl;
		cout << "Enter Amount : ";
		cin >> f[final].amount;
		f[final].amount = check_amount(f, f[final].type, f[final].amount);
		cout << endl << endl;
		setConsoleColor(3);
		cout << "Account Created... " << endl;
		setConsoleColor(7);
		/*cout << "K = " << k;  */     // i made it to check No. of struct 
	}
	else //check0=false means there is no empty place so you slould depend on k value
	{
		cout << endl << endl;
		f[k].ac_num = num;
		cin.ignore();
		cout << "Enter Name : ";
		getline(cin, f[k].ac_name);
		cout << endl;
		cout << "Enter Type : ";
		cin >> f[k].type;
		f[k].type = check_type(f, f[k].type);
		cout << endl;
		cout << "Enter Amount : ";
		cin >> f[k].amount;
		f[k].amount = check_amount(f, f[k].type, f[k].amount);
		cout << endl << endl;
		setConsoleColor(3);
		cout << "Account Created... " << endl;
		k++;
		setConsoleColor(7);
		/*	cout << "K = " << k; */     // i made it to check No. of struct 
	}
	timer(1);
}
void DEPOSIT_AMOUNT(inf f[10000])//2
{
	if (stupid(f) == false)                            // to make sure no one can enter this function unless he had an account 
	{
		cout << "      Create an Account First before coming Here ! " << endl;
		//create_new(f);
	}
	else
	{
		int account_number, amountTOD;
		cout << "          Enter The account No. :";
		cin >> account_number;
		cout << endl;
		int z = check_numberExistence(f, account_number); //number of struct that we knew already from looping in check_numberExistance function
		cout << "Account No. : ";
		cout << f[z].ac_num;
		cout << endl;
		cout << "Account Holder Name : ";
		cout << f[z].ac_name;
		cout << endl;
		cout << "Type of Account : ";
		cout << f[z].type;
		cout << endl;
		cout << "Balance amount : ";
		cout << f[z].amount << endl << endl;
		cout << "          To DEPOSITE AMOUNT" << endl;
		cout << "Enter The amout to be deposited : ";
		cin >> amountTOD;
		while (amountTOD <= 0)
		{
			setConsoleColor(5);
			cout << "What Are You Doing ! , Enter Poitive Amout To Be DEPOSITE : ";
			setConsoleColor(7);
			cin >> amountTOD;
			cout << endl;
		}
		f[z].amount = f[z].amount + amountTOD;
		setConsoleColor(3);
		cout << "          Record Updated... " << endl;
		setConsoleColor(7);
	}
	timer(1);
}
void WITHDRAW_AMOUNT(inf f[10000])//3
{
	if (stupid(f) == false)
	{
		cout << "      Create an Account First before coming Here ! " << endl;
		//create_new(f);
	}
	else
	{
		int account_number, amountW, to, choice;
		cout << "Enterthe Account No. : ";
		cin >> account_number;
		int z = check_numberExistence(f, account_number);
		cout << "Enter amount to withdraw : ";
		cin >> amountW;
		while (amountW > f[z].amount || amountW <= 0)                                    // to check that noone take money more than he had :)
		{
			if (amountW > f[z].amount)
				cout << "       You Haven't Enough Money, Poor! , Enter Amount To Be WITHDRAW : ";
			else
				cout << "       Enter Positive value ! :";
			cin >> amountW;
			cout << endl;
		}
		setConsoleColor(1);
		cout << "Press 1 To WITHDRAW " << endl;
		cout << "Press 2 To Send It" << endl;
		setConsoleColor(7);
		cout << "Your choice is : ";
		cin >> choice;
		while (choice != 1 && choice != 2)
		{
			setConsoleColor(5);
			cout << "Please Enter 1 or 2 ! : ";
			setConsoleColor(7);
			cin >> choice;

		}

		if (choice == 1)
		{
			f[z].amount = f[z].amount - amountW;
		}
		else
		{
			cout << "Enter the Account you want to send to : ";
			cin >> to;
			if (f[z].ac_num == to)
			{
				setConsoleColor(5);
				cout << "Really! Are you kidding me!" << endl << endl;
				setConsoleColor(7);

			}
			to = check_numberExistence(f, to);
			f[z].amount = f[z].amount - amountW;
			f[to].amount = f[to].amount + amountW;
		}
		setConsoleColor(3);
		cout << "          Record Updated... " << endl;
		setConsoleColor(7);
	}
	timer(1);
}
void BALANCE_ENQUIRY(inf f[10000])//4            i still have a problem here with 0 so i have to add a condition to Check_numberExistence including f[i].ac_name
{
	if (stupid(f) == false)
	{
		cout << "      Create an Account First before coming Here ! " << endl;
		//create_new(f);
	}
	else
	{
		int account_number;
		cout << "          Enter The Account No. : ";
		cin >> account_number;
		int z = check_numberExistence(f, account_number);

		cout << "BALANCE DETAILS" << endl << endl;
		cout << "Account No. : ";
		cout << f[z].ac_num;
		cout << endl;
		cout << "Account Holder Name : ";
		cout << f[z].ac_name;
		cout << endl;
		cout << "Type of Account : ";
		cout << f[z].type;
		cout << endl;
		cout << "Balance amount : ";
		cout << f[z].amount;
		cout << endl;
	}
	timer(2);
}                                               //use return to make it easy use this fun in another fun 
void ACCOUNT_HOLDER(inf f[10000])//5
{
	// i remove if  condition from here 

	//int min = show[0];
	//for (size_t i = 0; i < sizeof(show); i++)
	//{
	//	for (size_t j = 0; j < sizeof(show) - 1; j++) // or use k value instead of sizeof
	//	{
	//		if (show[j] > show[j + 1])
	//			swap(show[j], show[j + 1]);
	//	}
	//}
	//for (size_t i = 0; i < 10000; i++)
	//{
	//	for (size_t j = 0; j < sizeof(show); j++)
	//	{
	//		if (show[i] == f[j].ac_num)
	//		{
	//			cout << "A/c No.       NAME              Type       Balance      " << endl;
	//			cout << f[i].ac_num << "             " << f[i].ac_name << "                 " << f[i].type << "          " << f[i].amount << endl;
	//			break;
	//		}
	//	}
	//}
	//cout << endl << endl << endl;

	cout << "                    ACCOUNT HOLDER LIST    " << endl << endl;
	cout << "===========================================================" << endl;
	cout << "A/c No.       NAME              Type       Balance      " << endl;
	cout << "===========================================================" << endl;
	for (size_t i = 0; i < 10000; i++)
	{
		if ((f[i].type == 's' || f[i].type == 'c') && f[i].ac_name != "0")
			cout << f[i].ac_num << "             " << f[i].ac_name << "                 " << f[i].type << "          " << f[i].amount << endl;
	}
	cout << endl;
	timer(2);
}
void CLOSE_ACCOUNT(inf f[10000])//6
{
	if (stupid(f) == false)
	{
		cout << "      Create an Account First before coming Here ! " << endl << endl;
		//create_new(f);
	}
	else
	{
		int account_num;
		cout << "Enter the account No. : ";
		cin >> account_num;
		cout << endl << endl;
		int z = check_numberExistence(f, account_num);
		f[z].ac_num = 0;
		f[z].ac_name = "0";
		setConsoleColor(3);
		cout << "Record Deleted .. ";
		setConsoleColor(7);
		cout << endl;
	}
	timer(1);
}
void MODIFY_ACCOUNT(inf f[100000])//7              //or using cancel struct then create new 
{

	if (stupid(f) == false)                 // to make sure noone can Enter this function unless he had an Account
	{
		cout << "      Create an Account First before coming Here ! " << endl;
		create_new(f);
	}
	else
	{
		int account_num;
		bool check = false, check0 = false;
		cout << "Enter The Account No. :";
		cin >> account_num;
		int z = check_numberExistence(f, account_num); // z represent i value which tell us the Number of struct 
		cout << "Acc No. :";
		cout << f[z].ac_num << endl;
		cout << "Name : ";
		cout << f[z].ac_name << endl;
		cout << "type : ";
		cout << f[z].type << endl;
		cout << "amount : ";
		cout << f[z].amount << endl;
		//////////////////////////////
		cout << "Modify Account No. : ";
		cin >> account_num;           ///god help me plz
		for (size_t i = 0; i < 10000; i++)
		{
			if (account_num == f[i].ac_num)   // if bool check still = false then this num is accepted and it will not enter while loop
			{

				check = true;
				break;

			}
		}
		if (account_num == f[z].ac_num)  // i made this cause if someone Enter the same Acc No. it must be correct not Error 
			check = false;
		while (check)         // if bool check=true thats mean this No. is already used so while will cin value and then test it 
		{
			check = false;
			cout << "This Ac No. is already used , try another one : ";
			cin >> account_num;
			for (size_t i = 0; i < 10000; i++)
			{
				if (account_num == f[i].ac_num)
				{
					check = true;
					break;
				}
				if (account_num == f[z].ac_num)    // i made this cause if someone Enter Acc No. that is exist and then Enter the same Acc No. it must be correct not Error 
				{
					check = false;
					break;
				}
			}
			if (check == false)
			{
				break;
			}
		}
		f[z].ac_num = account_num;
		cin.ignore();
		cout << "Modify Account Holder Name : ";
		getline(cin, f[z].ac_name);
		cout << "Modify Type of Account : ";
		cin >> f[z].type;
		f[z].type = check_type(f, f[z].type);
		cout << "Modify Balance amount : ";
		cin >> f[z].amount;
		f[z].amount = check_amount(f, f[z].type, f[z].amount);
		setConsoleColor(3);
		cout << "     Record Updated";
		setConsoleColor(7);
	}
	timer(1);
}
void main()
{
	struct inf f[10000];
	int choice;

	do
	{
		system("cls");
		cout << "          MAIN MENU" << endl << endl;
		cout << "          01. NEW ACCOUNT" << endl;
		cout << endl;
		cout << "          02. DEPOSIT AMOUNT" << endl;
		cout << endl;
		cout << "          03. WITHDRAW AMOUNT" << endl;
		cout << endl;
		cout << "          04. BALANCE ENQUIRY" << endl;
		cout << endl;
		cout << "          05. ALL ACCOUNT HOLDER LIST" << endl;
		cout << endl;
		cout << "          06. CLOSE AN ACCOUNT" << endl;
		cout << endl;
		cout << "          07. MODIFY AN ACCOUNT" << endl;
		cout << endl;
		cout << "          08. EXIT" << endl;
		cout << endl << endl;
		cout << "          Selecet Your Option (1-8) : ";
		cin >> choice;
		system("cls");

		if (choice == 1)
		{
			create_new(f);
			cout << endl;
		}
		else if (choice == 2)
		{
			DEPOSIT_AMOUNT(f);
			cout << endl;
		}
		else if (choice == 3)
		{
			WITHDRAW_AMOUNT(f);
			cout << endl;

		}
		else if (choice == 4)
		{
			BALANCE_ENQUIRY(f);
			cout << endl;

		}
		else if (choice == 5)
		{
			ACCOUNT_HOLDER(f);
			cout << endl;

		}
		else if (choice == 6)
		{
			CLOSE_ACCOUNT(f);
			cout << endl;

		}
		else if (choice == 7)
		{

			MODIFY_ACCOUNT(f);
			cout << endl;

		}
		else if (choice == 8)
		{
			cout << "Thanks For Dealing With Us ";
			setConsoleColor(FOREGROUND_RED);
			heart();
			cout << endl << endl << endl;
			setConsoleColor(7);
			timer(3);
		}
		else
		{
			setConsoleColor(4);
			cout << "Try another choice between (1-8) !" << endl << endl;
			setConsoleColor(7);
		}
	} while (true);
}