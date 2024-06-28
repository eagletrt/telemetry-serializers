#include "telemetry/login_data.h"

#include <google/protobuf/util/json_util.h>
#include <tuple>

namespace Serializers
{
namespace Telemetry
{
LoginData::LoginData(const PbTelemetry::LoginData& protobuf) {
    username = protobuf.username();
    password = protobuf.password();
}

LoginData::operator PbTelemetry::LoginData() const {
    PbTelemetry::LoginData ret;
    ret.set_username(username);
    ret.set_password(password);
    return ret;
}

std::string LoginData::serializeAsJsonString() const {
    PbTelemetry::LoginData protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string LoginData::serializeAsProtobufString() const {
    PbTelemetry::LoginData protobuf(*this);
    return protobuf.SerializeAsString();
}

bool LoginData::deserializeFromJsonString(const std::string& str) {
    PbTelemetry::LoginData protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool LoginData::deserializeFromProtobufString(const std::string& str) {
    PbTelemetry::LoginData protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}