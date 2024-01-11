/*
    Hands On #5 - Counting Prime Numbers
*/

#include <iostream>
#include <iomanip>

using namespace std;

//------------------------------------- main() --------------------------------------
int main()
{
    /*
     This program prints the number of prime numbers in the given range.
     (Inclusive of the endpoints)
    */
    
    // Declare variables
    int beginValue, endValue;
    int primeCount = 0;
    bool isPrime;
    
    // Get the beginning and ending values from the user
    cout << "Please enter the beginning value: ";
    cin >> beginValue;
    cout << "Please enter the ending value: ";
    cin >> endValue;
    
    /* 
        Definition:
        A number that has only two divisors, 1 and itself, is a PRIME number.
    */
    if(beginValue < endValue && beginValue >= 0 && endValue >= 0)    // Check for valid inputs
    {
        // 0 and 1 are not prime numbers
        if(beginValue == 0 || beginValue == 1)
        {
            beginValue = 2;        // To be able to check the rest of the numbers in the range
        }
        
        // Count the number of prime numbers
        for(int i = beginValue; i <= endValue; i++)
        {
            isPrime = true;
            
            for(int j = 2; j <= i/2; j++)
            {
                // If a number has a divisor other than 1 and itself, it's not a prime number
                if(i % j == 0)
                {
                    isPrime = false;
                }
            }
            // If the number is a prime number, increase the primeCount
            if(isPrime)
            {
                primeCount++;
            }
        }
        
        // Print the total number of prime numbers in the given range
        cout << "\nThere are " << primeCount << " prime number(s) in the given range." << endl;
        
    } else
    {
        cout << "!!! Invalid entry !!!" << endl;
    }
    
    // Signature
    cout << "\n" << setfill('-') << setw(60) << '-' << endl;
    cout << "Hands On #5 - Counting Prime Numbers" << endl << endl;
    
    return 0;
}
//---------------------------------- end of main() ----------------------------------

//------------------------------------ The Output -----------------------------------
// Test data: 50 to 100
/*
 Please enter the beginning value: 50
 Please enter the ending value: 100

 There are 10 prime number(s) in the given range.

 ------------------------------------------------------------
 Hands On #5 - Counting Prime Numbers

 Program ended with exit code: 0
*/
