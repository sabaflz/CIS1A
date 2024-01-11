/*
    Lab 6 - Fill Rate Fall 2023
*/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//----------------------------------- prototypes ------------------------------------
double computeFillRate(int, int, int);
void output(ofstream&, string, string, double);
void signature();

//------------------------------------- main() --------------------------------------
int main()
{
    // This program determines fill rates & outputs report needed by the CIS department
    
    // Declare file variables and open the files
    ifstream inputFile;
    inputFile.open("Fall2023.txt");
    
    ofstream outputFile;
    outputFile.open("Fill_Rates.txt");
    
    // Check if the files are succesfully opened/created
    if(!inputFile)
    {
        cout << "No such file as Fall2023.txt!" << endl;
        exit(100);
    }
    else if(!outputFile)
    {
        cout << "No such file as Fill_Rates.txt!" << endl;
        exit(100);
    }
    
    // Declare variables
    string course_CRN_number;
    string class_name; // (e.g. CIS D002.-62Z)
    int current_enrollment;
    int maximum_enrollment;
    int students_on_waitlist;
    
    double fill_rate;
    
    string min_crn;
    string min_class_name;
    double min_fill_rate = 1000;
    double avg_fill_rate = 0;
    double sum_of_max = 0;
    
    // Output the heading directly to the file from main()
    outputFile << "CRN" << setw(20) << "Course" << setw(26) << "Fill Rate %" << endl;
    
    while (!inputFile.eof())
    {
        // Read the info from the given file (Fall2023.txt)
        inputFile >> course_CRN_number;
        getline(inputFile, class_name);
        // Manage the '\n' for Mac users
        if (class_name.substr(class_name.size()-1) == "\n" ||
            class_name.substr(class_name.size()-1) == "\r")
        {
            class_name = class_name.substr(0, class_name.size()-1);
        }
        inputFile >> current_enrollment;
        inputFile >> maximum_enrollment;
        inputFile >> students_on_waitlist;
        
        // Calculate the fill rate by calling the computeFillRate function
        fill_rate = computeFillRate(current_enrollment, students_on_waitlist, maximum_enrollment);
        
        // Output the required info to the output file (Fill_Rates.txt)
        output(outputFile, course_CRN_number, class_name, fill_rate);
        
        // Find the class with the minimum fill rate
        if(fill_rate < min_fill_rate && fill_rate != -1)
        {
            min_fill_rate = fill_rate;
            min_class_name = class_name;
            min_crn = course_CRN_number;
        }
        
        avg_fill_rate += current_enrollment + students_on_waitlist;
        sum_of_max += maximum_enrollment;
    }
    
    // Calculate the the average fill rate
    avg_fill_rate /= sum_of_max;
    
    // Print the info about the class with the lowest fill rate to the screen
    cout << "Class with the lowest fill rate:" << endl;
    cout << fixed << setprecision(1);
    cout << "CRN#" << setw(18) << "Course" << setw(26) << "Fill Rate %" << endl;
    cout << min_crn << setw(20) << min_class_name << setw(20) << min_fill_rate << endl;
    cout << "\nThe average fill rate is: " << avg_fill_rate << endl;
    
    // Close the files
    inputFile.close();
    outputFile.close();
    
    // Signature
    signature();
    
    return 0;
}
//---------------------------------- end of main() ----------------------------------

//-------------------------------- computeFillRate() --------------------------------
double computeFillRate(int enrolled, int waitlisted, int max_enrollment)
{
    /*
        Pre:
            enrolled       : Current number of students enrolled
            waitlisted     : Number of students on the wait-list
            max_enrollment : Maximum number of students allowed to enroll
     
        Post:
            fill_rate      : sum of current enrollment plus number of students
                             on wait-list divided by the maximum enrollment.
     
        Purpose:
            Calculate and return the value of fill rate for the given course.
             
    */
    double fill_rate;
    
    // The fill rate should be set to -1 if the maximum enrollment is zero
    if(max_enrollment == 0)
    {
        fill_rate = -1;
    }
    else
    {
        fill_rate = static_cast<double>(enrolled + waitlisted)
                    / static_cast<double>(max_enrollment) * 100;
    }
    
    return fill_rate;
}
//----------------------------  end of computeFillRate() ----------------------------

//----------------------------------- output() --------------------------------------
void output(ofstream& outputFile, string crn, string title, double fill_rate)
{
    /*
        Pre:
            outputFile : Reference to the outputFile (Fill_Rates.txt)
            crn        : CRN# of the course read from the input file (Fall2023.txt)
            title      : The name of the course read from the input file (Fall2023.txt)
        Post:
            Nothing
     
        Purpose:
            Output the CRN#, the name of the course and the fill rate percentage
            to the output file (Fill_Rates.txt)
    */
    
    if(fill_rate == -1) return;              // Do NOT output if the fill rate is -1
    outputFile << fixed << setprecision(1);  // Print the numbers up to 1 decimal places
    outputFile << crn << setw(20) << title << right << setw(20) << fill_rate << endl;
    
    
    return;
}
//-------------------------------- end of output() ----------------------------------

//----------------------------------- signature() -----------------------------------
void signature()
{
    cout << "\n" << setfill('-') << setw(60) << '-' << endl;
    cout << "Lab 6 - Fill Rate Fall 2023" << endl << endl;
}
//------------------------------- end of signature() --------------------------------
