#ifndef RACE_H
#define RACE_H

#include "race.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
namespace LapCounter
{
struct Lap
{
    int32_t number;
    uint64_t startTimestamp;
    uint64_t endTimestamp;
    std::vector<uint64_t> sectorsTimestamps;
    
    Lap() = default;
    Lap(const PbLapCounter::Lap& protobuf);
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
    Race(const PbLapCounter::Race& protobuf);
    operator PbLapCounter::Race() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif