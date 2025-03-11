from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict

from data import as_commands_pb2
from google.protobuf.json_format import MessageToJson, Parse


@dataclass
class ASCommands:
    steerAngleDegrees: float = 0.0
    pedalThrottle: float = 0.0
    pedalBrakes: float = 0.0
    
    _proto_message: as_commands_pb2.ASCommands = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = as_commands_pb2.ASCommands()

    def _populate_proto(self):
        self._proto_message.steerAngleDegrees = self.steerAngleDegrees
        self._proto_message.pedalThrottle = self.pedalThrottle
        self._proto_message.pedalBrakes = self.pedalBrakes

    @classmethod
    def _from_proto(cls, proto_message) -> "ASCommands":
        return cls(
            steerAngleDegrees = proto_message.steerAngleDegrees,
            pedalThrottle = proto_message.pedalThrottle,
            pedalBrakes = proto_message.pedalBrakes,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "ASCommands":
        message = as_commands_pb2.ASCommands()
        message.ParseFromString(data)
        return cls(
            steerAngleDegrees = message.steerAngleDegrees,
            pedalThrottle = message.pedalThrottle,
            pedalBrakes = message.pedalBrakes,
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "ASCommands":
        message = as_commands_pb2.ASCommands()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())
class Status(Enum):
    status_disabled = 0
    status_enabled = 1


@dataclass
class ASStatus:
    steerStatus: Status = None
    throttleStatus: Status = None
    brakesStatus: Status = None
    
    _proto_message: as_commands_pb2.ASStatus = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = as_commands_pb2.ASStatus()

    def _populate_proto(self):
        self._proto_message.steerStatus = self.steerStatus.value
        self._proto_message.throttleStatus = self.throttleStatus.value
        self._proto_message.brakesStatus = self.brakesStatus.value

    @classmethod
    def _from_proto(cls, proto_message) -> "ASStatus":
        return cls(
            steerStatus = Status._from_proto(proto_message.steerStatus),
            throttleStatus = Status._from_proto(proto_message.throttleStatus),
            brakesStatus = Status._from_proto(proto_message.brakesStatus),
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "ASStatus":
        message = as_commands_pb2.ASStatus()
        message.ParseFromString(data)
        return cls(
            steerStatus = Status(message.steerStatus),
            throttleStatus = Status(message.throttleStatus),
            brakesStatus = Status(message.brakesStatus),
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "ASStatus":
        message = as_commands_pb2.ASStatus()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())
