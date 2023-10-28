#include "configs/session_config.h"

#include <google/protobuf/util/json_util.h>

namespace Serializers
{
namespace Configs
{
Weather::Weather(const ConfigsWeather& proto) {
    temperature = proto.temperature();
    humidity = proto.humidity();
}

Weather::operator ConfigsWeather() const {
    ConfigsWeather ret;
    ret.set_temperature(temperature);
    ret.set_humidity(humidity);
    return ret;
}

std::string Weather::serializeAsJsonString() const {
    ConfigsWeather proto(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(proto, &ret, options);
    return ret;
}

std::string Weather::serializeAsProtobufString() const {
    ConfigsWeather proto(*this);
    return proto.SerializeAsString();
}

bool Weather::deserializeFromJsonString(const std::string& str) {
    ConfigsWeather proto;
    auto status = google::protobuf::util::JsonStringToMessage(str, &proto);
    if(status.ok()) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

bool Weather::deserializeFromProtobufString(const std::string& str) {
    ConfigsWeather proto;
    if(proto.ParseFromString(str)) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

SessionConfig::SessionConfig(const ConfigsSessionConfig& proto) {
    circuit = proto.circuit();
    driver = proto.driver();
    race = proto.race();
    test = proto.test();
    date = proto.date();
    time = proto.time();
    weather = proto.weather();
    notes = proto.notes();
    canlibVersion = proto.canlibversion();
}

SessionConfig::operator ConfigsSessionConfig() const {
    ConfigsSessionConfig ret;
    ret.set_circuit(circuit);
    ret.set_driver(driver);
    ret.set_race(race);
    ret.set_test(test);
    ret.set_date(date);
    ret.set_time(time);
    *(ret.mutable_weather()) = weather;
    ret.set_notes(notes);
    ret.set_canlibversion(canlibVersion);
    return ret;
}

std::string SessionConfig::serializeAsJsonString() const {
    ConfigsSessionConfig proto(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(proto, &ret, options);
    return ret;
}

std::string SessionConfig::serializeAsProtobufString() const {
    ConfigsSessionConfig proto(*this);
    return proto.SerializeAsString();
}

bool SessionConfig::deserializeFromJsonString(const std::string& str) {
    ConfigsSessionConfig proto;
    auto status = google::protobuf::util::JsonStringToMessage(str, &proto);
    if(status.ok()) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

bool SessionConfig::deserializeFromProtobufString(const std::string& str) {
    ConfigsSessionConfig proto;
    if(proto.ParseFromString(str)) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}
}
}