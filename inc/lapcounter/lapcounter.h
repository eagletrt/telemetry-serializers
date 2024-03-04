#ifndef LAPCOUNTER_H
#define LAPCOUNTER_H

#include "lapcounter.pb.h"

#include <cstdint>
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
    Vector(const PbLapCounter::Vector& message);
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
    Line(const PbLapCounter::Line& message);
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
    Circuit(const PbLapCounter::Circuit& message);
    operator PbLapCounter::Circuit() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct Lap
{
    int32_t number;
    uint64_t startTimestamp;
    uint64_t endTimestamp;
    std::vector<uint64_t> sectorsTimestamps;
    
    Lap() = default;
    Lap(const PbLapCounter::Lap& message);
    operator PbLapCounter::Lap() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct Race
{
    std::string raceId;
    std::string circuitId;
    std::string driverId;
    std::vector<Lap> laps;
    
    Race() = default;
    Race(const PbLapCounter::Race& message);
    operator PbLapCounter::Race() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif