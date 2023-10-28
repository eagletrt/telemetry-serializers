#ifndef LAPS_H
#define LAPS_H

#include "laps.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

typedef LapCounter::Lap LapCounterLap;
typedef LapCounter::Laps LapCounterLaps;

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
    Lap(const LapCounterLap& proto);
    operator LapCounterLap() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct Laps
{
    std::vector<Lap> laps;
    
    Laps() = default;
    Laps(const LapCounterLaps& proto);
    operator LapCounterLaps() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif