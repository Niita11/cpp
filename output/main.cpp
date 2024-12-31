#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class Employee {
private:
    int id;
    string name;
    int age;
    string position;
    double salary;

public:
    // Function to input employee details
    void inputDetails() {
        cout << "Enter Employee ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter Position: ";
        getline(cin, position);
        cout << "Enter Salary: ";
        cin >> salary;
    }

    // Function to display employee details
    void displayDetails() const {
        cout << left << setw(10) << id << setw(20) << name << setw(10) << age
             << setw(20) << position << setw(10) << salary << endl;
    }

    // Function to write employee data to a file
    void writeToFile() const {
        ofstream file("employees.txt", ios::app);
        if (file) {
            file << id << "\t" << name << "\t" << age << "\t" << position << "\t" << salary << endl;
            file.close();
        } else {
            cerr << "Error: Unable to open file!" << endl;
        }
    }

    // Function to read employee data from a file
    static void readFromFile() {
        ifstream file("employees.txt");
        if (file) {
            cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(10) 
                 << "Age" << setw(20) << "Position" << setw(10) << "Salary" << endl;
            cout << "------------------------------------------------------------------" << endl;
            string line;
            while (getline(file, line)) {
                cout << line << endl;
            }
            file.close();
        } else {
            cerr << "Error: Unable to open file!" << endl;
        }
    }
};

// Main menu function
void menu() {
    cout << "=====================================" << endl;
    cout << "      Employee Management System     " << endl;
    cout << "=====================================" << endl;
    cout << "1. Add Employee" << endl;
    cout << "2. View All Employees" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    Employee emp;
    int choice;

    do {
        menu();
        cin >> choice;

        switch (choice) {
            case 1:
                emp.inputDetails();
                emp.writeToFile();
                cout << "Employee details saved successfully!" << endl;
                break;

            case 2:
                Employee::readFromFile();
                break;

            case 3:
                cout << "Exiting the system. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again!" << endl;
        }

        cout << endl;
    } while (choice != 3);

    return 0;
}