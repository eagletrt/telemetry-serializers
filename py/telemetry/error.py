from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict

from telemetry import error_pb2
from google.protobuf.json_format import MessageToJson, Parse


@dataclass
class Error:
    timestamp: int = 0
    function: str = ""
    description: str = ""
    
    _proto_message: error_pb2.Error = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = error_pb2.Error()

    def _populate_proto(self):
        self._proto_message.timestamp = self.timestamp
        self._proto_message.function = self.function
        self._proto_message.description = self.description

    @classmethod
    def _from_proto(cls, proto_message) -> "Error":
        return cls(
            timestamp = proto_message.timestamp,
            function = proto_message.function,
            description = proto_message.description,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Error":
        message = error_pb2.Error()
        message.ParseFromString(data)
        return cls(
            timestamp = message.timestamp,
            function = message.function,
            description = message.description,
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Error":
        message = error_pb2.Error()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())
