#include <iostream>
#include <string>
using namespace std;

class publication {
public:
    string title;
    float price;

    // Method to get data for publication
    void getdata() {
        cout << "\nEnter title: ";
        cin >> title;
        if (title.empty()) 
            throw title;

        cout << "Enter price: ";
        cin >> price;
        if (price <= 0.0) 
            throw price;
    }
};

class book : public publication {
public:
    int page_count;

    // Method to get page count and handle exceptions
    void getPageCount() {
        try {
            getdata();
            cout << "Enter page count: ";
            cin >> page_count;
            if (page_count <= 0) 
                throw page_count;
            display();
        } catch (...) {
            cout << "Invalid data entered for book.\n";
            setdefault();
            display();
        }
    }

    // Method to display book details
    void display() {
        cout << "\nBook Details:\n";
        cout << "Title: " << title << "\t";
        cout << "Price: " << price << "\t";
        cout << "Page Count: " << page_count << endl;
    }

    // Method to set default values for book
    void setdefault() {
        title = "0";
        price = 0.0;
        page_count = 0;
    }
};

class tape : public publication {
public:
    float play_time;

    // Method to get play time and handle exceptions
    void getPlayTime() {
        try {
            getdata();
            cout << "Enter play time in minutes: ";
            cin >> play_time;
            if (play_time <= 0.0) 
                throw play_time;
            display();
        } catch (...) {
            cout << "Invalid data entered for tape.\n";
            setdefault();
            display();
        }
    }

    // Method to display tape details
    void display() {
        cout << "\nTape Details:\n";
        cout << "Title: " << title << "\t";
        cout << "Price: " << price << "\t";
        cout << "Play Time: " << play_time << " minutes" << endl;
    }

    // Method to set default values for tape
    void setdefault() {
        title = "0";
        price = 0.0;
        play_time = 0.0;
    }
};

int main() {
    book b;
    tape t;

    // Get and display book details
    b.getPageCount();

    // Get and display tape details
    t.getPlayTime();

    return 0;
}