/*
 * Course: COEN 2210 - Introduction to Programming
 * Name: [Jazer E. Ramos Muniz]
 * Lab: 8 - Functions
 * Description: [Workshop registration system]
 * Due Date: [10/10/2026]
 */

 #include <iostream>                                      // Provides cin, cout, and endl
using namespace std;                                     // Allows standard-library names without the std:: prefix

void displayMenu();
void registerAttendee(int &availableSeats);
void cancelRegistration(int maxSeats, int &availableSeats);

int main() {                                             // Starts the program
    int maxSeats;                                        // Stores the fixed workshop capacity
    int availableSeats;                                  // Stores the changing number of available seats
    int menuChoice;                                      // Stores one selected menu option

    do {
        cout << "Enter the maximum number of seats for the workshop (positive number): ";
        cin >> maxSeats;
        if (maxSeats <= 0) {
            cout << "Capacity must be greater than 0. Please try again." << endl;
        }
    } while (maxSeats <= 0);
    availableSeats = maxSeats;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> menuChoice;
        switch (menuChoice) {
            case 1:
                registerAttendee(availableSeats);
                break;
            case 2:
                cancelRegistration(maxSeats, availableSeats);
                break;
            case 3:
                cout << "Final available seats: " << availableSeats << endl;
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (menuChoice != 3);
    return 0;                                            // Ends the program successfully
}                                                        // Ends the main function

void displayMenu() {
    cout << "\nWorkshop Registration Menu:" << endl;
    cout << "1. Register Attendee" << endl;
    cout << "2. Cancel Registration" << endl;
    cout << "3. Exit" << endl;
}

void registerAttendee(int &availableSeats) {
    if (availableSeats > 0) {
        availableSeats--;
        cout << "Attendee registered successfully." << endl;
    } else {
        cout << "Sorry, the workshop is full." << endl;
    }
}

void cancelRegistration(int maxSeats, int &availableSeats) {
    if (availableSeats < maxSeats) {
        availableSeats++;
        cout << "Registration canceled successfully." << endl;
    } else {
        cout << "No registration to cancel." << endl;
    }
}

/*
Analysis

Test cases (expected final availability / observed final availability):
1. Capacity 1; register twice; cancel twice; exit: 1 / 1.
   The second registration is rejected because the workshop is full and the
   second cancellation is not made because no registration remains for it to cancel.
2. Capacity 2; register once; cancel once; exit: 2 / 2.
3. Capacity 2; enter invalid menu option 9; exit: 2 / 2.
   The invalid option does not change the available-seat count.

maxSeats does not need a reference parameter because cancelRegistration only
checks its value; it never changes the workshop's maximum capacity. On the other hand, availableSeats is
 passed by reference because registering or cancelling must permanently update the value stored in main.
*/