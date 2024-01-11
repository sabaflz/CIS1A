/*
    Lab 5 - Mortgage Payment
*/

#include <iostream>
#include <cmath>
#include <iomanip>

// Global Defined Constants
#define TAX_RATE 0.0125                  // yearly tax rate is 1.25% of selling price
#define INSURANCE_COST 3250.00           // insurance will be $3250.00 per year
#define HOUSING_EXPENSE_RATIO 0.31       // housing expense ratio of 31%

using namespace std;

//----------------------------------- prototypes ------------------------------------
void input(double&, double&, int&);
void mortgageCalc(double, double&, double, int, double&, double&, double&, double&, double&, double&);
void calcDownLoanMortgage(double, double, int, double&, double&, double&);
void output(double, double, double, double, int, double, double, double, double, double);
void signature();

//------------------------------------- main() --------------------------------------
int main()
{
    // This program calculates and prints the Monthly House Costs
    
    // Declare variables
    double selling_price;
    double down_payment;
    double loan_amount;
    double interest_rate;
    
    double monthly_mortgage_payment;
    double property_taxes;
    
    double total_house_costs;
    double minimum_income;
    double monthly_insurance;
    
    int years_for_loan;
    
    
    // Get the data from the user
    input(selling_price, interest_rate, years_for_loan);
    
    // Calculations
    mortgageCalc(selling_price, down_payment, interest_rate, years_for_loan, loan_amount, 
                 monthly_mortgage_payment, property_taxes, monthly_insurance, 
                 total_house_costs, minimum_income);

    // Prints the data for the user
    output(selling_price, down_payment, loan_amount, interest_rate, years_for_loan, 
           monthly_mortgage_payment, property_taxes, monthly_insurance, 
           total_house_costs, minimum_income);
    
    // Signature
    signature();
    
    return 0;
}
//---------------------------------- end of main() ----------------------------------

//------------------------------------ input() --------------------------------------
void input(double& selling_price, double& interest_rate, int& years_for_loan)
{
    /*
        Pre:
            selling_price   : Reference to the selling price of the house
            interest_rate   : Reference to the rate of interest
            years_for_loan  : Reference to the number of years for the loan
     
        Post:
             Nothing
     
        Purpose:
             Ask the user to input the amount of The selling price,
             The rate of interest and The number of years for the loan
    */

    // Ask the user to input the info needed
    cout << "Enter the selling price:($)  ";
    cin >> selling_price;
    
    cout << "Enter the rate of interest:(%)  ";
    cin >> interest_rate;
    
    cout << "Enter the number of years for the loan:  ";
    cin >> years_for_loan;
    
    return;
}
//--------------------------------- end of input() ----------------------------------

//--------------------------------- mortgageCalc() ----------------------------------
void mortgageCalc(double selling_price, double& down_payment, double interest_rate, 
                  int years_for_loan, double& loan_amount, double& monthly_mortgage_payment,
                  double& property_taxes, double& monthly_insurance, double& total_house_costs,
                  double& minimum_income)
{
    /*
        Pre:
            selling_price     : The selling price of the house
            down_payment      : Reference to the amount of down payment
            interest_rate     : The rate of interest
            years_for_loan    : The number of years for the loan
            loan_amount       : Reference to the loan amount
            monthly_mortgage_payment : Reference to the amount of monthly mortgage payment
            property_taxes    : Reference to the property taxes
            total_house_costs : Reference to the total amount of house costs
            minimum_income    : Reference to the minimum income
     
        Post:
            Nothing
     
        Purpose:
            Call the subfunctin calcDownLoanMortgage and Compute the values of 
            property_taxes, total_house_costs, minimum_income
    */
    
    // Calculations
    calcDownLoanMortgage(selling_price, interest_rate, years_for_loan, down_payment, 
                         loan_amount, monthly_mortgage_payment);
    
    // monthly property taxes
    property_taxes = selling_price * TAX_RATE / (12 * years_for_loan);
    // monthly insurance
    monthly_insurance = INSURANCE_COST / 12;
    
    // total_house_costs = (monthly mortgage payment + monthly property tax + monthly insurance)
    total_house_costs = (monthly_mortgage_payment) + (property_taxes) + (monthly_insurance);
    
    // minimum_income = (total house costs / housing expense ratio)
    minimum_income = total_house_costs / HOUSING_EXPENSE_RATIO;
    
    return;
}
//------------------------------ end of mortgageCalc() ------------------------------

//----------------------------- calcDownLoanMortgage() ------------------------------
void calcDownLoanMortgage(double selling_price, double interest_rate, int years_for_loan, 
                          double& down_payment, double& loan_amount,
                          double& monthly_mortgage_payment)
{
    /*
        Pre:
            selling_price     : The selling price of the house
            interest_rate     : The rate of interest
            years_for_loan    : The number of years for the loan
            down_payment      : Reference to the amount of down payment
            loan_amount       : Reference to the loan amount
            monthly_mortgage_payment : Reference to the amount of monthly mortgage payment
     
        Post:
            Nothing
     
        Purpose:
            Compute the values of down_payment, loan_amount and monthly_mortgage_payment
    */
    
    // Declare constants and variables
    const double down_payment_percentage = 0.2; // the down payment will be 20% of selling price
    double a; // loan_amount
    double i = interest_rate / (12 * 100);      // (annual rate / 12 * 100)
    double n = years_for_loan * 12;             // (yrs * 12)
    
    // Calculations
    down_payment = down_payment_percentage * selling_price;
    loan_amount = selling_price - down_payment;
    a = loan_amount;
    /*
        monthly mortgage payment = (a*i(1+i)^n)/((1 + i)^n – 1)
        a = amount of loan
        i = rate of interest per compounding period (annual rate/12)
        n = number of compounding periods (yrs*12)
    */
    monthly_mortgage_payment = (a * i * pow(1 + i,n))/(pow(1 + i,n) - 1);
    
    return;
}
//-------------------------- end of calcDownLoanMortgage() --------------------------

