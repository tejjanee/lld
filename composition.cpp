#include <iostream>

using namespace std;

class SeatValidator {
public:
    bool isAvailable(const string& eventId, const string& seatNumber) {
        cout << "Checking seat " << seatNumber << " for event " << eventId << endl;
        return true; // Simulated: seat is available
    }
};

class PaymentProcessor {
public:
    bool charge(const string& email, double amount) {
        cout << "Charging $" << amount << " to " << email << endl;
        return true; // Simulated: payment succeeds
    }
};

class QRCodeGenerator {
public:
    string generate(const string& eventId, const string& seatNumber) {
        string qrCode = "QR-" + eventId + "-" + seatNumber;
        cout << "Generated QR code: " << qrCode << endl;
        return qrCode;
    }
};

class EmailService {
public:
    void sendConfirmation(const string& email, const string& qrCode) {
        cout << "Sending confirmation to " << email << " with code " << qrCode << endl;
    }
};

class TicketBookingService {
public:
    bool bookTicket(const string& eventId, const string& seatNumber,
                    const string& email, double amount,
                    SeatValidator& validator, PaymentProcessor& payment,
                    QRCodeGenerator& qrGenerator, EmailService& emailService) {
        if (!validator.isAvailable(eventId, seatNumber)) {
            cout << "Seat not available." << endl;
            return false;
        }

        if (!payment.charge(email, amount)) {
            cout << "Payment failed." << endl;
            return false;
        }

        string qrCode = qrGenerator.generate(eventId, seatNumber);
        emailService.sendConfirmation(email, qrCode);

        cout << "Booking confirmed!" << endl;
        return true;
    }
};

int main() {
    TicketBookingService bookingService;

    // All dependencies are created externally and passed in
    SeatValidator validator;
    PaymentProcessor payment;
    QRCodeGenerator qrGenerator;
    EmailService emailService;

    bookingService.bookTicket("CONF-2025", "A12", "alice@example.com",
        99.99, validator, payment, qrGenerator, emailService);

    return 0;
}