#ifndef SERIALIZERS_INFLUX_QUERY_H
#define SERIALIZERS_INFLUX_QUERY_H

#include "influx_query.pb.h"

#include <cstdint>
#include <optional>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
namespace InfluxLogger
{
enum class QueryFormat
{
    QUERY_FORMAT_CSV = 0
};

enum class QueryCompression
{
    QUERY_COMPRESSION_GZIP = 0,
    QUERY_COMPRESSION_NONE = 1
};

enum class QueryState
{
    QUERY_STATE_ACCEPTED = 0,
    QUERY_STATE_RUNNING = 1,
    QUERY_STATE_COMPLETED = 2,
    QUERY_STATE_FAILED = 3
};

enum class QueryError
{
    QUERY_ERROR_NONE = 0,
    QUERY_ERROR_BAD_REQUEST = 1,
    QUERY_ERROR_INVALID_RANGE = 2,
    QUERY_ERROR_NOT_AUTHORIZED = 3,
    QUERY_ERROR_UNAVAILABLE = 4,
    QUERY_ERROR_DB_UNAVAILABLE = 5,
    QUERY_ERROR_QUERY_FAILED = 6,
    QUERY_ERROR_SERIALIZATION_FAILED = 7,
    QUERY_ERROR_PUBLISH_FAILED = 8,
    QUERY_ERROR_TIMEOUT = 9,
    QUERY_ERROR_TOO_MUCH_DATA = 10,
    QUERY_ERROR_INTERNAL = 11
};

struct QueryRequest
{
    uint64_t start;
    uint64_t stop;
    std::string transactionId;
    std::vector<std::string> networks;
    std::vector<std::string> measurements;
    QueryFormat format;
    QueryCompression compression;
    uint64_t maxRows;
    uint32_t protocolVersion;
    
    QueryRequest() = default;
    QueryRequest(const PbInfluxLogger::QueryRequest& protobuf);
    operator PbInfluxLogger::QueryRequest() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct QueryChunkInfo
{
    std::string transactionId;
    std::string network;
    std::string measurement;
    std::string topic;
    uint64_t chunkNumber;
    uint64_t rows;
    uint64_t sizeBytes;
    std::string hash;
    QueryFormat format;
    QueryCompression compression;
    
    QueryChunkInfo() = default;
    QueryChunkInfo(const PbInfluxLogger::QueryChunkInfo& protobuf);
    operator PbInfluxLogger::QueryChunkInfo() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct QueryStatus
{
    std::string transactionId;
    uint64_t timestamp;
    QueryState state;
    QueryError error;
    std::string stage;
    std::string description;
    uint64_t totalChunks;
    uint64_t totalRows;
    uint32_t protocolVersion;
    std::vector<QueryChunkInfo> chunks;
    std::unordered_map<std::string, std::string> details;
    
    QueryStatus() = default;
    QueryStatus(const PbInfluxLogger::QueryStatus& protobuf);
    operator PbInfluxLogger::QueryStatus() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif