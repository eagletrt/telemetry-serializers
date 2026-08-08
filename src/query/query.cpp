#include "query/query.h"

#include <google/protobuf/util/json_util.h>
#include <tuple>

namespace Serializers
{
namespace Query
{
Weather::Weather(const PbQuery::Weather& protobuf) {
    ambientTemperature = protobuf.ambienttemperature();
    trackTemperature = protobuf.tracktemperature();
    humidity = protobuf.humidity();
}

Weather::operator PbQuery::Weather() const {
    PbQuery::Weather ret;
    ret.set_ambienttemperature(ambientTemperature);
    ret.set_tracktemperature(trackTemperature);
    ret.set_humidity(humidity);
    return ret;
}

std::string Weather::serializeAsJsonString() const {
    PbQuery::Weather protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string Weather::serializeAsProtobufString() const {
    PbQuery::Weather protobuf(*this);
    return protobuf.SerializeAsString();
}

bool Weather::deserializeFromJsonString(const std::string& str) {
    PbQuery::Weather protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool Weather::deserializeFromProtobufString(const std::string& str) {
    PbQuery::Weather protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

SessionConfig::SessionConfig(const PbQuery::SessionConfig& protobuf) {
    trackLocation = protobuf.tracklocation();
    trackLayout = protobuf.tracklayout();
    sessionName = protobuf.sessionname();
    driver = protobuf.driver();
    date = protobuf.date();
    time = protobuf.time();
    weather = protobuf.weather();
    notes = protobuf.notes();
    canlibVersion = protobuf.canlibversion();
    startTimestamp = protobuf.starttimestamp();
    endTimestamp = protobuf.endtimestamp();
}

SessionConfig::operator PbQuery::SessionConfig() const {
    PbQuery::SessionConfig ret;
    ret.set_tracklocation(trackLocation);
    ret.set_tracklayout(trackLayout);
    ret.set_sessionname(sessionName);
    ret.set_driver(driver);
    ret.set_date(date);
    ret.set_time(time);
    *(ret.mutable_weather()) = weather;
    ret.set_notes(notes);
    ret.set_canlibversion(canlibVersion);
    ret.set_starttimestamp(startTimestamp);
    ret.set_endtimestamp(endTimestamp);
    return ret;
}

std::string SessionConfig::serializeAsJsonString() const {
    PbQuery::SessionConfig protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string SessionConfig::serializeAsProtobufString() const {
    PbQuery::SessionConfig protobuf(*this);
    return protobuf.SerializeAsString();
}

bool SessionConfig::deserializeFromJsonString(const std::string& str) {
    PbQuery::SessionConfig protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool SessionConfig::deserializeFromProtobufString(const std::string& str) {
    PbQuery::SessionConfig protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

SessionByYearMonth::SessionByYearMonth(const PbQuery::SessionByYearMonth& protobuf) {
    year = protobuf.year();
    month = protobuf.month();
}

SessionByYearMonth::operator PbQuery::SessionByYearMonth() const {
    PbQuery::SessionByYearMonth ret;
    ret.set_year(year);
    ret.set_month(month);
    return ret;
}

std::string SessionByYearMonth::serializeAsJsonString() const {
    PbQuery::SessionByYearMonth protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string SessionByYearMonth::serializeAsProtobufString() const {
    PbQuery::SessionByYearMonth protobuf(*this);
    return protobuf.SerializeAsString();
}

bool SessionByYearMonth::deserializeFromJsonString(const std::string& str) {
    PbQuery::SessionByYearMonth protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool SessionByYearMonth::deserializeFromProtobufString(const std::string& str) {
    PbQuery::SessionByYearMonth protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

SessionByYearMonthFound::SessionByYearMonthFound(const PbQuery::SessionByYearMonthFound& protobuf) {
    daysFound = {protobuf.daysfound().begin(), protobuf.daysfound().end()};
}

SessionByYearMonthFound::operator PbQuery::SessionByYearMonthFound() const {
    PbQuery::SessionByYearMonthFound ret;
    *(ret.mutable_daysfound()) = {daysFound.begin(), daysFound.end()};
    return ret;
}

std::string SessionByYearMonthFound::serializeAsJsonString() const {
    PbQuery::SessionByYearMonthFound protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string SessionByYearMonthFound::serializeAsProtobufString() const {
    PbQuery::SessionByYearMonthFound protobuf(*this);
    return protobuf.SerializeAsString();
}

bool SessionByYearMonthFound::deserializeFromJsonString(const std::string& str) {
    PbQuery::SessionByYearMonthFound protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool SessionByYearMonthFound::deserializeFromProtobufString(const std::string& str) {
    PbQuery::SessionByYearMonthFound protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

SessionByDayRange::SessionByDayRange(const PbQuery::SessionByDayRange& protobuf) {
    yearMonth = protobuf.yearmonth();
    startDay = protobuf.startday();
    endDay = protobuf.endday();
}

SessionByDayRange::operator PbQuery::SessionByDayRange() const {
    PbQuery::SessionByDayRange ret;
    *(ret.mutable_yearmonth()) = yearMonth;
    ret.set_startday(startDay);
    ret.set_endday(endDay);
    return ret;
}

std::string SessionByDayRange::serializeAsJsonString() const {
    PbQuery::SessionByDayRange protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string SessionByDayRange::serializeAsProtobufString() const {
    PbQuery::SessionByDayRange protobuf(*this);
    return protobuf.SerializeAsString();
}

bool SessionByDayRange::deserializeFromJsonString(const std::string& str) {
    PbQuery::SessionByDayRange protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool SessionByDayRange::deserializeFromProtobufString(const std::string& str) {
    PbQuery::SessionByDayRange protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

sessionByDayRangeFound::sessionByDayRangeFound(const PbQuery::sessionByDayRangeFound& protobuf) {
    sessionsFound = {protobuf.sessionsfound().begin(), protobuf.sessionsfound().end()};
}

sessionByDayRangeFound::operator PbQuery::sessionByDayRangeFound() const {
    PbQuery::sessionByDayRangeFound ret;
    *(ret.mutable_sessionsfound()) = {sessionsFound.begin(), sessionsFound.end()};
    return ret;
}

std::string sessionByDayRangeFound::serializeAsJsonString() const {
    PbQuery::sessionByDayRangeFound protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string sessionByDayRangeFound::serializeAsProtobufString() const {
    PbQuery::sessionByDayRangeFound protobuf(*this);
    return protobuf.SerializeAsString();
}

bool sessionByDayRangeFound::deserializeFromJsonString(const std::string& str) {
    PbQuery::sessionByDayRangeFound protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool sessionByDayRangeFound::deserializeFromProtobufString(const std::string& str) {
    PbQuery::sessionByDayRangeFound protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}