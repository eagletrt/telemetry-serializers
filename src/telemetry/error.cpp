#include "telemetry/error.h"

#include <google/protobuf/util/json_util.h>

namespace Serializers
{
namespace Telemetry
{
Error::Error(const TelemetryError& proto) {
    timestamp = proto.timestamp();
    function = proto.function();
    description = proto.description();
}

Error::operator TelemetryError() const {
    TelemetryError ret;
    ret.set_timestamp(timestamp);
    ret.set_function(function);
    ret.set_description(description);
    return ret;
}

std::string Error::serializeAsJsonString() const {
    TelemetryError proto(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(proto, &ret, options);
    return ret;
}

std::string Error::serializeAsProtobufString() const {
    TelemetryError proto(*this);
    return proto.SerializeAsString();
}

bool Error::deserializeFromJsonString(const std::string& str) {
    TelemetryError proto;
    auto status = google::protobuf::util::JsonStringToMessage(str, &proto);
    if(status.ok()) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

bool Error::deserializeFromProtobufString(const std::string& str) {
    TelemetryError proto;
    if(proto.ParseFromString(str)) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}
}
}