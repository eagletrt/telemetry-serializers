#ifndef SERIALIZERS_VEHICLE_STATE_H
#define SERIALIZERS_VEHICLE_STATE_H

#include "vehicle_state.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
namespace Data
{
struct VehicleState
{
    double x;
    double y;
    double heading;
    double u;
    double v;
    
    VehicleState() = default;
    VehicleState(const PbData::VehicleState& protobuf);
    operator PbData::VehicleState() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif