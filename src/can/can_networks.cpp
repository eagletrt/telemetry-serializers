#include "can/can_networks.h"

#include <google/protobuf/util/json_util.h>

namespace Serializers
{
namespace Can
{
CanMessage::CanMessage(const PbCan::CanMessage& protobuf) {
    id = protobuf.id();
    name = protobuf.name();
    data = protobuf.data();
    timestamp = protobuf.timestamp();
    frequency = protobuf.frequency();
}

CanMessage::operator PbCan::CanMessage() const {
    PbCan::CanMessage ret;
    ret.set_id(id);
    ret.set_name(name);
    ret.set_data(data);
    ret.set_timestamp(timestamp);
    ret.set_frequency(frequency);
    return ret;
}

std::string CanMessage::serializeAsJsonString() const {
    PbCan::CanMessage protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string CanMessage::serializeAsProtobufString() const {
    PbCan::CanMessage protobuf(*this);
    return protobuf.SerializeAsString();
}

bool CanMessage::deserializeFromJsonString(const std::string& str) {
    PbCan::CanMessage protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool CanMessage::deserializeFromProtobufString(const std::string& str) {
    PbCan::CanMessage protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

CanNetwork::CanNetwork(const PbCan::CanNetwork& protobuf) {
    name = protobuf.name();
    canMessages = {protobuf.canmessages().begin(), protobuf.canmessages().end()};
}

CanNetwork::operator PbCan::CanNetwork() const {
    PbCan::CanNetwork ret;
    ret.set_name(name);
    *(ret.mutable_canmessages()) = {canMessages.begin(), canMessages.end()};
    return ret;
}

std::string CanNetwork::serializeAsJsonString() const {
    PbCan::CanNetwork protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string CanNetwork::serializeAsProtobufString() const {
    PbCan::CanNetwork protobuf(*this);
    return protobuf.SerializeAsString();
}

bool CanNetwork::deserializeFromJsonString(const std::string& str) {
    PbCan::CanNetwork protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool CanNetwork::deserializeFromProtobufString(const std::string& str) {
    PbCan::CanNetwork protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

CanNetworks::CanNetworks(const PbCan::CanNetworks& protobuf) {
    timestamp = protobuf.timestamp();
    networks = {protobuf.networks().begin(), protobuf.networks().end()};
}

CanNetworks::operator PbCan::CanNetworks() const {
    PbCan::CanNetworks ret;
    ret.set_timestamp(timestamp);
    *(ret.mutable_networks()) = {networks.begin(), networks.end()};
    return ret;
}

std::string CanNetworks::serializeAsJsonString() const {
    PbCan::CanNetworks protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string CanNetworks::serializeAsProtobufString() const {
    PbCan::CanNetworks protobuf(*this);
    return protobuf.SerializeAsString();
}

bool CanNetworks::deserializeFromJsonString(const std::string& str) {
    PbCan::CanNetworks protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool CanNetworks::deserializeFromProtobufString(const std::string& str) {
    PbCan::CanNetworks protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}