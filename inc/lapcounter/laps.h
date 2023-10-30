#ifndef LAPS_H
#define LAPS_H

#include "laps.pb.h"

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

struct Laps
{
    Lap bestLap;
    std::vector<Lap> laps;
    
    Laps() = default;
    Laps(const PbLapCounter::Laps& protobuf);
    operator PbLapCounter::Laps() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif