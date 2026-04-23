#include "configs/session_config.h"

#include <google/protobuf/util/json_util.h>
#include <tuple>

namespace Serializers
{
namespace Configs
{
Weather::Weather(const PbConfigs::Weather& protobuf) {
    ambientTemperature = protobuf.ambienttemperature();
    trackTemperature = protobuf.tracktemperature();
    humidity = protobuf.humidity();
}

Weather::operator PbConfigs::Weather() const {
    PbConfigs::Weather ret;
    ret.set_ambienttemperature(ambientTemperature);
    ret.set_tracktemperature(trackTemperature);
    ret.set_humidity(humidity);
    return ret;
}

std::string Weather::serializeAsJsonString() const {
    PbConfigs::Weather protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
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
    trackLocation = protobuf.tracklocation();
    trackLayout = protobuf.tracklayout();
    sessionName = protobuf.sessionname();
    driver = protobuf.driver();
    date = protobuf.date();
    time = protobuf.time();
    weather = protobuf.weather();
    notes = protobuf.notes();
    canlibVersion = protobuf.canlibversion();
    startTimestamp = protobuf.starttimestamp();
    endTimestamp = protobuf.endtimestamp();
}

SessionConfig::operator PbConfigs::SessionConfig() const {
    PbConfigs::SessionConfig ret;
    ret.set_tracklocation(trackLocation);
    ret.set_tracklayout(trackLayout);
    ret.set_sessionname(sessionName);
    ret.set_driver(driver);
    ret.set_date(date);
    ret.set_time(time);
    *(ret.mutable_weather()) = weather;
    ret.set_notes(notes);
    ret.set_canlibversion(canlibVersion);
    ret.set_starttimestamp(startTimestamp);
    ret.set_endtimestamp(endTimestamp);
    return ret;
}

std::string SessionConfig::serializeAsJsonString() const {
    PbConfigs::SessionConfig protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
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