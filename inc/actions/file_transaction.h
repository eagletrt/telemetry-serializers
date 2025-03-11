#ifndef SERIALIZERS_FILE_TRANSACTION_H
#define SERIALIZERS_FILE_TRANSACTION_H

#include "file_transaction.pb.h"

#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>

namespace Serializers
{
namespace Actions
{
struct FileTransactionSetup
{
    std::string id;
    std::string hash;
    std::string topic;
    
    FileTransactionSetup() = default;
    FileTransactionSetup(const PbActions::FileTransactionSetup& protobuf);
    operator PbActions::FileTransactionSetup() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct FileTransactionStatus
{
    std::string fileName;
    std::string hash;
    std::string destinationPath;
    uint64_t totalChunks;
    
    FileTransactionStatus() = default;
    FileTransactionStatus(const PbActions::FileTransactionStatus& protobuf);
    operator PbActions::FileTransactionStatus() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};

struct FileTransactionChunk
{
    std::string data;
    std::string hash;
    uint64_t chunkNumber;
    uint64_t totalChunks;
    
    FileTransactionChunk() = default;
    FileTransactionChunk(const PbActions::FileTransactionChunk& protobuf);
    operator PbActions::FileTransactionChunk() const;

    std::string serializeAsJsonString() const;
    std::string serializeAsProtobufString() const;
    bool deserializeFromJsonString(const std::string& str);
    bool deserializeFromProtobufString(const std::string& str);
};
}
}

#endif