#include "app_config.h"

#include <google/protobuf/util/json_util.h>

namespace Serializers
{
Connection::Connection(const app_config::Connection& proto) {
    ip = proto.ip();
    port = proto.port();
    mode = proto.mode();
}

Connection::operator app_config::Connection() const {
    app_config::Connection ret;
    ret.set_ip(ip);
    ret.set_port(port);
    ret.set_mode(mode);
    return ret;
}

std::string Connection::serializeAsJsonString() const {
    app_config::Connection proto(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(proto, &ret, options);
    return ret;
}

std::string Connection::serializeAsProtobufString() const {
    app_config::Connection proto(*this);
    return proto.SerializeAsString();
}

bool Connection::deserializeFromJsonString(const std::string& str) {
    app_config::Connection proto;
    auto status = google::protobuf::util::JsonStringToMessage(str, &proto);
    if(status.ok()) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

bool Connection::deserializeFromProtobufString(const std::string& str) {
    app_config::Connection proto;
    if(proto.ParseFromString(str)) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

Config::Config(const app_config::Config& proto) {
    config = proto.config();
    name = proto.name();
    connection = proto.connection();
}

Config::operator app_config::Config() const {
    app_config::Config ret;
    ret.set_config(config);
    ret.set_name(name);
    *(ret.mutable_connection()) = connection;
    return ret;
}

std::string Config::serializeAsJsonString() const {
    app_config::Config proto(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(proto, &ret, options);
    return ret;
}

std::string Config::serializeAsProtobufString() const {
    app_config::Config proto(*this);
    return proto.SerializeAsString();
}

bool Config::deserializeFromJsonString(const std::string& str) {
    app_config::Config proto;
    auto status = google::protobuf::util::JsonStringToMessage(str, &proto);
    if(status.ok()) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

bool Config::deserializeFromProtobufString(const std::string& str) {
    app_config::Config proto;
    if(proto.ParseFromString(str)) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}
}