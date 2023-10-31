#include "configs/session_config.h"

#include <google/protobuf/util/json_util.h>

namespace Serializers
{
namespace Configs
{
Weather::Weather(const PbConfigs::Weather& protobuf) {
    temperature = protobuf.temperature();
    humidity = protobuf.humidity();
}

Weather::operator PbConfigs::Weather() const {
    PbConfigs::Weather ret;
    ret.set_temperature(temperature);
    ret.set_humidity(humidity);
    return ret;
}

std::string Weather::serializeAsJsonString() const {
    PbConfigs::Weather protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Weather::serializeAsProtobufString() const {
    PbConfigs::Weather protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Weather::deserializeFromJsonString(const std::string& str) {
    PbConfigs::Weather protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Weather::deserializeFromProtobufString(const std::string& str) {
    PbConfigs::Weather protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

SessionConfig::SessionConfig(const PbConfigs::SessionConfig& protobuf) {
    circuitId = protobuf.circuitid();
    raceId = protobuf.raceid();
    test = protobuf.test();
    driverId = protobuf.driverid();
    date = protobuf.date();
    time = protobuf.time();
    weather = protobuf.weather();
    notes = protobuf.notes();
    canlibVersion = protobuf.canlibversion();
}

SessionConfig::operator PbConfigs::SessionConfig() const {
    PbConfigs::SessionConfig ret;
    ret.set_circuitid(circuitId);
    ret.set_raceid(raceId);
    ret.set_test(test);
    ret.set_driverid(driverId);
    ret.set_date(date);
    ret.set_time(time);
    *(ret.mutable_weather()) = weather;
    ret.set_notes(notes);
    ret.set_canlibversion(canlibVersion);
    return ret;
}

std::string SessionConfig::serializeAsJsonString() const {
    PbConfigs::SessionConfig protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string SessionConfig::serializeAsProtobufString() const {
    PbConfigs::SessionConfig protobuf(*this);
    return protobuf.SerializeAsString();
}

bool SessionConfig::deserializeFromJsonString(const std::string& str) {
    PbConfigs::SessionConfig protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool SessionConfig::deserializeFromProtobufString(const std::string& str) {
    PbConfigs::SessionConfig protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}