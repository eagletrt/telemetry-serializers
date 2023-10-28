#ifndef STATUS_H
#define STATUS_H

#include "status.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

typedef Telemetry::Message TelemetryMessage;
typedef Telemetry::Camera TelemetryCamera;
typedef Telemetry::Status TelemetryStatus;

namespace Serializers
{
namespace Telemetry
{
struct Message
{
    std::string deviceName;
    uint64_t bitsPerSecond;
    double busLoad;
    uint64_t count;
    
    Message() = default;
    Message(const TelemetryMessage& proto);
    operator TelemetryMessage() const;

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
    Camera(const TelemetryCamera& proto);
    operator TelemetryCamera() const;

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
    std::vector<Message> messages;
    
    Status() = default;
    Status(const TelemetryStatus& proto);
    operator TelemetryStatus() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif