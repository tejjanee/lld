#include <iostream>
using namespace std;

class Computer {
public:
    int ram;
    int storage;
    string processor;

    void show() {
        cout << ram << " GB RAM\n";
        cout << storage << " GB Storage\n";
        cout << processor << endl;
    }
};

class ComputerBuilder {
private:
    Computer c;

public:
    ComputerBuilder& setRAM(int r) {
        c.ram = r;
        // return *this;
    }

    ComputerBuilder& setStorage(int s) {
        c.storage = s;
        // return *this;
    }

    ComputerBuilder& setProcessor(string p) {
        c.processor = p;
        // return *this;
    }

    Computer build() {
        return c;
    }
};

int main() {
    // Computer c = ComputerBuilder()
    //                 .setRAM(16)
    //                 .setStorage(512)
    //                 .setProcessor("Intel")
    //                 .build();
    ComputerBuilder builder;

builder.setRAM(16);
builder.setStorage(512);
builder.setProcessor("Intel");

Computer c = builder.build();

    c.show();
}