#ifndef CAN_NETWORKS_H
#define CAN_NETWORKS_H

#include "can_networks.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
namespace Can
{
struct CanMessage
{
    uint64_t id;
    std::string name;
    uint64_t data;
    uint64_t timestamp;
    uint64_t frequency;
    
    CanMessage() = default;
    CanMessage(const PbCan::CanMessage& protobuf);
    operator PbCan::CanMessage() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct CanNetwork
{
    std::string name;
    std::vector<CanMessage> canMessages;
    
    CanNetwork() = default;
    CanNetwork(const PbCan::CanNetwork& protobuf);
    operator PbCan::CanNetwork() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct CanNetworks
{
    uint64_t timestamp;
    std::vector<CanNetwork> networks;
    
    CanNetworks() = default;
    CanNetworks(const PbCan::CanNetworks& protobuf);
    operator PbCan::CanNetworks() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif