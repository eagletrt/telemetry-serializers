#ifndef CAN_FREQUENCIES_H
#define CAN_FREQUENCIES_H

#include "can_frequencies.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
namespace Can
{
struct CanFrequency
{
    uint64_t id;
    std::string name;
    uint64_t count;
    uint64_t timestamp;
    uint64_t data;
    
    CanFrequency() = default;
    CanFrequency(const PbCan::CanFrequency& protobuf);
    operator PbCan::CanFrequency() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct CanFrequencies
{
    uint64_t packTimestamp;
    std::vector<CanFrequency> canFrequenciesPrimary;
    std::vector<CanFrequency> canFrequenciesSecondary;
    
    CanFrequencies() = default;
    CanFrequencies(const PbCan::CanFrequencies& protobuf);
    operator PbCan::CanFrequencies() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif