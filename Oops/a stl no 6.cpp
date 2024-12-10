#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Class to represent an Item
class Item {
public:
    char name[10];
    int quantity;
    int cost;
    int code;

    // Overloaded equality operator for searching by code
    bool operator==(const Item& i1) const {
        return code == i1.code;
    }
};

// Global vector to store items
vector<Item> o1;

// Function declarations
void print(Item& i1);
void display();
void insert();
void search();
void dlt();
bool compare(const Item& i1, const Item& i2);

// Main function
int main() {
    int ch;
    do {
        cout << "\n*Menu*\n"
             << "1. Insert\n"
             << "2. Display\n"
             << "3. Search\n"
             << "4. Sort\n"
             << "5. Delete\n"
             << "6. Exit\n"
             << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:
                sort(o1.begin(), o1.end(), compare);
                display();
                break;
            case 5:
                dlt();
                break;
            case 6:
                exit(0);
            default:
                cout << "\nInvalid choice. Please try again.";
        }
    } while (ch != 6);

    return 0;
}

// Function to insert a new item
void insert() {
    Item i1;
    cout << "\nEnter Item Name: ";
    cin >> i1.name;
    cout << "Enter Item Quantity: ";
    cin >> i1.quantity;
    cout << "Enter Item Cost: ";
    cin >> i1.cost;
    cout << "Enter Item Code: ";
    cin >> i1.code;
    o1.push_back(i1);
    cout << "\nItem added successfully.";
}

// Function to display all items
void display() {
    if (o1.empty()) {
        cout << "\nNo items to display.";
    } else {
        cout << "\nItem List:";
        for_each(o1.begin(), o1.end(), print);
    }
}

// Function to print details of a single item
void print(Item& i1) {
    cout << "\n\nItem Name: " << i1.name
         << "\nItem Quantity: " << i1.quantity
         << "\nItem Cost: " << i1.cost
         << "\nItem Code: " << i1.code;
}

// Function to search for an item by code
void search() {
    Item i1;
    cout << "\nEnter Item Code to search: ";
    cin >> i1.code;
    vector<Item>::iterator p = find(o1.begin(), o1.end(), i1);
    if (p == o1.end()) {
        cout << "\nItem not found.";
    } else {
        cout << "\nItem found.\n"
             << "Item Name: " << p->name
             << "\nItem Quantity: " << p->quantity
             << "\nItem Cost: " << p->cost
             << "\nItem Code: " << p->code << endl;
    }
}

// Function to delete an item by code
void dlt() {
    Item i1;
    cout << "\nEnter Item Code to delete: ";
    cin >> i1.code;
    vector<Item>::iterator p = find(o1.begin(), o1.end(), i1);
    if (p == o1.end()) {
        cout << "\nItem not found.";
    } else {
        o1.erase(p);
        cout << "\nItem deleted successfully.";
    }
}

// Comparator function for sorting items by cost
bool compare(const Item& i1, const Item& i2) {
    return i1.cost < i2.cost;
}