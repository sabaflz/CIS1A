/*
    Lab 3 - ETS CIS Refresh 2022
    Date 10.25.2023
*/

#include <iostream>
#include <iomanip>

using namespace std;

// Set tax rate currently for Cupertino CA
#define TAX_RATE 0.0913

int main()
{
    /*
     This program Prints an INVOICE for the De Anza College
     Advance Technology Building CIS computer refresh for 2022
     
     Unit Price for each Product:
     Tables  ------------>  $429.88
     Dell All-in-One  --->  $1001
     Apple iMac  -------->  $1299
     Meeting Owl 3 ------>  $1049
     Meeting Owl 3 HQ  -->  $1817.93
    */
    
    
    // Declare variables and constants
    const double table_price = 429.88;
    const double dell_computer_price = 1001;
    const double apple_computer_price = 1299;
    const double meeting_owl_price = 1049;
    const double meeting_owl_HQ_price = 1817.93;
    
    int tables_num;
    int dell_computer_num;
    int apple_computer_num;
    int meeting_owl_num;
    int meeting_owl_HQ_num;
    
    double tables_subtotal;
    double dell_computer_subtotal,apple_computer_subtotal;
    double meeting_owl_subtotal,meeting_owl_HQ_subtotal;
    double subtotal, tax, total;
    
    // Get the number of ordered products from the user
    cout << "How many 24 x 72 inch tables ordered?  ";
    cin >> tables_num;
    cout << "How many Dell All-in-One Thin Clients ordered?  ";
    cin >> dell_computer_num;
    cout << "How many Apple iMac computers ordered?  ";
    cin >> apple_computer_num;
    cout << "How many Meeting Owl 3 ordered?  ";
    cin >> meeting_owl_num;
    cout << "How many Meeting Owl HQ devices ordered?  ";
    cin >> meeting_owl_HQ_num;
    cout << endl;
    
    // Calculate the SUBTOTAL amount needed for each product
    tables_subtotal = tables_num * table_price;                                // Tables Subtotal
    dell_computer_subtotal = dell_computer_num * dell_computer_price;          // Dell Computer Subtotal
    apple_computer_subtotal = apple_computer_num * apple_computer_price;       // Apple Computer Subtotal
    meeting_owl_subtotal = meeting_owl_num * meeting_owl_price;                // Meeting Owl Subtotal
    meeting_owl_HQ_subtotal = meeting_owl_HQ_num * meeting_owl_HQ_price;       // Meeting Owl HQ Subtotal
    
    
    // Calculate the FULL SUBTOTAL
    subtotal = tables_subtotal
               + dell_computer_subtotal + apple_computer_subtotal
               + meeting_owl_subtotal + meeting_owl_HQ_subtotal;
    // Calculate the Tax
    tax = subtotal * TAX_RATE;
    // Calculate the TOTAL amount needed
    total = subtotal + tax;
    
    // Print the invoice in a table format
    cout << " ------------------------------- INVOICE -------------------------------" << endl;
    cout << left << setw(6) << "QTY" << setw(37) << "Description"
         << setw(20) << "Unit Price" << setw(15) << "Total Price" << endl;                   // Print the title of the columns
    
    // Print the content of the table
    cout << fixed << setprecision(2);    // printing numbers up to 2 decimal places
  
    
    cout << right << setw(3) << tables_num << setw(3) << " "
         << left << setw(35) << "TABLES 24 X 72 INCH"
         << right << setw(10) << table_price << setw(22) << tables_subtotal << endl;                   // Tables Info
    
    
    cout << right << setw(3) << dell_computer_num << setw(3) << " "
         << left << setw(35) << "DELL ALL-IN-ONE THIN CLIENTS"
         << right << setw(10) << dell_computer_price << setw(22) << dell_computer_subtotal << endl;    // Dell Computer Info
    
    cout << right << setw(3) << apple_computer_num << setw(3) << " "
         << left << setw(35) << "APPLE iMac 24-inch"
         << right << setw(10) << apple_computer_price << setw(22) << apple_computer_subtotal << endl;  // Apple Computer Info
    
    cout << right << setw(3) << meeting_owl_num << setw(3) << " "
         << left << setw(35) << "MEETING OWL 3"
         << right << setw(10) << meeting_owl_price << setw(22) << meeting_owl_subtotal << endl;        // Meeting Owl Info
    
    cout << right << setw(3) << meeting_owl_HQ_num << setw(3) << " "
         << left << setw(35) << "MEETING OWL HQ"
         << right << setw(10) << meeting_owl_HQ_price << setw(22) << meeting_owl_HQ_subtotal << endl;  // Meeting Owl HQ Info

    // Print the Subtotal, Tax and Total
    cout << endl;
    cout << setw(31) << "Subtotal" << setw(20) << subtotal << endl;                                    // Print Subtotal
    cout << setw(31) << "Tax" << setw(20) << tax << endl;                                              // Print Tax
    cout << setw(31) << "Total" << setw(20) << total << endl;                                          // Print Total
    cout << " -----------------------------------------------------------------------" << endl;
    // Print Lab info
    cout << "Lab 3:  ETS CIS Refresh 2022" << endl;
    cout << "Date:   10.25.2023" << endl << endl;
    
    return 0;
}

// The Output with the Test Data 1: 120, 351, 26, 1, 4
/*
 How many 24 x 72 inch tables ordered?  120
 How many Dell All-in-One Thin Clients ordered?  351
 How many Apple iMac computers ordered?  26
 How many Meeting Owl 3 ordered?  1
 How many Meeting Owl HQ devices ordered?  4

  ------------------------------- INVOICE -------------------------------
 QTY   Description                          Unit Price          Total Price
 120   TABLES 24 X 72 INCH                    429.88              51585.60
 351   DELL ALL-IN-ONE THIN CLIENTS          1001.00             351351.00
  26   APPLE iMac 24-inch                    1299.00              33774.00
   1   MEETING OWL 3                         1049.00               1049.00
   4   MEETING OWL HQ                        1817.93               7271.72

                        Subtotal           445031.32
                             Tax            40631.36
                           Total           485662.68
  -----------------------------------------------------------------------
 Lab 3:  ETS CIS Refresh 2022
 Date:   10.25.2023

 Program ended with exit code: 0
*/
