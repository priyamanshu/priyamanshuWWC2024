#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Patient structure
struct Patient {
    string name;
    int triagePriority;  // 1 = Life-threatening, 2 = Severe, 3 = Moderate, 4 = Minor
    int severity;
    int arrivalTime;

    Patient(string name, int triagePriority, int severity, int arrivalTime)
        : name(name), triagePriority(triagePriority), severity(severity), arrivalTime(arrivalTime) {}
};

// Comparator for priority queue
struct ComparePatient {
    bool operator()(const Patient& p1, const Patient& p2) {
        // Higher triage priority comes first
        if (p1.triagePriority != p2.triagePriority)
            return p1.triagePriority > p2.triagePriority;
        // If triage priority is the same, higher severity comes first
        if (p1.severity != p2.severity)
            return p1.severity < p2.severity;
        // If severity is the same, earlier arrival time comes first
        return p1.arrivalTime > p2.arrivalTime;
    }
};

int main() {
    // Priority queue to manage patients
    priority_queue<Patient, vector<Patient>, ComparePatient> patientQueue;

    int currentTime = 0; // Keeps track of arrival order

    // Adding some initial patients
    patientQueue.emplace("Alice", 1, 90, currentTime++);
    patientQueue.emplace("Bob", 2, 80, currentTime++);
    patientQueue.emplace("Charlie", 3, 70, currentTime++);

    // Adding a new patient dynamically
    cout << "A new patient arrives dynamically: " << endl;
    patientQueue.emplace("David", 1, 95, currentTime++);

    cout << "\nPatients sorted by priority:\n";
    cout << left << setw(10) << "Name" << setw(15) << "Triage Priority"
         << setw(10) << "Severity" << "Arrival Time" << endl;
    cout << "-------------------------------------------------\n";

    while (!patientQueue.empty()) {
        Patient patient = patientQueue.top();
        patientQueue.pop();

        cout << left << setw(10) << patient.name
             << setw(15) << patient.triagePriority
             << setw(10) << patient.severity
             << patient.arrivalTime << endl;
    }

    return 0;
}
