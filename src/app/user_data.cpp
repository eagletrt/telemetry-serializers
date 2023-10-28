#include "app/user_data.h"

#include <google/protobuf/util/json_util.h>

namespace Serializers
{
namespace App
{
UserData::UserData(const AppUserData& proto) {
    username = proto.username();
    token = proto.token();
    refresh_token = proto.refresh_token();
    expiry = proto.expiry();
    role = proto.role();
}

UserData::operator AppUserData() const {
    AppUserData ret;
    ret.set_username(username);
    ret.set_token(token);
    ret.set_refresh_token(refresh_token);
    ret.set_expiry(expiry);
    ret.set_role(role);
    return ret;
}

std::string UserData::serializeAsJsonString() const {
    AppUserData proto(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(proto, &ret, options);
    return ret;
}

std::string UserData::serializeAsProtobufString() const {
    AppUserData proto(*this);
    return proto.SerializeAsString();
}

bool UserData::deserializeFromJsonString(const std::string& str) {
    AppUserData proto;
    auto status = google::protobuf::util::JsonStringToMessage(str, &proto);
    if(status.ok()) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

bool UserData::deserializeFromProtobufString(const std::string& str) {
    AppUserData proto;
    if(proto.ParseFromString(str)) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}
}
}