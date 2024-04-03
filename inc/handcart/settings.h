#ifndef SERIALIZERS_SETTINGS_H
#define SERIALIZERS_SETTINGS_H

#include "settings.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
namespace Handcart
{
struct Settings
{
    uint32_t status;
    double targetVoltage;
    bool fansOverride;
    double fansSpeed;
    double accChargeCurrent;
    double gridMaxCurrent;
    
    Settings() = default;
    Settings(const PbHandcart::Settings& protobuf);
    operator PbHandcart::Settings() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif