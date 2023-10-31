#ifndef CAR_CONFIG_H
#define CAR_CONFIG_H

#include "car_config.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
namespace Configs
{
struct Aero
{
    double angleOfIncidenceFront;
    double angleOfIncidenceRear;
    std::string flap;
    
    Aero() = default;
    Aero(const PbConfigs::Aero& protobuf);
    operator PbConfigs::Aero() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct Wheel
{
    double camber;
    double toe;
    
    Wheel() = default;
    Wheel(const PbConfigs::Wheel& protobuf);
    operator PbConfigs::Wheel() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct Damper
{
    double bound;
    double rebound;
    double preload;
    
    Damper() = default;
    Damper(const PbConfigs::Damper& protobuf);
    operator PbConfigs::Damper() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct CarConfig
{
    Aero aero;
    Wheel wheelFront;
    Wheel wheelRear;
    Damper damperFront;
    Damper damperRear;
    std::string wheelCompound;
    double rideHeight;
    std::string balancing;
    std::string notes;
    
    CarConfig() = default;
    CarConfig(const PbConfigs::CarConfig& protobuf);
    operator PbConfigs::CarConfig() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif