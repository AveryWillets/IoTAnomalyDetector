#include "Logger.h"
#include <fstream>
#include <string>

// Defining anomaly detector
bool isAnomaly(const SensorReading& reading) {
    // Based on sensor type
    switch (reading.type) {
    case SensorType::Temperature:
        return reading.value < 18.0f || reading.value > 27.0f;
    case SensorType::Humidity:
        return reading.value < 40.0f || reading.value > 60.0f;
    case SensorType::PowerConsumption:
        return reading.value < 90.0f || reading.value > 550.0f;
    default:
        return false;
    }
}

// Defining log function - send anomalies to csv
void logAnomalies(const std::vector<SensorReading>& readings) {
    std::ofstream logFile("anomalies.csv", std::ios::app);

    // Iterating through each reading, checking if anomaly
    for (const auto& reading : readings) {
        if (isAnomaly(reading)) {
            // Adding anomalies to file
            logFile << reading.timestamp << ","
                    << reading.sensorId << ","
                    << sensorTypeToString(reading.type) << ","
                    << reading.value << ",Anomaly\n";
        }
    }

    logFile.close();
}

// Defining log function - send readings to csv
void logReadings(const std::vector<SensorReading>& readings) {
    std::ofstream logFile("readings.csv", std::ios::app);

    // Iterating through each reading, adding to file
    for (const auto& reading : readings) {
        logFile << reading.timestamp << ","
                << reading.sensorId << ","
                << sensorTypeToString(reading.type) << ","
                << reading.value << "\n";
    }

    logFile.close();
}
