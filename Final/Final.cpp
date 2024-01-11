#include <iostream>
#include <iomanip>
using namespace std;

//Write Prototypes for getData()and computeCosts() here:
double getData(double&, double&, double&);
double computeCosts(double, double, double, double, double&, double&);

int main() {
    // Variable declarations
    double length, width, carpetPricePerSqFt, padPricePerSqYd, totalCost, carpetCost, padCost;

    // Input measurements of room and unit costs for materials
    carpetPricePerSqFt = getData(length, width, padPricePerSqYd);

    // Calculation of area and costs
    totalCost = computeCosts(length, width, carpetPricePerSqFt, padPricePerSqYd, carpetCost, padCost );

    // Output cost of carpet, carpet pad, and total for the room
    cout << fixed << setprecision(2);
    cout << "Cost of Carpet:            $" << setw(10) << carpetCost << endl;
    cout << "Cost of Carpet Pad:        $" << setw(10) << padCost << endl;
    cout << "Total Cost (Carpet + Pad): $" << setw(10) << totalCost << endl;

    return 0;
}//Define functions below
//----------------- getData() -----------------
double getData(double& length, double& width, double& padPricePerSqYd)
{
    double carpetPricePerSqFt;
    
    cout << "Enter the length of the room in feet: ";
    cin >> length;
    
    cout << "Enter the width of the room in feet: ";
    cin >> width;
    
    cout << "Enter the price of carpet per square foot: $";
    cin >> carpetPricePerSqFt;
    
    cout << "Enter the price of carpet pad per square yard: $";
    cin >> padPricePerSqYd;
    
    return carpetPricePerSqFt;
}

//---------------- end of getData() ----------------

//----------------- computeCosts() -----------------
double computeCosts(double length, double width, double carpetPricePerSqFt,
                    double padPricePerSqYd, double& carpetCost, double& padCost)
{
    double area, total;
    
    area = length * width;
    
    carpetCost = area * carpetPricePerSqFt;
    
    padCost = (area * padPricePerSqYd) / 9;
    
    total = carpetCost + padCost;
    
    return total;
}
//------------- end of computeCosts() --------------
