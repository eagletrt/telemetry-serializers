#include "configs/telemetry_config.h"

#include <google/protobuf/util/json_util.h>

namespace Serializers
{
namespace Configs
{
CanDevice::CanDevice(const ConfigsCanDevice& proto) {
    socket = proto.socket();
    name = proto.name();
    networks = {proto.networks().begin(), proto.networks().end()};
}

CanDevice::operator ConfigsCanDevice() const {
    ConfigsCanDevice ret;
    ret.set_socket(socket);
    ret.set_name(name);
    *(ret.mutable_networks()) = {networks.begin(), networks.end()};
    return ret;
}

std::string CanDevice::serializeAsJsonString() const {
    ConfigsCanDevice proto(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(proto, &ret, options);
    return ret;
}

std::string CanDevice::serializeAsProtobufString() const {
    ConfigsCanDevice proto(*this);
    return proto.SerializeAsString();
}

bool CanDevice::deserializeFromJsonString(const std::string& str) {
    ConfigsCanDevice proto;
    auto status = google::protobuf::util::JsonStringToMessage(str, &proto);
    if(status.ok()) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

bool CanDevice::deserializeFromProtobufString(const std::string& str) {
    ConfigsCanDevice proto;
    if(proto.ParseFromString(str)) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

GpsDevice::GpsDevice(const ConfigsGpsDevice& proto) {
    address = proto.address();
    mode = proto.mode();
    enabled = proto.enabled();
}

GpsDevice::operator ConfigsGpsDevice() const {
    ConfigsGpsDevice ret;
    ret.set_address(address);
    ret.set_mode(mode);
    ret.set_enabled(enabled);
    return ret;
}

std::string GpsDevice::serializeAsJsonString() const {
    ConfigsGpsDevice proto(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(proto, &ret, options);
    return ret;
}

std::string GpsDevice::serializeAsProtobufString() const {
    ConfigsGpsDevice proto(*this);
    return proto.SerializeAsString();
}

bool GpsDevice::deserializeFromJsonString(const std::string& str) {
    ConfigsGpsDevice proto;
    auto status = google::protobuf::util::JsonStringToMessage(str, &proto);
    if(status.ok()) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

bool GpsDevice::deserializeFromProtobufString(const std::string& str) {
    ConfigsGpsDevice proto;
    if(proto.ParseFromString(str)) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

Connection::Connection(const ConfigsConnection& proto) {
    ip = proto.ip();
    port = proto.port();
    mode = proto.mode();
    whoamiUrl = proto.whoamiurl();
    tlsEnabled = proto.tlsenabled();
    cafile = proto.cafile();
    capath = proto.capath();
    certfile = proto.certfile();
    keyfile = proto.keyfile();
}

Connection::operator ConfigsConnection() const {
    ConfigsConnection ret;
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
    ConfigsConnection proto(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(proto, &ret, options);
    return ret;
}

std::string Connection::serializeAsProtobufString() const {
    ConfigsConnection proto(*this);
    return proto.SerializeAsString();
}

bool Connection::deserializeFromJsonString(const std::string& str) {
    ConfigsConnection proto;
    auto status = google::protobuf::util::JsonStringToMessage(str, &proto);
    if(status.ok()) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

bool Connection::deserializeFromProtobufString(const std::string& str) {
    ConfigsConnection proto;
    if(proto.ParseFromString(str)) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

ConnectionConfig::ConnectionConfig(const ConfigsConnectionConfig& proto) {
    enabled = proto.enabled();
    downsampleEnabled = proto.downsampleenabled();
    downsampleSkipData = proto.downsampleskipdata();
    downsampleMps = proto.downsamplemps();
    sendRate = proto.sendrate();
    sendSensorData = proto.sendsensordata();
}

ConnectionConfig::operator ConfigsConnectionConfig() const {
    ConfigsConnectionConfig ret;
    ret.set_enabled(enabled);
    ret.set_downsampleenabled(downsampleEnabled);
    ret.set_downsampleskipdata(downsampleSkipData);
    ret.set_downsamplemps(downsampleMps);
    ret.set_sendrate(sendRate);
    ret.set_sendsensordata(sendSensorData);
    return ret;
}

std::string ConnectionConfig::serializeAsJsonString() const {
    ConfigsConnectionConfig proto(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(proto, &ret, options);
    return ret;
}

std::string ConnectionConfig::serializeAsProtobufString() const {
    ConfigsConnectionConfig proto(*this);
    return proto.SerializeAsString();
}

bool ConnectionConfig::deserializeFromJsonString(const std::string& str) {
    ConfigsConnectionConfig proto;
    auto status = google::protobuf::util::JsonStringToMessage(str, &proto);
    if(status.ok()) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

bool ConnectionConfig::deserializeFromProtobufString(const std::string& str) {
    ConfigsConnectionConfig proto;
    if(proto.ParseFromString(str)) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

TelemetryConfig::TelemetryConfig(const ConfigsTelemetryConfig& proto) {
    vehicleId = proto.vehicleid();
    deviceId = proto.deviceid();
    role = proto.role();
    cameraEnabled = proto.cameraenabled();
    generateCsv = proto.generatecsv();
    connection = proto.connection();
    connectionConfig = proto.connectionconfig();
    canDevies = {proto.candevies().begin(), proto.candevies().end()};
    gpsDevices = {proto.gpsdevices().begin(), proto.gpsdevices().end()};
}

TelemetryConfig::operator ConfigsTelemetryConfig() const {
    ConfigsTelemetryConfig ret;
    ret.set_vehicleid(vehicleId);
    ret.set_deviceid(deviceId);
    ret.set_role(role);
    ret.set_cameraenabled(cameraEnabled);
    ret.set_generatecsv(generateCsv);
    *(ret.mutable_connection()) = connection;
    *(ret.mutable_connectionconfig()) = connectionConfig;
    *(ret.mutable_candevies()) = {canDevies.begin(), canDevies.end()};
    *(ret.mutable_gpsdevices()) = {gpsDevices.begin(), gpsDevices.end()};
    return ret;
}

std::string TelemetryConfig::serializeAsJsonString() const {
    ConfigsTelemetryConfig proto(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(proto, &ret, options);
    return ret;
}

std::string TelemetryConfig::serializeAsProtobufString() const {
    ConfigsTelemetryConfig proto(*this);
    return proto.SerializeAsString();
}

bool TelemetryConfig::deserializeFromJsonString(const std::string& str) {
    ConfigsTelemetryConfig proto;
    auto status = google::protobuf::util::JsonStringToMessage(str, &proto);
    if(status.ok()) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

bool TelemetryConfig::deserializeFromProtobufString(const std::string& str) {
    ConfigsTelemetryConfig proto;
    if(proto.ParseFromString(str)) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}
}
}