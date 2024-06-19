#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
    string name;
    int age;

public:
    Person(const string &name, int age) : name(name), age(age) {}

    const string &getName() const { return name; }
    int getAge() const { return age; }
};

class Student public Person
{
private:
    string subject;
    int grade;

public:
    Student(const string &subject, int grade) : subject(subject), grade(grade) {}
    void show() const
    {
        cout << "Name:" << name << endl;
        cout << "Age:" << age << endl;
        cout << "Subject:" << subject << endl;
        cout << "Grade:" << grade << endl;
    }
};