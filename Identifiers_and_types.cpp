// This program demonstrates the use of characters, strings, integers and floating point

// Saba Feilizadeh

#include <iostream>
#include <string>

using namespace std;

int main()
{

// Declaration of constants
const string FAVORITESODA = "Dr. Dolittle"; // use double quotes for strings
const int NUMBER_SURVEYED = 1000; //


char rating; // A, B, C product rating
string favoriteSnack; // most preferred snack
int numberOfPeople; // the number of people in the survey
double price; //price of snack

// Fill in the code to do the following:

// Assign avalue to favoriteSnack
favoriteSnack = "chips";
// Assign a grade of 'B' to rating
rating = 'B';
// Assign the number 202 to the numberOfPeople
numberOfPeople = 202;
// Assign the number 2.49 to the price
price = 2.49;


// Fill in the blanks of the following with identifiers:

cout << "The preferred soda is " << FAVORITESODA << endl;
cout << sizeof(FAVORITESODA) << endl;

cout << "The preferred snack is " << favoriteSnack << endl;
cout << sizeof(favoriteSnack) << endl;;

cout << "Out of " << NUMBER_SURVEYED << " people "<< numberOfPeople << " chose these items!" << endl;
cout << sizeof(numberOfPeople) << endl;

cout << "Each of these products were given a rating of " << rating;
cout << sizeof(rating) << endl;
cout << " from our expert tasters" << endl;

cout << "The price of the favorite snack was $ " << price << endl;
cout << sizeof(price) << endl;
system("pause");

return 0;

}
