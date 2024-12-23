#include <iostream>
#include <string>

using namespace std;

// Node structure for a seat
struct Seat {
    int seatNumber;
    bool isBooked;
    Seat* next;

    Seat(int number) : seatNumber(number), isBooked(false), next(nullptr) {}
};

// Node structure for a compartment̀̀
struct Compartment {
    string compartmentID;
    Seat* seats;
    int totalSeats;
    Compartment* next;

    Compartment(string id, int total) : compartmentID(id), seats(nullptr), totalSeats(total), next(nullptr) {
        for (int i = 1; i <= totalSeats; i++) {
            Seat* newSeat = new Seat(i);
            if (!seats) {
                seats = newSeat;
            } else {
                Seat* temp = seats;
                while (temp->next) temp = temp->next;
                temp->next = newSeat;
            }
        }
    }
};

// Node structure for a train
struct Train {
    string trainID;
    Compartment* compartments;
    Train* next;

    Train(string id) : trainID(id), compartments(nullptr), next(nullptr) {}
};

// Train Reservation System class
class TrainReservationSystem {
private:
    Train* trains;

    Compartment* findCompartment(Train* train, const string& compID) {
        Compartment* temp = train->compartments;
        while (temp) {
            if (temp->compartmentID == compID) return temp;
            temp = temp->next;
        }
        return nullptr;
    }

    Train* findTrain(const string& trainID) {
        Train* temp = trains;
        while (temp) {
            if (temp->trainID == trainID) return temp;
            temp = temp->next;
        }
        return nullptr;
    }

public:
    TrainReservationSystem() : trains(nullptr) {}

    // Add a new train
    void addTrain(const string& trainID) {
        Train* newTrain = new Train(trainID);
        if (!trains) {
            trains = newTrain;
        } else {
            Train* temp = trains;
            while (temp->next) temp = temp->next;
            temp->next = newTrain;
        }
        cout << "Train " << trainID << " added.\n";
    }

    // Add a new compartment to a train
    void addCompartment(const string& trainID, const string& compID, int totalSeats) {
        Train* train = findTrain(trainID);
        if (!train) {
            cout << "Train not found.\n";
            return;
        }

        Compartment* newCompartment = new Compartment(compID, totalSeats);
        if (!train->compartments) {
            train->compartments = newCompartment;
        } else {
            Compartment* temp = train->compartments;
            while (temp->next) temp = temp->next;
            temp->next = newCompartment;
        }
        cout << "Compartment " << compID << " with " << totalSeats << " seats added to Train " << trainID << ".\n";
    }

    // Book a seat in a specific compartment
    void bookSeat(const string& trainID, const string& compID, int seatNumber) {
        Train* train = findTrain(trainID);
        if (!train) {
            cout << "Train not found.\n";
            return;
        }

        Compartment* compartment = findCompartment(train, compID);
        if (!compartment) {
            cout << "Compartment not found.\n";
            return;
        }

        Seat* temp = compartment->seats;
        while (temp) {
            if (temp->seatNumber == seatNumber) {
                if (temp->isBooked) {
                    cout << "Seat " << seatNumber << " is already booked.\n";
                } else {
                    temp->isBooked = true;
                    cout << "Seat " << seatNumber << " in Compartment " << compID << " of Train " << trainID << " booked successfully.\n";
                }
                return;
            }
            temp = temp->next;
        }
        cout << "Seat " << seatNumber << " not found.\n";
    }

    // Cancel a booking
    void cancelSeat(const string& trainID, const string& compID, int seatNumber) {
        Train* train = findTrain(trainID);
        if (!train) {
            cout << "Train not found.\n";
            return;
        }

        Compartment* compartment = findCompartment(train, compID);
        if (!compartment) {
            cout << "Compartment not found.\n";
            return;
        }

        Seat* temp = compartment->seats;
        while (temp) {
            if (temp->seatNumber == seatNumber) {
                if (!temp->isBooked) {
                    cout << "Seat " << seatNumber << " is not booked.\n";
                } else {
                    temp->isBooked = false;
                    cout << "Seat " << seatNumber << " in Compartment " << compID << " of Train " << trainID << " canceled successfully.\n";
                }
                return;
            }
            temp = temp->next;
        }
        cout << "Seat " << seatNumber << " not found.\n";
    }

    // Check availability of seats in a compartment
    void checkAvailability(const string& trainID, const string& compID) {
        Train* train = findTrain(trainID);
        if (!train) {
            cout << "Train not found.\n";
            return;
        }

        Compartment* compartment = findCompartment(train, compID);
        if (!compartment) {
            cout << "Compartment not found.\n";
            return;
        }

        Seat* temp = compartment->seats;
        cout << "Available seats in Compartment " << compID << " of Train " << trainID << ": ";
        bool available = false;
        while (temp) {
            if (!temp->isBooked) {
                cout << temp->seatNumber << " ";
                available = true;
            }
            temp = temp->next;
        }
        if (!available) cout << "None";
        cout << "\n";
    }
};

int main() {
    TrainReservationSystem system;

    system.addTrain("Train1");
    system.addCompartment("Train1", "A", 5);
    system.addCompartment("Train1", "B", 3);

    system.bookSeat("Train1", "A", 1);
    system.bookSeat("Train1", "A", 2);
    system.bookSeat("Train1", "B", 1);

    system.checkAvailability("Train1", "A");
    system.cancelSeat("Train1", "A", 1);
    system.checkAvailability("Train1", "A");

    return 0;
}
