#include "can/can_frequencies.h"

#include <google/protobuf/util/json_util.h>

namespace Serializers
{
namespace Can
{
CanFrequency::CanFrequency(const PbCan::CanFrequency& message) {
    timestamp = message.timestamp();
    id = message.id();
    name = message.name();
    data = message.data();
    frequency = message.frequency();
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
    PbCan::CanFrequency message(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(message, &ret, options);
    return ret;
}

std::string CanFrequency::serializeAsProtobufString() const {
    PbCan::CanFrequency message(*this);
    return message.SerializeAsString();
}

bool CanFrequency::deserializeFromJsonString(const std::string& str) {
    PbCan::CanFrequency message;
    auto status = google::protobuf::util::JsonStringToMessage(str, &message);
    if(status.ok()) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

bool CanFrequency::deserializeFromProtobufString(const std::string& str) {
    PbCan::CanFrequency message;
    if(message.ParseFromString(str)) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

CanFrequencies::CanFrequencies(const PbCan::CanFrequencies& message) {
    frequencies = {message.frequencies().begin(), message.frequencies().end()};
}

CanFrequencies::operator PbCan::CanFrequencies() const {
    PbCan::CanFrequencies ret;
    *(ret.mutable_frequencies()) = {frequencies.begin(), frequencies.end()};
    return ret;
}

std::string CanFrequencies::serializeAsJsonString() const {
    PbCan::CanFrequencies message(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(message, &ret, options);
    return ret;
}

std::string CanFrequencies::serializeAsProtobufString() const {
    PbCan::CanFrequencies message(*this);
    return message.SerializeAsString();
}

bool CanFrequencies::deserializeFromJsonString(const std::string& str) {
    PbCan::CanFrequencies message;
    auto status = google::protobuf::util::JsonStringToMessage(str, &message);
    if(status.ok()) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

bool CanFrequencies::deserializeFromProtobufString(const std::string& str) {
    PbCan::CanFrequencies message;
    if(message.ParseFromString(str)) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

CanNetworksFrequencies::CanNetworksFrequencies(const PbCan::CanNetworksFrequencies& message) {
    timestamp = message.timestamp();
    networks = {message.networks().begin(), message.networks().end()};
}

CanNetworksFrequencies::operator PbCan::CanNetworksFrequencies() const {
    PbCan::CanNetworksFrequencies ret;
    ret.set_timestamp(timestamp);
    *(ret.mutable_networks()) = {networks.begin(), networks.end()};
    return ret;
}

std::string CanNetworksFrequencies::serializeAsJsonString() const {
    PbCan::CanNetworksFrequencies message(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(message, &ret, options);
    return ret;
}

std::string CanNetworksFrequencies::serializeAsProtobufString() const {
    PbCan::CanNetworksFrequencies message(*this);
    return message.SerializeAsString();
}

bool CanNetworksFrequencies::deserializeFromJsonString(const std::string& str) {
    PbCan::CanNetworksFrequencies message;
    auto status = google::protobuf::util::JsonStringToMessage(str, &message);
    if(status.ok()) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

bool CanNetworksFrequencies::deserializeFromProtobufString(const std::string& str) {
    PbCan::CanNetworksFrequencies message;
    if(message.ParseFromString(str)) {
        *this = message;
        return true;
    } else {
        return false;
    }
}
}
}