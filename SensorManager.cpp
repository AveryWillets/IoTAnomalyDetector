#include "SensorManager.h"
#include "Sensors.h"

// Adding sensor to manager
void SensorManager::addSensor(std::shared_ptr<Sensor> sensor) {
    sensors.push_back(sensor);
}

// Collecting batch data
std::vector<SensorReading> SensorManager::collectBatchData() {
    // Creating vector of readings
    std::vector<SensorReading> readings;
    // Iterating though each sensor
    for (const auto& sensor : sensors) {
        SensorReading reading;
        // Adding info to sensor reading
        reading.timestamp = time(nullptr);
        reading.sensorId = sensor->getSensorId();
        reading.type = sensor->getType();
        reading.value = sensor->generateReading();
        // Adding reading to vector
        readings.push_back(reading);
    }
    return readings;
}
