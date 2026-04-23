#ifndef SERIALIZERS_WAIT_READY_H
#define SERIALIZERS_WAIT_READY_H

#include "wait_ready.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
namespace Telemetry
{
enum class ReadyStatus
{
    WAITING = 0,
    READY = 1
};

struct ReplayReady
{
    ReadyStatus status;
    
    ReplayReady() = default;
    ReplayReady(const PbTelemetry::ReplayReady& protobuf);
    operator PbTelemetry::ReplayReady() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct ReplayStart
{
    uint64_t startTimestamp;
    
    ReplayStart() = default;
    ReplayStart(const PbTelemetry::ReplayStart& protobuf);
    operator PbTelemetry::ReplayStart() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif