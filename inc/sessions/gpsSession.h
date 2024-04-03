#ifndef SERIALIZERS_GPSSESSION_H
#define SERIALIZERS_GPSSESSION_H

#include "gpsSession.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
namespace Sessions
{
struct GpsSession
{
    std::string gpsName;
    std::string dateTime;
    double durationSeconds;
    uint64_t startTimestamp;
    uint64_t endTimestamp;
    uint64_t messages;
    
    GpsSession() = default;
    GpsSession(const PbSessions::GpsSession& protobuf);
    operator PbSessions::GpsSession() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif