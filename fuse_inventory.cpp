/*
 * Course: COEN 2210 - Introduction to Programming
 * Name: [Jazer E. Ramos Muniz]
 * Lab: 8 - Functions
 * Description: [Fuse inventory management program]
 * Due Date: [10/10/2026]
 */

 #include <iostream>                                      // Provides cin, cout, and endl
using namespace std;                                     // Allows standard-library names without the std:: prefix

// TODO: Declare prototypes for the three functions described below.
void displayHeading();
void reportFuseUsage(char usedFuse);
void updateFuseCount(int &fuseCount);

int main() {                                             // Starts the program
    int fuseCount;                                       // Stores the official number of spare fuses
    char usedFuse;                                       // Stores the technician decision

    // TODO: Call the heading function, read fuseCount, and read Y or N.
    displayHeading();
    cout << "Enter the number of spare fuses: ";
    cin >> fuseCount;
    cout << "Was a fuse used? (Y/N): ";
    cin >> usedFuse;

    // TODO: Use if/else to decide whether to call the inventory-update function.
    if (usedFuse == 'Y' || usedFuse == 'y') {
        reportFuseUsage(usedFuse);
        updateFuseCount(fuseCount);
    } else {
        reportFuseUsage(usedFuse);
    }

    // TODO: Display the final number of spare fuses.
    cout << "Final number of spare fuses: " << fuseCount << endl;

    return 0;                                            // Ends the program successfully
}                                                        // Ends the main function

// TODO: Define a void function that displays the cabinet heading.
void displayHeading() {
    cout << "Fuse Inventory Management" << endl;
    cout << "--------------------------" << endl;
}
// TODO: Define a void function that reports whether the response uses a fuse.
void reportFuseUsage(char usedFuse) {
    if (usedFuse == 'Y' || usedFuse == 'y') {
        cout << "A fuse was used." << endl;
    } else if (usedFuse == 'N' || usedFuse == 'n') {
        cout << "No fuse was used." << endl;
    } else {
        cout << "Invalid input. Please enter Y or N." << endl;
    }
}
// TODO: Define a void function that receives fuseCount by reference and subtracts one.
void updateFuseCount(int &fuseCount) {
    if (fuseCount == 0) {
        cout << "Not acceptable: a fuse cannot be used when none are available." << endl;
    } else {
        fuseCount--; // Subtracts one from the official count of spare fuses
    }
}

/*
Analysis

Test cases:
1. Input: 5, Y -> A fuse was used. Final number of spare fuses: 4.
2. Input: 5, N -> No fuse was used. Final number of spare fuses: 5.
3. Input: 0, Y -> The fuse use is rejected. Final number of spare fuses: 0.
4. Input: 3, X -> The response is invalid. Final number of spare fuses: 3.

Only updateFuseCount needs an int reference parameter because it changes the
official fuse count stored in main. displayHeading does not need a parameter,
and reportFuseUsage only reads the user's response, so it can receive a copy
of the char value.
*/