#ifndef SERIALIZERS_NTRIP_BASE_CONFIG_H
#define SERIALIZERS_NTRIP_BASE_CONFIG_H

#include "ntrip_base_config.pb.h"

#include <cstdint>
#include <optional>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
namespace Configs
{
struct NtripBaseSurveyIn
{
    int32_t minDurationS{};
    double accuracyLimitM{};
    
    NtripBaseSurveyIn() = default;
    NtripBaseSurveyIn(const PbConfigs::NtripBaseSurveyIn& protobuf);
    operator PbConfigs::NtripBaseSurveyIn() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct NtripBaseFixedPosition
{
    double lat{};
    double lon{};
    double heightM{};
    double accuracyM{};
    
    NtripBaseFixedPosition() = default;
    NtripBaseFixedPosition(const PbConfigs::NtripBaseFixedPosition& protobuf);
    operator PbConfigs::NtripBaseFixedPosition() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct NtripBaseFixAveraging
{
    int32_t averageS{};
    double accuracyLimitM{};
    double maxStdM{};
    
    NtripBaseFixAveraging() = default;
    NtripBaseFixAveraging(const PbConfigs::NtripBaseFixAveraging& protobuf);
    operator PbConfigs::NtripBaseFixAveraging() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct NtripBaseUpstream
{
    std::string casterHost{};
    int32_t casterPort{};
    std::string mountPoint{};
    std::string username{};
    std::string password{};
    
    NtripBaseUpstream() = default;
    NtripBaseUpstream(const PbConfigs::NtripBaseUpstream& protobuf);
    operator PbConfigs::NtripBaseUpstream() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct NtripBaseDelivery
{
    bool ntrip{};
    bool mqtt{};
    bool uplink{};
    
    NtripBaseDelivery() = default;
    NtripBaseDelivery(const PbConfigs::NtripBaseDelivery& protobuf);
    operator PbConfigs::NtripBaseDelivery() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

enum class NtripBaseMode
{
    NTRIP_BASE_MODE_SURVEY_IN = 0,
    NTRIP_BASE_MODE_NTRIP_FIX = 1,
    NTRIP_BASE_MODE_FIXED = 2,
    NTRIP_BASE_MODE_RELAY = 3
};

struct NtripBaseConfig
{
    NtripBaseMode mode{};
    NtripBaseSurveyIn surveyIn{};
    NtripBaseUpstream upstream{};
    NtripBaseFixAveraging ntripFix{};
    NtripBaseFixedPosition fixed{};
    NtripBaseDelivery delivery{};
    
    NtripBaseConfig() = default;
    NtripBaseConfig(const PbConfigs::NtripBaseConfig& protobuf);
    operator PbConfigs::NtripBaseConfig() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif