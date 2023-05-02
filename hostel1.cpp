#include <iostream>
#include <fstream>
#include<vector>
#include<string>
#include <sstream>
#include<windows.h>
#include<conio.h>
#include <ctime>
#include <cstdlib>
using namespace std;

//Inheritance
//Hostel has admin
//Hotel has hostellites

class Person {
//data members
    protected:
    string auth_email, auth_password, email, password;
    string name, phone_no, cnic, city;
    int room_no;
    public:	
    int count_success=0, count_fail=0,count_password=0; 
//member functions

//Register/SignUp function
    void SignUp (fstream& file_1){
    cout << "\n\t\tSign Up!";
    cout << "\n\t\tEnter the following to register: " << endl;

    cout << "\n\t\tEnter Your Email: ";
    cin >> email;
    file_1 << email << ",";

    cout << "\n\t\tEnter Password: ";
    cin >> password;
    file_1 << password << ",";

    cout << "Account Creation in progress, Please wait..";
    for (int i=0; i<3; i++){
    cout << '.';
    Sleep(1000);
    }
    system("CLS");
    cout << "Congratulation! Your account has been created.\n\n";
    //file_1.close();
    }

//Login/Sign In function

void Signin(fstream& file_2) {

//create a string vector
vector<string> row;
string line, word;

//take sign In data
cout << "\n\t\tSign In!\n" ;
cout << "\n\t\tEnter Your Email: ";
cin >> email;
cout << "\n\t\tEnter Your Password: ";
cin >> password;

//untill the file has something in it
while(file_2.good()) {
row.clear();
getline(file_2, line);
stringstream s(line);
while (getline(s, word, ',')) {
    row.push_back(word);
}
auth_email = row[0];
auth_password = row[1];
if ( email==auth_email && password==auth_password){
    count_success+=1;
}
else if (email==auth_email && password!=auth_password){
    count_password+=1;
}
else {
    count_fail+=1;
}

}
file_2.close();
}	

};


class Admin : public Person{
public:

void show_admin_data(){
    ifstream my_file;
    my_file.open("hostellites.csv", ios::in);
    int i=0;

    while(my_file.good()) {
    i++;
    string line;
    getline(my_file, line, '\n');
    cout << i << ". " << line << "\n";
    }
    my_file.close();
}


void search_data(fstream& file_2) {

//create a string vector
string auth_cnic, cnic;

vector<string> row;
string line, word;

//take sign In data
cout << "\n\t\tSearch data!\n" ;
cout << "\n\t\tEnter CNIC: ";
cin >> cnic;

//untill the file has something in it
while(file_2.good()) {
row.clear();
getline(file_2, line);
stringstream s(line);
while (getline(s, word, ',')) {
    row.push_back(word);
}

auth_cnic = row[3];

if ( auth_cnic==cnic ){
    cout << "Name: " << row[2] << endl;
    cout << "CNIC: " << row[3] << endl;
    cout << "Email: " << row[0] << endl;
    cout << "Phone Number: " << row[4] << endl;
    cout << "City: " << row[5] << endl;
    cout << "Room Number: " << row[6] << endl;
        }
    } 
    file_2.close();
}

void make_admin(fstream& file_1){
    cout << "\n\t\tSign Up!";
    cout << "\n\t\tEnter the following to register as an Admin: " << endl;

    cout << "\n\t\tEnter Your Email: ";
    cin >> email;
    file_1 << email << ",";

    cout << "\n\t\tEnter Password: ";
    cin >> password;
    file_1 << password << endl;

    cout << "Account Creation in progress, Please wait..";
    for (int i=0; i<3; i++){
    cout << '.';
    Sleep(1000);
    }
    system("CLS");
    cout << "Congratulation! Your account has been created.\n\n";
    file_1.close();
}


};

