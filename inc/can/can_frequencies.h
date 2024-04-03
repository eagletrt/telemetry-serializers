#ifndef SERIALIZERS_CAN_FREQUENCIES_H
#define SERIALIZERS_CAN_FREQUENCIES_H

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
    uint64_t timestamp;
    uint64_t id;
    std::string name;
    uint64_t data;
    uint64_t frequency;
    
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
    std::unordered_map<uint64_t, CanFrequency> frequencies;
    
    CanFrequencies() = default;
    CanFrequencies(const PbCan::CanFrequencies& protobuf);
    operator PbCan::CanFrequencies() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct CanNetworksFrequencies
{
    uint64_t timestamp;
    std::unordered_map<std::string, CanFrequencies> networks;
    
    CanNetworksFrequencies() = default;
    CanNetworksFrequencies(const PbCan::CanNetworksFrequencies& protobuf);
    operator PbCan::CanNetworksFrequencies() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif