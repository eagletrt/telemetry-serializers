#include "telemetry/odometer.h"

#include <google/protobuf/util/json_util.h>
#include <tuple>

namespace Serializers
{
namespace Telemetry
{
Odometer::Odometer(const PbTelemetry::Odometer& protobuf) {
    startDate = protobuf.startdate();
    kilometers = protobuf.kilometers();
}

Odometer::operator PbTelemetry::Odometer() const {
    PbTelemetry::Odometer ret;
    ret.set_startdate(startDate);
    ret.set_kilometers(kilometers);
    return ret;
}

std::string Odometer::serializeAsJsonString() const {
    PbTelemetry::Odometer protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Odometer::serializeAsProtobufString() const {
    PbTelemetry::Odometer protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Odometer::deserializeFromJsonString(const std::string& str) {
    PbTelemetry::Odometer protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Odometer::deserializeFromProtobufString(const std::string& str) {
    PbTelemetry::Odometer protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}