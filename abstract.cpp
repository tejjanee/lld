#include <iostream>
using namespace std;

class Database {
private:
    // The constructor is private, so main() cannot create a Database directly.
    Database() {
        cout << "Database created\n";
    }

public:
    // This function creates the Database the first time it is called.
    // On later calls, it returns the same Database.
    static Database& getInstance() {
        static Database obj;
        return obj;
    }

    void connect() {
        cout << "Connected to database\n";
    }
};

int main() {
    // Ask the class for its Database object instead of creating one directly.
    Database& firstDatabase = Database::getInstance();
    Database& secondDatabase = Database::getInstance();

    firstDatabase.connect();
    secondDatabase.connect();

    // This prints 1 because both names refer to the same object.
    cout << (&firstDatabase == &secondDatabase) << '\n';
}