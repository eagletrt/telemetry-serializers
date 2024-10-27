#include "data/steer_command.h"

#include <google/protobuf/util/json_util.h>
#include <tuple>

namespace Serializers
{
namespace Data
{
SteerCommand::SteerCommand(const PbData::SteerCommand& protobuf) {
    angleDegrees = protobuf.angledegrees();
}

SteerCommand::operator PbData::SteerCommand() const {
    PbData::SteerCommand ret;
    ret.set_angledegrees(angleDegrees);
    return ret;
}

std::string SteerCommand::serializeAsJsonString() const {
    PbData::SteerCommand protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string SteerCommand::serializeAsProtobufString() const {
    PbData::SteerCommand protobuf(*this);
    return protobuf.SerializeAsString();
}

bool SteerCommand::deserializeFromJsonString(const std::string& str) {
    PbData::SteerCommand protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool SteerCommand::deserializeFromProtobufString(const std::string& str) {
    PbData::SteerCommand protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

SteerStatus::SteerStatus(const PbData::SteerStatus& protobuf) {
    status = static_cast<Status>(protobuf.status());
}

SteerStatus::operator PbData::SteerStatus() const {
    PbData::SteerStatus ret;
    ret.set_status(static_cast<PbData::Status>(status));
    return ret;
}

std::string SteerStatus::serializeAsJsonString() const {
    PbData::SteerStatus protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string SteerStatus::serializeAsProtobufString() const {
    PbData::SteerStatus protobuf(*this);
    return protobuf.SerializeAsString();
}

bool SteerStatus::deserializeFromJsonString(const std::string& str) {
    PbData::SteerStatus protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool SteerStatus::deserializeFromProtobufString(const std::string& str) {
    PbData::SteerStatus protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}