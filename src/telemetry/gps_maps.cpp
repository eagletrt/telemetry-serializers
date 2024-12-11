#include "telemetry/gps_maps.h"

#include <google/protobuf/util/json_util.h>
#include <tuple>

namespace Serializers
{
namespace Telemetry
{
Baseline::Baseline(const PbTelemetry::Baseline& protobuf) {
    valid = protobuf.valid();
    logging = protobuf.logging();
    length = protobuf.length();
    x = {protobuf.x().begin(), protobuf.x().end()};
    y = {protobuf.y().begin(), protobuf.y().end()};
    resampled = protobuf.resampled();
    s = {protobuf.s().begin(), protobuf.s().end()};
    theta = {protobuf.theta().begin(), protobuf.theta().end()};
}

Baseline::operator PbTelemetry::Baseline() const {
    PbTelemetry::Baseline ret;
    ret.set_valid(valid);
    ret.set_logging(logging);
    ret.set_length(length);
    *(ret.mutable_x()) = {x.begin(), x.end()};
    *(ret.mutable_y()) = {y.begin(), y.end()};
    ret.set_resampled(resampled);
    *(ret.mutable_s()) = {s.begin(), s.end()};
    *(ret.mutable_theta()) = {theta.begin(), theta.end()};
    return ret;
}

std::string Baseline::serializeAsJsonString() const {
    PbTelemetry::Baseline protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Baseline::serializeAsProtobufString() const {
    PbTelemetry::Baseline protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Baseline::deserializeFromJsonString(const std::string& str) {
    PbTelemetry::Baseline protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Baseline::deserializeFromProtobufString(const std::string& str) {
    PbTelemetry::Baseline protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

GPSMapOrigin::GPSMapOrigin(const PbTelemetry::GPSMapOrigin& protobuf) {
    latitude = protobuf.latitude();
    longitude = protobuf.longitude();
    altitude = protobuf.altitude();
}

GPSMapOrigin::operator PbTelemetry::GPSMapOrigin() const {
    PbTelemetry::GPSMapOrigin ret;
    ret.set_latitude(latitude);
    ret.set_longitude(longitude);
    ret.set_altitude(altitude);
    return ret;
}

std::string GPSMapOrigin::serializeAsJsonString() const {
    PbTelemetry::GPSMapOrigin protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
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
    trackLocation = protobuf.tracklocation();
    trackLayout = protobuf.tracklayout();
    origins = {protobuf.origins().begin(), protobuf.origins().end()};
    tracksBaseline = {protobuf.tracksbaseline().begin(), protobuf.tracksbaseline().end()};
}

GPSMapOrigins::operator PbTelemetry::GPSMapOrigins() const {
    PbTelemetry::GPSMapOrigins ret;
    ret.set_tracklocation(trackLocation);
    ret.set_tracklayout(trackLayout);
    *(ret.mutable_origins()) = {origins.begin(), origins.end()};
    *(ret.mutable_tracksbaseline()) = {tracksBaseline.begin(), tracksBaseline.end()};
    return ret;
}

std::string GPSMapOrigins::serializeAsJsonString() const {
    PbTelemetry::GPSMapOrigins protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
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

SetBaseline::SetBaseline(const PbTelemetry::SetBaseline& protobuf) {
    trackLocation = protobuf.tracklocation();
    trackLayout = protobuf.tracklayout();
    origin = protobuf.origin();
    x = {protobuf.x().begin(), protobuf.x().end()};
    y = {protobuf.y().begin(), protobuf.y().end()};
}

SetBaseline::operator PbTelemetry::SetBaseline() const {
    PbTelemetry::SetBaseline ret;
    ret.set_tracklocation(trackLocation);
    ret.set_tracklayout(trackLayout);
    *(ret.mutable_origin()) = origin;
    *(ret.mutable_x()) = {x.begin(), x.end()};
    *(ret.mutable_y()) = {y.begin(), y.end()};
    return ret;
}

std::string SetBaseline::serializeAsJsonString() const {
    PbTelemetry::SetBaseline protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string SetBaseline::serializeAsProtobufString() const {
    PbTelemetry::SetBaseline protobuf(*this);
    return protobuf.SerializeAsString();
}

bool SetBaseline::deserializeFromJsonString(const std::string& str) {
    PbTelemetry::SetBaseline protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool SetBaseline::deserializeFromProtobufString(const std::string& str) {
    PbTelemetry::SetBaseline protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}