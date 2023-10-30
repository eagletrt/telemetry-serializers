#ifndef STATUS_H
#define STATUS_H

#include "status.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
namespace Telemetry
{
struct MessagesPerSecond
{
    std::string deviceName;
    uint64_t bitsPerSecond;
    double busLoad;
    uint64_t count;
    
    MessagesPerSecond() = default;
    MessagesPerSecond(const PbTelemetry::MessagesPerSecond& protobuf);
    operator PbTelemetry::MessagesPerSecond() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct Camera
{
    std::string status;
    std::string error;
    
    Camera() = default;
    Camera(const PbTelemetry::Camera& protobuf);
    operator PbTelemetry::Camera() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct Status
{
    uint64_t timestamp;
    uint64_t zeroTimestamp;
    uint64_t cpuTotalLoad;
    uint64_t cpuProcessLoad;
    uint64_t memProcessLoad;
    uint64_t canlibVersion;
    Camera camera;
    std::vector<MessagesPerSecond> messagesPerSecond;
    
    Status() = default;
    Status(const PbTelemetry::Status& protobuf);
    operator PbTelemetry::Status() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif