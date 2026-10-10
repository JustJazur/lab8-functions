/*
 * Course: COEN 2210 - Introduction to Programming
 * Name: [Jazer E. Ramos Muniz]
 * Lab: 8 - Functions
 * Description: [Value reference code demonstration]
 * Due Date: [10/10/2026]
 */

 #include <iostream>                                      // Provides cin, cout, and endl
using namespace std;                                     // Allows standard-library names without the std:: prefix

void showProjectedCount(int completedInspections);       // Declares a value-parameter function
void recordCompletedInspection(int &completedInspections); // Declares a reference-parameter function

int main() {                                             // Starts the program
    int completedInspections;                            // Stores the official completed-inspection count

    cout << "Enter completed inspections: ";           // Prompts for the official count
    cin >> completedInspections;                         // Reads the value stored by main

    showProjectedCount(completedInspections);            // Sends a copied count to the first function
    cout << "After projection: " << completedInspections << endl; // Shows that main kept its count
    recordCompletedInspection(completedInspections);     // Sends the original count by reference
    cout << "After recording: " << completedInspections << endl; // Shows that main now stores the update

    /* showProjectedCount basically it recieves the 4 as indicated in the github assignment for the lab
    after that the code adds to that number from the void then it puts that on screen, after it goes
    and reads the original value again and from the other void it adds again making it have incoherent values. */

    return 0;                                            // Ends the program successfully
}                                                        // Ends the main function

void showProjectedCount(int completedInspections) {      // Defines a function that changes only its local copy
    completedInspections++;                              // Adds one only to the copied parameter
    cout << "Projected count: " << completedInspections << endl; // Displays the possible next count
}                                                        // Ends the value-parameter function

void recordCompletedInspection(int &completedInspections) { // Defines a function that accesses the original variable
    completedInspections++;                              // Changes the official count through the reference
    cout << "Inspection recorded." << endl;             // Confirms the permanent update
}                                                        // Ends the reference-parameter function