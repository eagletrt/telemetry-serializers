#ifndef SERIALIZERS_QUERY_H
#define SERIALIZERS_QUERY_H

#include "query.pb.h"

#include <cstdint>
#include <optional>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
namespace Query
{
struct Weather
{
    double ambientTemperature;
    double trackTemperature;
    double humidity;
    
    Weather() = default;
    Weather(const PbQuery::Weather& protobuf);
    operator PbQuery::Weather() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct SessionConfig
{
    std::string trackLocation;
    std::string trackLayout;
    std::string sessionName;
    std::string driver;
    std::string date;
    std::string time;
    Weather weather;
    std::string notes;
    double canlibVersion;
    uint64_t startTimestamp;
    uint64_t endTimestamp;
    
    SessionConfig() = default;
    SessionConfig(const PbQuery::SessionConfig& protobuf);
    operator PbQuery::SessionConfig() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct SessionByYearMonth
{
    std::string year;
    std::string month;
    
    SessionByYearMonth() = default;
    SessionByYearMonth(const PbQuery::SessionByYearMonth& protobuf);
    operator PbQuery::SessionByYearMonth() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct SessionByYearMonthFound
{
    std::vector<int32_t> daysFound;
    
    SessionByYearMonthFound() = default;
    SessionByYearMonthFound(const PbQuery::SessionByYearMonthFound& protobuf);
    operator PbQuery::SessionByYearMonthFound() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct SessionByDayRange
{
    SessionByYearMonth yearMonth;
    std::string startDay;
    std::string endDay;
    
    SessionByDayRange() = default;
    SessionByDayRange(const PbQuery::SessionByDayRange& protobuf);
    operator PbQuery::SessionByDayRange() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct SessionByDayRangeFound
{
    std::vector<SessionConfig> sessionsFound;
    
    SessionByDayRangeFound() = default;
    SessionByDayRangeFound(const PbQuery::SessionByDayRangeFound& protobuf);
    operator PbQuery::SessionByDayRangeFound() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif