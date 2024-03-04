#include "actions/file_transaction.h"

#include <google/protobuf/util/json_util.h>

namespace Serializers
{
namespace Actions
{
FileTransactionSetup::FileTransactionSetup(const PbActions::FileTransactionSetup& message) {
    id = message.id();
    hash = message.hash();
    topic = message.topic();
}

FileTransactionSetup::operator PbActions::FileTransactionSetup() const {
    PbActions::FileTransactionSetup ret;
    ret.set_id(id);
    ret.set_hash(hash);
    ret.set_topic(topic);
    return ret;
}

std::string FileTransactionSetup::serializeAsJsonString() const {
    PbActions::FileTransactionSetup message(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(message, &ret, options);
    return ret;
}

std::string FileTransactionSetup::serializeAsProtobufString() const {
    PbActions::FileTransactionSetup message(*this);
    return message.SerializeAsString();
}

bool FileTransactionSetup::deserializeFromJsonString(const std::string& str) {
    PbActions::FileTransactionSetup message;
    auto status = google::protobuf::util::JsonStringToMessage(str, &message);
    if(status.ok()) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

bool FileTransactionSetup::deserializeFromProtobufString(const std::string& str) {
    PbActions::FileTransactionSetup message;
    if(message.ParseFromString(str)) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

FileTransactionStatus::FileTransactionStatus(const PbActions::FileTransactionStatus& message) {
    fileName = message.filename();
    hash = message.hash();
    destinationPath = message.destinationpath();
    totalChunks = message.totalchunks();
}

FileTransactionStatus::operator PbActions::FileTransactionStatus() const {
    PbActions::FileTransactionStatus ret;
    ret.set_filename(fileName);
    ret.set_hash(hash);
    ret.set_destinationpath(destinationPath);
    ret.set_totalchunks(totalChunks);
    return ret;
}

std::string FileTransactionStatus::serializeAsJsonString() const {
    PbActions::FileTransactionStatus message(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(message, &ret, options);
    return ret;
}

std::string FileTransactionStatus::serializeAsProtobufString() const {
    PbActions::FileTransactionStatus message(*this);
    return message.SerializeAsString();
}

bool FileTransactionStatus::deserializeFromJsonString(const std::string& str) {
    PbActions::FileTransactionStatus message;
    auto status = google::protobuf::util::JsonStringToMessage(str, &message);
    if(status.ok()) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

bool FileTransactionStatus::deserializeFromProtobufString(const std::string& str) {
    PbActions::FileTransactionStatus message;
    if(message.ParseFromString(str)) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

FileTransactionChunk::FileTransactionChunk(const PbActions::FileTransactionChunk& message) {
    data = message.data();
    hash = message.hash();
    chunkNumber = message.chunknumber();
    totalChunks = message.totalchunks();
}

FileTransactionChunk::operator PbActions::FileTransactionChunk() const {
    PbActions::FileTransactionChunk ret;
    ret.set_data(data);
    ret.set_hash(hash);
    ret.set_chunknumber(chunkNumber);
    ret.set_totalchunks(totalChunks);
    return ret;
}

std::string FileTransactionChunk::serializeAsJsonString() const {
    PbActions::FileTransactionChunk message(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(message, &ret, options);
    return ret;
}

std::string FileTransactionChunk::serializeAsProtobufString() const {
    PbActions::FileTransactionChunk message(*this);
    return message.SerializeAsString();
}

bool FileTransactionChunk::deserializeFromJsonString(const std::string& str) {
    PbActions::FileTransactionChunk message;
    auto status = google::protobuf::util::JsonStringToMessage(str, &message);
    if(status.ok()) {
        *this = message;
        return true;
    } else {
        return false;
    }
}

bool FileTransactionChunk::deserializeFromProtobufString(const std::string& str) {
    PbActions::FileTransactionChunk message;
    if(message.ParseFromString(str)) {
        *this = message;
        return true;
    } else {
        return false;
    }
}
}
}