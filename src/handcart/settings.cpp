#include "handcart/settings.h"

#include <google/protobuf/util/json_util.h>

namespace Serializers
{
namespace Handcart
{
Settings::Settings(const PbHandcart::Settings& message) {
    status = message.status();
    targetVoltage = message.targetvoltage();
    fansOverride = message.fansoverride();
    fansSpeed = message.fansspeed();
    accChargeCurrent = message.accchargecurrent();
    gridMaxCurrent = message.gridmaxcurrent();
}

Settings::operator PbHandcart::Settings() const {
    PbHandcart::Settings ret;
    ret.set_status(status);
    ret.set_targetvoltage(targetVoltage);
    ret.set_fansoverride(fansOverride);
    ret.set_fansspeed(fansSpeed);
    ret.set_accchargecurrent(accChargeCurrent);
    ret.set_gridmaxcurrent(gridMaxCurrent);
    return ret;
}

std::string Settings::serializeAsJsonString() const {
    PbHandcart::Settings message(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(message, &ret, options);
    return ret;
}

std::string Settings::serializeAsProtobufString() const {
    PbHandcart::Settings message(*this);
    return message.SerializeAsString();
}

bool Settings::deserializeFromJsonString(const std::string& str) {
    PbHandcart::Settings message;
    auto status = google::protobuf::util::JsonStringToMessage(str, &message);
    if(status.ok()) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

bool Settings::deserializeFromProtobufString(const std::string& str) {
    PbHandcart::Settings message;
    if(message.ParseFromString(str)) {
        *this = message;
        return true;
    } else {
        return false;
    }
}
}
}