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
    std::vector<double> buffer;
    
    VectorDouble() = default;
    VectorDouble(const PbData::VectorDouble& protobuf);
    operator PbData::VectorDouble() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct DataFile
{
    std::unordered_map<std::string, VectorDouble> data;
    
    DataFile() = default;
    DataFile(const PbData::DataFile& protobuf);
    operator PbData::DataFile() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct TelemetryLapData
{
    std::string dateTime;
    std::string trackLocation;
    std::string trackLayout;
    std::string driver;
    uint32_t lapNumber;
    std::string filenameHash;
    
    TelemetryLapData() = default;
    TelemetryLapData(const PbData::TelemetryLapData& protobuf);
    operator PbData::TelemetryLapData() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct DataBase
{
    std::vector<TelemetryLapData> lapsData;
    
    DataBase() = default;
    DataBase(const PbData::DataBase& protobuf);
    operator PbData::DataBase() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif