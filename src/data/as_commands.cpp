#include "data/as_commands.h"

#include <google/protobuf/util/json_util.h>
#include <tuple>

namespace Serializers
{
namespace Data
{
ASCommands::ASCommands(const PbData::ASCommands& protobuf) {
    steerAngleDegrees = protobuf.steerangledegrees();
    pedalThrottle = protobuf.pedalthrottle();
    pedalBrakes = protobuf.pedalbrakes();
}

ASCommands::operator PbData::ASCommands() const {
    PbData::ASCommands ret;
    ret.set_steerangledegrees(steerAngleDegrees);
    ret.set_pedalthrottle(pedalThrottle);
    ret.set_pedalbrakes(pedalBrakes);
    return ret;
}

std::string ASCommands::serializeAsJsonString() const {
    PbData::ASCommands protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string ASCommands::serializeAsProtobufString() const {
    PbData::ASCommands protobuf(*this);
    return protobuf.SerializeAsString();
}

bool ASCommands::deserializeFromJsonString(const std::string& str) {
    PbData::ASCommands protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool ASCommands::deserializeFromProtobufString(const std::string& str) {
    PbData::ASCommands protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

ASStatus::ASStatus(const PbData::ASStatus& protobuf) {
    steerStatus = static_cast<Status>(protobuf.steerstatus());
    throttleStatus = static_cast<Status>(protobuf.throttlestatus());
    brakesStatus = static_cast<Status>(protobuf.brakesstatus());
}

ASStatus::operator PbData::ASStatus() const {
    PbData::ASStatus ret;
    ret.set_steerstatus(static_cast<PbData::Status>(steerStatus));
    ret.set_throttlestatus(static_cast<PbData::Status>(throttleStatus));
    ret.set_brakesstatus(static_cast<PbData::Status>(brakesStatus));
    return ret;
}

std::string ASStatus::serializeAsJsonString() const {
    PbData::ASStatus protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string ASStatus::serializeAsProtobufString() const {
    PbData::ASStatus protobuf(*this);
    return protobuf.SerializeAsString();
}

bool ASStatus::deserializeFromJsonString(const std::string& str) {
    PbData::ASStatus protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool ASStatus::deserializeFromProtobufString(const std::string& str) {
    PbData::ASStatus protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}