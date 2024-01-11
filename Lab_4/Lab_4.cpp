/*
    Lab 4 - Uber Driver Earnings
*/

#include <iostream>
#include <iomanip>

using namespace std;

//----------------------------------- prototypes ------------------------------------
double calcFare(int time, double distance, char type, double surge);
double calcPay(double fare, double tip);
void output(double fare, double earnings);
void signature();

//------------------------------------- main() --------------------------------------
int main()
{
    /*
     This program simulates Uber’s method of calculating pay for their Uber drivers.
    */
    
    // Declare variables
    int length_of_ride;
    char service_type;
    char has_surge;
    double distance_of_ride;
    double surge_multiplier = 0;
    double tip;
    double fare;
    double earnings;

    /*
       Get the ride info from the user:
        (Length of Ride, Distance Traveled,
        Service Type, Surge Multiplier, Tip Amount)
    */
    cout << "Enter time in minutes:  ";
    cin >> length_of_ride;
    cout << "Enter distance in miles:  ";
    cin >> distance_of_ride;
    cout << "Enter 'X' for uberX or 'S' for SUV or ‘L for luxury:  ";
    cin >> service_type;
    service_type = toupper(service_type);                      // Make sure that the service_type is not case sensitive
    // Check for Erroneous Input
    if(!(service_type == 'X' || service_type == 'S' || service_type == 'L'))
    {
        cout << "\n!!! ERROR : Erroneous Input !!!\n" << endl; // Print an Error Message when the Input is Erroneous
        exit(EXIT_FAILURE);                                    // Exit the program
    }
    cout << "Enter 'Y' if surge or ‘N’ if not:  ";
    cin >> has_surge;
    has_surge = toupper(has_surge);                            // Make sure that the has_surge is not case sensitive
    // Ask for the Surge Multiplier only if the answer was YES
    if(has_surge == 'Y')
    {
        cout << "Enter surge multiplier:  ";
        cin >> surge_multiplier;
    }
    else if (has_surge != 'N')                                 // Check for Erroneous Input
    {
        cout << "\n!!! ERROR : Erroneous Input !!!\n" << endl; // Print an Error Message when the Input is Erroneous
        exit(EXIT_FAILURE);                                    // Exit the program
    }
    
    cout << "Enter amount of tip:  ";
    cin >> tip;
    
    // Calculate the Total Fare and the Total Earnings
    fare = calcFare(length_of_ride, distance_of_ride, service_type, surge_multiplier);
    earnings = calcPay(fare, tip);
    
    // Print The TOTAL FARE and The TOTAL EARNINGS
    output(fare, earnings);
    
    // Signature
    signature();
    
    return 0;
}
//---------------------------------- end of main() ----------------------------------

//---------------------------------- Fee Schedule -----------------------------------
/*
    Type of vehicle     base fare       per minute      per mile        Minimum fare
    UberX               $ 2.00          $ 0.22          $ 1.15          $ 6.55
    SUV                 $ 15.00         $ 0.90          $ 3.75          $ 25.00
    Luxury              $ 5.00          $ 0.50          $ 2.75          $ 10.55
*/

//----------------------------------- calcFare() ------------------------------------
double calcFare(int time, double distance, char type, double surge)
{
    /* 
      Pre:
            time : The length of the ride in minutes
            distance : The distance of the ride in miles
            type : Type of the service that rider requested
            surge : Shows if there is high demand
     
       Post: 
            total_fare : Total Fare that the rider should pay
       Purpose:
            Compute and Return the value of total fare
    */
    
    // Declare variables
    double total_fare;
    double base_fare;
    double per_minute;
    double per_mile;
    double minimum_fee;
    
    // Initialize the Base Fare based on the type of service
    switch(type)
    {
        case 'X':
        {
            base_fare = 2.00;
            per_minute = 0.22;
            per_mile = 1.15;
            minimum_fee = 6.55;
            break;
        }
        
        case 'S':
        {
            base_fare = 15.00;
            per_minute = 0.90;
            per_mile = 3.75;
            minimum_fee = 25.00;
            break;
        }
        case 'L':
        {
            base_fare = 5.00;
            per_minute = 0.50;
            per_mile = 2.75;
            minimum_fee = 10.55;
            break;
        }
        default:
        {
            cout << "ERROR: This is not supposed to be possible!" << endl;
            exit(EXIT_FAILURE);
        }
        
    }
    
    if(surge != 0) {base_fare *= surge;}
    
    // Calculate the Total Fare
    total_fare = base_fare + (per_minute * time) + (per_mile * distance);
    
    if(total_fare < minimum_fee) {total_fare = minimum_fee;}
    
    return total_fare;
}
//-------------------------------- end of calcFare() --------------------------------

