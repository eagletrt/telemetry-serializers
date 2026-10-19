#include "can/can_sand.h"

#include <google/protobuf/util/json_util.h>
#include <tuple>

namespace Serializers
{
namespace Can
{
CanSendMessage::CanSendMessage(const PbCan::CanSendMessage& protobuf) {
    name = protobuf.name();
    device = protobuf.device();
    network = protobuf.network();
    id = protobuf.id();
    fields = protobuf.fields();
    mode = static_cast<CanSendMode>(protobuf.mode());
    frequencyHz = protobuf.frequencyhz();
    enabled = protobuf.enabled();
}

CanSendMessage::operator PbCan::CanSendMessage() const {
    PbCan::CanSendMessage ret;
    ret.set_name(name);
    ret.set_device(device);
    ret.set_network(network);
    ret.set_id(id);
    ret.set_fields(fields);
    ret.set_mode(static_cast<PbCan::CanSendMode>(mode));
    ret.set_frequencyhz(frequencyHz);
    ret.set_enabled(enabled);
    return ret;
}

std::string CanSendMessage::serializeAsJsonString() const {
    PbCan::CanSendMessage protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string CanSendMessage::serializeAsProtobufString() const {
    PbCan::CanSendMessage protobuf(*this);
    return protobuf.SerializeAsString();
}

bool CanSendMessage::deserializeFromJsonString(const std::string& str) {
    PbCan::CanSendMessage protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool CanSendMessage::deserializeFromProtobufString(const std::string& str) {
    PbCan::CanSendMessage protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

CanSendRequest::CanSendRequest(const PbCan::CanSendRequest& protobuf) {
    action = static_cast<CanSendAction>(protobuf.action());
    message = protobuf.message();
}

CanSendRequest::operator PbCan::CanSendRequest() const {
    PbCan::CanSendRequest ret;
    ret.set_action(static_cast<PbCan::CanSendAction>(action));
    *(ret.mutable_message()) = message;
    return ret;
}

std::string CanSendRequest::serializeAsJsonString() const {
    PbCan::CanSendRequest protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string CanSendRequest::serializeAsProtobufString() const {
    PbCan::CanSendRequest protobuf(*this);
    return protobuf.SerializeAsString();
}

bool CanSendRequest::deserializeFromJsonString(const std::string& str) {
    PbCan::CanSendRequest protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool CanSendRequest::deserializeFromProtobufString(const std::string& str) {
    PbCan::CanSendRequest protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

CanSendList::CanSendList(const PbCan::CanSendList& protobuf) {
    messages = {protobuf.messages().begin(), protobuf.messages().end()};
}

CanSendList::operator PbCan::CanSendList() const {
    PbCan::CanSendList ret;
    *(ret.mutable_messages()) = {messages.begin(), messages.end()};
    return ret;
}

std::string CanSendList::serializeAsJsonString() const {
    PbCan::CanSendList protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string CanSendList::serializeAsProtobufString() const {
    PbCan::CanSendList protobuf(*this);
    return protobuf.SerializeAsString();
}

bool CanSendList::deserializeFromJsonString(const std::string& str) {
    PbCan::CanSendList protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool CanSendList::deserializeFromProtobufString(const std::string& str) {
    PbCan::CanSendList protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}