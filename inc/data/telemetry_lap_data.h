#ifndef SERIALIZERS_TELEMETRY_LAP_DATA_H
#define SERIALIZERS_TELEMETRY_LAP_DATA_H

#include "telemetry_lap_data.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
namespace Data
{
struct VectorDouble
{
    std::vector<double> data;
    
    VectorDouble() = default;
    VectorDouble(const PbData::VectorDouble& protobuf);
    operator PbData::VectorDouble() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct TelemetryLapData
{
    std::string dateTime;
    std::string circuitId;
    std::string layoutId;
    std::string driverId;
    uint32_t lapNumber;
    std::unordered_map<std::string, VectorDouble> data;
    
    TelemetryLapData() = default;
    TelemetryLapData(const PbData::TelemetryLapData& protobuf);
    operator PbData::TelemetryLapData() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif