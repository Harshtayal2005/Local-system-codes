#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;

public:
    Person(const string& n) : name(n) {}

    void display() {
        cout << "Name: " << name << endl;
    }
};

class Student : public Person {
protected:
    int studentID;

public:
    Student(const string& n, int id) : Person(n), studentID(id) {}

    void display() {
        Person::display();
        cout << "Student ID: " << studentID << endl;
    }
};

class GraduateStudent : public Student {
private:
    string researchTopic;

public:
    GraduateStudent(const string& n, int id, const string& topic) : Student(n, id), researchTopic(topic) {}

    void display() {
        Student::display();
        cout << "Research Topic: " << researchTopic << endl;
    }
};

int main() {
    GraduateStudent gradStudent("Alice", 12345, "Machine Learning");
    cout << "Graduate Student Information:" << endl;
    gradStudent.display();

    return 0;
}