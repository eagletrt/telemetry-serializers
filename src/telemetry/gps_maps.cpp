#include "telemetry/gps_maps.h"

#include <google/protobuf/util/json_util.h>

namespace Serializers
{
namespace Telemetry
{
GPSMapOrigin::GPSMapOrigin(const PbTelemetry::GPSMapOrigin& protobuf) {
    latitude = protobuf.latitude();
    longitude = protobuf.longitude();
    ecefX = protobuf.ecefx();
    ecefY = protobuf.ecefy();
    ecefZ = protobuf.ecefz();
}

GPSMapOrigin::operator PbTelemetry::GPSMapOrigin() const {
    PbTelemetry::GPSMapOrigin ret;
    ret.set_latitude(latitude);
    ret.set_longitude(longitude);
    ret.set_ecefx(ecefX);
    ret.set_ecefy(ecefY);
    ret.set_ecefz(ecefZ);
    return ret;
}

std::string GPSMapOrigin::serializeAsJsonString() const {
    PbTelemetry::GPSMapOrigin protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string GPSMapOrigin::serializeAsProtobufString() const {
    PbTelemetry::GPSMapOrigin protobuf(*this);
    return protobuf.SerializeAsString();
}

bool GPSMapOrigin::deserializeFromJsonString(const std::string& str) {
    PbTelemetry::GPSMapOrigin protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool GPSMapOrigin::deserializeFromProtobufString(const std::string& str) {
    PbTelemetry::GPSMapOrigin protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

GPSMapOrigins::GPSMapOrigins(const PbTelemetry::GPSMapOrigins& protobuf) {
    selectedMap = protobuf.selectedmap();
    origins = {protobuf.origins().begin(), protobuf.origins().end()};
}

GPSMapOrigins::operator PbTelemetry::GPSMapOrigins() const {
    PbTelemetry::GPSMapOrigins ret;
    ret.set_selectedmap(selectedMap);
    *(ret.mutable_origins()) = {origins.begin(), origins.end()};
    return ret;
}

std::string GPSMapOrigins::serializeAsJsonString() const {
    PbTelemetry::GPSMapOrigins protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string GPSMapOrigins::serializeAsProtobufString() const {
    PbTelemetry::GPSMapOrigins protobuf(*this);
    return protobuf.SerializeAsString();
}

bool GPSMapOrigins::deserializeFromJsonString(const std::string& str) {
    PbTelemetry::GPSMapOrigins protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool GPSMapOrigins::deserializeFromProtobufString(const std::string& str) {
    PbTelemetry::GPSMapOrigins protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}