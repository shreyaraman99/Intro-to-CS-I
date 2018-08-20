
#include <iostream>
using namespace std;

int main() {
    
    string destination;
    int zones = 0;
    int age = 0;
    string student;
    
    cout << "Age of rider: ";
    cin >> age;
    cout << "Student? (y/n): ";
    cin >> student;
    cin.ignore(10000, '\n'); // deletes the rest of the input line
    cout << "Destination: ";
    getline(cin, destination);
    cout << "Number of zone boundaries crossed: ";
    cin >> zones;
    
    cout << "---" << endl;
    
    if (age < 0) { // if the user entered a negative number
        cout << "The age must not be negative" << endl;
        return 1;
    } else if (student != "y" && student != "n") { // if the user entered a character than is not y or n
        cout << "You must enter y or n" << endl;
        return 1;
    } else if (destination == "") { // if the user did not enter a destination
        cout << "You must enter a destination" << endl;
        return 1;
    } else if (zones < 0) { // if the user entered a negative number
        cout << "The number of zone boundaries crossed must not be negative" << endl;
        return 1;
    }
    
    double fare = 0.0;
    
    if (age >= 65 && zones == 0) {
        fare = 0.45;
    } else if ( (age < 18 && zones <= 1) || (student == "y" && zones <=1) ) { // under 18 and crossing 0 or 1 zone boundaries OR a student crossing 0 or 1 zone boundaries
        fare = 0.65;
    } else if (age >= 65 && zones >= 1) { // senior and crossing at least 1 boundary
        fare = 0.55 + zones * 0.25;
    } else { // every other situation
        fare = 1.35 + zones * 0.55;
    }
    
    
    
    cout.setf(ios::fixed);
    cout.precision(2); // makes the fare amount have two spots after the decimal place
    cout << "The fare to " << destination << " is $" << fare << endl;
}

