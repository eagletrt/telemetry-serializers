#include "handcart/settings.h"

#include <google/protobuf/util/json_util.h>
#include <tuple>

namespace Serializers
{
namespace Handcart
{
Settings::Settings(const PbHandcart::Settings& protobuf) {
    status = protobuf.status();
    targetVoltage = protobuf.targetvoltage();
    fansOverride = protobuf.fansoverride();
    fansSpeed = protobuf.fansspeed();
    accChargeCurrent = protobuf.accchargecurrent();
    gridMaxCurrent = protobuf.gridmaxcurrent();
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
    PbHandcart::Settings protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Settings::serializeAsProtobufString() const {
    PbHandcart::Settings protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Settings::deserializeFromJsonString(const std::string& str) {
    PbHandcart::Settings protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Settings::deserializeFromProtobufString(const std::string& str) {
    PbHandcart::Settings protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}