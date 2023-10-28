#include "handcart/settings.h"

#include <google/protobuf/util/json_util.h>

namespace Serializers
{
namespace Handcart
{
Settings::Settings(const HandcartSettings& proto) {
    status = proto.status();
    targetVoltage = proto.targetvoltage();
    fansOverride = proto.fansoverride();
    fansSpeed = proto.fansspeed();
    accChargeCurrent = proto.accchargecurrent();
    girdMaxCurrent = proto.girdmaxcurrent();
}

Settings::operator HandcartSettings() const {
    HandcartSettings ret;
    ret.set_status(status);
    ret.set_targetvoltage(targetVoltage);
    ret.set_fansoverride(fansOverride);
    ret.set_fansspeed(fansSpeed);
    ret.set_accchargecurrent(accChargeCurrent);
    ret.set_girdmaxcurrent(girdMaxCurrent);
    return ret;
}

std::string Settings::serializeAsJsonString() const {
    HandcartSettings proto(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(proto, &ret, options);
    return ret;
}

std::string Settings::serializeAsProtobufString() const {
    HandcartSettings proto(*this);
    return proto.SerializeAsString();
}

bool Settings::deserializeFromJsonString(const std::string& str) {
    HandcartSettings proto;
    auto status = google::protobuf::util::JsonStringToMessage(str, &proto);
    if(status.ok()) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

bool Settings::deserializeFromProtobufString(const std::string& str) {
    HandcartSettings proto;
    if(proto.ParseFromString(str)) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}
}
}