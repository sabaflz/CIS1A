#include <iostream>
#include <iomanip>

using namespace std;

/* Set the national average residential electricity rate is 15.72 cents/kWh
   this rate for Santa Clara County residents is 30.70 cents/kWh */
#define COST_PER_KWH 15.72 // Since I don't live in Santa Clara County

int main()
{
    /*
        This program computes the cost of running
        an appliance for a specified amount of time.
    */
    
    // Declare variables
    double watts;
    double time_in_mins, time_in_hrs;
    double kWh;
    double cost_in_dollars;
    
    // Get the value of watts the appliance uses and time in minutes from user
    cout << "Enter watts of appliance:  ";
    cin >> watts;
    cout << "Enter minutes in use:  ";
    cin >> time_in_mins;
    
    // Calculations
    // Convert time in minutes to hours
    time_in_hrs = time_in_mins / 60;
    
    /* Calculate kilowatt hours (kWh) by multiplying watts
       by time in hours and dividing by 1000 */
    kWh = (watts * time_in_hrs)/1000;
    
    // Convert the Cost per kWh from cents/kWh to dollars/kWh
    cost_in_dollars = COST_PER_KWH / 100;
    
    // Calculate the final cost by multiplying kWh by the cost/kWh in dollars
    cost_in_dollars *= kWh;
    
    /* Print the cost of the appliance formatted
       with 2 digits to the right of the decimal point */
    cout << fixed << setprecision(2);
    cout << "kWh used:  " << kWh << endl;
    cout << "Cost ($):  " << cost_in_dollars << endl;

    return 0;
}


//    cout << sizeof(13/3) << endl;

//    int x = 2; int z;
//    z = ++x * 10;
//    pow(x,5.0);
//    int k = 21;
//    int div = 6;
//    cout << static_cast<double>(k) / div << endl;
//    cout << x << endl;
//    cout << z << endl;
//    cout << sizeof("A") << endl;
//    cout << sizeof('A') << endl;
