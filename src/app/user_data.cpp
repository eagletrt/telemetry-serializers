#include "app/user_data.h"

#include <google/protobuf/util/json_util.h>
#include <tuple>

namespace Serializers
{
namespace App
{
UserData::UserData(const PbApp::UserData& protobuf) {
    username = protobuf.username();
    token = protobuf.token();
    refreshToken = protobuf.refreshtoken();
    expiry = protobuf.expiry();
    role = protobuf.role();
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
    PbApp::UserData protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string UserData::serializeAsProtobufString() const {
    PbApp::UserData protobuf(*this);
    return protobuf.SerializeAsString();
}

bool UserData::deserializeFromJsonString(const std::string& str) {
    PbApp::UserData protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool UserData::deserializeFromProtobufString(const std::string& str) {
    PbApp::UserData protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}