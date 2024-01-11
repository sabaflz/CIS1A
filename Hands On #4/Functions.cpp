 /*
    Hands On #4 - Functions (Tuition)
    CWID # - 12345678
*/

#include <iostream>
#include <iomanip>

using namespace std;

// Cost per Unit for each quarter
#define UNIT_COST 31

//--------------------------------- prototypes ----------------------------------
double calcTuition(double units, double studentFees, double medical);
void output(double total);
void signature();

//------------------------------------ main -------------------------------------
int main()
{
    /*
     This program calculates the costs for attending De Anza this quarter.
     
     Unit Cost ---> $31
     
     Basic Fees for All Students:
     Student Body Fee ---------------------> $10 per quarter
     Campus Center Fee --------------------> $17.50 per quarter
     Health Services Fee ------------------> $17 per quarter
     Registration Support Fee -------------> $1.50 per quarter
     Student Representation Fee -----------> $2 per quarter
     SmartPass (formerly Eco Pass) Fee ----> $7.75 per quarter
                    ----------------------------------------
                           student fee ----> $55.75
                    (10 + 17.50 + 17 + 1.50 + 2 + 7.75 = 55.75)
     
     Medical Insurance Cost ---------------> 0 for US residents
    */
    
    // Declare variables
    double unitNum;
    double studentFees;
    double medicalFees;
    double totalCost;
    bool isResident;

    // Get the number of Units, Student Fees and Medical Fees from the user
    cout << "Please enter the number of units:  ";
    cin >> unitNum;
    cout << "Please enter your student fees:  ";
    cin >> studentFees;
    cout << "Are you a resident?(enter 1 if you are, enter 0 if you are not)  ";
    cin >> isResident;
    if(!isResident)
    {
        cout << "Please enter your Health insurance fees:  ";
        cin >> medicalFees;
    }
    else medicalFees = 0;  // Medical Insurance Cost is 0 for residents

    
    // Calculate the TOTAL COST for this quarter
    totalCost = calcTuition(unitNum, studentFees, medicalFees);
    
    // Print the TOTAL COST for the user
    cout << "The Total Cost for this quarter is:  " << totalCost << endl;
    
    // Signature
    signature();
    
    return 0;
}
//--------------------------------- end of main ---------------------------------

//--------------------------------- calcTuition ---------------------------------
double calcTuition(double units, double studentFees, double medical)
{
    /* 
      Pre:
            units - Number of Units the user has this quarter
            studentFees - Student Fees entered by the user
            medical - Medical Insurance Fees based on their residence status
     
       Post: 
            total - Total Cost for this quarter
       Purpose:
            Compute and Return the value of total cost
    */
    
    // Declare variables
    double total;
    
    // Compute the Total Cost
    total = (units * UNIT_COST) + studentFees + medical;
    
    return total;
}
//-----------------------------  end of calcTuition -----------------------------

//---------------------------------- signature ----------------------------------
void signature()
{
    /* 
       Pre:  -
       Post: -
       Purpose: Print the programmers information (Name and CWID #)
    */
    
    // Print the programmers Name and CWID #
    cout << "----------------------------------------------------------" << endl;
    cout << "CWID #:  12345678" << endl << endl;
    
    return;
}
//------------------------------- end of signature ------------------------------

//---------------------------------- the output ---------------------------------
// The Output with the Test Data : 14.5 , 55.75 , 1
/*
 Please enter the number of units:  14.5
 Please enter your student fees:  55.75
 Are you a resident?(enter 1 if you are, enter 0 if you are not)  1
 The Total Cost for this quarter is:  505.25
 ----------------------------------------------------------
 CWID #:  12345678

 Program ended with exit code: 0
*/
