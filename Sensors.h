#ifndef SENSORS_H
#define SENSORS_H

#include <string>
#include <vector>
#include <ctime>

// Enum for sensor type
enum class SensorType {
    Temperature,
    Humidity,
    PowerConsumption
};

// Convert enum to string
std::string sensorTypeToString(SensorType type);

// Struct to hold readings
struct SensorReading {
    time_t timestamp;
    std::string sensorId;
    SensorType type;
    float value;
};

// Abstract base class for sensors
class Sensor {
public:
    Sensor(std::string id, float minVal, float maxVal);
    virtual ~Sensor();

    virtual float generateReading() = 0;
    virtual SensorType getType() const = 0;

    std::string getSensorId() const;
    float getMinValue() const;
    float getMaxValue() const;

protected:
    std::string sensorId;
    float minValue;
    float maxValue;
};

// Temperature sensor
class TemperatureSensor : public Sensor {
public:
    TemperatureSensor(std::string id, float minTemp, float maxTemp);
    float generateReading() override;
    SensorType getType() const override;
};

// Humidity sensor
class HumiditySensor : public Sensor {
public:
    HumiditySensor(std::string id, float minHum, float maxHum);
    float generateReading() override;
    SensorType getType() const override;
};

// Power consumption sensor
class PowerConsumptionSensor : public Sensor {
public:
    PowerConsumptionSensor(std::string id, float minPower, float maxPower);
    float generateReading() override;
    SensorType getType() const override;
};

#endif // SENSORS_H
