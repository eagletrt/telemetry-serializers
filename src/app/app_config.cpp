#include "app/app_config.h"

#include <google/protobuf/util/json_util.h>

namespace Serializers
{
namespace App
{
Connection::Connection(const PbApp::Connection& protobuf) {
    ip = protobuf.ip();
    port = protobuf.port();
    mode = protobuf.mode();
}

Connection::operator PbApp::Connection() const {
    PbApp::Connection ret;
    ret.set_ip(ip);
    ret.set_port(port);
    ret.set_mode(mode);
    return ret;
}

std::string Connection::serializeAsJsonString() const {
    PbApp::Connection protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Connection::serializeAsProtobufString() const {
    PbApp::Connection protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Connection::deserializeFromJsonString(const std::string& str) {
    PbApp::Connection protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Connection::deserializeFromProtobufString(const std::string& str) {
    PbApp::Connection protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

AppConfig::AppConfig(const PbApp::AppConfig& protobuf) {
    loginTimestamp = protobuf.logintimestamp();
    colorTheme = protobuf.colortheme();
    mode = protobuf.mode();
    connection = protobuf.connection();
    savedConnections = {protobuf.savedconnections().begin(), protobuf.savedconnections().end()};
    activeTabs = {protobuf.activetabs().begin(), protobuf.activetabs().end()};
    filesPaths = {protobuf.filespaths().begin(), protobuf.filespaths().end()};
    stringCache = {protobuf.stringcache().begin(), protobuf.stringcache().end()};
    boolCache = {protobuf.boolcache().begin(), protobuf.boolcache().end()};
}

AppConfig::operator PbApp::AppConfig() const {
    PbApp::AppConfig ret;
    ret.set_logintimestamp(loginTimestamp);
    ret.set_colortheme(colorTheme);
    ret.set_mode(mode);
    *(ret.mutable_connection()) = connection;
    *(ret.mutable_savedconnections()) = {savedConnections.begin(), savedConnections.end()};
    *(ret.mutable_activetabs()) = {activeTabs.begin(), activeTabs.end()};
    *(ret.mutable_filespaths()) = {filesPaths.begin(), filesPaths.end()};
    *(ret.mutable_stringcache()) = {stringCache.begin(), stringCache.end()};
    *(ret.mutable_boolcache()) = {boolCache.begin(), boolCache.end()};
    return ret;
}

std::string AppConfig::serializeAsJsonString() const {
    PbApp::AppConfig protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string AppConfig::serializeAsProtobufString() const {
    PbApp::AppConfig protobuf(*this);
    return protobuf.SerializeAsString();
}

bool AppConfig::deserializeFromJsonString(const std::string& str) {
    PbApp::AppConfig protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool AppConfig::deserializeFromProtobufString(const std::string& str) {
    PbApp::AppConfig protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}