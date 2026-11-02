#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Doctor;
class Patient;
class Room {
    string number;
    int floor;
    public:
    Room(string number,int floor){
        this->number=number;
        this->floor=floor;
    }
    string getNumber(){
        return this->number;
    }

};
class Appointment{
    public:
    Doctor *doctor;
    Patient *patient;
    Room* room;
    string time;
    public:
    Appointment(Doctor*doctor,Patient*patient,Room* room,string time);
    
    Doctor* getDoctor(){
        return this->doctor;
    }
    Patient* getPatient(){
        return this->patient;
    }
    string getTime(){
        return this->time;
    }
    Room* getRoom(){
        return this->room;
    }
};
class Doctor{
    string name;
    string specialization;
    vector<Appointment*>appointments;
    public:
    Doctor(string name, string specialization){
        this->name=name;
        this->specialization =specialization;
    }
    string getName(){
        return this->name;
    }    
    string getSpecialization(){
        return this->specialization;
    }
    void addAppointment(Appointment*appt){
        this->appointments.push_back(appt);
    }
    
    vector<Appointment*> getAppointments(){
        vector<Appointment*>ans;
        for(auto it:appointments){
            if(it->doctor->name == this->name){
                ans.push_back(it);
            }
        }
        return ans;

    }
    vector<Patient*>getPatients(){
        vector<Patient*> ans;
        for(auto it:appointments){
            if(it->doctor->name == this->name){
                ans.push_back(it->patient);
            }
        }
        return ans;
    }

};
class Patient{
    public:
    string name;
    vector<Appointment*>appointments;
    public:
    Patient(string name){
        this->name=name;
    }
    string getName(){
        return this->name;
    }
    void addAppointment(Appointment*appt){
        this->appointments.push_back(appt);
    }
    vector<Doctor*> getDoctors(){
        vector<Doctor*> ans;
        for(auto it:appointments){
            if(it->patient->name == this->name){
                ans.push_back(it->doctor);
            }
        }
        return ans;
    }

};

// Constructor definition moved here
Appointment::Appointment(Doctor* doctor, Patient* patient, Room* room, string time) {
    this->doctor = doctor;
    this->patient = patient;
    this->room = room;
    this->time = time;

    doctor->addAppointment(this);
    patient->addAppointment(this);
}
int main() {
    Doctor drSmith("Dr. Smith", "Cardiology");
    Doctor drPatel("Dr. Patel", "Neurology");

    Patient alice("Alice");
    Patient bob("Bob");

    Room room101("101", 1);
    Room room205("205", 2);

    Appointment a1(&drSmith, &alice, &room101, "9:00 AM");
    Appointment a2(&drSmith, &bob, &room101, "10:00 AM");
    Appointment a3(&drPatel, &alice, &room205, "2:00 PM");

    cout << drSmith.getName() << "'s patients:" << endl;
    for (auto* p : drSmith.getPatients())
        cout << "  - " << p->getName() << endl;

    cout << alice.getName() << "'s doctors:" << endl;
    for (auto* d : alice.getDoctors())
        cout << "  - " << d->getName() << " (" << d->getSpecialization() << ")" << endl;

    cout << drSmith.getName() << "'s schedule:" << endl;
    for (auto* a : drSmith.getAppointments()){
        cout << "  - " << a->getTime() << " with " << a->getPatient()->getName()
             << " in Room " << a->getRoom()->getNumber() << endl;
            }

    return 0;
}