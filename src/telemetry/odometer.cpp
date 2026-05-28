#include "telemetry/odometer.h"

#include <google/protobuf/util/json_util.h>
#include <tuple>

namespace Serializers
{
namespace Telemetry
{
Tyre::Tyre(const PbTelemetry::Tyre& protobuf) {
    id = protobuf.id();
    kilometers = protobuf.kilometers();
}

Tyre::operator PbTelemetry::Tyre() const {
    PbTelemetry::Tyre ret;
    ret.set_id(id);
    ret.set_kilometers(kilometers);
    return ret;
}

std::string Tyre::serializeAsJsonString() const {
    PbTelemetry::Tyre protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Tyre::serializeAsProtobufString() const {
    PbTelemetry::Tyre protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Tyre::deserializeFromJsonString(const std::string& str) {
    PbTelemetry::Tyre protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Tyre::deserializeFromProtobufString(const std::string& str) {
    PbTelemetry::Tyre protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

Odometer::Odometer(const PbTelemetry::Odometer& protobuf) {
    startDate = protobuf.startdate();
    fl = protobuf.fl();
    fr = protobuf.fr();
    rl = protobuf.rl();
    rr = protobuf.rr();
}

Odometer::operator PbTelemetry::Odometer() const {
    PbTelemetry::Odometer ret;
    ret.set_startdate(startDate);
    *(ret.mutable_fl()) = fl;
    *(ret.mutable_fr()) = fr;
    *(ret.mutable_rl()) = rl;
    *(ret.mutable_rr()) = rr;
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