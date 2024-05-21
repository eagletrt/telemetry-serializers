#ifndef SERIALIZERS_STEER_COMMAND_H
#define SERIALIZERS_STEER_COMMAND_H

#include "steer_command.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
namespace Data
{
struct SteerCommand
{
    double angleDegrees;
    
    SteerCommand() = default;
    SteerCommand(const PbData::SteerCommand& protobuf);
    operator PbData::SteerCommand() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif