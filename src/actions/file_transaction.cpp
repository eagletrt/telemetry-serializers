#include "actions/file_transaction.h"

#include <google/protobuf/util/json_util.h>
#include <tuple>

namespace Serializers
{
namespace Actions
{
FileTransactionSetup::FileTransactionSetup(const PbActions::FileTransactionSetup& protobuf) {
    id = protobuf.id();
    hash = protobuf.hash();
    topic = protobuf.topic();
}

FileTransactionSetup::operator PbActions::FileTransactionSetup() const {
    PbActions::FileTransactionSetup ret;
    ret.set_id(id);
    ret.set_hash(hash);
    ret.set_topic(topic);
    return ret;
}

std::string FileTransactionSetup::serializeAsJsonString() const {
    PbActions::FileTransactionSetup protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string FileTransactionSetup::serializeAsProtobufString() const {
    PbActions::FileTransactionSetup protobuf(*this);
    return protobuf.SerializeAsString();
}

bool FileTransactionSetup::deserializeFromJsonString(const std::string& str) {
    PbActions::FileTransactionSetup protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool FileTransactionSetup::deserializeFromProtobufString(const std::string& str) {
    PbActions::FileTransactionSetup protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

FileTransactionStatus::FileTransactionStatus(const PbActions::FileTransactionStatus& protobuf) {
    fileName = protobuf.filename();
    hash = protobuf.hash();
    destinationPath = protobuf.destinationpath();
    totalChunks = protobuf.totalchunks();
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
    PbActions::FileTransactionStatus protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string FileTransactionStatus::serializeAsProtobufString() const {
    PbActions::FileTransactionStatus protobuf(*this);
    return protobuf.SerializeAsString();
}

bool FileTransactionStatus::deserializeFromJsonString(const std::string& str) {
    PbActions::FileTransactionStatus protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool FileTransactionStatus::deserializeFromProtobufString(const std::string& str) {
    PbActions::FileTransactionStatus protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

FileTransactionChunk::FileTransactionChunk(const PbActions::FileTransactionChunk& protobuf) {
    data = protobuf.data();
    hash = protobuf.hash();
    chunkNumber = protobuf.chunknumber();
    totalChunks = protobuf.totalchunks();
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
    PbActions::FileTransactionChunk protobuf(*this);
    std::string ret;
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    std::ignore = google::protobuf::util::MessageToJsonString(protobuf, &ret, options);
    return ret;
}

std::string FileTransactionChunk::serializeAsProtobufString() const {
    PbActions::FileTransactionChunk protobuf(*this);
    return protobuf.SerializeAsString();
}

bool FileTransactionChunk::deserializeFromJsonString(const std::string& str) {
    PbActions::FileTransactionChunk protobuf;
    auto status = google::protobuf::util::JsonStringToMessage(str, &protobuf);
    if(status.ok()) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}

bool FileTransactionChunk::deserializeFromProtobufString(const std::string& str) {
    PbActions::FileTransactionChunk protobuf;
    if(protobuf.ParseFromString(str)) {
        *this = protobuf;
        return true;
    } else {
        return false;
    }
}
}
}