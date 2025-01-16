//Catherine Nicholson
//COSC 1437 
//Program Set 3-Extra credit#2
//References: Gaddis Book chapter 20 section 20.4: Fibonacci numbers since they are very similar.

#include <iostream>
#include<iomanip>
using namespace std;

//function prototype
int lucas(int n);


int main() {
    char choice;//user input to run the program again or not
    do {
        int n;
        cout << "Enter a number in the range [1, 500]: ";
        cin >> n;

        // Check for valid input
        //must choose between 1-500,allows you to renter a valid number
        while (cin.fail() || n < 1 || n > 500) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), ' ');
            cout << "Invalid input. Enter a number in the range [1, 500]: ";
            cin >> n;
            cout << endl;
        }

        // Print Lucas numbers aligned right, allows 5 numbers a line
        for (int i = 0; i < n; i++) {
            cout << right << setw(5) << lucas(i) << " ";
            if ((i + 1) % 5 == 0)
                cout << endl;
        }
        if (n % 5 != 0)
            cout << endl;

        // Ask if user wants to run the program again
        //user can enter Y,y,N or n
        
        cout << "Do you want to run the program again? (y/n): ";
        cin >> choice;
        cout << endl;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
// Recursive function to calculate Lucas numbers
//program 20.3 in chapter 20
int lucas(int n) {
    if (n == 0)
        return 2;// base case
    else if (n == 1)
        return 1; //base case
    else
        return lucas(n - 1) + lucas(n - 2);//recursive case
}
