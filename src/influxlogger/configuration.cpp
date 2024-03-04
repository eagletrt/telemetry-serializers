#include "influxlogger/configuration.h"

#include <google/protobuf/util/json_util.h>

namespace Serializers
{
namespace InfluxLogger
{
Configuration::Configuration(const PbInfluxLogger::Configuration& message) {
    mqtt_host = message.mqtt_host();
    mqtt_port = message.mqtt_port();
    vehicle_id = message.vehicle_id();
    device_id = message.device_id();
    influx_host = message.influx_host();
    influx_port = message.influx_port();
    influx_https = message.influx_https();
    influx_bucket = message.influx_bucket();
    influx_orgid = message.influx_orgid();
    influx_token = message.influx_token();
    networks = {message.networks().begin(), message.networks().end()};
    proxy_host = message.proxy_host();
    proxy_port = message.proxy_port();
}

Configuration::operator PbInfluxLogger::Configuration() const {
    PbInfluxLogger::Configuration ret;
    ret.set_mqtt_host(mqtt_host);
    ret.set_mqtt_port(mqtt_port);
    ret.set_vehicle_id(vehicle_id);
    ret.set_device_id(device_id);
    ret.set_influx_host(influx_host);
    ret.set_influx_port(influx_port);
    ret.set_influx_https(influx_https);
    ret.set_influx_bucket(influx_bucket);
    ret.set_influx_orgid(influx_orgid);
    ret.set_influx_token(influx_token);
    *(ret.mutable_networks()) = {networks.begin(), networks.end()};
    ret.set_proxy_host(proxy_host);
    ret.set_proxy_port(proxy_port);
    return ret;
}

std::string Configuration::serializeAsJsonString() const {
    PbInfluxLogger::Configuration message(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(message, &ret, options);
    return ret;
}

std::string Configuration::serializeAsProtobufString() const {
    PbInfluxLogger::Configuration message(*this);
    return message.SerializeAsString();
}

bool Configuration::deserializeFromJsonString(const std::string& str) {
    PbInfluxLogger::Configuration message;
    auto status = google::protobuf::util::JsonStringToMessage(str, &message);
    if(status.ok()) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

bool Configuration::deserializeFromProtobufString(const std::string& str) {
    PbInfluxLogger::Configuration message;
    if(message.ParseFromString(str)) {
        *this = message;
        return true;
    } else {
        return false;
    }
}
}
}