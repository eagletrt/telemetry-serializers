#include "influxlogger/influx_query.h"

#include <google/protobuf/util/json_util.h>
#include <tuple>

namespace Serializers
{
namespace InfluxLogger
{
QueryRequest::QueryRequest(const PbInfluxLogger::QueryRequest& protobuf) {
    start = protobuf.start();
    stop = protobuf.stop();
    transactionId = protobuf.transactionid();
    networks = {protobuf.networks().begin(), protobuf.networks().end()};
    measurements = {protobuf.measurements().begin(), protobuf.measurements().end()};
    format = static_cast<QueryFormat>(protobuf.format());
    compression = static_cast<QueryCompression>(protobuf.compression());
    maxRows = protobuf.maxrows();
    protocolVersion = protobuf.protocolversion();
}

QueryRequest::operator PbInfluxLogger::QueryRequest() const {
    PbInfluxLogger::QueryRequest ret;
    ret.set_start(start);
    ret.set_stop(stop);
    ret.set_transactionid(transactionId);
    *(ret.mutable_networks()) = {networks.begin(), networks.end()};
    *(ret.mutable_measurements()) = {measurements.begin(), measurements.end()};
    ret.set_format(static_cast<PbInfluxLogger::QueryFormat>(format));
    ret.set_compression(static_cast<PbInfluxLogger::QueryCompression>(compression));
    ret.set_maxrows(maxRows);
    ret.set_protocolversion(protocolVersion);
    return ret;
}

std::string QueryRequest::serializeAsJsonString() const {
    PbInfluxLogger::QueryRequest protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string QueryRequest::serializeAsProtobufString() const {
    PbInfluxLogger::QueryRequest protobuf(*this);
    return protobuf.SerializeAsString();
}

bool QueryRequest::deserializeFromJsonString(const std::string& str) {
    PbInfluxLogger::QueryRequest protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool QueryRequest::deserializeFromProtobufString(const std::string& str) {
    PbInfluxLogger::QueryRequest protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

QueryChunkInfo::QueryChunkInfo(const PbInfluxLogger::QueryChunkInfo& protobuf) {
    transactionId = protobuf.transactionid();
    network = protobuf.network();
    measurement = protobuf.measurement();
    topic = protobuf.topic();
    chunkNumber = protobuf.chunknumber();
    rows = protobuf.rows();
    sizeBytes = protobuf.sizebytes();
    hash = protobuf.hash();
    format = static_cast<QueryFormat>(protobuf.format());
    compression = static_cast<QueryCompression>(protobuf.compression());
}

QueryChunkInfo::operator PbInfluxLogger::QueryChunkInfo() const {
    PbInfluxLogger::QueryChunkInfo ret;
    ret.set_transactionid(transactionId);
    ret.set_network(network);
    ret.set_measurement(measurement);
    ret.set_topic(topic);
    ret.set_chunknumber(chunkNumber);
    ret.set_rows(rows);
    ret.set_sizebytes(sizeBytes);
    ret.set_hash(hash);
    ret.set_format(static_cast<PbInfluxLogger::QueryFormat>(format));
    ret.set_compression(static_cast<PbInfluxLogger::QueryCompression>(compression));
    return ret;
}

std::string QueryChunkInfo::serializeAsJsonString() const {
    PbInfluxLogger::QueryChunkInfo protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string QueryChunkInfo::serializeAsProtobufString() const {
    PbInfluxLogger::QueryChunkInfo protobuf(*this);
    return protobuf.SerializeAsString();
}

bool QueryChunkInfo::deserializeFromJsonString(const std::string& str) {
    PbInfluxLogger::QueryChunkInfo protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool QueryChunkInfo::deserializeFromProtobufString(const std::string& str) {
    PbInfluxLogger::QueryChunkInfo protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

QueryStatus::QueryStatus(const PbInfluxLogger::QueryStatus& protobuf) {
    transactionId = protobuf.transactionid();
    timestamp = protobuf.timestamp();
    state = static_cast<QueryState>(protobuf.state());
    error = static_cast<QueryError>(protobuf.error());
    stage = protobuf.stage();
    description = protobuf.description();
    totalChunks = protobuf.totalchunks();
    totalRows = protobuf.totalrows();
    protocolVersion = protobuf.protocolversion();
    chunks = {protobuf.chunks().begin(), protobuf.chunks().end()};
    details = {protobuf.details().begin(), protobuf.details().end()};
}

QueryStatus::operator PbInfluxLogger::QueryStatus() const {
    PbInfluxLogger::QueryStatus ret;
    ret.set_transactionid(transactionId);
    ret.set_timestamp(timestamp);
    ret.set_state(static_cast<PbInfluxLogger::QueryState>(state));
    ret.set_error(static_cast<PbInfluxLogger::QueryError>(error));
    ret.set_stage(stage);
    ret.set_description(description);
    ret.set_totalchunks(totalChunks);
    ret.set_totalrows(totalRows);
    ret.set_protocolversion(protocolVersion);
    *(ret.mutable_chunks()) = {chunks.begin(), chunks.end()};
    *(ret.mutable_details()) = {details.begin(), details.end()};
    return ret;
}

std::string QueryStatus::serializeAsJsonString() const {
    PbInfluxLogger::QueryStatus protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string QueryStatus::serializeAsProtobufString() const {
    PbInfluxLogger::QueryStatus protobuf(*this);
    return protobuf.SerializeAsString();
}

bool QueryStatus::deserializeFromJsonString(const std::string& str) {
    PbInfluxLogger::QueryStatus protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool QueryStatus::deserializeFromProtobufString(const std::string& str) {
    PbInfluxLogger::QueryStatus protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}