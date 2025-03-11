#include "data/extra.h"

#include <google/protobuf/util/json_util.h>
#include <tuple>

namespace Serializers
{
namespace Data
{
RepeatedValueUint64::RepeatedValueUint64(const PbData::RepeatedValueUint64& protobuf) {
    values = {protobuf.values().begin(), protobuf.values().end()};
}

RepeatedValueUint64::operator PbData::RepeatedValueUint64() const {
    PbData::RepeatedValueUint64 ret;
    *(ret.mutable_values()) = {values.begin(), values.end()};
    return ret;
}

std::string RepeatedValueUint64::serializeAsJsonString() const {
    PbData::RepeatedValueUint64 protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string RepeatedValueUint64::serializeAsProtobufString() const {
    PbData::RepeatedValueUint64 protobuf(*this);
    return protobuf.SerializeAsString();
}

bool RepeatedValueUint64::deserializeFromJsonString(const std::string& str) {
    PbData::RepeatedValueUint64 protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool RepeatedValueUint64::deserializeFromProtobufString(const std::string& str) {
    PbData::RepeatedValueUint64 protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

RepeatedValueDouble::RepeatedValueDouble(const PbData::RepeatedValueDouble& protobuf) {
    values = {protobuf.values().begin(), protobuf.values().end()};
}

RepeatedValueDouble::operator PbData::RepeatedValueDouble() const {
    PbData::RepeatedValueDouble ret;
    *(ret.mutable_values()) = {values.begin(), values.end()};
    return ret;
}

std::string RepeatedValueDouble::serializeAsJsonString() const {
    PbData::RepeatedValueDouble protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string RepeatedValueDouble::serializeAsProtobufString() const {
    PbData::RepeatedValueDouble protobuf(*this);
    return protobuf.SerializeAsString();
}

bool RepeatedValueDouble::deserializeFromJsonString(const std::string& str) {
    PbData::RepeatedValueDouble protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool RepeatedValueDouble::deserializeFromProtobufString(const std::string& str) {
    PbData::RepeatedValueDouble protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

ValuesMap::ValuesMap(const PbData::ValuesMap& protobuf) {
    timestamp = protobuf.timestamp();
    valuesMap = {protobuf.valuesmap().begin(), protobuf.valuesmap().end()};
}

ValuesMap::operator PbData::ValuesMap() const {
    PbData::ValuesMap ret;
    *(ret.mutable_timestamp()) = timestamp;
    *(ret.mutable_valuesmap()) = {valuesMap.begin(), valuesMap.end()};
    return ret;
}

std::string ValuesMap::serializeAsJsonString() const {
    PbData::ValuesMap protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string ValuesMap::serializeAsProtobufString() const {
    PbData::ValuesMap protobuf(*this);
    return protobuf.SerializeAsString();
}

bool ValuesMap::deserializeFromJsonString(const std::string& str) {
    PbData::ValuesMap protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool ValuesMap::deserializeFromProtobufString(const std::string& str) {
    PbData::ValuesMap protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

TimeValuesPack::TimeValuesPack(const PbData::TimeValuesPack& protobuf) {
    valuesPack = {protobuf.valuespack().begin(), protobuf.valuespack().end()};
}

TimeValuesPack::operator PbData::TimeValuesPack() const {
    PbData::TimeValuesPack ret;
    *(ret.mutable_valuespack()) = {valuesPack.begin(), valuesPack.end()};
    return ret;
}

std::string TimeValuesPack::serializeAsJsonString() const {
    PbData::TimeValuesPack protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string TimeValuesPack::serializeAsProtobufString() const {
    PbData::TimeValuesPack protobuf(*this);
    return protobuf.SerializeAsString();
}

bool TimeValuesPack::deserializeFromJsonString(const std::string& str) {
    PbData::TimeValuesPack protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool TimeValuesPack::deserializeFromProtobufString(const std::string& str) {
    PbData::TimeValuesPack protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}