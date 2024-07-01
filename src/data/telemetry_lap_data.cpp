#include "data/telemetry_lap_data.h"

#include <google/protobuf/util/json_util.h>
#include <tuple>

namespace Serializers
{
namespace Data
{
VectorDouble::VectorDouble(const PbData::VectorDouble& protobuf) {
    data = {protobuf.data().begin(), protobuf.data().end()};
}

VectorDouble::operator PbData::VectorDouble() const {
    PbData::VectorDouble ret;
    *(ret.mutable_data()) = {data.begin(), data.end()};
    return ret;
}

std::string VectorDouble::serializeAsJsonString() const {
    PbData::VectorDouble protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string VectorDouble::serializeAsProtobufString() const {
    PbData::VectorDouble protobuf(*this);
    return protobuf.SerializeAsString();
}

bool VectorDouble::deserializeFromJsonString(const std::string& str) {
    PbData::VectorDouble protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool VectorDouble::deserializeFromProtobufString(const std::string& str) {
    PbData::VectorDouble protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

TelemetryLapData::TelemetryLapData(const PbData::TelemetryLapData& protobuf) {
    dateTime = protobuf.datetime();
    circuitId = protobuf.circuitid();
    layoutId = protobuf.layoutid();
    driverId = protobuf.driverid();
    lapNumber = protobuf.lapnumber();
    data = {protobuf.data().begin(), protobuf.data().end()};
}

TelemetryLapData::operator PbData::TelemetryLapData() const {
    PbData::TelemetryLapData ret;
    ret.set_datetime(dateTime);
    ret.set_circuitid(circuitId);
    ret.set_layoutid(layoutId);
    ret.set_driverid(driverId);
    ret.set_lapnumber(lapNumber);
    *(ret.mutable_data()) = {data.begin(), data.end()};
    return ret;
}

std::string TelemetryLapData::serializeAsJsonString() const {
    PbData::TelemetryLapData protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string TelemetryLapData::serializeAsProtobufString() const {
    PbData::TelemetryLapData protobuf(*this);
    return protobuf.SerializeAsString();
}

bool TelemetryLapData::deserializeFromJsonString(const std::string& str) {
    PbData::TelemetryLapData protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool TelemetryLapData::deserializeFromProtobufString(const std::string& str) {
    PbData::TelemetryLapData protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}