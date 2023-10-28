#include "can/can_frequencies.h"

#include <google/protobuf/util/json_util.h>

namespace Serializers
{
namespace Can
{
CanFrequency::CanFrequency(const CanCanFrequency& proto) {
    id = proto.id();
    name = proto.name();
    count = proto.count();
    timestamp = proto.timestamp();
    data = proto.data();
}

CanFrequency::operator CanCanFrequency() const {
    CanCanFrequency ret;
    ret.set_id(id);
    ret.set_name(name);
    ret.set_count(count);
    ret.set_timestamp(timestamp);
    ret.set_data(data);
    return ret;
}

std::string CanFrequency::serializeAsJsonString() const {
    CanCanFrequency proto(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(proto, &ret, options);
    return ret;
}

std::string CanFrequency::serializeAsProtobufString() const {
    CanCanFrequency proto(*this);
    return proto.SerializeAsString();
}

bool CanFrequency::deserializeFromJsonString(const std::string& str) {
    CanCanFrequency proto;
    auto status = google::protobuf::util::JsonStringToMessage(str, &proto);
    if(status.ok()) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

bool CanFrequency::deserializeFromProtobufString(const std::string& str) {
    CanCanFrequency proto;
    if(proto.ParseFromString(str)) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

CanFrequencies::CanFrequencies(const CanCanFrequencies& proto) {
    packTimestamp = proto.packtimestamp();
    canFrequenciesPrimary = {proto.canfrequenciesprimary().begin(), proto.canfrequenciesprimary().end()};
    canFrequenciesSecondary = {proto.canfrequenciessecondary().begin(), proto.canfrequenciessecondary().end()};
}

CanFrequencies::operator CanCanFrequencies() const {
    CanCanFrequencies ret;
    ret.set_packtimestamp(packTimestamp);
    *(ret.mutable_canfrequenciesprimary()) = {canFrequenciesPrimary.begin(), canFrequenciesPrimary.end()};
    *(ret.mutable_canfrequenciessecondary()) = {canFrequenciesSecondary.begin(), canFrequenciesSecondary.end()};
    return ret;
}

std::string CanFrequencies::serializeAsJsonString() const {
    CanCanFrequencies proto(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(proto, &ret, options);
    return ret;
}

std::string CanFrequencies::serializeAsProtobufString() const {
    CanCanFrequencies proto(*this);
    return proto.SerializeAsString();
}

bool CanFrequencies::deserializeFromJsonString(const std::string& str) {
    CanCanFrequencies proto;
    auto status = google::protobuf::util::JsonStringToMessage(str, &proto);
    if(status.ok()) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

bool CanFrequencies::deserializeFromProtobufString(const std::string& str) {
    CanCanFrequencies proto;
    if(proto.ParseFromString(str)) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}
}
}