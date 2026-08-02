#ifndef SERIALIZERS_LAPCOUNTER_H
#define SERIALIZERS_LAPCOUNTER_H

#include "lapcounter.pb.h"

#include <cstdint>
#include <optional>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
namespace LapCounter
{
struct Vector
{
    double x;
    double y;
    
    Vector() = default;
    Vector(const PbLapCounter::Vector& protobuf);
    operator PbLapCounter::Vector() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct Line
{
    Vector position;
    Vector direction;
    
    Line() = default;
    Line(const PbLapCounter::Line& protobuf);
    operator PbLapCounter::Line() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct Circuit
{
    std::string circuitId;
    std::vector<Line> checksLines;
    std::vector<Line> sectorsLines;
    
    Circuit() = default;
    Circuit(const PbLapCounter::Circuit& protobuf);
    operator PbLapCounter::Circuit() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

enum class Status
{
    DISARMED = 0,
    NO_INSTRUMENT = 1,
    NO_POSITION = 2,
    NO_PROJECTION = 3,
    OFF_TRACK = 4,
    OUT_LAP = 5,
    TIMING = 6
};

struct LapCounterStatus
{
    Status status;
    uint32_t dropped_laps;
    std::string detail;
    
    LapCounterStatus() = default;
    LapCounterStatus(const PbLapCounter::LapCounterStatus& protobuf);
    operator PbLapCounter::LapCounterStatus() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif