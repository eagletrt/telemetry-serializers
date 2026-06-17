#ifndef SERIALIZERS_CAN_ERROR_H
#define SERIALIZERS_CAN_ERROR_H

#include "can_error.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
namespace Can
{
struct Invalid_can_id
{
    uint64_t timestamp;
    uint32_t id;
    std::vector<uint32_t> payload;
    std::string network;
    
    Invalid_can_id() = default;
    Invalid_can_id(const PbCan::Invalid_can_id& protobuf);
    operator PbCan::Invalid_can_id() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif