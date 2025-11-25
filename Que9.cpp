9. Person, Student, Employee (Polymorphism Example)#include <iostream>
using namespace std;

class Person {
protected:
    string name;
public:
    virtual void input() {
        cout << "Enter name: ";
        cin >> name;
    }
    virtual void display() {
        cout << "Name: " << name << endl;
    }
};

class Student : public Person {
    string course;
    int marks;
    int year;
public:
    void input() {
        Person::input();
        cout << "Enter course: ";
        cin >> course;
        cout << "Enter marks: ";
        cin >> marks;
        cout << "Enter year: ";
        cin >> year;
    }
    void display() {
        Person::display();
        cout << "Course: " << course << ", Marks: " << marks << ", Year: " << year << endl;
    }
};

class Employee : public Person {
    string department;
    int salary;
public:
    void input() {
        Person::input();
        cout << "Enter department: ";
        cin >> department;
        cout << "Enter salary: ";
        cin >> salary;
    }
    void display() {
        Person::display();
        cout << "Department: " << department << ", Salary: " << salary << endl;
    }
};

int main() {
    Person* p[2];
    Student s;
    Employee e;

    cout << "Enter Student details:
";
    p[0] = &s;
    p[0]->input();

    cout << "Enter Employee details:
";
    p[1] = &e;
    p[1]->input();

    cout << "
Displaying Student and Employee details using polymorphism:
";
    for(int i=0; i<2; i++)
        p[i]->display();

    return 0;
}