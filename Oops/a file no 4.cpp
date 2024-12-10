#include <string>
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    // Write to a file
    ofstream Sfilew("swapnil.txt"); // Creating and opening "swapnil.txt"
    if (Sfilew.is_open()) {
        Sfilew << "Welcome to file \nHere you can write"; // Writing to the file
        Sfilew.close(); // Always close the file
        cout << "File written successfully.\n";
    } else {
        cout << "Unable to open the file for writing.\n";
    }

    string mytext; // Variable to hold the file content
    // Read from the file
    ifstream Sfiler("swapnil.txt"); // Opening "swapnil.txt" for reading
    if (Sfiler.is_open()) {
        cout << "\nReading from file:\n";
        while (getline(Sfiler, mytext)) {
            cout << mytext << endl; // Output each line
        }
        Sfiler.close(); // Always close the file
    } else {
        cout << "Unable to open the file for reading.\n";
    }

    return 0;
}