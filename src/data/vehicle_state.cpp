#include "data/vehicle_state.h"

#include <google/protobuf/util/json_util.h>
#include <tuple>

namespace Serializers
{
namespace Data
{
VehicleState::VehicleState(const PbData::VehicleState& protobuf) {
    x = protobuf.x();
    y = protobuf.y();
    heading = protobuf.heading();
    u = protobuf.u();
    v = protobuf.v();
}

VehicleState::operator PbData::VehicleState() const {
    PbData::VehicleState ret;
    ret.set_x(x);
    ret.set_y(y);
    ret.set_heading(heading);
    ret.set_u(u);
    ret.set_v(v);
    return ret;
}

std::string VehicleState::serializeAsJsonString() const {
    PbData::VehicleState protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string VehicleState::serializeAsProtobufString() const {
    PbData::VehicleState protobuf(*this);
    return protobuf.SerializeAsString();
}

bool VehicleState::deserializeFromJsonString(const std::string& str) {
    PbData::VehicleState protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool VehicleState::deserializeFromProtobufString(const std::string& str) {
    PbData::VehicleState protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}