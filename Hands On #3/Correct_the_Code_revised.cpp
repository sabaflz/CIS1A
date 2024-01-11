/*
  Hands-On #3 - Correct the Code
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Set the PI value
#define PI 3.141592 // The correct amount of PI

int main()
{
    // Declare variables
    double radius;
    double area;
    
    // Input the radius
    cout << "Enter the radius: ";
    cin >> radius;
    
    // Compute the Area of the Circle
    area = PI * radius * radius;
    
    // Output the area up to 2 decimal points
    cout << fixed << setprecision(2); // Have consistant precision throughout the program
    cout << "Area of Circle: " << area << endl;
    
    // Signature
    cout << "\n\nSaba\n\n";
    
    system("pause");    // Since I use Xcode, this statement is not going to work for me
                        // hence the "sh: pause: command not found" in the output
    return 0;
}

//Output:
/*
 Enter the radius: 10
 Area of Circle: 314.16

 sh: pause: command not found
 Program ended with exit code: 0
*/
