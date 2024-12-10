#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    // Define a map to store state names as keys and population as values
    typedef map<string, int> mapType;
    mapType populationMap;

    // Inserting population data for different states
    populationMap.insert(pair<string, int>("Maharashtra", 7026357));
    populationMap.insert(pair<string, int>("Rajasthan", 6578936));
    populationMap.insert(pair<string, int>("Karnataka", 6678993)); // Corrected spelling
    populationMap.insert(pair<string, int>("Punjab", 5789032));
    populationMap.insert(pair<string, int>("West Bengal", 6676291));

    // Display the size of the map
    cout << "======== Population of States in India ==========\n";
    cout << "\nSize of Population Map: " << populationMap.size() << "\n";

    // Input state name from user
    string state_name;
    cout << "\nEnter the name of the state: ";
    cin >> state_name;

    // Find the population of the entered state
    mapType::iterator iter = populationMap.find(state_name);
    if (iter != populationMap.end()) {
        // If the state is found in the map
        cout << state_name << "'s population is " << iter->second << "\n";
    } else {
        // If the state is not found
        cout << "Key is not in Population Map\n";
    }

    // Clear the map
    populationMap.clear();
    cout << "\nPopulation Map cleared. Size now: " << populationMap.size() << "\n";

    return 0;
}