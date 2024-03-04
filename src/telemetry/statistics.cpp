#include "telemetry/statistics.h"

#include <google/protobuf/util/json_util.h>

namespace Serializers
{
namespace Telemetry
{
Statistics::Statistics(const PbTelemetry::Statistics& message) {
    messages = message.messages();
    averageFrequency = message.averagefrequency();
    seconds = message.seconds();
}

Statistics::operator PbTelemetry::Statistics() const {
    PbTelemetry::Statistics ret;
    ret.set_messages(messages);
    ret.set_averagefrequency(averageFrequency);
    ret.set_seconds(seconds);
    return ret;
}

std::string Statistics::serializeAsJsonString() const {
    PbTelemetry::Statistics message(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(message, &ret, options);
    return ret;
}

std::string Statistics::serializeAsProtobufString() const {
    PbTelemetry::Statistics message(*this);
    return message.SerializeAsString();
}

bool Statistics::deserializeFromJsonString(const std::string& str) {
    PbTelemetry::Statistics message;
    auto status = google::protobuf::util::JsonStringToMessage(str, &message);
    if(status.ok()) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

bool Statistics::deserializeFromProtobufString(const std::string& str) {
    PbTelemetry::Statistics message;
    if(message.ParseFromString(str)) {
        *this = message;
        return true;
    } else {
        return false;
    }
}
}
}