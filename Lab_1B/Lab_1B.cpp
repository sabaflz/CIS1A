/*
    Lab 1B - Paying in Coins
 */

#include <iostream>

using namespace std;

int main()
{
    /*
        This program prints the number of Quarters, Dimes,
        Nickels and Pennies you need to pay your bill :)
    */
    
    // Declare variables
    double amountOwed;
    int numQuarters, numDimes, numNickels, numPennies;
    int totalCents;
    
    // Input the amount of money owed
    cout << "Please enter the amount of money that you owe: $ ";
    cin >> amountOwed;
    
    // Convert dollars and cents into cents
    totalCents = amountOwed * 100;
    
    // Calculate the number of quarters
    numQuarters = totalCents / 25;
    totalCents = totalCents % 25;

    // Calculate the number of dimes
    numDimes = totalCents / 10;
    totalCents = totalCents % 10;

    // Calculate the number of nickels
    numNickels = totalCents / 5;
    totalCents = totalCents % 5;
    
    // The remaining cents are pennies
    numPennies = totalCents;
    
    // Print the number of Quarters, Dimes, Nickels and Pennies
    cout << numQuarters << " quarter(s)" << endl;
    cout << numDimes << " dime(s)" << endl;
    cout << numNickels << " nickel(s)" << endl;
    cout << numPennies << " pennies" << endl;
    
    return 0;
}

//The output:
/*
 Please enter the amount of money that you owe: $ 15.45
 61 quarter(s)
 2 dime(s)
 0 nickel(s)
 0 pennies

 Program ended with exit code: 0
 */
