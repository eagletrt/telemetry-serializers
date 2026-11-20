#include "actions/rtcm_source.h"

#include <google/protobuf/util/json_util.h>
#include <tuple>

namespace Serializers
{
namespace Actions
{
RtcmSource::RtcmSource(const PbActions::RtcmSource& protobuf) {
    type = protobuf.type();
    topic = protobuf.topic();
    ref_topic = protobuf.ref_topic();
    profile = protobuf.profile();
}

RtcmSource::operator PbActions::RtcmSource() const {
    PbActions::RtcmSource ret;
    ret.set_type(type);
    ret.set_topic(topic);
    ret.set_ref_topic(ref_topic);
    ret.set_profile(profile);
    return ret;
}

std::string RtcmSource::serializeAsJsonString() const {
    PbActions::RtcmSource protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string RtcmSource::serializeAsProtobufString() const {
    PbActions::RtcmSource protobuf(*this);
    return protobuf.SerializeAsString();
}

bool RtcmSource::deserializeFromJsonString(const std::string& str) {
    PbActions::RtcmSource protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool RtcmSource::deserializeFromProtobufString(const std::string& str) {
    PbActions::RtcmSource protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

RtcmSourceCommand::RtcmSourceCommand(const PbActions::RtcmSourceCommand& protobuf) {
    seq = protobuf.seq();
    base = protobuf.base();
    by = protobuf.by();
    source = protobuf.source();
}

RtcmSourceCommand::operator PbActions::RtcmSourceCommand() const {
    PbActions::RtcmSourceCommand ret;
    ret.set_seq(seq);
    ret.set_base(base);
    ret.set_by(by);
    *(ret.mutable_source()) = source;
    return ret;
}

std::string RtcmSourceCommand::serializeAsJsonString() const {
    PbActions::RtcmSourceCommand protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string RtcmSourceCommand::serializeAsProtobufString() const {
    PbActions::RtcmSourceCommand protobuf(*this);
    return protobuf.SerializeAsString();
}

bool RtcmSourceCommand::deserializeFromJsonString(const std::string& str) {
    PbActions::RtcmSourceCommand protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool RtcmSourceCommand::deserializeFromProtobufString(const std::string& str) {
    PbActions::RtcmSourceCommand protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

RtcmSourceStatus::RtcmSourceStatus(const PbActions::RtcmSourceStatus& protobuf) {
    seq = protobuf.seq();
    ok = protobuf.ok();
    source = protobuf.source();
    error = protobuf.error();
    rtcm_age_s = protobuf.rtcm_age_s();
    rtcm_bytes = protobuf.rtcm_bytes();
    frames = protobuf.frames();
    bad_frames = protobuf.bad_frames();
}

RtcmSourceStatus::operator PbActions::RtcmSourceStatus() const {
    PbActions::RtcmSourceStatus ret;
    ret.set_seq(seq);
    ret.set_ok(ok);
    *(ret.mutable_source()) = source;
    ret.set_error(error);
    ret.set_rtcm_age_s(rtcm_age_s);
    ret.set_rtcm_bytes(rtcm_bytes);
    ret.set_frames(frames);
    ret.set_bad_frames(bad_frames);
    return ret;
}

std::string RtcmSourceStatus::serializeAsJsonString() const {
    PbActions::RtcmSourceStatus protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string RtcmSourceStatus::serializeAsProtobufString() const {
    PbActions::RtcmSourceStatus protobuf(*this);
    return protobuf.SerializeAsString();
}

bool RtcmSourceStatus::deserializeFromJsonString(const std::string& str) {
    PbActions::RtcmSourceStatus protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool RtcmSourceStatus::deserializeFromProtobufString(const std::string& str) {
    PbActions::RtcmSourceStatus protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}