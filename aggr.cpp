#include <iostream>
using namespace std;

class Teacher {
public:
    string name;

    Teacher(string n) {
        name = n;
    }
};

class Department {
public:
    Teacher* teacher;

    Department(Teacher* t) {
        teacher = t;
    }

    void display() {
        cout << teacher->name;
    }
};

int main() {
    Teacher t("Rahul");

    Department d(&t);

    d.display();
}