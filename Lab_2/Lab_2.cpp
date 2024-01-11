/*
    Lab 2 – Swag for De Anza’s 2023 Welcome Day
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Set tax rate
#define TAX_RATE 0.0913

int main()
{
    /*
     This program Prints the Bill Information for De Anza’s 2023 Welcome Day
     
     Pens – sold in packages of 50 for $65.50/package
     T-shirts - sold in packages of 25 for $192.50/package
     Phone Stands - sold in packages of 15 for $89.85/package
    */
    
    // Declare variables and constants
    const double penPrice = 65.50;
    const double tshirtPrice = 192.50;
    const double phoneStandPrice = 89.85;
    string date;
    int numPeople;
    int numPenPackages , numTshirtPackages, numPhoneStandPackages;
    double pensSubtotal, tshirtSubtotal, phoneStandSubtotal;
    double subtotal, tax, total;
    
    
    // Input the Month and Year
    cout << "Enter Month and Year (ex: October 2023):  ";
    getline(cin, date);                                           // Get the whole line as one string
    cout << "Enter Number of RSVPs received:  ";
    cin >> numPeople;                                             // Get the number of people who registered to attend as an integer
    
    // Calculate the Number of Packages to order based on the number of people attending
    numPenPackages = (numPeople + 50 - 1) / 50;
    numTshirtPackages = (numPeople + 25 - 1) / 25;
    numPhoneStandPackages = (numPeople + 15 - 1) / 15;
    
    // Calculate the SUBTOTAL amount needed for each item
    pensSubtotal = numPenPackages * penPrice;                     // Pens Subtotal
    tshirtSubtotal = numTshirtPackages * tshirtPrice;             // T-shirts Subtotal
    phoneStandSubtotal = numPhoneStandPackages * phoneStandPrice; // Phone Stands Subtotal
    
    // Calculate the FULL SUBTOTAL
    subtotal = pensSubtotal + tshirtSubtotal + phoneStandSubtotal;
    // Calculate the Tax
    tax = subtotal * TAX_RATE;
    // Calculate the TOTAL amount needed
    total = subtotal + tax;
    
    
    // Print the Month and Year entered by the user
    cout << "\nMonth:  " << date << endl << endl;
    
    // Print the bill information in a table format
    cout << left << setw(25) << "ITEM" << setw(20) << "#PACKAGES"
         << setw(20) << "UNIT_COST" << setw(15) << "SUBTOTAL" << endl;                     // Print the title of the columns
    
    // Print the content of the table
    cout << fixed << setprecision(2); // printing numbers up to 2 decimal places
    
    cout << left << setw(29) << "Pens" << right << numPenPackages
                 << setw(21) << penPrice << setw(20) << pensSubtotal << endl;              // Pens Info
    
    cout << left << setw(29) << "T-shirts" << right << numTshirtPackages
                 << setw(21) << tshirtPrice << setw(20) << tshirtSubtotal << endl;         // T-shirts Info
    
    cout << left << setw(29) << "Phone Stands" << right << numPhoneStandPackages
                 << setw(21) << phoneStandPrice << setw(20) << phoneStandSubtotal << endl; // Phone Stands Info
    
    cout << endl;
    cout << setw(12) << "Subtotal" << setw(20) << subtotal << endl;               // Print Subtotal
    cout << setw(12) << "Tax" << setw(20) << tax << endl;                         // Print Tax
    cout << setw(12) << "Total" << setw(20) << total << endl;                     // Print Total
    
    return 0;
}

// The Output
/*
 Enter Month and Year (ex: October 2023):  August 2023
 Enter Number of RSVPs received:  847

 Month:  August 2023

 ITEM                     #PACKAGES           UNIT_COST           SUBTOTAL
 Pens                         17                65.50             1113.50
 T-shirts                     34               192.50             6545.00
 Phone Stands                 57                89.85             5121.45

     Subtotal            12779.95
          Tax             1166.81
        Total            13946.76

 Program ended with exit code: 0
*/
