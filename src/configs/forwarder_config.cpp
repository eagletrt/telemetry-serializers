#include "configs/forwarder_config.h"

#include <google/protobuf/util/json_util.h>
#include <tuple>

namespace Serializers
{
namespace Configs
{
NtripClient::NtripClient(const PbConfigs::NtripClient& protobuf) {
    casterHost = protobuf.casterhost();
    casterPort = protobuf.casterport();
    mountPoint = protobuf.mountpoint();
    username = protobuf.username();
    password = protobuf.password();
}

NtripClient::operator PbConfigs::NtripClient() const {
    PbConfigs::NtripClient ret;
    ret.set_casterhost(casterHost);
    ret.set_casterport(casterPort);
    ret.set_mountpoint(mountPoint);
    ret.set_username(username);
    ret.set_password(password);
    return ret;
}

std::string NtripClient::serializeAsJsonString() const {
    PbConfigs::NtripClient protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string NtripClient::serializeAsProtobufString() const {
    PbConfigs::NtripClient protobuf(*this);
    return protobuf.SerializeAsString();
}

bool NtripClient::deserializeFromJsonString(const std::string& str) {
    PbConfigs::NtripClient protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool NtripClient::deserializeFromProtobufString(const std::string& str) {
    PbConfigs::NtripClient protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

GpsDev::GpsDev(const PbConfigs::GpsDev& protobuf) {
    address = protobuf.address();
    port = protobuf.port();
    mode = protobuf.mode();
    enabled = protobuf.enabled();
}

GpsDev::operator PbConfigs::GpsDev() const {
    PbConfigs::GpsDev ret;
    ret.set_address(address);
    ret.set_port(port);
    ret.set_mode(mode);
    ret.set_enabled(enabled);
    return ret;
}

std::string GpsDev::serializeAsJsonString() const {
    PbConfigs::GpsDev protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string GpsDev::serializeAsProtobufString() const {
    PbConfigs::GpsDev protobuf(*this);
    return protobuf.SerializeAsString();
}

bool GpsDev::deserializeFromJsonString(const std::string& str) {
    PbConfigs::GpsDev protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool GpsDev::deserializeFromProtobufString(const std::string& str) {
    PbConfigs::GpsDev protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

ForwarderConfig::ForwarderConfig(const PbConfigs::ForwarderConfig& protobuf) {
    gpsDevice = protobuf.gpsdevice();
    ntripClient = protobuf.ntripclient();
}

ForwarderConfig::operator PbConfigs::ForwarderConfig() const {
    PbConfigs::ForwarderConfig ret;
    *(ret.mutable_gpsdevice()) = gpsDevice;
    *(ret.mutable_ntripclient()) = ntripClient;
    return ret;
}

std::string ForwarderConfig::serializeAsJsonString() const {
    PbConfigs::ForwarderConfig protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string ForwarderConfig::serializeAsProtobufString() const {
    PbConfigs::ForwarderConfig protobuf(*this);
    return protobuf.SerializeAsString();
}

bool ForwarderConfig::deserializeFromJsonString(const std::string& str) {
    PbConfigs::ForwarderConfig protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool ForwarderConfig::deserializeFromProtobufString(const std::string& str) {
    PbConfigs::ForwarderConfig protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}