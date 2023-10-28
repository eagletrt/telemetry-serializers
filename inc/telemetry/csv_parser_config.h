#ifndef CSV_PARSER_CONFIG_H
#define CSV_PARSER_CONFIG_H

#include "csv_parser_config.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

typedef Telemetry::CsvParserConfig TelemetryCsvParserConfig;

namespace Serializers
{
namespace Telemetry
{
struct CsvParserConfig
{
    std::string subfolderName;
    bool parseCan;
    bool parseGps;
    bool generateReport;
    
    CsvParserConfig() = default;
    CsvParserConfig(const TelemetryCsvParserConfig& proto);
    operator TelemetryCsvParserConfig() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif