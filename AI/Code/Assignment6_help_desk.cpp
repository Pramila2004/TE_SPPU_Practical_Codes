#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Function to convert a string to lowercase
string toLowerCase(string str)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// Function to check symptoms and provide solutions
void diagnoseIssue(string symptom)
{
    symptom = toLowerCase(symptom); // Convert input to lowercase

    if (symptom == "computer won't start")
    {
        cout << "Possible solutions:\n";
        cout << "1. Check if the power cable is connected.\n";
        cout << "2. Ensure that the power button is working.\n";
        cout << "3. Check if the motherboard is receiving power.\n";
    }
    else if (symptom == "no internet connection")
    {
        cout << "Possible solutions:\n";
        cout << "1. Check if the Wi-Fi is turned on.\n";
        cout << "2. Restart the router.\n";
        cout << "3. Check the network cables for any loose connections.\n";
        cout << "4. Check if your ISP is experiencing outages.\n";
    }
    else if (symptom == "slow performance")
    {
        cout << "Possible solutions:\n";
        cout << "1. Close unnecessary programs running in the background.\n";
        cout << "2. Perform a disk cleanup.\n";
        cout << "3. Run an antivirus scan to check for malware.\n";
    }
    else
    {
        cout << "Sorry, I cannot diagnose this issue. Please contact technical support.\n";
    }
}

int main()
{
    string symptom;

    cout << "Welcome to the Help Desk Expert System!\n";
    cout << "Please describe the issue you're facing (e.g., 'Computer won't start', 'No internet connection', etc.): ";
    getline(cin, symptom);

    diagnoseIssue(symptom);

    return 0;
}