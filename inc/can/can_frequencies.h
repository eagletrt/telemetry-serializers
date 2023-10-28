#ifndef CAN_FREQUENCIES_H
#define CAN_FREQUENCIES_H

#include "can_frequencies.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

typedef Can::CanFrequency CanCanFrequency;
typedef Can::CanFrequencies CanCanFrequencies;

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
    CanFrequency(const CanCanFrequency& proto);
    operator CanCanFrequency() const;

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
    CanFrequencies(const CanCanFrequencies& proto);
    operator CanCanFrequencies() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif