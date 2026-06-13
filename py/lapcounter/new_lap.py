from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict

from lapcounter import new_lap_pb2
from google.protobuf.json_format import MessageToJson, Parse


@dataclass
class NewLap:
    timestamp: int = 0
    
    _proto_message: new_lap_pb2.NewLap = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = new_lap_pb2.NewLap()

    def _populate_proto(self):
        self._proto_message.timestamp = self.timestamp

    @classmethod
    def _from_proto(cls, proto_message) -> "NewLap":
        return cls(
            timestamp = proto_message.timestamp,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "NewLap":
        message = new_lap_pb2.NewLap()
        message.ParseFromString(data)
        return cls(
            timestamp = message.timestamp,
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "NewLap":
        message = new_lap_pb2.NewLap()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())
