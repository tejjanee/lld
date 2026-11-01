#include <iostream>
using namespace std;

class Room {
public:
    Room() {
        cout << "Room created\n";
    }

    ~Room() {
        cout << "Room destroyed\n";
    }
};

class House {
private:
    Room room;

public:
    House() {
        cout << "House created\n";
    }
};

int main() {
    {
        House h;
    }
}