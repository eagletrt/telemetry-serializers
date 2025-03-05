#include "data/dv_commands.h"

#include <google/protobuf/util/json_util.h>
#include <tuple>

namespace Serializers
{
namespace Data
{
ActuatorsCommands::ActuatorsCommands(const PbData::ActuatorsCommands& protobuf) {
    steerAngleDegrees = protobuf.steerangledegrees();
    pedalThrottle = protobuf.pedalthrottle();
    pedalBrakes = protobuf.pedalbrakes();
}

ActuatorsCommands::operator PbData::ActuatorsCommands() const {
    PbData::ActuatorsCommands ret;
    ret.set_steerangledegrees(steerAngleDegrees);
    ret.set_pedalthrottle(pedalThrottle);
    ret.set_pedalbrakes(pedalBrakes);
    return ret;
}

std::string ActuatorsCommands::serializeAsJsonString() const {
    PbData::ActuatorsCommands protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string ActuatorsCommands::serializeAsProtobufString() const {
    PbData::ActuatorsCommands protobuf(*this);
    return protobuf.SerializeAsString();
}

bool ActuatorsCommands::deserializeFromJsonString(const std::string& str) {
    PbData::ActuatorsCommands protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool ActuatorsCommands::deserializeFromProtobufString(const std::string& str) {
    PbData::ActuatorsCommands protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

ActuatorsStatus::ActuatorsStatus(const PbData::ActuatorsStatus& protobuf) {
    steerStatus = static_cast<Status>(protobuf.steerstatus());
    throttleStatus = static_cast<Status>(protobuf.throttlestatus());
    brakesStatus = static_cast<Status>(protobuf.brakesstatus());
}

ActuatorsStatus::operator PbData::ActuatorsStatus() const {
    PbData::ActuatorsStatus ret;
    ret.set_steerstatus(static_cast<PbData::Status>(steerStatus));
    ret.set_throttlestatus(static_cast<PbData::Status>(throttleStatus));
    ret.set_brakesstatus(static_cast<PbData::Status>(brakesStatus));
    return ret;
}

std::string ActuatorsStatus::serializeAsJsonString() const {
    PbData::ActuatorsStatus protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string ActuatorsStatus::serializeAsProtobufString() const {
    PbData::ActuatorsStatus protobuf(*this);
    return protobuf.SerializeAsString();
}

bool ActuatorsStatus::deserializeFromJsonString(const std::string& str) {
    PbData::ActuatorsStatus protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool ActuatorsStatus::deserializeFromProtobufString(const std::string& str) {
    PbData::ActuatorsStatus protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}