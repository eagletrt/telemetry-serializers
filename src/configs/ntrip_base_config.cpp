#include "configs/ntrip_base_config.h"

#include <google/protobuf/util/json_util.h>
#include <tuple>

namespace Serializers
{
namespace Configs
{
NtripBaseSurveyIn::NtripBaseSurveyIn(const PbConfigs::NtripBaseSurveyIn& protobuf) {
    minDurationS = protobuf.mindurations();
    accuracyLimitM = protobuf.accuracylimitm();
}

NtripBaseSurveyIn::operator PbConfigs::NtripBaseSurveyIn() const {
    PbConfigs::NtripBaseSurveyIn ret;
    ret.set_mindurations(minDurationS);
    ret.set_accuracylimitm(accuracyLimitM);
    return ret;
}

std::string NtripBaseSurveyIn::serializeAsJsonString() const {
    PbConfigs::NtripBaseSurveyIn protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string NtripBaseSurveyIn::serializeAsProtobufString() const {
    PbConfigs::NtripBaseSurveyIn protobuf(*this);
    return protobuf.SerializeAsString();
}

bool NtripBaseSurveyIn::deserializeFromJsonString(const std::string& str) {
    PbConfigs::NtripBaseSurveyIn protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool NtripBaseSurveyIn::deserializeFromProtobufString(const std::string& str) {
    PbConfigs::NtripBaseSurveyIn protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

NtripBaseFixedPosition::NtripBaseFixedPosition(const PbConfigs::NtripBaseFixedPosition& protobuf) {
    lat = protobuf.lat();
    lon = protobuf.lon();
    heightM = protobuf.heightm();
    accuracyM = protobuf.accuracym();
}

NtripBaseFixedPosition::operator PbConfigs::NtripBaseFixedPosition() const {
    PbConfigs::NtripBaseFixedPosition ret;
    ret.set_lat(lat);
    ret.set_lon(lon);
    ret.set_heightm(heightM);
    ret.set_accuracym(accuracyM);
    return ret;
}

std::string NtripBaseFixedPosition::serializeAsJsonString() const {
    PbConfigs::NtripBaseFixedPosition protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string NtripBaseFixedPosition::serializeAsProtobufString() const {
    PbConfigs::NtripBaseFixedPosition protobuf(*this);
    return protobuf.SerializeAsString();
}

bool NtripBaseFixedPosition::deserializeFromJsonString(const std::string& str) {
    PbConfigs::NtripBaseFixedPosition protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool NtripBaseFixedPosition::deserializeFromProtobufString(const std::string& str) {
    PbConfigs::NtripBaseFixedPosition protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

NtripBaseFixAveraging::NtripBaseFixAveraging(const PbConfigs::NtripBaseFixAveraging& protobuf) {
    averageS = protobuf.averages();
    accuracyLimitM = protobuf.accuracylimitm();
    maxStdM = protobuf.maxstdm();
}

NtripBaseFixAveraging::operator PbConfigs::NtripBaseFixAveraging() const {
    PbConfigs::NtripBaseFixAveraging ret;
    ret.set_averages(averageS);
    ret.set_accuracylimitm(accuracyLimitM);
    ret.set_maxstdm(maxStdM);
    return ret;
}

std::string NtripBaseFixAveraging::serializeAsJsonString() const {
    PbConfigs::NtripBaseFixAveraging protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string NtripBaseFixAveraging::serializeAsProtobufString() const {
    PbConfigs::NtripBaseFixAveraging protobuf(*this);
    return protobuf.SerializeAsString();
}

bool NtripBaseFixAveraging::deserializeFromJsonString(const std::string& str) {
    PbConfigs::NtripBaseFixAveraging protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool NtripBaseFixAveraging::deserializeFromProtobufString(const std::string& str) {
    PbConfigs::NtripBaseFixAveraging protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

NtripBaseUpstream::NtripBaseUpstream(const PbConfigs::NtripBaseUpstream& protobuf) {
    casterHost = protobuf.casterhost();
    casterPort = protobuf.casterport();
    mountPoint = protobuf.mountpoint();
    username = protobuf.username();
    password = protobuf.password();
}

NtripBaseUpstream::operator PbConfigs::NtripBaseUpstream() const {
    PbConfigs::NtripBaseUpstream ret;
    ret.set_casterhost(casterHost);
    ret.set_casterport(casterPort);
    ret.set_mountpoint(mountPoint);
    ret.set_username(username);
    ret.set_password(password);
    return ret;
}

std::string NtripBaseUpstream::serializeAsJsonString() const {
    PbConfigs::NtripBaseUpstream protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string NtripBaseUpstream::serializeAsProtobufString() const {
    PbConfigs::NtripBaseUpstream protobuf(*this);
    return protobuf.SerializeAsString();
}

bool NtripBaseUpstream::deserializeFromJsonString(const std::string& str) {
    PbConfigs::NtripBaseUpstream protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool NtripBaseUpstream::deserializeFromProtobufString(const std::string& str) {
    PbConfigs::NtripBaseUpstream protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

NtripBaseDelivery::NtripBaseDelivery(const PbConfigs::NtripBaseDelivery& protobuf) {
    ntrip = protobuf.ntrip();
    mqtt = protobuf.mqtt();
    uplink = protobuf.uplink();
}

NtripBaseDelivery::operator PbConfigs::NtripBaseDelivery() const {
    PbConfigs::NtripBaseDelivery ret;
    ret.set_ntrip(ntrip);
    ret.set_mqtt(mqtt);
    ret.set_uplink(uplink);
    return ret;
}

std::string NtripBaseDelivery::serializeAsJsonString() const {
    PbConfigs::NtripBaseDelivery protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string NtripBaseDelivery::serializeAsProtobufString() const {
    PbConfigs::NtripBaseDelivery protobuf(*this);
    return protobuf.SerializeAsString();
}

bool NtripBaseDelivery::deserializeFromJsonString(const std::string& str) {
    PbConfigs::NtripBaseDelivery protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool NtripBaseDelivery::deserializeFromProtobufString(const std::string& str) {
    PbConfigs::NtripBaseDelivery protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

NtripBaseConfig::NtripBaseConfig(const PbConfigs::NtripBaseConfig& protobuf) {
    mode = static_cast<NtripBaseMode>(protobuf.mode());
    surveyIn = protobuf.surveyin();
    upstream = protobuf.upstream();
    ntripFix = protobuf.ntripfix();
    fixed = protobuf.fixed();
    delivery = protobuf.delivery();
}

NtripBaseConfig::operator PbConfigs::NtripBaseConfig() const {
    PbConfigs::NtripBaseConfig ret;
    ret.set_mode(static_cast<PbConfigs::NtripBaseMode>(mode));
    *(ret.mutable_surveyin()) = surveyIn;
    *(ret.mutable_upstream()) = upstream;
    *(ret.mutable_ntripfix()) = ntripFix;
    *(ret.mutable_fixed()) = fixed;
    *(ret.mutable_delivery()) = delivery;
    return ret;
}

std::string NtripBaseConfig::serializeAsJsonString() const {
    PbConfigs::NtripBaseConfig protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string NtripBaseConfig::serializeAsProtobufString() const {
    PbConfigs::NtripBaseConfig protobuf(*this);
    return protobuf.SerializeAsString();
}

bool NtripBaseConfig::deserializeFromJsonString(const std::string& str) {
    PbConfigs::NtripBaseConfig protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool NtripBaseConfig::deserializeFromProtobufString(const std::string& str) {
    PbConfigs::NtripBaseConfig protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}