#include "can/can_frequencies.h"

#include <google/protobuf/util/json_util.h>

namespace Serializers
{
namespace Can
{
CanFrequency::CanFrequency(const PbCan::CanFrequency& protobuf) {
    id = protobuf.id();
    name = protobuf.name();
    count = protobuf.count();
    timestamp = protobuf.timestamp();
    data = protobuf.data();
}

CanFrequency::operator PbCan::CanFrequency() const {
    PbCan::CanFrequency ret;
    ret.set_id(id);
    ret.set_name(name);
    ret.set_count(count);
    ret.set_timestamp(timestamp);
    ret.set_data(data);
    return ret;
}

std::string CanFrequency::serializeAsJsonString() const {
    PbCan::CanFrequency protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
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
    packTimestamp = protobuf.packtimestamp();
    canFrequenciesPrimary = {protobuf.canfrequenciesprimary().begin(), protobuf.canfrequenciesprimary().end()};
    canFrequenciesSecondary = {protobuf.canfrequenciessecondary().begin(), protobuf.canfrequenciessecondary().end()};
}

CanFrequencies::operator PbCan::CanFrequencies() const {
    PbCan::CanFrequencies ret;
    ret.set_packtimestamp(packTimestamp);
    *(ret.mutable_canfrequenciesprimary()) = {canFrequenciesPrimary.begin(), canFrequenciesPrimary.end()};
    *(ret.mutable_canfrequenciessecondary()) = {canFrequenciesSecondary.begin(), canFrequenciesSecondary.end()};
    return ret;
}

std::string CanFrequencies::serializeAsJsonString() const {
    PbCan::CanFrequencies protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
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
}
}