//----------------------------------- output() --------------------------------------
void output(double selling_price, double down_payment, double loan_amount, 
            double interest_rate, int years_for_loan, double mortgage,
            double property_taxes, double monthly_insurance, double total_house_costs,
            double minimum_income)
{
    /*
        Pre:
            selling_price     : The selling price of the house
            down_payment      : The amount of down payment
            loan_amount       : The loan amount
            interest_rate     : The rate of interest
            years_for_loan    : The number of years for the loan
            mortgage          : The amount of monthly mortgage payment
            property_taxes    : The property taxes
            total_house_costs : The total amount of house costs
            minimum_income    : The minimum income
     
        Post:
            Nothing
     
        Purpose:
            Print all the information (values used or calculated) for the user
    */
    cout << setfill('-') << setw(60) << '-' << endl;
    cout << "\n" << fixed << setprecision(2) << setfill(' ');       // Print the numbers up to 2 decimal places
    
    cout << left << "MONTHLY COST OF HOUSE" << endl;
    cout << left << setw(30) << "SELLING PRICE" << right << setw(20) << selling_price << endl;
    cout << left << setw(30) << "DOWN PAYMENT" << right << setw(20) << down_payment << endl;
    cout << left << setw(30) << "AMOUNT OF LOAN" << right << setw(20) << loan_amount << endl;
    cout << left << setw(30) << "INTEREST RATE" << right << setw(19) << interest_rate << "%" << endl;
    cout << left << setw(30) << "TAX RATE" << right << setw(19) << TAX_RATE << "%" << endl;
    cout << left << setw(30) << "DURATION OF LOAN (YEARS)" << right << setw(20) << years_for_loan << endl;
    
    cout << left << "\nMONTHLY PAYMENT" << endl;
    cout << left << setw(30) << "MORTGAGE" << right << setw(20) << mortgage << endl;
    cout << left << setw(30) << "PROPERTY TAXES" << right << setw(20) << property_taxes << endl;
    cout << left << setw(30) << "INSURANCE" << right << setw(20) << monthly_insurance << endl;
    cout << right << setw(50) << "---------" << endl;
    cout << right << setw(43) << "$ " << total_house_costs << endl;
    
    cout << left << setw(30) << "\nMINIMUM MONTHLY INCOME" << right << setw(14) << "$ " << minimum_income << endl;
    
    
    return;
}
//--------------------------------- end of output() ---------------------------------

//----------------------------------- signature() -----------------------------------
void signature()
{
    cout << "\n" << setfill('-') << setw(60) << '-' << endl;
    cout << "Lab 5 - Mortgage Payment" << endl << endl;
}
//------------------------------- end of signature() --------------------------------

//------------------------------------ THE OUTPUT -----------------------------------
// Test Set 1 – 700,000, 2.75, 30
/*
 Enter the selling price:($)  700000
 Enter the rate of interest:(%)  2.75
 Enter the number of years for the loan:  30
 ------------------------------------------------------------

 MONTHLY COST OF HOUSE
 SELLING PRICE                            700000.00
 DOWN PAYMENT                             140000.00
 AMOUNT OF LOAN                           560000.00
 INTEREST RATE                                2.75%
 TAX RATE                                     0.01%
 DURATION OF LOAN (YEARS)                        30

 MONTHLY PAYMENT
 MORTGAGE                                   2286.15
 PROPERTY TAXES                               24.31
 INSURANCE                                   270.83
                                          ---------
                                          $ 2581.29

 MINIMUM MONTHLY INCOME                   $ 8326.74

 ------------------------------------------------------------
 Lab 5 - Mortgage Payment

 Program ended with exit code: 0
*/
//-----------------------------------------------------------------------------------
// Test Set 2 – 700,000, 7.750, 30
/*
 Enter the selling price:($)  700000
 Enter the rate of interest:(%)  7.750
 Enter the number of years for the loan:  30
 ------------------------------------------------------------

 MONTHLY COST OF HOUSE
 SELLING PRICE                            700000.00
 DOWN PAYMENT                             140000.00
 AMOUNT OF LOAN                           560000.00
 INTEREST RATE                                7.75%
 TAX RATE                                     0.01%
 DURATION OF LOAN (YEARS)                        30

 MONTHLY PAYMENT
 MORTGAGE                                   4011.91
 PROPERTY TAXES                               24.31
 INSURANCE                                   270.83
                                          ---------
                                          $ 4307.05

 MINIMUM MONTHLY INCOME                   $ 13893.70

 ------------------------------------------------------------
 Lab 5 - Mortgage Payment

 Program ended with exit code: 0
*/
