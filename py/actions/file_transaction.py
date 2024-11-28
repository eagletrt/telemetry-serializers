from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict

from actions import file_transaction_pb2
from google.protobuf.json_format import MessageToJson, Parse


@dataclass
class FileTransactionSetup:
    id: str = ""
    hash: str = ""
    topic: str = ""
    
    _proto_message: file_transaction_pb2.FileTransactionSetup = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = file_transaction_pb2.FileTransactionSetup()

    def populate_proto(self):
        self._proto_message.id = self.id
        self._proto_message.hash = self.hash
        self._proto_message.topic = self.topic

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "FileTransactionSetup":
        message = file_transaction_pb2.FileTransactionSetup()
        message.ParseFromString(data)
        return cls(
            id=message.id,
            hash=message.hash,
            topic=message.topic,
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "FileTransactionSetup":
        message = file_transaction_pb2.FileTransactionSetup()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    def __str__(self):
        return self.serializeAsJsonString()

@dataclass
class FileTransactionStatus:
    fileName: str = ""
    hash: str = ""
    destinationPath: str = ""
    totalChunks: int = 0
    
    _proto_message: file_transaction_pb2.FileTransactionStatus = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = file_transaction_pb2.FileTransactionStatus()

    def populate_proto(self):
        self._proto_message.fileName = self.fileName
        self._proto_message.hash = self.hash
        self._proto_message.destinationPath = self.destinationPath
        self._proto_message.totalChunks = self.totalChunks

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "FileTransactionStatus":
        message = file_transaction_pb2.FileTransactionStatus()
        message.ParseFromString(data)
        return cls(
            fileName=message.fileName,
            hash=message.hash,
            destinationPath=message.destinationPath,
            totalChunks=message.totalChunks,
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "FileTransactionStatus":
        message = file_transaction_pb2.FileTransactionStatus()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    def __str__(self):
        return self.serializeAsJsonString()

@dataclass
class FileTransactionChunk:
    data: str = ""
    hash: str = ""
    chunkNumber: int = 0
    totalChunks: int = 0
    
    _proto_message: file_transaction_pb2.FileTransactionChunk = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = file_transaction_pb2.FileTransactionChunk()

    def populate_proto(self):
        self._proto_message.data = self.data
        self._proto_message.hash = self.hash
        self._proto_message.chunkNumber = self.chunkNumber
        self._proto_message.totalChunks = self.totalChunks

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "FileTransactionChunk":
        message = file_transaction_pb2.FileTransactionChunk()
        message.ParseFromString(data)
        return cls(
            data=message.data,
            hash=message.hash,
            chunkNumber=message.chunkNumber,
            totalChunks=message.totalChunks,
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "FileTransactionChunk":
        message = file_transaction_pb2.FileTransactionChunk()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    def __str__(self):
        return self.serializeAsJsonString()