#include <iostream>
#include <string>
using namespace std;

void triageSystem() {
    cout << "=== Hospital Expert System: Patient Triage Assistant ===\n";

    string name;
    int age;
    char input;
    bool chest_pain, short_breath, bleeding, high_fever, injury, dizziness, stomach_pain;

    cout << "Enter Patient Name: ";
    getline(cin, name);

    cout << "Enter Age: ";
    cin >> age;

    cout << "\nSelect Symptoms (Y/N):\n";

    cout << "Chest Pain? ";
    cin >> input;
    chest_pain = (tolower(input) == 'y');

    cout << "Shortness of Breath? ";
    cin >> input;
    short_breath = (tolower(input) == 'y');

    cout << "Heavy Bleeding? ";
    cin >> input;
    bleeding = (tolower(input) == 'y');

    cout << "High Fever? ";
    cin >> input;
    high_fever = (tolower(input) == 'y');

    cout << "Recent Injury? ";
    cin >> input;
    injury = (tolower(input) == 'y');

    cout << "Dizziness or Fainting? ";
    cin >> input;
    dizziness = (tolower(input) == 'y');

    cout << "Severe Stomach Pain? ";
    cin >> input;
    stomach_pain = (tolower(input) == 'y');

    cout << "\nAnalyzing symptoms...\n";

    string department, advice;

    if (bleeding || injury) {
        department = "Emergency Room (ER)";
        advice = "Immediate attention required. Proceed to the ER.";
    } else if (chest_pain || short_breath) {
        department = "Cardiology";
        advice = "Cardiac symptoms detected. Visit Cardiology immediately.";
    } else if (high_fever && age < 12) {
        department = "Pediatrics";
        advice = "High fever in child. Visit Pediatrics urgently.";
    } else if (high_fever) {
        department = "General Medicine";
        advice = "Consult a general physician for evaluation.";
    } else if (dizziness) {
        department = "Neurology";
        advice = "Neurological symptoms present. Visit Neurology.";
    } else if (stomach_pain) {
        department = "Gastroenterology";
        advice = "Visit a gastroenterologist for further diagnosis.";
    } else {
        department = "Outpatient (OPD)";
        advice = "No critical symptoms. You may proceed to OPD.";
    }

    cout << "\n=== Patient Report ===\n";
    cout << "Name: " << name << endl;
    cout << "Recommended Department: " << department << endl;
    cout << "Advice: " << advice << endl;
}

int main() {
    triageSystem();
    return 0;
}
