

//PROGRAM FOR BANK MANAGEMENT SYSTEM
// Including libraries
#include<iostream>    // Standard Input Output library
#include<fstream>     // To write in data files
#include <cstdlib>    //  C standard library
#include<iomanip>     // to use parametric manipulators

using namespace std;

class account        // Defining a class

{
    // Defining  variables

private :

        int accountnumber;       // account number of user

        char name[50];           // name of user

        int deposit;             // Balance in account

        char type;               // account type

public:

       //Pre-Defining Function

        void create_account();      // to create account

        void show_account();        // Pops up details of a user

        void modify_account();      // modify details

        void deposit_funds(int);    //deposit money

        void draw_funds(int);       // withdraw money

        void get_report();          // access details

        int get_accountnumber();     //access account number

        int get_funds();             //access balance

        char get_accounttype();      //to access account type (savings or current)

        void bucks () ;             //to cout balance

};

void account :: bucks () {

cout << deposit ;


}



void account::create_account()

{

     do {

         cout<<"\nEnter The account Number (6-8 digits) : ";

        cin>>accountnumber;

        if (accountnumber<100000 || accountnumber >99999999) cout << "Invalid acc number !!" ;

        else break ;

        }while (accountnumber<100000 || accountnumber >99999999 ) ;    // to get 6-8 character long account number

        cout<<"\nEnter The Name of The account Holder : ";

        cin.ignore();

        cin.getline(name,50);                                         //to get name including blank space



   do{

        cout<<"\nEnter account type (enter s - saving or c - credit): ";

        cin>>type;

        type=toupper(type);                                     // uppercase input

        if(type=='C' ){

        do{

        cout<<"\nEnter The Initial amount 1000 or more for current : ";

        cin>>deposit;

        if (deposit<1000){

        cout << "invalid amount!" ;                            // shows invalid amount if entered amount is below minimum

        }else break ;

        }while(deposit<1000) ;

        cout << "Account created successfully ! " ; break ; }

        else if(type=='S' ) {

        do{

        cout<<"\nEnter The Initial amount 500 or more for current : ";

        cin>>deposit;

        if (deposit<500){

        cout << "invalid amount!" ;                            // shows invalid amount if entered amount is below minimum

        }else break ;

        }while(deposit<500) ;

        cout<<"\n\n\nAccount Created Successfully..."; break ;

        }else { cout << "invalid Type ! " ; }

        }while(type != 'S' || type != 'C') ;


}



void account::show_account()

{          // shows account details

        cout<<"\nAccount Number: "<<accountnumber;

        cout<<"\nAccount Holder Name: "<<name;

        cout<<"\nType of Account: "<<type;

        cout<<"\nBalance amount: "<<deposit;

}





void account::modify_account()

{       // To save modified details

        cout<<"\nAccount Number: "<<accountnumber;

        cout<<"\nModify Account Holder Name: ";

        cin.ignore();

        cin.getline(name,50);

        cout<<"\nModify Type of Account: ";

        cin>>type;

        type=toupper(type);

}





void account::deposit_funds(int x)      // deposit amount

{

        deposit+=x;

}



void account::draw_funds(int x)       //withdraw amount

{

        deposit-=x;

}



void account::get_report()         // access account details

{

        cout<<accountnumber<<setw(10)<<" "<<name<<setw(10)<<" "<<type<<setw(6)<<deposit<<endl;

}





int account::get_accountnumber()    // to access account number

{

        return accountnumber;

}



int account::get_funds()           //to access account balance

{

        return deposit;

}



char account::get_accounttype()     //gives account type

{

        return type;

}

// Defining function to work with data files

void write_account();

void display_sp(int);

void modify_account(int);

void delete_account(int);

void display_all();

void deposit_withdraw(int, int);



int main()

{

        char opt;

        int num;

       // for(;;)

       while(1) {

                system("color 20");             // changes color of terminal window

                system("cls");                  // Pops up a new interface




            cout << "            \n\n                    BANK MANAGEMENT SYSTEM           " <<endl;
                cout<<"\n\t\tPress 1 to Create New Account";

                cout<<"\n\t\tPress 2 to Deposit Funds";

                cout<<"\n\t\tPress 3 to Withdraw Funds";

                cout<<"\n\t\tPress 4 to Balance Enquiry ";

                cout<<"\n\t\tPress 5 to Modify an Account";

                cout<<"\n\t\tPress 6 to Close an Account";

                cout<<"\n\t\tPress 7 to Exit the Program";

// cout<<"\n\t\t@b@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";

                 cout<<"\n\n\t\tOption: ";

                cin>>opt;

                if(opt=='7'){

                        break ;

                }


                system("cls");

                switch(opt)

                {

                case '1':

                system("color 02");

                        write_account();

                        break;

                case '2':

                system("color 03");

                        cout<<"\n\n\tEnter The account No. : "; cin>>num;

                        deposit_withdraw(num, 1);

                        break;

                case '3':

                system("color 06");

                        cout<<"\n\n\tEnter The account No. : "; cin>>num;

                        deposit_withdraw(num, 2);

                        break;

                case '4':

                system("color 08");

                        cout<<"\n\n\tEnter The account No. : "; cin>>num;

                        display_sp(num);

                        break;

               /* case '5':

                system("color 9");

                        display_all();

                        break;*/

                case '6':

                system("color 10");

                        cout<<"\n\n\tEnter The account No. : "; cin>>num;

                        delete_account(num);

                        break;

                 case '5':

                 system("color 11");

                        cout<<"\n\n\tEnter The account No. : "; cin>>num;

                        modify_account(num);

                        break;

                 case '7':

                 system("color 04");

                        cout<<"\n\n\tThanks for using Bank Management System";

                        break;

                 default :cout<<"Invalid Option\n";

                }

                cin.ignore();

                cin.get();


        }

        return 0;

}







void write_account()

{

        account ac;

        ofstream outFile;

        outFile.open("MyAccount.dat",ios::binary|ios::app);

        ac.create_account();

        outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));

        outFile.close();

}





void display_sp(int n)

{

        account ac;

        bool flag=false;

        ifstream inFile;

        inFile.open("MyAccount.dat",ios::binary);

        if(!inFile)

        {

                cout<<"File could not be open !! Press any Key...";

                return;

        }

        cout<<"\nBALANCE DETAILS\n";



        while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))

        {

                if(ac.get_accountnumber()==n)

                {

                        ac.show_account();

                        flag=true;

                }

        }

        inFile.close();

        if(flag==false)

                cout<<"\n\nAccount number does not exist";

}



void modify_account(int n)

{

        bool found=false;

        account ac;

        fstream File;

        File.open("MyAccount.dat",ios::binary|ios::in|ios::out);

        if(!File)

        {

                cout<<"File could not be open !! Press any Key...";

                return;

        }

        while(!File.eof() && found==false)

        {

                File.read(reinterpret_cast<char *> (&ac), sizeof(account));

                if(ac.get_accountnumber()==n)

                {

                        ac.show_account();

                        cout<<"\n\nEnter The New Details of account: "<<endl;

                        ac.modify_account();

                        int pos=(-1)*static_cast<int>(sizeof(account));

                        File.seekp(pos,ios::cur);

                        File.write(reinterpret_cast<char *> (&ac), sizeof(account));

                        cout<<"\n\n\t Record Updated...";

                        found=true;

                  }

        }

        File.close();

        if(found==false)

                cout<<"\n\n Record Not Found ";

}



void delete_account(int n)

{

        account ac;

        ifstream inFile;

        ofstream outFile;

        inFile.open("MyAccount.dat",ios::binary);

        if(!inFile)

        {

                cout<<"File could not be open !! Press any Key...";

                return;

        }

        outFile.open("Temp.dat",ios::binary);

        inFile.seekg(0,ios::beg);

        while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))

        {

                if(ac.get_accountnumber()!=n)

                {

                        outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));

                }

        }

        inFile.close();

        outFile.close();

        remove("MyAccount.dat");

        rename("Temp.dat","account.dat");

        cout<<"\n\n\tRecord Deleted...";

}





void display_all()

{

        account ac;

        ifstream inFile;

        inFile.open("MyAccount.dat",ios::binary);

        if(!inFile)

        {

                cout<<"File could not be open !! Press any Key...";

                return;

        }

        cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";

        cout<<"====================================================\n";

        cout<<"Account No.      Name           Type Balance\n";

        cout<<"====================================================\n";

        while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))

        {

                ac.get_report();

        }

        inFile.close();

}



void deposit_withdraw(int n, int option)

{

        int amt;

        bool found=false;

        account ac;

        fstream File;

        File.open("MyAccount.dat", ios::binary|ios::in|ios::out);

        if(!File)

        {

                cout<<"File could not be open !! Press any Key...";

                return;

        }

        while(!File.eof() && found==false)

        {

                File.read(reinterpret_cast<char *> (&ac), sizeof(account));

                if(ac.get_accountnumber()==n)

                {

                        ac.show_account();

                        if(option==1)

                        {

                                cout<<"\n\n\tTO DEPOSIT AMOUNT ";

                             do{   cout<<"\n\nEnter The amount to be deposited: ";

                                cin>>amt;


                                if(amt < 0){

                                    cout << "Invalid amount !\n\n " ;

                                }

                             }while(amt <0) ;

                                ac.deposit_funds(amt) ;

                                cout<<"\n\n\t Record Updated\n\n";

                                cout << " your current balance is : " ;

                                ac.bucks() ;

                           }

                        if(option==2)

                        {

                                cout<<"\n\n\tTO WITHDRAW AMOUNT ";

                            do{

                                cout<<"\n\nEnter The amount to be withdraw: ";

                                cin>>amt;

                                if (amt < 0){

                                    cout << "invalid amount ! " ;

                                }

                            }

                                while(amt < 0) ;


                                int bal=ac.get_funds()-amt;

                                if((bal<500 && ac.get_accounttype()=='S') || (bal<1000 && ac.get_accounttype()=='C'))

                                        cout<<"Insufficient balance! \n there must be a minimum balance of \nrupees 500 for saving \n \tand \n1000 for current !";

                                else {

                                        ac.draw_funds(amt) ;

                                        cout<<"\n\n\t Record Updated! \n\n";

                                        cout << " your remaining balance is : " ;

                                        ac.bucks() ;



                                         }


                        }

                        int pos=(-1)*static_cast<int>(sizeof(ac));

                        File.seekp(pos,ios::cur);

                        File.write(reinterpret_cast<char *> (&ac), sizeof(account));

                       // cout<<"\n\n\t Record Updated";

                        found=true;

               }

         }

        File.close();

        if(found==false)

                cout<<"\n\n Record Not Found  ";

}

