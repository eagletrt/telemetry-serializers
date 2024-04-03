#ifndef SERIALIZERS_ERROR_H
#define SERIALIZERS_ERROR_H

#include "error.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
namespace Telemetry
{
struct Error
{
    uint64_t timestamp;
    std::string function;
    std::string description;
    
    Error() = default;
    Error(const PbTelemetry::Error& protobuf);
    operator PbTelemetry::Error() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif