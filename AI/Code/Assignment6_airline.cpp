#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure for Flight Details
struct Flight
{
    string flightNumber;
    string origin;
    string destination;
    string departureTime;    // Format: HH:MM
    string arrivalTime;      // Format: HH:MM
    int cargoCapacity;       // in tons
    int availableCargoSpace; // in tons
};

// Structure for Cargo Details
struct Cargo
{
    string cargoID;
    int weight; // in tons
    string destination;
    bool scheduled = false; // Added flag to track if cargo has been scheduled
};

// Expert System class
class ExpertSystem
{
private:
    vector<Flight> flights;
    vector<Cargo> cargos;

public:
    // Add a new flight to the system
    void addFlight()
    {
        Flight flight;
        cout << "Enter Flight Number: ";
        cin >> flight.flightNumber;
        cout << "Enter Origin: ";
        cin >> flight.origin;
        cout << "Enter Destination: ";
        cin >> flight.destination;
        cout << "Enter Departure Time (HH:MM): ";
        cin >> flight.departureTime;
        cout << "Enter Arrival Time (HH:MM): ";
        cin >> flight.arrivalTime;
        cout << "Enter Cargo Capacity (tons): ";
        cin >> flight.cargoCapacity;
        flight.availableCargoSpace = flight.cargoCapacity;
        flights.push_back(flight);
    }

    // Add new cargo to the system
    void addCargo()
    {
        Cargo cargo;
        cout << "Enter Cargo ID: ";
        cin >> cargo.cargoID;
        cout << "Enter Weight (tons): ";
        cin >> cargo.weight;
        cout << "Enter Destination: ";
        cin >> cargo.destination;
        cargos.push_back(cargo);
    }

    // Find a flight with available cargo space and schedule the cargo
    void scheduleCargo()
    {
        for (auto &cargo : cargos)
        {
            if (cargo.scheduled)
            {
                cout << "Cargo " << cargo.cargoID << " has already been scheduled.\n";
                continue; // Skip already scheduled cargo
            }

            bool scheduled = false;
            for (auto &flight : flights)
            {
                if (flight.availableCargoSpace >= cargo.weight && flight.destination == cargo.destination)
                {
                    flight.availableCargoSpace -= cargo.weight;
                    cargo.scheduled = true; // Mark cargo as scheduled
                    cout << "Cargo " << cargo.cargoID << " scheduled on Flight " << flight.flightNumber << endl;
                    scheduled = true;
                    break;
                }
            }

            if (!scheduled)
            {
                cout << "No available flight for Cargo " << cargo.cargoID << " to " << cargo.destination << endl;
            }
        }
    }

    // Display all flights
    void displayFlights()
    {
        if (flights.empty())
        {
            cout << "No flights available.\n";
            return;
        }
        cout << "\nFlight Schedule: \n";
        for (const auto &flight : flights)
        {
            cout << "Flight " << flight.flightNumber << " from " << flight.origin << " to " << flight.destination
                 << " departing at " << flight.departureTime << " arriving at " << flight.arrivalTime
                 << " with cargo capacity " << flight.cargoCapacity << " tons, available cargo space: "
                 << flight.availableCargoSpace << " tons\n";
        }
    }

    // Display all cargos
    void displayCargos()
    {
        if (cargos.empty())
        {
            cout << "No cargos available.\n";
            return;
        }
        cout << "\nCargo Details: \n";
        for (const auto &cargo : cargos)
        {
            cout << "Cargo ID: " << cargo.cargoID << ", Weight: " << cargo.weight << " tons, Destination: "
                 << cargo.destination << ", Scheduled: " << (cargo.scheduled ? "Yes" : "No") << endl;
        }
    }
};

int main()
{
    ExpertSystem system;
    int choice;

    do
    {
        cout << "\n---- Airline and Cargo Scheduling Expert System ----\n";
        cout << "1. Add Flight\n";
        cout << "2. Add Cargo\n";
        cout << "3. Display Flights\n";
        cout << "4. Display Cargos\n";
        cout << "5. Schedule Cargo\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            system.addFlight();
            break;
        case 2:
            system.addCargo();
            break;
        case 3:
            system.displayFlights();
            break;
        case 4:
            system.displayCargos();
            break;
        case 5:
            system.scheduleCargo();
            break;
        case 6:
            cout << "Exiting system...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}