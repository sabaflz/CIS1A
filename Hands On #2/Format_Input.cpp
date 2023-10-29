/*
    Saba Feilizadeh
    Hands On #2 - Learn to Format with Input
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
 //Constants for minimum payment and interest rate
 const double minPayRate = 0.2, interestRate = 0.26/12;
 //Declare variables
 double balance, minPay, interest, amtPaid, balanceForward;
 
 //User input of balance and amount paid on credit card
 cout << "Enter current balance on card: ";
 cin >> balance;
 cout << "Enter amount you paid of balance: ";
 cin >> amtPaid;
 
 //Calculate minimum payment
 minPay = balance * minPayRate;
 //Calculate interest on remaining balance (assume balance >= amtPaid)
 interest = (balance - amtPaid) * interestRate;
 //Calculate new balance brought forward to next month
 balanceForward = balance - amtPaid + interest;
 
 //Output payment details
 cout << left << setw(50) << "Beginning Balance" 
    << fixed << setprecision(2) << right << setw(10) << balance << endl;
 cout << left << setw(50) << "Minimum Payment"
    << fixed << setprecision(2) << right << setw(10) << minPay << endl;
 cout << left << setw(50) << "Amount Paid"
    << fixed << setprecision(2) << right << setw(10) << amtPaid << endl;
 cout << left << setw(50) << "Next month's interest on remaining balance"
    << fixed << setprecision(2) << right << setw(10) << interest << endl;
 cout << left << setw(50) << "Balance Forward"
    << fixed << setprecision(2) << right << setw(10) << balanceForward << endl;
 
 return 0;
}
