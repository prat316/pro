#include <iostream>
using namespace std;

class info {
    int roll_no;

public:
    // Default constructor
    info() : roll_no(1) {}

    // Destructor
    ~info() {
        cout << "\nDestructor called from info class\n";
    }

    // Copy constructor
    info(const info &i) : roll_no(i.roll_no) {}

    // Friend class declaration
    friend class student;
};

class student {
    string name;

public:
    // Default constructor
    student() : name("Jishu") {}

    // Destructor
    ~student() {
        cout << "\nDestructor called from student class\n";
    }

    // Copy constructor
    student(const student &s) : name(s.name) {}

    // Create student details
    void create(info &i) {
        cout << "\nEnter your name: ";
        cin >> name;
        cout << "Enter your roll number: ";
        cin >> i.roll_no;
    }

    // Display student details
    void display(const info &i) const {
        cout << "\nYour name: " << name << endl;
        cout << "Your roll number: " << i.roll_no << endl;
    }

    // Static member to count objects
    static int cnt;

    // Increment object count
    inline static void objcount() {
        cnt++;
    }

    // Display object count
    inline static void objcountshow() {
        cout << cnt;
    }
};

// Initialize static member
int student::cnt = 0;

int main() {
    cout << "\nDefault constructor\n";
    info in1;
    student st1;

    st1.display(in1);

    cout << "+++++++++++++++++++++++++++++++\n";
    cout << "Create database and Display database\n";

    int n;
    cout << "\nEnter number of students' details: ";
    cin >> n;

    // Dynamically allocate memory for info and student objects
    info *i1 = new info[n];
    student *s1 = new student[n];

    cout << "\nCreate database\n";
    for (int k = 0; k < n; k++) {
        s1[k].create(i1[k]);
        student::objcount();
    }

    cout << "++++++++++++++++++++++++++++++++\n";
    cout << "Total number of objects created: ";
    student::objcountshow();
    cout << endl << "+++++++++++++++++++++++++++++\n";

    cout << "\nDisplay database\n";
    for (int k = 0; k < n; k++) {
        s1[k].display(i1[k]);
    }

    cout << "+++++++++++++++++++++++++++++++\n";

    cout << "\nCopy constructor\n";
    info in2;
    student st2;

    st2.create(in2);

    // Create copies using copy constructors
    student st3(st2);
    info in3(in2);

    cout << "+++++++++++++++++++++++++++++++\n";
    cout << "\nDisplay data from copy constructor\n";
    st3.display(in3);

    cout << "+++++++++++++++++++++++++++++\n";

    // Free dynamically allocated memory
    delete[] i1;
    delete[] s1;

    return 0;
}