//------------------------------------ calcPay() ------------------------------------
double calcPay(double fare, double tip)
{
    /*
      Pre:
            fare : The total fare that's been payed by the rider
            tip : The amount of tip that the rider wants to pay
     
       Post:
            total_pay : Total amount that the driver is going to get
       Purpose:
            Compute and Return the value of total pay
    */
    
    // Declare variables and constants
    double total_pay;
    const double TAX = 0.153;            // Federal Tax (self-employment taxes)
    
    // Calculate the Total pay
    fare *= 0.75;                        // Uber keeps 25% of each ride fare
    total_pay = (fare + tip) * (1 - TAX);
    
    return total_pay;
}
//--------------------------------- end of calcPay() --------------------------------

//------------------------------------- output() ------------------------------------
void output(double fare, double earnings)
{
    /*
       Pre:
            fare: The total amount that the rider has to pay
            earnings: The total amount that the uber driver is going to be paid
       Post: -
       Purpose: Print the programmers Name and the Lab info
    */
    
    // Format the output
    cout << endl;
    cout << fixed << setprecision(2); // Print the numbers up to 2 decimal places
    cout << left << setw(20) << "Fare: " << "$" << right << setw(10) << fare << endl;
    cout << left << setw(20) << "Driver's earnings: " << "$" << right << setw(10) << earnings << endl;
    return;
}
//--------------------------------- end of output() ---------------------------------

//----------------------------------- signature() -----------------------------------
void signature()
{
    /* 
       Pre:  -
       Post: -
       Purpose: Print the programmers Name and Email and the Lab Info
    */
    
    // Print the programmers Name and Email and the Lab Info
    cout << "\n" << setfill('-') << setw(60) << '-' << endl;
    cout << "Lab 4 - Uber Driver Earnings" << endl << endl;
    
    return;
}
//-------------------------------- end of signature() -------------------------------

//------------------------------------ The Output -----------------------------------
//----------------------------------- Test Data 1 -----------------------------------
// The Output with Test Data 1: 70, 55, X, Y, 1.9, 3
/*
 Enter time in minutes:  70
 Enter distance in miles:  55
 Enter 'X' for uberX or 'S' for SUV or ‘L for luxury:  X
 Enter 'Y' if surge or ‘N’ if not:  Y
 Enter surge multiplier:  1.9
 Enter amount of tip:  3

 Fare:               $     82.45
 Driver's earnings:  $     54.92

 ------------------------------------------------------------
 Lab 4 - Uber Driver Earnings

 Program ended with exit code: 0
*/
//----------------------------------- Test Data 2 -----------------------------------
// The Output with Test Data 2: 15, 16.8, L, N, 0
/*
 Enter time in minutes:  15
 Enter distance in miles:  16.8
 Enter 'X' for uberX or 'S' for SUV or ‘L for luxury:  L
 Enter 'Y' if surge or ‘N’ if not:  N
 Enter amount of tip:  0

 Fare:               $     58.70
 Driver's earnings:  $     37.29

 ------------------------------------------------------------
 Lab 4 - Uber Driver Earnings

 Program ended with exit code: 0
*/
//----------------------------------- Test Data 3 -----------------------------------
// The Output with Test Data 3: 45, 13.8, C, N, 20
/*
 Enter time in minutes:  45
 Enter distance in miles:  13.8
 Enter 'X' for uberX or 'S' for SUV or ‘L for luxury:  C

 !!! ERROR : Erroneous Input !!!

 Program ended with exit code: 255
*/
