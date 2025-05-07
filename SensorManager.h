#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H

#include "Sensors.h"
#include <vector>
#include <memory>

// Sensor manager class declaration
class SensorManager {
public:
    // Methods
    // Add sensor to vector
    void addSensor(std::shared_ptr<Sensor> sensor);
    // collecting reading batch data
    std::vector<SensorReading> collectBatchData();
private:
    // Attribute: vector of sensors
    std::vector<std::shared_ptr<Sensor>> sensors;
};

#endif // SENSOR_MANAGER_H
