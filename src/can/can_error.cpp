#include "can/can_error.h"

#include <google/protobuf/util/json_util.h>
#include <tuple>

namespace Serializers
{
namespace Can
{
Invalid_can_id::Invalid_can_id(const PbCan::Invalid_can_id& protobuf) {
    timestamp = protobuf.timestamp();
    id = protobuf.id();
    payload = {protobuf.payload().begin(), protobuf.payload().end()};
    network = protobuf.network();
}

Invalid_can_id::operator PbCan::Invalid_can_id() const {
    PbCan::Invalid_can_id ret;
    ret.set_timestamp(timestamp);
    ret.set_id(id);
    *(ret.mutable_payload()) = {payload.begin(), payload.end()};
    ret.set_network(network);
    return ret;
}

std::string Invalid_can_id::serializeAsJsonString() const {
    PbCan::Invalid_can_id protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Invalid_can_id::serializeAsProtobufString() const {
    PbCan::Invalid_can_id protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Invalid_can_id::deserializeFromJsonString(const std::string& str) {
    PbCan::Invalid_can_id protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Invalid_can_id::deserializeFromProtobufString(const std::string& str) {
    PbCan::Invalid_can_id protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}