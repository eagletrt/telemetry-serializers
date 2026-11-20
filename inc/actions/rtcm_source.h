#ifndef SERIALIZERS_RTCM_SOURCE_H
#define SERIALIZERS_RTCM_SOURCE_H

#include "rtcm_source.pb.h"

#include <cstdint>
#include <optional>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
namespace Actions
{
struct RtcmSource
{
    std::string type{};
    std::string topic{};
    std::string ref_topic{};
    std::string profile{};
    
    RtcmSource() = default;
    RtcmSource(const PbActions::RtcmSource& protobuf);
    operator PbActions::RtcmSource() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct RtcmSourceCommand
{
    double seq{};
    std::string base{};
    std::string by{};
    RtcmSource source{};
    
    RtcmSourceCommand() = default;
    RtcmSourceCommand(const PbActions::RtcmSourceCommand& protobuf);
    operator PbActions::RtcmSourceCommand() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct RtcmSourceStatus
{
    double seq{};
    bool ok{};
    RtcmSource source{};
    std::string error{};
    double rtcm_age_s{};
    double rtcm_bytes{};
    uint32_t frames{};
    uint32_t bad_frames{};
    
    RtcmSourceStatus() = default;
    RtcmSourceStatus(const PbActions::RtcmSourceStatus& protobuf);
    operator PbActions::RtcmSourceStatus() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif