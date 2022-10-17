#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

//Function Declaration

void addContact();
void searchContact();
void help();
void self_exit();
bool check_number(string);
bool check_digits(string);

//Global Variable Declaration
string fname; //Stores the first name
string lname; //Stores the last name
string phone_number; //Stores a 10 digit number

int main(){
  int choice;
  system("cls");
  system("color 02");
  cout << "\n\n\n\t\t\t\t\t\tContact Management System..";
  cout << "\n\n\t1. Add Contact\n\t2. Search Contact\n\t3. Help\n\t4. Exit\n\n\t> ";
  cin >> choice;

  switch(choice){
  case(1):
    addContact();
    break;
  case(2):
    searchContact();
    break;
  case(3):
    help();
    break;
  case(4):
    self_exit();
    break;
  default:
    cout<<"\n\n\tInvalid Input !!";
    cout<<"\n\tPress any key to continue...";
    getch();
    main();
  }

  return 0;
}

void self_exit()
{
    system("cls");
    cout<<"\n\tThank You For Using Our System...\n\n";
    exit(1);
}

void help()
{
    cout<<"\n\tPlease enter digits from 1 to 4";
    cout<<"\n\tPress any key to go back to the menu..";
    getch();
    main();
}

void addContact()
{
    ofstream phone("number.txt",ios::app); //Opening the file in append mode
    system("cls");
    cout << "\n\tEnter the first name: ";
    cin >> fname;
    cout << "\n\tEnter the last name: ";
    cin >> lname;
    cout << "\n\tEnter the phone number: ";
    cin >> phone_number;

    if(check_number(phone_number)==true){
        if(check_digits(phone_number)==true){
           if(phone.is_open()){
                phone << fname << " " << lname << " " << phone_number << endl;
                cout << "\n\tContact Saved Successfully..\n\t";
           }
           else{
                cout << "\n\tError Opening File..\n\t";
           }
        }
        else{
           cout << "\n\tA Phone Number Has To Be Digits..\n\t";
        }
    }
    else{
        cout << "\n\tA Phone Number Must Be of 10 Digits..\n\t";
    }

    phone.close();

}

void searchContact()
{
    bool found = false;
    ifstream myfile("number.txt");
    string keyword;
    cout << "\n\tEnter the name to search: ";
    cin >> keyword;
    while(myfile >> fname >> lname >> phone_number){
        if(keyword == fname || keyword == lname){
            system("cls");
            cout << "\n\tContact Details..";
            cout << "\n\n\tFirst Name : " << fname;
            cout << "\n\tLast Name : " << lname;
            cout << "\n\tPhone Number : " << phone_number;
            found = true;
            break;
        }
    }
    if(found == false){
        cout << "\n\tContact Not Found..";
        cout << "\n\tEnter Any Key To Go Back..";
        getch();
        main();
    }
}

bool check_number(string ph)
{
    if(ph.length()==10) return true;
    else return false;
}

bool check_digits(string ph)
{
    bool check = true;
    for(int i=0;i<ph.length();i++){
        if(!(int(ph[i])>=48 && int(ph[i])<=57)){
            check = false;
            break;
        }
    }
    return check;
}
