#include "telemetry/error.h"

#include <google/protobuf/util/json_util.h>

namespace Serializers
{
namespace Telemetry
{
Error::Error(const PbTelemetry::Error& message) {
    timestamp = message.timestamp();
    function = message.function();
    description = message.description();
}

Error::operator PbTelemetry::Error() const {
    PbTelemetry::Error ret;
    ret.set_timestamp(timestamp);
    ret.set_function(function);
    ret.set_description(description);
    return ret;
}

std::string Error::serializeAsJsonString() const {
    PbTelemetry::Error message(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(message, &ret, options);
    return ret;
}

std::string Error::serializeAsProtobufString() const {
    PbTelemetry::Error message(*this);
    return message.SerializeAsString();
}

bool Error::deserializeFromJsonString(const std::string& str) {
    PbTelemetry::Error message;
    auto status = google::protobuf::util::JsonStringToMessage(str, &message);
    if(status.ok()) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

bool Error::deserializeFromProtobufString(const std::string& str) {
    PbTelemetry::Error message;
    if(message.ParseFromString(str)) {
        *this = message;
        return true;
    } else {
        return false;
    }
}
}
}