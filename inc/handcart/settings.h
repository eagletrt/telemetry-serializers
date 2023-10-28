#ifndef SETTINGS_H
#define SETTINGS_H

#include "settings.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

typedef Handcart::Settings HandcartSettings;

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
    double girdMaxCurrent;
    
    Settings() = default;
    Settings(const HandcartSettings& proto);
    operator HandcartSettings() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif