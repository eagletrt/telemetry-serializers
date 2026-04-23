#include "telemetry/statistics.h"

#include <google/protobuf/util/json_util.h>
#include <tuple>

namespace Serializers
{
namespace Telemetry
{
Statistics::Statistics(const PbTelemetry::Statistics& protobuf) {
    messages = protobuf.messages();
    averageFrequency = protobuf.averagefrequency();
    seconds = protobuf.seconds();
}

Statistics::operator PbTelemetry::Statistics() const {
    PbTelemetry::Statistics ret;
    ret.set_messages(messages);
    ret.set_averagefrequency(averageFrequency);
    ret.set_seconds(seconds);
    return ret;
}

std::string Statistics::serializeAsJsonString() const {
    PbTelemetry::Statistics protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Statistics::serializeAsProtobufString() const {
    PbTelemetry::Statistics protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Statistics::deserializeFromJsonString(const std::string& str) {
    PbTelemetry::Statistics protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Statistics::deserializeFromProtobufString(const std::string& str) {
    PbTelemetry::Statistics protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}