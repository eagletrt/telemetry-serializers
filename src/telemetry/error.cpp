#include "telemetry/error.h"

#include <google/protobuf/util/json_util.h>
#include <tuple>

namespace Serializers
{
namespace Telemetry
{
Error::Error(const PbTelemetry::Error& protobuf) {
    timestamp = protobuf.timestamp();
    function = protobuf.function();
    description = protobuf.description();
}

Error::operator PbTelemetry::Error() const {
    PbTelemetry::Error ret;
    ret.set_timestamp(timestamp);
    ret.set_function(function);
    ret.set_description(description);
    return ret;
}

std::string Error::serializeAsJsonString() const {
    PbTelemetry::Error protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Error::serializeAsProtobufString() const {
    PbTelemetry::Error protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Error::deserializeFromJsonString(const std::string& str) {
    PbTelemetry::Error protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Error::deserializeFromProtobufString(const std::string& str) {
    PbTelemetry::Error protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}