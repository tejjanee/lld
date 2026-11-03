
#include <iostream>
#include <string>
using namespace std;

class Profile {
private:
    string fullName;

public:
    explicit Profile(string name) : fullName(move(name)) {}

    const string& getFullName() const {
        return fullName;
    }
};

class Registration {
private:
    string licensePlate;

public:
    explicit Registration(string plate) : licensePlate(move(plate)) {}

    const string& getLicensePlate() const {
        return licensePlate;
    }
};

class Vehicle {
private:
    Registration registration;

public:
    explicit Vehicle(string plate) : registration(move(plate)) {}

    const Registration& getRegistration() const {
        return registration;
    }
};

class Driver {
private:
    Profile profile;
    Vehicle vehicle;

public:
    Driver(string name, string plate)
        : profile(move(name)), vehicle(move(plate)) {}

    const Profile& getProfile() const {
        return profile;
    }

    const Vehicle& getVehicle() const {
        return vehicle;
    }
};

class ContactInfo {
private:
    string phoneNumber;

public:
    explicit ContactInfo(string phone) : phoneNumber(move(phone)) {}

    const string& getPhoneNumber() const {
        return phoneNumber;
    }
};

class Passenger {
private:
    ContactInfo contactInfo;

public:
    explicit Passenger(string phone) : contactInfo(move(phone)) {}

    const ContactInfo& getContactInfo() const {
        return contactInfo;
    }
};

class Ride {
private:
    Driver driver;
    Passenger passenger;

public:
    Ride(string driverName, string driverPlate, string passengerPhone)
        : driver(move(driverName), move(driverPlate)),
          passenger(move(passengerPhone)) {}

    string getDriverName() const {
        return driver.getProfile().getFullName();
    }

    string getDriverLicensePlate() const {
        return driver.getVehicle().getRegistration().getLicensePlate();
    }

    string getPassengerPhoneNumber() const {
        return passenger.getContactInfo().getPhoneNumber();
    }
};

class NotificationService {
public:
    void sendRideUpdate(const Ride& ride) const {
        const string driverName = ride.getDriverName();
        const string plate = ride.getDriverLicensePlate();
        const string phone = ride.getPassengerPhoneNumber();

        cout << "SMS to: " << phone << endl;
        cout << "Your driver " << driverName
             << " is arriving in vehicle " << plate << endl;
    }
};

int main() {
    Ride ride("Rahul Sharma", "KA-03-AB-1234", "9876543210");

    NotificationService notification;
    notification.sendRideUpdate(ride);

    return 0;
}
