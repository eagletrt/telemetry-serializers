#include "telemetry/csv_parser_config.h"

#include <google/protobuf/util/json_util.h>

namespace Serializers
{
namespace Telemetry
{
CsvParserConfig::CsvParserConfig(const TelemetryCsvParserConfig& proto) {
    subfolderName = proto.subfoldername();
    parseCan = proto.parsecan();
    parseGps = proto.parsegps();
    generateReport = proto.generatereport();
}

CsvParserConfig::operator TelemetryCsvParserConfig() const {
    TelemetryCsvParserConfig ret;
    ret.set_subfoldername(subfolderName);
    ret.set_parsecan(parseCan);
    ret.set_parsegps(parseGps);
    ret.set_generatereport(generateReport);
    return ret;
}

std::string CsvParserConfig::serializeAsJsonString() const {
    TelemetryCsvParserConfig proto(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(proto, &ret, options);
    return ret;
}

std::string CsvParserConfig::serializeAsProtobufString() const {
    TelemetryCsvParserConfig proto(*this);
    return proto.SerializeAsString();
}

bool CsvParserConfig::deserializeFromJsonString(const std::string& str) {
    TelemetryCsvParserConfig proto;
    auto status = google::protobuf::util::JsonStringToMessage(str, &proto);
    if(status.ok()) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

bool CsvParserConfig::deserializeFromProtobufString(const std::string& str) {
    TelemetryCsvParserConfig proto;
    if(proto.ParseFromString(str)) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}
}
}