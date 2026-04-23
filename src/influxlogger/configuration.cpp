#include "influxlogger/configuration.h"

#include <google/protobuf/util/json_util.h>
#include <tuple>

namespace Serializers
{
namespace InfluxLogger
{
Configuration::Configuration(const PbInfluxLogger::Configuration& protobuf) {
    mqtt_host = protobuf.mqtt_host();
    mqtt_port = protobuf.mqtt_port();
    vehicle_id = protobuf.vehicle_id();
    device_id = protobuf.device_id();
    influx_host = protobuf.influx_host();
    influx_port = protobuf.influx_port();
    influx_https = protobuf.influx_https();
    influx_bucket = protobuf.influx_bucket();
    influx_orgid = protobuf.influx_orgid();
    influx_token = protobuf.influx_token();
    networks = {protobuf.networks().begin(), protobuf.networks().end()};
    proxy_host = protobuf.proxy_host();
    proxy_port = protobuf.proxy_port();
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
    PbInfluxLogger::Configuration protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Configuration::serializeAsProtobufString() const {
    PbInfluxLogger::Configuration protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Configuration::deserializeFromJsonString(const std::string& str) {
    PbInfluxLogger::Configuration protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Configuration::deserializeFromProtobufString(const std::string& str) {
    PbInfluxLogger::Configuration protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}