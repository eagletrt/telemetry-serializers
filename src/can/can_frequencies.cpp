#include "can/can_frequencies.h"

#include <google/protobuf/util/json_util.h>
#include <tuple>

namespace Serializers
{
namespace Can
{
CanFrequency::CanFrequency(const PbCan::CanFrequency& protobuf) {
    timestamp = protobuf.timestamp();
    id = protobuf.id();
    name = protobuf.name();
    data = protobuf.data();
    frequency = protobuf.frequency();
}

CanFrequency::operator PbCan::CanFrequency() const {
    PbCan::CanFrequency ret;
    ret.set_timestamp(timestamp);
    ret.set_id(id);
    ret.set_name(name);
    ret.set_data(data);
    ret.set_frequency(frequency);
    return ret;
}

std::string CanFrequency::serializeAsJsonString() const {
    PbCan::CanFrequency protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string CanFrequency::serializeAsProtobufString() const {
    PbCan::CanFrequency protobuf(*this);
    return protobuf.SerializeAsString();
}

bool CanFrequency::deserializeFromJsonString(const std::string& str) {
    PbCan::CanFrequency protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool CanFrequency::deserializeFromProtobufString(const std::string& str) {
    PbCan::CanFrequency protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

CanFrequencies::CanFrequencies(const PbCan::CanFrequencies& protobuf) {
    frequencies = {protobuf.frequencies().begin(), protobuf.frequencies().end()};
}

CanFrequencies::operator PbCan::CanFrequencies() const {
    PbCan::CanFrequencies ret;
    *(ret.mutable_frequencies()) = {frequencies.begin(), frequencies.end()};
    return ret;
}

std::string CanFrequencies::serializeAsJsonString() const {
    PbCan::CanFrequencies protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string CanFrequencies::serializeAsProtobufString() const {
    PbCan::CanFrequencies protobuf(*this);
    return protobuf.SerializeAsString();
}

bool CanFrequencies::deserializeFromJsonString(const std::string& str) {
    PbCan::CanFrequencies protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool CanFrequencies::deserializeFromProtobufString(const std::string& str) {
    PbCan::CanFrequencies protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

CanNetworksFrequencies::CanNetworksFrequencies(const PbCan::CanNetworksFrequencies& protobuf) {
    timestamp = protobuf.timestamp();
    networks = {protobuf.networks().begin(), protobuf.networks().end()};
}

CanNetworksFrequencies::operator PbCan::CanNetworksFrequencies() const {
    PbCan::CanNetworksFrequencies ret;
    ret.set_timestamp(timestamp);
    *(ret.mutable_networks()) = {networks.begin(), networks.end()};
    return ret;
}

std::string CanNetworksFrequencies::serializeAsJsonString() const {
    PbCan::CanNetworksFrequencies protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string CanNetworksFrequencies::serializeAsProtobufString() const {
    PbCan::CanNetworksFrequencies protobuf(*this);
    return protobuf.SerializeAsString();
}

bool CanNetworksFrequencies::deserializeFromJsonString(const std::string& str) {
    PbCan::CanNetworksFrequencies protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool CanNetworksFrequencies::deserializeFromProtobufString(const std::string& str) {
    PbCan::CanNetworksFrequencies protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}