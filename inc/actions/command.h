#ifndef SERIALIZERS_COMMAND_H
#define SERIALIZERS_COMMAND_H

#include "command.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
namespace Actions
{
struct Command
{
    std::string input;
    std::string output;
    
    Command() = default;
    Command(const PbActions::Command& protobuf);
    operator PbActions::Command() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif