#ifndef SERIALIZERS_ODOMETER_H
#define SERIALIZERS_ODOMETER_H

#include "odometer.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
namespace Telemetry
{
struct Odometer
{
    std::string startDate;
    double kilometers;
    
    Odometer() = default;
    Odometer(const PbTelemetry::Odometer& protobuf);
    operator PbTelemetry::Odometer() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif