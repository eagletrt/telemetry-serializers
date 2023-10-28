#ifndef CAR_CONFIG_H
#define CAR_CONFIG_H

#include "car_config.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

typedef Configs::Aero ConfigsAero;
typedef Configs::Wheel ConfigsWheel;
typedef Configs::Damper ConfigsDamper;
typedef Configs::Driver ConfigsDriver;
typedef Configs::CarConfig ConfigsCarConfig;

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
    Aero(const ConfigsAero& proto);
    operator ConfigsAero() const;

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
    Wheel(const ConfigsWheel& proto);
    operator ConfigsWheel() const;

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
    Damper(const ConfigsDamper& proto);
    operator ConfigsDamper() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct Driver
{
    std::string name;
    double weight;
    
    Driver() = default;
    Driver(const ConfigsDriver& proto);
    operator ConfigsDriver() const;

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
    Driver driver;
    std::string wheelCompound;
    double rideHeight;
    std::string balancing;
    std::string notes;
    
    CarConfig() = default;
    CarConfig(const ConfigsCarConfig& proto);
    operator ConfigsCarConfig() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif