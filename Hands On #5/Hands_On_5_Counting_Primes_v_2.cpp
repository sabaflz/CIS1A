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
        A number that doesn't have any divisors other than 1 and itself, is a PRIME number.
    */
    if(beginValue < endValue && beginValue >= 0 && endValue >= 0)                           // Check for valid inputs
    {
        /*
            In case the user has entered 0 or 1 as the beginValue,
            since 0 and 1 are not prime numbers,
            we can change the beginValue to 2 and check the range [2,endValue]
        */
        
        if(beginValue == 0 || beginValue == 1)
        {
            beginValue = 2;
        }
        
        /*
            Check if each number in the given range is not prime
            by checking if it has divisors other than 1 and itself
        */
        for(int currentNum = beginValue; currentNum <= endValue; currentNum++)
        {
            isPrime = true;                                                          // We assume the number is prime
            
            /*
                Since the smallest devisor that a number can have (besides 1) is 2,
                the largest possible divisor is number/2.
                So we only need to check up to number/2 for each num in the range.
            */
            for(int divisor = 2; divisor <= currentNum/2; divisor++)
            {
                // Check for devisors in range [2,currentNum/2]
                if(currentNum % divisor == 0)
                {
                    isPrime = false;            // The number has a divisor in this range, so it's not a prime number
                }
            }
            
            if(isPrime)
            {
                primeCount++;                             // If the number is a prime number, increase the primeCount
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
