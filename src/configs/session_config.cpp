#include "configs/session_config.h"

#include <google/protobuf/util/json_util.h>

namespace Serializers
{
namespace Configs
{
Weather::Weather(const PbConfigs::Weather& message) {
    ambient_temperature = message.ambient_temperature();
    track_temperature = message.track_temperature();
    humidity = message.humidity();
}

Weather::operator PbConfigs::Weather() const {
    PbConfigs::Weather ret;
    ret.set_ambient_temperature(ambient_temperature);
    ret.set_track_temperature(track_temperature);
    ret.set_humidity(humidity);
    return ret;
}

std::string Weather::serializeAsJsonString() const {
    PbConfigs::Weather message(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(message, &ret, options);
    return ret;
}

std::string Weather::serializeAsProtobufString() const {
    PbConfigs::Weather message(*this);
    return message.SerializeAsString();
}

bool Weather::deserializeFromJsonString(const std::string& str) {
    PbConfigs::Weather message;
    auto status = google::protobuf::util::JsonStringToMessage(str, &message);
    if(status.ok()) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

bool Weather::deserializeFromProtobufString(const std::string& str) {
    PbConfigs::Weather message;
    if(message.ParseFromString(str)) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

SessionConfig::SessionConfig(const PbConfigs::SessionConfig& message) {
    circuitId = message.circuitid();
    raceId = message.raceid();
    test = message.test();
    driverId = message.driverid();
    date = message.date();
    time = message.time();
    weather = message.weather();
    notes = message.notes();
    canlibVersion = message.canlibversion();
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
    PbConfigs::SessionConfig message(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(message, &ret, options);
    return ret;
}

std::string SessionConfig::serializeAsProtobufString() const {
    PbConfigs::SessionConfig message(*this);
    return message.SerializeAsString();
}

bool SessionConfig::deserializeFromJsonString(const std::string& str) {
    PbConfigs::SessionConfig message;
    auto status = google::protobuf::util::JsonStringToMessage(str, &message);
    if(status.ok()) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

bool SessionConfig::deserializeFromProtobufString(const std::string& str) {
    PbConfigs::SessionConfig message;
    if(message.ParseFromString(str)) {
        *this = message;
        return true;
    } else {
        return false;
    }
}
}
}