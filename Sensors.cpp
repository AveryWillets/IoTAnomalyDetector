#include "Sensors.h"
#include <cstdlib>
#include <sstream>

// Converts SensorType to string
std::string sensorTypeToString(SensorType type) {
    switch (type) {
        case SensorType::Temperature: return "Temperature";
        case SensorType::Humidity: return "Humidity";
        case SensorType::PowerConsumption: return "Power Consumption";
        default: return "Unknown";
    }
}

// Sensor base constructor/destructor
Sensor::Sensor(std::string id, float minVal, float maxVal)
    : sensorId(std::move(id)), minValue(minVal), maxValue(maxVal) {}

Sensor::~Sensor() {}

// Getters
std::string Sensor::getSensorId() const {
    return sensorId;
}

float Sensor::getMinValue() const {
    return minValue;
}

float Sensor::getMaxValue() const {
    return maxValue;
}

// --- TemperatureSensor ---
// Constructor
TemperatureSensor::TemperatureSensor(std::string id, float minTemp, float maxTemp)
    : Sensor(std::move(id), minTemp, maxTemp) {}
// Reading generator
float TemperatureSensor::generateReading() {
    float reading = minValue + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (maxValue - minValue)));
    if (rand() % 10 == 0)
        reading += (rand() % 2 == 0) ? 10.0f : -10.0f;
    return reading;
}
// type 'getter'
SensorType TemperatureSensor::getType() const {
    return SensorType::Temperature;
}

// --- HumiditySensor ---
// Constructor
HumiditySensor::HumiditySensor(std::string id, float minHum, float maxHum)
    : Sensor(std::move(id), minHum, maxHum) {}
// Reading generator
float HumiditySensor::generateReading() {
    float reading = minValue + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (maxValue - minValue)));
    if (rand() % 10 == 0)
        reading += (rand() % 2 == 0) ? 20.0f : -20.0f;
    return reading;
}
// Type 'getter'
SensorType HumiditySensor::getType() const {
    return SensorType::Humidity;
}

// --- PowerConsumptionSensor ---
// Constructor
PowerConsumptionSensor::PowerConsumptionSensor(std::string id, float minPower, float maxPower)
    : Sensor(std::move(id), minPower, maxPower) {}
// Reading generator
float PowerConsumptionSensor::generateReading() {
    float reading = minValue + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (maxValue - minValue)));
    if (rand() % 10 == 0)
        reading += (rand() % 2 == 0) ? 100.0f : -50.0f;
    return reading;
}
// Type 'getter'
SensorType PowerConsumptionSensor::getType() const {
    return SensorType::PowerConsumption;
}