class Hosellite : public Person{
public:

void enter_data (fstream& file_my){
    string name, cnic, phone_no, city;
    int room_no;

    cout << "Enter Name: ";
    getline(cin >> ws, name);

    cout << "Enter CNIC: ";
    getline(cin, cnic);

    cout << "Enter phone number: ";
    cin >> phone_no;

    cout << "Enter City: ";
    cin >> city;

    cout << "Enter Room Number: ";
    cin >> room_no;

    file_my << name << ",";
    file_my<< cnic  << ",";
    file_my << phone_no << ","; 
    file_my << city << ","; 
    file_my << room_no << endl;
}

//show hostellite her data
void show_your_data(fstream& file_2){

    //create a string vector
vector<string> row;
string line, word;
int count=0, success=0;

cout << "\n\t\tPlease verify your email to see you data!\n" ;
cout << "\n\t\tEnter Your Email: ";
cin >> email;
cout << "\n\t\tEnter Your Password: ";
cin >> password;

//untill the file has something in it
while(file_2.good()) {
row.clear();
getline(file_2, line);
stringstream s(line);
while (getline(s, word, ',')) {
    row.push_back(word);
}
auth_email = row[0];
auth_password = row[1];
if ( this->email==auth_email && this->password==auth_password){
    success++;
    cout << "Name: " << row[2] << endl;
    cout << "CNIC: " << row[3] << endl;
    cout << "Email: " << row[0] << endl;
    cout << "Phone Number: " << row[4] << endl;
    cout << "City: " << row[5] << endl;
    cout << "Room Number: " << row[6] << endl;
    break;
}
else if ( this->email!=auth_email || this->password!=auth_password){
    count++;
    //cout << "Enter Valid Email!" << endl;
    //break;
}

}

if ( success==0 ) cout << "Enter Valid Email!" << endl;
file_2.close();

}

//Update Existing
void update_data(){

}

void delete_data(){

}

void pay_mess(){

    int months=0, fine=200;
    srand(time(0));
    int challan_no, days=0;
    int transaction_id;
    string choice;
    int bill =5500, deduction=185;
    cout << "Enter the Number of months you want to pay Mess Dues for: ";
    cin >> months;

    cout << "Have you skipped mess anyday, Enter days: ";
    cin >> days;

    cout << "\n\t\tGenerating Your Invoice: ";
    for ( int i=0; i<3; i++){
        cout << ".";
        Sleep(1000);
    }
    cout << endl;

    challan_no =  (rand() % 2550000 - 1550000) + 1550000;
    transaction_id =  (rand() % 255550077 - 155776004) + 155776004;
    for ( int j=0; j<months; j++){
        cout << "\nBill of Month " << j+1 << ": " << bill;
    }

    if ( months==1 ){
        cout << "\n\n\t\t------------------------------------------------------\n\n";
        cout << "\n\tChallan No: " << challan_no << endl;
        cout << "\n\tTransaction ID: " << transaction_id << endl;
        cout << "\n\tDeduction from total bill: " << days*deduction << endl;
        cout << "\n\tTotal Bill: " << (fine*months) + (bill*months) - (days*deduction) << endl;
        cout << "\n\tThis Challan is Valid untill 3 days from Today.\n" << endl;
        }
    else {
            cout << "\n\n\t\t------------------------------------------------------\n\n";
            cout << "\n\tChallan No: " << challan_no << endl;
            cout << "\n\tTransaction ID: " << challan_no << endl;
            cout << "\n\tBill of " << months << " months: " << bill*months << endl;
            cout <<  "\n\tFine: " << fine*(months-1) << endl;
            cout << "\n\tDeduction from total bill: " << days*deduction << endl;
            cout << "\n\tTotal Bill: " << (fine*(months-1)) + (bill*months) - (days*deduction) << endl;
            cout << "\n\tThis Challan is Valid untill 3 days from Today.\n" << endl;
            cout << "Note: Kindly pay your challan by 15 of every month so that " <<
            "you don't get fined next time!\n";
            
    }
}


};

