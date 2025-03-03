from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict

from data import steer_command_pb2
from google.protobuf.json_format import MessageToJson, Parse


@dataclass
class SteerCommand:
    angleDegrees: float = 0.0
    
    _proto_message: steer_command_pb2.SteerCommand = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = steer_command_pb2.SteerCommand()

    def _populate_proto(self):
        self._proto_message.angleDegrees = self.angleDegrees

    @classmethod
    def _from_proto(cls, proto_message) -> "SteerCommand":
        return cls(
            angleDegrees = proto_message.angleDegrees,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "SteerCommand":
        message = steer_command_pb2.SteerCommand()
        message.ParseFromString(data)
        return cls(
            angleDegrees = message.angleDegrees,
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "SteerCommand":
        message = steer_command_pb2.SteerCommand()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())
class Status(Enum):
    steer_status_disabled = 0
    steer_status_enabled = 1


@dataclass
class SteerStatus:
    status: Status = None
    
    _proto_message: steer_command_pb2.SteerStatus = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = steer_command_pb2.SteerStatus()

    def _populate_proto(self):
        self._proto_message.status = self.status.value

    @classmethod
    def _from_proto(cls, proto_message) -> "SteerStatus":
        return cls(
            status = Status._from_proto(proto_message.status),
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "SteerStatus":
        message = steer_command_pb2.SteerStatus()
        message.ParseFromString(data)
        return cls(
            status = Status(message.status),
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "SteerStatus":
        message = steer_command_pb2.SteerStatus()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())
