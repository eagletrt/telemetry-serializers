#ifndef SERIALIZERS_NEW_LAP_H
#define SERIALIZERS_NEW_LAP_H

#include "new_lap.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
namespace LapCounter
{
struct NewLap
{
    uint64_t timestamp;
    
    NewLap() = default;
    NewLap(const PbLapCounter::NewLap& protobuf);
    operator PbLapCounter::NewLap() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif