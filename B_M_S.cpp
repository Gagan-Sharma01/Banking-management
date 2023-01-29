#include<bits/stdc++.h>
using namespace std;
class Bank_Account
{
	
	int Money_Deposit;
	char type;
	int acno;
	char name[70];
public:
	
	void report() const;
	int retMoney_Deposit() const;
	void create_Bank_Account();
	void dep(int);
	int retacno() const;
	void Display_Account() const;
	void Updation();
	char rettype() const;
	void draw(int);
};


void Bank_Account::Updation()
{
	cout<<"\n\tBank_Account No. : "<<acno;
	cout<<"\n\tUpdation Bank_Account Holder Name : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n\tUpdation Type of Bank_Account : ";
	cin>>type;
	type=toupper(type);
	cout<<"\n\tUpdation Balance Total-Money : ";
	cin>>Money_Deposit;
}
void Bank_Account::create_Bank_Account()
{
	system("CLS");
	cout<<"\n\tPlease Enter the Bank_Account No. : ";
	cin>>acno;
	cout<<"\n\n\tPlease Enter the Name of the Bank_Account holder : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n\tPlease Enter Type of the Bank_Account (C/S) : ";
	cin>>type;
	type=toupper(type);
	cout<<"\n\tPlease Enter The Starting Total-Money : ";
	cin>>Money_Deposit;
	cout<<"\n\n\tBank_Account Created..";
}

void Bank_Account::Display_Account() const
{
	cout<<"\n\tBank_Account No. : "<<acno;
	cout<<"\n\tBank_Account Holder Name : ";
	cout<<name;
	cout<<"\n\tType of Bank_Account : "<<type;
	cout<<"\n\tBalance Total-Money : "<<Money_Deposit;
}
int Bank_Account::retacno() const
{
	return acno;
}



char Bank_Account::rettype() const
{
	return type;
}
void Bank_Account::report() const
{
	cout<<acno<<setw(10)<<" "<<name<<setw(10)<<" "<<type<<setw(6)<<Money_Deposit<<endl;
}
void Bank_Account::dep(int x)
{
	Money_Deposit+=x;
}
void Bank_Account::draw(int x)
{
	Money_Deposit-=x;
}
int Bank_Account::retMoney_Deposit() const
{
	return Money_Deposit;
}


void write_Bank_Account();
void display_sp(int);
void display_all();

void delete_Bank_Account(int);
void Money_Deposit_withdraw(int, int);
void Updation_Bank_Account(int);
int main()
{
	char ch;
	int num;
	do
	{
	system("CLS");
	cout<<"\n\n\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
	
	cout<<"\t\tBANK MANAGEMENT SYSTEM";
	cout<<"\n\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!";

		cout<<"\t\t    ::MAIN MENU::\n";
		cout<<"\n\t\t1. NEW Bank_Account";
		cout<<"\n\t\t2. Money_Deposit Total-Money";
		cout<<"\n\t\t3. WITHDRAW Total-Money";
		cout<<"\n\t\t4. BALANCE ENQUIRY";
		cout<<"\n\t\t5. ALL Bank_Account HOLDER LIST";
		cout<<"\n\t\t6. CLOSE AN Bank_Account";
		cout<<"\n\t\t7. Updation AN Bank_Account";
		cout<<"\n\t\t8. EXIT";
		cout<<"\n\n\t\tSelect Your Option (1-8): ";
		cin>>ch;

		switch(ch)
		{
		case '1':
			write_Bank_Account();
			break;
		case '2':
			system("CLS");
			cout<<"\n\n\tPlease Enter The Bank_Account No. : "; cin>>num;
			Money_Deposit_withdraw(num, 1);
			break;
		case '3':
			system("CLS");
			cout<<"\n\n\tPlease Enter The Bank_Account No. : "; cin>>num;
			Money_Deposit_withdraw(num, 2);
			break;
		case '4':
			system("CLS");
			cout<<"\n\n\tPlease Enter The Bank_Account No. : "; cin>>num;
			display_sp(num);
			break;
		case '5':
			display_all();
			break;
		case '6':
			system("CLS");
			cout<<"\n\n\tPlease Enter The Bank_Account No. : "; cin>>num;
			delete_Bank_Account(num);
			break;
		 case '7':
		 	system("CLS");
			cout<<"\n\n\tPlease Enter The Bank_Account No. : "; cin>>num;
			Updation_Bank_Account(num);
			break;
		 case '8':
		 	system("CLS");
			cout<<"\n\n\tBrought To You By code-projects.org";
			break;
		 default :cout<<"\a";
		}
		cin.ignore();
		cin.get();
    }while(ch!='8');
	return 0;
}





void write_Bank_Account()
{
	Bank_Account ac;
	ofstream outFile;
	outFile.open("Bank_Account.dat",ios::binary|ios::app);
	ac.create_Bank_Account();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(Bank_Account));
	outFile.close();
}
void delete_Bank_Account(int n)
{
	Bank_Account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("Bank_Account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Bank_Account)))
	{
		if(ac.retacno()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(Bank_Account));
		}
	}
    inFile.close();
	outFile.close();
	remove("Bank_Account.dat");
	rename("Temp.dat","Bank_Account.dat");
	cout<<"\n\nRecord Deleted ..";
}

void display_sp(int n)
{
	Bank_Account ac;
	bool flag=false;
	ifstream inFile;
	inFile.open("Bank_Account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\tBALANCE DETAILS\n";
    	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Bank_Account)))
	{
		if(ac.retacno()==n)
		{
			ac.Display_Account();
			flag=true;
		}
	}
    inFile.close();
	if(flag==false)
		cout<<"\n\n\tBank_Account number does not exist";
}


void display_all()
{
	system("CLS");
	Bank_Account ac;
	ifstream inFile;
	inFile.open("Bank_Account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\tBank_Account HOLDER LIST\n\n";
	cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!========\n";
	cout<<"A/c no.      NAME           Type  Balance\n";
	cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!========\n";
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Bank_Account)))
	{
		ac.report();
	}
	inFile.close();
}
void Updation_Bank_Account(int n)
{
	bool found=false;
	Bank_Account ac;
	fstream File;
    File.open("Bank_Account.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(Bank_Account));
		if(ac.retacno()==n)
		{
			ac.Display_Account();
			cout<<"\n\n\tPlease Enter The New Details of Bank_Account"<<endl;
			ac.Updation();
			int pos=(-1)*static_cast<int>(sizeof(Bank_Account));
			File.seekp(pos,ios::cur); //fncallat1353
		    File.write(reinterpret_cast<char *> (&ac), sizeof(Bank_Account));
		    cout<<"\n\n\tRecord Updated";
		    found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n\tRecord Not Found ";
}

void Money_Deposit_withdraw(int n, int option)
{
	int amt;
	bool found=false;
	Bank_Account ac;
	fstream File;
    File.open("Bank_Account.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(Bank_Account));
		if(ac.retacno()==n)
		{
			ac.Display_Account();
			if(option==1)
			{
				cout<<"\n\n\tTO Money_DepositSS Total-Money";
				cout<<"\n\n\tPlease Enter The Total-Money to be Money_Deposited: ";
				cin>>amt;
				ac.dep(amt);
			}
		    if(option==2)
			{
				cout<<"\n\n\tTO WITHDRAW Total-Money";
				cout<<"\n\n\tPlease Enter The Total-Money to be withdraw: ";
				cin>>amt;
				int bal=ac.retMoney_Deposit()-amt;
				if(bal<0)
					cout<<"Insufficience balance";
				else
					ac.draw(amt);
		      }
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);//fn1353
			File.write(reinterpret_cast<char *> (&ac), sizeof(Bank_Account));
			cout<<"\n\n\tRecord Updated";
			found=true;
	       }
         }
    File.close();
	if(found==false)
		cout<<"\n\n\tRecord Not Found ";
}
 

Output

Bank Management System in c++
Download Bank Management System in C++
 

BANK MANAGEMENT SYSTEM USING C++ – Project 2
//HEADER FILE USED IN PROJECT
#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
using namespace std;

// CLASS USED IN PROJECT

class account
{
	int Account_No;
	char Account_Holder_Name[44];
	char type;
	int Deposit_Amount;
public:
	void Open_account();	//function to get data from user
	void Display_account() const;	//function to show data on screen
	void Update();	//function to add new data
	void dep(int);	//function to accept amount and add to balance amount
	void Withdraw(int);	//function to accept amount and subtract from balance amount
	void report() const;	//function to show data in tabular format
	int Return_Account_Number() const;	//function to return account number
	int Return_Deposit_Amount() const;	//function to return balance amount
	char Return_type() const;	//function to return type of account
};         //class ends here


void account::Display_account() const
{
	cout<<"\nAccount No. : "<<Account_No;
	cout<<"\nAccount Holder Name : ";
	cout<<Account_Holder_Name;
	cout<<"\nType of Account : "<<type;
	cout<<"\nBalance amount : "<<Deposit_Amount;
}
void account::Open_account()
{
	cout<<"\nPlease! Enter The account No. :";
	cin>>Account_No;
	cout<<"\nPlease! Enter The Name of The account Holder : ";
	cin.ignore();
	cin.getline(Account_Holder_Name,44);
	cout<<"\nPlease! Enter Type of The account (C/S) : ";
	cin>>type;
	type=toupper(type);
	cout<<"\nPlease! Enter The Initial amount(>=440 for Saving and >=1000 for current ) : ";
	cin>>Deposit_Amount;
	cout<<"\n\nAccount Created..";
}



	
void account::dep(int x)
{
	Deposit_Amount+=x;
}
	
void account::Withdraw(int x)
{
	Deposit_Amount-=x;
}
	
void account::report() const
{
	cout<<Account_No<<setw(10)<<" "<<Account_Holder_Name<<setw(10)<<" "<<type<<setw(6)<<Deposit_Amount<<endl;
}

void account::Update()
{
	cout<<"\nAccount No. : "<<Account_No;
	cout<<"\nUpdate Account Holder Name : ";
	cin.ignore();
	cin.getline(Account_Holder_Name,44);
	cout<<"\nUpdate Type of Account : ";
	cin>>type;
	type=toupper(type);
	cout<<"\nUpdate Balance amount : ";
	cin>>Deposit_Amount;
}
	
int account::Return_Account_Number() const
{
	return Account_No;
}


char account::Return_type() const
{
	return type;
}
int account::Return_Deposit_Amount() const
{
	return Deposit_Amount;
}

//function declaration

void delete_account(int);	//function to delete record of file
void display_all();		//function to display all account details
void write_account();	//function to write record in binary file
void display_sp(int);	//function to display account details given by user
void Deposit_Amount_withWithdraw(int, int); // function to desposit/withWithdraw amount for given account
void intro();	//introductory screen function
void Update_account(int);	//function to Update record of file
//THE MAIN FUNCTION OF PROGRAM

int main()
{
	char ch;
	int num;
	intro();
	do
	{
		system("cls");
		cout<<"\n\n\t\tMAIN MENU";
		cout<<"\n\t\t01. NEW ACCOUNT";
		cout<<"\n\t\t02. Deposit_Amount AMOUNT";
		cout<<"\n\t\t03. WITHWithdraw AMOUNT";
		cout<<"\n\t\t04. BALANCE ENQUIRY";
		cout<<"\n\t\t05. ALL ACCOUNT HOLDER LIST";
		cout<<"\n\t\t06. CLOSE AN ACCOUNT";
		cout<<"\n\t\t07. Update AN ACCOUNT";
		cout<<"\n\t\t08. EXIT";
		cout<<"\n\t\tSelect Your Option (1-8) ";
		cin>>ch;
		system("cls");
		switch(ch)
		{
		case '1':
			write_account();
			break;
		case '2':
			cout<<"\n\t\tPlease! Enter The account No. : "; cin>>num;
			Deposit_Amount_withWithdraw(num, 1);
			break;
		case '3':
			cout<<"\n\t\tPlease! Enter The account No. : "; cin>>num;
			Deposit_Amount_withWithdraw(num, 2);
			break;
		case '4': 
			cout<<"\n\t\tPlease! Enter The account No. : "; cin>>num;
			display_sp(num);
			break;
		case '5':
			display_all();
			break;
		case '6':
			cout<<"\n\t\tPlease! Enter The account No. : "; cin>>num;
			delete_account(num);
			break;
		 case '7':
			cout<<"\n\t\tPlease! Enter The account No. : "; cin>>num;
			Update_account(num);
			break;
		 case '8':
			cout<<"\n\t\tThanks for using bank managemnt system";
			break;
		 default :cout<<"\a";
		}
		cin.ignore();
		cin.get();
	}while(ch!='8');
	return 0;
}
//function to write in file

void write_account()
{
	account ac;
	ofstream outFile;
	outFile.open("account.dat",ios::binary|ios::app);
	ac.Open_account();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
	outFile.close();
}

//function to read specific record from file

void display_sp(int n)
{
	account ac;
	bool flag=false;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\nBALANCE DETAILS\n";

    	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.Return_Account_Number()==n)
		{
			ac.Display_account();
			flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\nAccount number does not exist";
}


//function to Update record of file

void Update_account(int n)
{
	bool found=false;
	account ac;
	fstream File;
	File.open("account.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.Return_Account_Number()==n)
		{
			ac.Display_account();
			cout<<"\nPlease! Enter The New Details of account"<<endl;
			ac.Update();
			int pos=(-1)*static_cast<int>(sizeof(account));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\t\t Record Updated";
			found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n Record Not Found ";
}

//function to delete record of file

void delete_account(int n)
{
	account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.Return_Account_Number()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
		}
	}
	inFile.close();
	outFile.close();
	remove("account.dat");
	rename("Temp.dat","account.dat");
	cout<<"\n\t\tRecord Deleted ..";
}

//function to display all accounts Deposit_Amount list

void display_all()
{
	account ac;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\t\t\t\tACCOUNT HOLDER LIST\n";
	cout<<"*************************\n";
	cout<<"A/c no.      NAME           Type  Balance\n";
	cout<<"*************************\n";
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		ac.report();
	}
	inFile.close();
}

