#ifndef LOGGER_H
#define LOGGER_H

#include "Sensors.h"
#include <vector>

// Declaring log functions
// Logging anomalies
void logAnomalies(const std::vector<SensorReading>& readings);
// Logging readings
void logReadings(const std::vector<SensorReading>& readings);
// Checking for anomalies
bool isAnomaly(const SensorReading& reading);

#endif
