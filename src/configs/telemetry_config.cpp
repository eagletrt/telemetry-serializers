#include "configs/telemetry_config.h"

#include <google/protobuf/util/json_util.h>

namespace Serializers
{
namespace Configs
{
CanDevice::CanDevice(const PbConfigs::CanDevice& message) {
    socket = message.socket();
    name = message.name();
    networks = {message.networks().begin(), message.networks().end()};
}

CanDevice::operator PbConfigs::CanDevice() const {
    PbConfigs::CanDevice ret;
    ret.set_socket(socket);
    ret.set_name(name);
    *(ret.mutable_networks()) = {networks.begin(), networks.end()};
    return ret;
}

std::string CanDevice::serializeAsJsonString() const {
    PbConfigs::CanDevice message(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(message, &ret, options);
    return ret;
}

std::string CanDevice::serializeAsProtobufString() const {
    PbConfigs::CanDevice message(*this);
    return message.SerializeAsString();
}

bool CanDevice::deserializeFromJsonString(const std::string& str) {
    PbConfigs::CanDevice message;
    auto status = google::protobuf::util::JsonStringToMessage(str, &message);
    if(status.ok()) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

bool CanDevice::deserializeFromProtobufString(const std::string& str) {
    PbConfigs::CanDevice message;
    if(message.ParseFromString(str)) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

GpsDevice::GpsDevice(const PbConfigs::GpsDevice& message) {
    address = message.address();
    mode = message.mode();
    enabled = message.enabled();
}

GpsDevice::operator PbConfigs::GpsDevice() const {
    PbConfigs::GpsDevice ret;
    ret.set_address(address);
    ret.set_mode(mode);
    ret.set_enabled(enabled);
    return ret;
}

std::string GpsDevice::serializeAsJsonString() const {
    PbConfigs::GpsDevice message(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(message, &ret, options);
    return ret;
}

std::string GpsDevice::serializeAsProtobufString() const {
    PbConfigs::GpsDevice message(*this);
    return message.SerializeAsString();
}

bool GpsDevice::deserializeFromJsonString(const std::string& str) {
    PbConfigs::GpsDevice message;
    auto status = google::protobuf::util::JsonStringToMessage(str, &message);
    if(status.ok()) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

bool GpsDevice::deserializeFromProtobufString(const std::string& str) {
    PbConfigs::GpsDevice message;
    if(message.ParseFromString(str)) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

Connection::Connection(const PbConfigs::Connection& message) {
    ip = message.ip();
    port = message.port();
    mode = message.mode();
    whoamiUrl = message.whoamiurl();
    tlsEnabled = message.tlsenabled();
    cafile = message.cafile();
    capath = message.capath();
    certfile = message.certfile();
    keyfile = message.keyfile();
}

Connection::operator PbConfigs::Connection() const {
    PbConfigs::Connection ret;
    ret.set_ip(ip);
    ret.set_port(port);
    ret.set_mode(mode);
    ret.set_whoamiurl(whoamiUrl);
    ret.set_tlsenabled(tlsEnabled);
    ret.set_cafile(cafile);
    ret.set_capath(capath);
    ret.set_certfile(certfile);
    ret.set_keyfile(keyfile);
    return ret;
}

std::string Connection::serializeAsJsonString() const {
    PbConfigs::Connection message(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(message, &ret, options);
    return ret;
}

std::string Connection::serializeAsProtobufString() const {
    PbConfigs::Connection message(*this);
    return message.SerializeAsString();
}

bool Connection::deserializeFromJsonString(const std::string& str) {
    PbConfigs::Connection message;
    auto status = google::protobuf::util::JsonStringToMessage(str, &message);
    if(status.ok()) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

bool Connection::deserializeFromProtobufString(const std::string& str) {
    PbConfigs::Connection message;
    if(message.ParseFromString(str)) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

ConnectionSettings::ConnectionSettings(const PbConfigs::ConnectionSettings& message) {
    enabled = message.enabled();
    downsampleEnabled = message.downsampleenabled();
    downsampleSkipData = message.downsampleskipdata();
    downsampleMps = message.downsamplemps();
    sendRate = message.sendrate();
    sendSensorData = message.sendsensordata();
}

ConnectionSettings::operator PbConfigs::ConnectionSettings() const {
    PbConfigs::ConnectionSettings ret;
    ret.set_enabled(enabled);
    ret.set_downsampleenabled(downsampleEnabled);
    ret.set_downsampleskipdata(downsampleSkipData);
    ret.set_downsamplemps(downsampleMps);
    ret.set_sendrate(sendRate);
    ret.set_sendsensordata(sendSensorData);
    return ret;
}

std::string ConnectionSettings::serializeAsJsonString() const {
    PbConfigs::ConnectionSettings message(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(message, &ret, options);
    return ret;
}

std::string ConnectionSettings::serializeAsProtobufString() const {
    PbConfigs::ConnectionSettings message(*this);
    return message.SerializeAsString();
}

bool ConnectionSettings::deserializeFromJsonString(const std::string& str) {
    PbConfigs::ConnectionSettings message;
    auto status = google::protobuf::util::JsonStringToMessage(str, &message);
    if(status.ok()) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

bool ConnectionSettings::deserializeFromProtobufString(const std::string& str) {
    PbConfigs::ConnectionSettings message;
    if(message.ParseFromString(str)) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

TelemetryConfig::TelemetryConfig(const PbConfigs::TelemetryConfig& message) {
    vehicleId = message.vehicleid();
    deviceId = message.deviceid();
    role = message.role();
    cameraEnabled = message.cameraenabled();
    generateCsv = message.generatecsv();
    connection = message.connection();
    connectionSettings = message.connectionsettings();
    canDevices = {message.candevices().begin(), message.candevices().end()};
    gpsDevices = {message.gpsdevices().begin(), message.gpsdevices().end()};
}

TelemetryConfig::operator PbConfigs::TelemetryConfig() const {
    PbConfigs::TelemetryConfig ret;
    ret.set_vehicleid(vehicleId);
    ret.set_deviceid(deviceId);
    ret.set_role(role);
    ret.set_cameraenabled(cameraEnabled);
    ret.set_generatecsv(generateCsv);
    *(ret.mutable_connection()) = connection;
    *(ret.mutable_connectionsettings()) = connectionSettings;
    *(ret.mutable_candevices()) = {canDevices.begin(), canDevices.end()};
    *(ret.mutable_gpsdevices()) = {gpsDevices.begin(), gpsDevices.end()};
    return ret;
}

std::string TelemetryConfig::serializeAsJsonString() const {
    PbConfigs::TelemetryConfig message(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(message, &ret, options);
    return ret;
}

std::string TelemetryConfig::serializeAsProtobufString() const {
    PbConfigs::TelemetryConfig message(*this);
    return message.SerializeAsString();
}

bool TelemetryConfig::deserializeFromJsonString(const std::string& str) {
    PbConfigs::TelemetryConfig message;
    auto status = google::protobuf::util::JsonStringToMessage(str, &message);
    if(status.ok()) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

bool TelemetryConfig::deserializeFromProtobufString(const std::string& str) {
    PbConfigs::TelemetryConfig message;
    if(message.ParseFromString(str)) {
        *this = message;
        return true;
    } else {
        return false;
    }
}
}
}