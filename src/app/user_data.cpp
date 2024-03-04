#include "app/user_data.h"

#include <google/protobuf/util/json_util.h>

namespace Serializers
{
namespace App
{
UserData::UserData(const PbApp::UserData& message) {
    username = message.username();
    token = message.token();
    refreshToken = message.refreshtoken();
    expiry = message.expiry();
    role = message.role();
}

UserData::operator PbApp::UserData() const {
    PbApp::UserData ret;
    ret.set_username(username);
    ret.set_token(token);
    ret.set_refreshtoken(refreshToken);
    ret.set_expiry(expiry);
    ret.set_role(role);
    return ret;
}

std::string UserData::serializeAsJsonString() const {
    PbApp::UserData message(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(message, &ret, options);
    return ret;
}

std::string UserData::serializeAsProtobufString() const {
    PbApp::UserData message(*this);
    return message.SerializeAsString();
}

bool UserData::deserializeFromJsonString(const std::string& str) {
    PbApp::UserData message;
    auto status = google::protobuf::util::JsonStringToMessage(str, &message);
    if(status.ok()) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

bool UserData::deserializeFromProtobufString(const std::string& str) {
    PbApp::UserData message;
    if(message.ParseFromString(str)) {
        *this = message;
        return true;
    } else {
        return false;
    }
}
}
}