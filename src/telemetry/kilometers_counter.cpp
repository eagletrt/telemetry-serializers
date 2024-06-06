#include "telemetry/kilometers_counter.h"

#include <google/protobuf/util/json_util.h>

namespace Serializers
{
namespace Telemetry
{
KilometersCounter::KilometersCounter(const PbTelemetry::KilometersCounter& protobuf) {
    startDate = protobuf.startdate();
    kilometers = protobuf.kilometers();
}

KilometersCounter::operator PbTelemetry::KilometersCounter() const {
    PbTelemetry::KilometersCounter ret;
    ret.set_startdate(startDate);
    ret.set_kilometers(kilometers);
    return ret;
}

std::string KilometersCounter::serializeAsJsonString() const {
    PbTelemetry::KilometersCounter protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string KilometersCounter::serializeAsProtobufString() const {
    PbTelemetry::KilometersCounter protobuf(*this);
    return protobuf.SerializeAsString();
}

bool KilometersCounter::deserializeFromJsonString(const std::string& str) {
    PbTelemetry::KilometersCounter protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool KilometersCounter::deserializeFromProtobufString(const std::string& str) {
    PbTelemetry::KilometersCounter protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}