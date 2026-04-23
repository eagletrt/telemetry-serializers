#ifndef SERIALIZERS_GPS_MAPS_H
#define SERIALIZERS_GPS_MAPS_H

#include "gps_maps.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
namespace Telemetry
{
struct Baseline
{
    bool valid;
    bool logging;
    double length;
    std::vector<double> x;
    std::vector<double> y;
    bool resampled;
    std::vector<double> s;
    std::vector<double> theta;
    
    Baseline() = default;
    Baseline(const PbTelemetry::Baseline& protobuf);
    operator PbTelemetry::Baseline() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct GPSMapOrigin
{
    double latitude;
    double longitude;
    double altitude;
    
    GPSMapOrigin() = default;
    GPSMapOrigin(const PbTelemetry::GPSMapOrigin& protobuf);
    operator PbTelemetry::GPSMapOrigin() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct GPSMapOrigins
{
    std::string trackLocation;
    std::string trackLayout;
    std::unordered_map<std::string, GPSMapOrigin> origins;
    std::unordered_map<std::string, Baseline> tracksBaseline;
    
    GPSMapOrigins() = default;
    GPSMapOrigins(const PbTelemetry::GPSMapOrigins& protobuf);
    operator PbTelemetry::GPSMapOrigins() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct SetBaseline
{
    std::string trackLocation;
    std::string trackLayout;
    GPSMapOrigin origin;
    std::vector<double> x;
    std::vector<double> y;
    
    SetBaseline() = default;
    SetBaseline(const PbTelemetry::SetBaseline& protobuf);
    operator PbTelemetry::SetBaseline() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif