#include "sessions/gpsSession.h"

#include <google/protobuf/util/json_util.h>
#include <tuple>

namespace Serializers
{
namespace Sessions
{
GpsSession::GpsSession(const PbSessions::GpsSession& protobuf) {
    gpsName = protobuf.gpsname();
    dateTime = protobuf.datetime();
    durationSeconds = protobuf.durationseconds();
    startTimestamp = protobuf.starttimestamp();
    endTimestamp = protobuf.endtimestamp();
    messages = protobuf.messages();
}

GpsSession::operator PbSessions::GpsSession() const {
    PbSessions::GpsSession ret;
    ret.set_gpsname(gpsName);
    ret.set_datetime(dateTime);
    ret.set_durationseconds(durationSeconds);
    ret.set_starttimestamp(startTimestamp);
    ret.set_endtimestamp(endTimestamp);
    ret.set_messages(messages);
    return ret;
}

std::string GpsSession::serializeAsJsonString() const {
    PbSessions::GpsSession protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string GpsSession::serializeAsProtobufString() const {
    PbSessions::GpsSession protobuf(*this);
    return protobuf.SerializeAsString();
}

bool GpsSession::deserializeFromJsonString(const std::string& str) {
    PbSessions::GpsSession protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool GpsSession::deserializeFromProtobufString(const std::string& str) {
    PbSessions::GpsSession protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}