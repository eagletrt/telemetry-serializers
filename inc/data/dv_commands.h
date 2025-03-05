#ifndef SERIALIZERS_DV_COMMANDS_H
#define SERIALIZERS_DV_COMMANDS_H

#include "dv_commands.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
namespace Data
{
struct ActuatorsCommands
{
    double steerAngleDegrees;
    double pedalThrottle;
    double pedalBrakes;
    
    ActuatorsCommands() = default;
    ActuatorsCommands(const PbData::ActuatorsCommands& protobuf);
    operator PbData::ActuatorsCommands() const;

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

struct ActuatorsStatus
{
    Status steerStatus;
    Status throttleStatus;
    Status brakesStatus;
    
    ActuatorsStatus() = default;
    ActuatorsStatus(const PbData::ActuatorsStatus& protobuf);
    operator PbData::ActuatorsStatus() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif