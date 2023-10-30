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
    uint64_t timestamp;
    int32_t number;
    double time;
    std::vector<double> sectorTimes;
    
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
    Lap bestLap;
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