#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <thread>

#include "Sensors.h"
#include "SensorManager.h"
#include "Logger.h"

using namespace std;

int main() {
// Initializing randomizer based on time
    srand(static_cast<unsigned int>(time(0)));

    // Initializiing variables
    SensorManager sensorManager;
    vector<SensorReading> allReadings;
    char userChoice = 'y';

    // Creating sensor objects
    // Adding via shared pointers to avoid unnecessary copying

    // Temp sensors, 1 per floor currently
    sensorManager.addSensor(make_shared<TemperatureSensor>("temp001", 18.0f, 27.0f));
    sensorManager.addSensor(make_shared<TemperatureSensor>("temp002", 18.0f, 27.0f));
    sensorManager.addSensor(make_shared<TemperatureSensor>("temp003", 18.0f, 27.0f));
    // Hum sensors, 1 per floor currently
    sensorManager.addSensor(make_shared<HumiditySensor>("hum001", 40.0f, 60.0f));
    sensorManager.addSensor(make_shared<HumiditySensor>("hum002", 40.0f, 60.0f));
    sensorManager.addSensor(make_shared<HumiditySensor>("hum003", 40.0f, 60.0f));
    // PwrCons sensors, 1 per floor currently
    sensorManager.addSensor(make_shared<PowerConsumptionSensor>("pwrCons001", 40.0f, 60.0f));
    sensorManager.addSensor(make_shared<PowerConsumptionSensor>("pwrCons002", 40.0f, 60.0f));
    sensorManager.addSensor(make_shared<PowerConsumptionSensor>("pwrCons003", 40.0f, 60.0f));

    // welcoming user 
    cout << "Welcome to Mushroom Data Center!" << endl;
    cout << "I see you are here to monitor our IoT systems. Right this way!" << endl;

    cout << "Would you like to check systems now? (y/n):";
    cin >> userChoice;
    
    // Running program
    while (userChoice == 'y' || userChoice == 'Y') {
        cout << "Collecting diagnostics now....." << endl;
        // Running simulation for set period (10 secs)
        for (int i = 0; i < 10; i++) {
            // Creating vector of batchdata strings
            vector<SensorReading> batch = sensorManager.collectBatchData();
            // Adding batch to OVERALL data vector
            allReadings.insert(allReadings.end(), batch.begin(), batch.end());

            // Detect/log anomalies at end of batch - not exactly real-time, but still close and more optimized
            logAnomalies(batch);

            // Logging all readings for analysis
            logReadings(allReadings);
            
            // "Loading"
            cout << ". \n";

            // Wait 1 second before next batch
            this_thread::sleep_for(chrono::seconds(1));
        }

        cout << "Data Collection complete. Check 'anomalies.csv' for anomalies and 'readings.csv for all readings.\n";
        cout << "Would you like to run another data collection batch? (Y/n)";
        cin >> userChoice;
    }

    // Exiting the program
    cout << "Thank you for running diagnostics on the IoT systems here at Mushroom Data Center!";

}