//  	function to Deposit_Amount and withWithdraw amounts


void Deposit_Amount_withWithdraw(int n, int option)
{
	int Amount;
	bool found=false;
	account ac;
	fstream File;
	File.open("account.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.Return_Account_Number()==n)
		{
			ac.Display_account();
			if(option==1)
			{
				cout<<"\n\t\tTO Deposit_AmountE AMOUNT ";
				cout<<"\nPlease! Enter The amount to be Deposit_Amounted";
				cin>>Amount;
				ac.dep(Amount);
			}
			if(option==2)
			{
				cout<<"\n\t\tTO WITHWithdraw AMOUNT ";
				cout<<"\nPlease! Enter The amount to be withWithdraw";
				cin>>Amount;
				int bal=ac.Return_Deposit_Amount()-Amount;
				if((bal<440 && ac.Return_type()=='S') || (bal<1000 && ac.Return_type()=='C'))
					cout<<"Insufficience balance";
				else
					ac.Withdraw(Amount);
			}
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\t\t Record Updated";
			found=true;
	       }
         }
	File.close();
	if(found==false)
		cout<<"\n Record Not Found ";
}


//INTRODUCTION FUNCTION

void intro()
{
	cout<<"\n\n\t\t  BANK";
	cout<<"\n\t\tMANAGEMENT";
	cout<<"\n\t\t  SYSTEM";
	cout<<"\n\nMADE BY : your name";
	cout<<"\nSCHOOL : your school name";
	cin.get();
}