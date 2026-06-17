from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict

from can import can_error_pb2
from google.protobuf.json_format import MessageToJson, Parse


@dataclass
class Invalid_can_id:
    timestamp: int = 0
    id: int = 0
    payload: List[int] = field(default_factory=list)
    network: str = ""
    
    _proto_message: can_error_pb2.Invalid_can_id = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = can_error_pb2.Invalid_can_id()

    def _populate_proto(self):
        self._proto_message.timestamp = self.timestamp
        self._proto_message.id = self.id
        del self._proto_message.payload[:]
        for val in self.payload:
            self._proto_message.payload.append(val)
        self._proto_message.network = self.network

    @classmethod
    def _from_proto(cls, proto_message) -> "Invalid_can_id":
        return cls(
            timestamp = proto_message.timestamp,
            id = proto_message.id,
            payload=[int(val) for val in proto_message.payload],
            network = proto_message.network,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Invalid_can_id":
        message = can_error_pb2.Invalid_can_id()
        message.ParseFromString(data)
        return cls(
            timestamp = message.timestamp,
            id = message.id,
            payload = [int(val) for val in message.payload],
            network = message.network,
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Invalid_can_id":
        message = can_error_pb2.Invalid_can_id()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())
