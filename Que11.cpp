11. Student Class with File Handling#include <iostream>
#include <fstream>
using namespace std;

class Student {
    int roll;
    string name;
    string clas;
    int year;
    int total;
public:
    void input() {
        cout << "Enter Roll No: ";
        cin >> roll;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Class: ";
        cin >> clas;
        cout << "Enter Year: ";
        cin >> year;
        cout << "Enter Total Marks: ";
        cin >> total;
    }
    void output() {
        cout << "Roll: " << roll << ", Name: " << name << ", Class: " << clas
             << ", Year: " << year << ", Total: " << total << endl;
    }
    void writeToFile() {
        ofstream out("students.txt", ios::app);
        out << roll << ' ' << name << ' ' << clas << ' ' << year << ' ' << total << endl;
        out.close();
    }
    static void readFromFile() {
        ifstream in("students.txt");
        int roll, year, total;
        string name, clas;
        while (in >> roll >> name >> clas >> year >> total) {
            cout << "Roll: " << roll << ", Name: " << name << ", Class: " << clas
                 << ", Year: " << year << ", Total: " << total << endl;
        }
        in.close();
    }
};

int main() {
    int choice;
    do {
        cout << "
Menu:
1. Add Student
2. Show All Students
3. Exit
Choice: ";
        cin >> choice;
        if (choice == 1) {
            Student s;
            s.input();
            s.writeToFile();
        } else if (choice == 2) {
            Student::readFromFile();
        } else if (choice != 3) {
            cout << "Invalid choice.
";
        }
    } while (choice != 3);
    return 0;
}