int main () {
    cout << "\n\t\t-----<Hostel Management System>------\n";
    fstream file_3;
    fstream file_2;
    ifstream file_4; 
    char choice, choice1;
    Person h1;
    Admin a1;
    Hosellite obj1;
    bool check = false;

bbb:
    cout << "Press 1 if you're an Admin and 2 if you're a Hostellite: ";
    cin >> choice;

//hostellite
if ( choice == '2'){
    
file_2.open("hostellites.csv", ios::out | ios::in | ios::app);
cout << "Press 1 to regsiter and press 2 to SignIn: ";
cin >> choice1;

if ( choice1 == '1'){
h1.SignUp(file_2);
//file_2.open("hostellites.csv", ios::out | ios::in | ios::app);
obj1.enter_data(file_2);
cout << "Your data has been Stored.\n";
file_2.open("hostellites.csv", ios::out | ios::in | ios::app);
h1.Signin(file_2);
goto start1;
}

else h1.Signin(file_2);

start1:
cout << "Success Count: " << h1.count_success << endl;
cout << "count_password : " << h1.count_password << endl;
cout << "Fail Count: " << h1.count_fail << endl;

if ( h1.count_success>=1)	{
for ( int i=0; i<3; i++){
    cout << ".";
    Sleep(1000);
}
system("CLS");
cout << "\n\t\t---Logged In, Successfully!!" << endl;
goto hostellite;
check = true;
}

else if ( h1.count_success==0 && h1.count_password>=1)	{
for ( int i=0; i<3; i++){
    cout << ".";
    Sleep(1000);
}
system("CLS");
cout << "\n\t\t---Invalid Password!!" << endl;
h1.count_password=0;
while( check = true ){ 
file_2.open("hostellites.csv", ios::out | ios::in | ios::app);
h1.Signin(file_2);
goto start1;
}

}

else if ( h1.count_success==0 && h1.count_password==0 && h1.count_fail>=1 )  {
for ( int i=0; i<3; i++){
    cout << ".";
    Sleep(1000);
}
system("CLS");
cout << "\n\t\t---No accound with this Email!!" << endl;
while( check = true ){ 
file_2.open("hostellites.csv", ios::out | ios::in | ios::app);
h1.Signin(file_2);
goto start1;
}
}


}

//admin
else if ( choice == '1' ){

file_2.open("admin_passwords.csv", ios::out | ios::in | ios::app);
h1.Signin(file_2);

start:
cout << "Success Count: " << h1.count_success << endl;
cout << "count_password : " << h1.count_password << endl;
cout << "Fail Count: " << h1.count_fail << endl;

if ( h1.count_success>=1)	{
for ( int i=0; i<3; i++){
    cout << ".";
    Sleep(1000);
}
system("CLS");
cout << "\n\t\t---Logged In, Successfully!!" << endl;
goto admin;
check = true;
}

else if ( h1.count_success==0 && h1.count_password>=1)	{
for ( int i=0; i<3; i++){
    cout << ".";
    Sleep(1000);
}
system("CLS");
cout << "\n\t\t---Invalid Password!!" << endl;
h1.count_password=0;
while( check = true ){ 
file_2.open("admin_passwords.csv", ios::out | ios::in | ios::app);
h1.Signin(file_2);
goto start;
}

}

else if ( h1.count_success==0 && h1.count_password==0 && h1.count_fail>=1 )  {
for ( int i=0; i<3; i++){
    cout << ".";
    Sleep(1000);
}
system("CLS");
cout << "\n\t\t---No accound with this Email!!" << endl;
while( check = true ){ 
file_2.open("admin_passwords.csv", ios::out | ios::in | ios::app);
h1.Signin(file_2);
goto start;
}
}
}

else {
    cout << "Invalid Input." << endl;
    system("CLS");
    goto bbb;
}

//Hostellite logged in Successfully
hostellite:
char user;

while (1){
    //system("CLS");
    cout << "\n\t\tPress 1 to show your data." << endl;
    cout << "\n\t\tPress 2 to pay your mess challan." << endl;
    cout << "\n\t\tPress 3 to exit" << endl;
    user = getch();	
    switch(user){
        case '1':
        file_2.open("hostellites.csv", ios::out | ios::in | ios::app);
        obj1.show_your_data(file_2);
        break;

        case '2':
        cout << "\n\n\t\t------------------------------------------------------\n\n";
        obj1.pay_mess();
        cout << "\n\n\t\t------------------------------------------------------\n\n";
        break;

        default:
		cout << "\aInvalid input" << endl;
		break;

		case '3':
		return 0;
    }
    //goto cut;
}
    
//admin logged in Successfully

admin:
while (1){
    cout << "\n\t\tPress 1 to show all data" << endl;
    cout << "\n\t\tPress 2 to search data." << endl;
    cout << "\n\t\tPress 3 to Make another person admin." << endl;
    cout << "\n\t\tPress 4 to exit" << endl;
    user = getch();	
    switch(user){
        case '1':
        system("CLS");
        cout << "\n\n\t\t---All the data will be displayed here---\n\n";
        for ( int k=0; k<3; k++){
            cout << ".";
            Sleep(1000);
        }
        cout << "\n";
        //file_2.open("hostellites.csv", ios::out | ios::in | ios::app);
        a1.show_admin_data();
        break;

        case '2':
        file_2.open("hostellites.csv", ios::out | ios::in | ios::app);
        a1.search_data(file_2);
        break;

        case '3':
        file_2.open("admin_passwords.csv", ios::out | ios::in | ios::app);
        a1.make_admin(file_2);
        break;

		case '4':
		return 0;

        default:
		cout << "\aInvalid input" << endl;
		break;


    }
}

cut:
        return 0;
}