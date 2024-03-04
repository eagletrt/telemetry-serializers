#include "telemetry/login_data.h"

#include <google/protobuf/util/json_util.h>

namespace Serializers
{
namespace Telemetry
{
LoginData::LoginData(const PbTelemetry::LoginData& message) {
    username = message.username();
    password = message.password();
}

LoginData::operator PbTelemetry::LoginData() const {
    PbTelemetry::LoginData ret;
    ret.set_username(username);
    ret.set_password(password);
    return ret;
}

std::string LoginData::serializeAsJsonString() const {
    PbTelemetry::LoginData message(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(message, &ret, options);
    return ret;
}

std::string LoginData::serializeAsProtobufString() const {
    PbTelemetry::LoginData message(*this);
    return message.SerializeAsString();
}

bool LoginData::deserializeFromJsonString(const std::string& str) {
    PbTelemetry::LoginData message;
    auto status = google::protobuf::util::JsonStringToMessage(str, &message);
    if(status.ok()) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

bool LoginData::deserializeFromProtobufString(const std::string& str) {
    PbTelemetry::LoginData message;
    if(message.ParseFromString(str)) {
        *this = message;
        return true;
    } else {
        return false;
    }
}
}
}