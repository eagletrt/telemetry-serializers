#include "data/telemetry_lap_data.h"

#include <google/protobuf/util/json_util.h>
#include <tuple>

namespace Serializers
{
namespace Data
{
VectorDouble::VectorDouble(const PbData::VectorDouble& protobuf) {
    buffer = {protobuf.buffer().begin(), protobuf.buffer().end()};
}

VectorDouble::operator PbData::VectorDouble() const {
    PbData::VectorDouble ret;
    *(ret.mutable_buffer()) = {buffer.begin(), buffer.end()};
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

DataFile::DataFile(const PbData::DataFile& protobuf) {
    data = {protobuf.data().begin(), protobuf.data().end()};
}

DataFile::operator PbData::DataFile() const {
    PbData::DataFile ret;
    *(ret.mutable_data()) = {data.begin(), data.end()};
    return ret;
}

std::string DataFile::serializeAsJsonString() const {
    PbData::DataFile protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string DataFile::serializeAsProtobufString() const {
    PbData::DataFile protobuf(*this);
    return protobuf.SerializeAsString();
}

bool DataFile::deserializeFromJsonString(const std::string& str) {
    PbData::DataFile protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool DataFile::deserializeFromProtobufString(const std::string& str) {
    PbData::DataFile protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

TelemetryLapData::TelemetryLapData(const PbData::TelemetryLapData& protobuf) {
    dateTime = protobuf.datetime();
    trackLocation = protobuf.tracklocation();
    trackLayout = protobuf.tracklayout();
    driver = protobuf.driver();
    lapNumber = protobuf.lapnumber();
    filenameHash = protobuf.filenamehash();
}

TelemetryLapData::operator PbData::TelemetryLapData() const {
    PbData::TelemetryLapData ret;
    ret.set_datetime(dateTime);
    ret.set_tracklocation(trackLocation);
    ret.set_tracklayout(trackLayout);
    ret.set_driver(driver);
    ret.set_lapnumber(lapNumber);
    ret.set_filenamehash(filenameHash);
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

DataBase::DataBase(const PbData::DataBase& protobuf) {
    lapsData = {protobuf.lapsdata().begin(), protobuf.lapsdata().end()};
}

DataBase::operator PbData::DataBase() const {
    PbData::DataBase ret;
    *(ret.mutable_lapsdata()) = {lapsData.begin(), lapsData.end()};
    return ret;
}

std::string DataBase::serializeAsJsonString() const {
    PbData::DataBase protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string DataBase::serializeAsProtobufString() const {
    PbData::DataBase protobuf(*this);
    return protobuf.SerializeAsString();
}

bool DataBase::deserializeFromJsonString(const std::string& str) {
    PbData::DataBase protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool DataBase::deserializeFromProtobufString(const std::string& str) {
    PbData::DataBase protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}