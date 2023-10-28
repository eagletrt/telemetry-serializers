#include "telemetry/login_data.h"

#include <google/protobuf/util/json_util.h>

namespace Serializers
{
namespace Telemetry
{
LoginData::LoginData(const TelemetryLoginData& proto) {
    username = proto.username();
    password = proto.password();
}

LoginData::operator TelemetryLoginData() const {
    TelemetryLoginData ret;
    ret.set_username(username);
    ret.set_password(password);
    return ret;
}

std::string LoginData::serializeAsJsonString() const {
    TelemetryLoginData proto(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(proto, &ret, options);
    return ret;
}

std::string LoginData::serializeAsProtobufString() const {
    TelemetryLoginData proto(*this);
    return proto.SerializeAsString();
}

bool LoginData::deserializeFromJsonString(const std::string& str) {
    TelemetryLoginData proto;
    auto status = google::protobuf::util::JsonStringToMessage(str, &proto);
    if(status.ok()) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

bool LoginData::deserializeFromProtobufString(const std::string& str) {
    TelemetryLoginData proto;
    if(proto.ParseFromString(str)) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}
}
}