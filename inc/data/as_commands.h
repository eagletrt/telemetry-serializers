#ifndef SERIALIZERS_AS_COMMANDS_H
#define SERIALIZERS_AS_COMMANDS_H

#include "as_commands.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
namespace Data
{
struct ASCommands
{
    double steerAngleDegrees;
    double pedalThrottle;
    double pedalBrakes;
    
    ASCommands() = default;
    ASCommands(const PbData::ASCommands& protobuf);
    operator PbData::ASCommands() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

enum class Status
{
    status_disabled = 0,
    status_enabled = 1
};

struct ASStatus
{
    Status steerStatus;
    Status throttleStatus;
    Status brakesStatus;
    
    ASStatus() = default;
    ASStatus(const PbData::ASStatus& protobuf);
    operator PbData::ASStatus() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif