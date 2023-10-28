#include "actions/file_transaction.h"

#include <google/protobuf/util/json_util.h>

namespace Serializers
{
namespace Actions
{
FileTransactionSetup::FileTransactionSetup(const ActionsFileTransactionSetup& proto) {
    id = proto.id();
    hash = proto.hash();
    topic = proto.topic();
}

FileTransactionSetup::operator ActionsFileTransactionSetup() const {
    ActionsFileTransactionSetup ret;
    ret.set_id(id);
    ret.set_hash(hash);
    ret.set_topic(topic);
    return ret;
}

std::string FileTransactionSetup::serializeAsJsonString() const {
    ActionsFileTransactionSetup proto(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(proto, &ret, options);
    return ret;
}

std::string FileTransactionSetup::serializeAsProtobufString() const {
    ActionsFileTransactionSetup proto(*this);
    return proto.SerializeAsString();
}

bool FileTransactionSetup::deserializeFromJsonString(const std::string& str) {
    ActionsFileTransactionSetup proto;
    auto status = google::protobuf::util::JsonStringToMessage(str, &proto);
    if(status.ok()) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

bool FileTransactionSetup::deserializeFromProtobufString(const std::string& str) {
    ActionsFileTransactionSetup proto;
    if(proto.ParseFromString(str)) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

FileTransactionStatus::FileTransactionStatus(const ActionsFileTransactionStatus& proto) {
    fileName = proto.filename();
    hash = proto.hash();
    destinationPath = proto.destinationpath();
    totalChunks = proto.totalchunks();
}

FileTransactionStatus::operator ActionsFileTransactionStatus() const {
    ActionsFileTransactionStatus ret;
    ret.set_filename(fileName);
    ret.set_hash(hash);
    ret.set_destinationpath(destinationPath);
    ret.set_totalchunks(totalChunks);
    return ret;
}

std::string FileTransactionStatus::serializeAsJsonString() const {
    ActionsFileTransactionStatus proto(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(proto, &ret, options);
    return ret;
}

std::string FileTransactionStatus::serializeAsProtobufString() const {
    ActionsFileTransactionStatus proto(*this);
    return proto.SerializeAsString();
}

bool FileTransactionStatus::deserializeFromJsonString(const std::string& str) {
    ActionsFileTransactionStatus proto;
    auto status = google::protobuf::util::JsonStringToMessage(str, &proto);
    if(status.ok()) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

bool FileTransactionStatus::deserializeFromProtobufString(const std::string& str) {
    ActionsFileTransactionStatus proto;
    if(proto.ParseFromString(str)) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

FileTransactionChunk::FileTransactionChunk(const ActionsFileTransactionChunk& proto) {
    data = proto.data();
    hash = proto.hash();
    chunkNumber = proto.chunknumber();
    totalChunks = proto.totalchunks();
}

FileTransactionChunk::operator ActionsFileTransactionChunk() const {
    ActionsFileTransactionChunk ret;
    ret.set_data(data);
    ret.set_hash(hash);
    ret.set_chunknumber(chunkNumber);
    ret.set_totalchunks(totalChunks);
    return ret;
}

std::string FileTransactionChunk::serializeAsJsonString() const {
    ActionsFileTransactionChunk proto(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    google::protobuf::util::MessageToJsonString(proto, &ret, options);
    return ret;
}

std::string FileTransactionChunk::serializeAsProtobufString() const {
    ActionsFileTransactionChunk proto(*this);
    return proto.SerializeAsString();
}

bool FileTransactionChunk::deserializeFromJsonString(const std::string& str) {
    ActionsFileTransactionChunk proto;
    auto status = google::protobuf::util::JsonStringToMessage(str, &proto);
    if(status.ok()) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}

bool FileTransactionChunk::deserializeFromProtobufString(const std::string& str) {
    ActionsFileTransactionChunk proto;
    if(proto.ParseFromString(str)) {
        *this = proto;
        return true;
    } else {
        return false;
    }
}
}
}