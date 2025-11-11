#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void controlTrafficLight(int trafficDensityA, int trafficDensityB) {
    int baseTime = 10;
    int greenTimeA, greenTimeB;

    if (trafficDensityA > trafficDensityB) {
        greenTimeA = baseTime + (trafficDensityA - trafficDensityB);
        greenTimeB = baseTime - (trafficDensityA - trafficDensityB) / 2;
    } else if (trafficDensityB > trafficDensityA) {
        greenTimeB = baseTime + (trafficDensityB - trafficDensityA);
        greenTimeA = baseTime - (trafficDensityB - trafficDensityA) / 2;
    } else {
        greenTimeA = greenTimeB = baseTime;
    }

    if (greenTimeA < 5) greenTimeA = 5;
    if (greenTimeB < 5) greenTimeB = 5;

    cout << "\nSmart Traffic Light Control System Simulation\n\n";
    cout << "Traffic Light A (North-South) GREEN for " << greenTimeA << " seconds.\n";
    this_thread::sleep_for(chrono::seconds(2)); 
    cout << "Traffic Light A turns RED.\n";
    cout << "Traffic Light B (East-West) turns GREEN for " << greenTimeB << " seconds.\n";
    this_thread::sleep_for(chrono::seconds(2)); 
    cout << "Traffic Light B turns RED.\n\n";
    cout << "Cycle completed. Adjusting for next round based on new data...\n";
}

int main() {
    int trafficA, trafficB;
    char choice;

    cout << "===== SMART TRAFFIC LIGHT CONTROL SYSTEM =====\n";
    do {
        cout << "\nEnter traffic density for Road A (0–10): ";
        cin >> trafficA;
        cout << "Enter traffic density for Road B (0–10): ";
        cin >> trafficB;

        controlTrafficLight(trafficA, trafficB);

        cout << "\nRun another cycle? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "\nSystem shutting down. Goodbye!\n";
    return 0;
}
