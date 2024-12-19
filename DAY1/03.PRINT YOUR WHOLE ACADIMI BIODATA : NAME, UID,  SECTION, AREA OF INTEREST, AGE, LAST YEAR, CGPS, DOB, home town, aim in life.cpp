#include <iostream>
using namespace std;

int main() {
    string name, uid, area_of_interest, dob, home_town, aim_in_life;
    char section;
    int age, last_year;
    float cgpa;

    // Taking input from the user
    cout << "Enter your Name: ";
    getline(cin, name);

    cout << "Enter your UID: ";
    getline(cin, uid);

    cout << "Enter your Section: ";
    cin >> section;

    cout << "Enter your Area of Interest: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, area_of_interest);

    cout << "Enter your Age: ";
    cin >> age;

    cout << "Enter your Last Academic Year: ";
    cin >> last_year;

    cout << "Enter your CGPA: ";
    cin >> cgpa;

    cout << "Enter your Date of Birth (e.g., 01-Jan-2003): ";
    cin.ignore(); // Clear the input buffer
    getline(cin, dob);

    cout << "Enter your Home Town: ";
    getline(cin, home_town);

    cout << "Enter your Aim in Life: ";
    getline(cin, aim_in_life);

    // Displaying the biodata
    cout << "\n---- Academic Biodata ----" << endl;
    cout << "Name: " << name << endl;
    cout << "UID: " << uid << endl;
    cout << "Section: " << section << endl;
    cout << "Area of Interest: " << area_of_interest << endl;
    cout << "Age: " << age << endl;
    cout << "Last Year: " << last_year << endl;
    cout << "CGPA: " << cgpa << endl;
    cout << "Date of Birth: " << dob << endl;
    cout << "Home Town: " << home_town << endl;
    cout << "Aim in Life: " << aim_in_life << endl;

    return 0;
}
