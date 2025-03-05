from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict

from data import dv_commands_pb2
from google.protobuf.json_format import MessageToJson, Parse


@dataclass
class ActuatorsCommands:
    steerAngleDegrees: float = 0.0
    pedalThrottle: float = 0.0
    pedalBrakes: float = 0.0
    
    _proto_message: dv_commands_pb2.ActuatorsCommands = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = dv_commands_pb2.ActuatorsCommands()

    def _populate_proto(self):
        self._proto_message.steerAngleDegrees = self.steerAngleDegrees
        self._proto_message.pedalThrottle = self.pedalThrottle
        self._proto_message.pedalBrakes = self.pedalBrakes

    @classmethod
    def _from_proto(cls, proto_message) -> "ActuatorsCommands":
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
    def deserializeFromProtobufString(cls, data: bytes) -> "ActuatorsCommands":
        message = dv_commands_pb2.ActuatorsCommands()
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
    def deserializeFromJsonString(cls, data: str) -> "ActuatorsCommands":
        message = dv_commands_pb2.ActuatorsCommands()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())
class Status(Enum):
    status_disabled = 0
    status_enabled = 1


@dataclass
class ActuatorsStatus:
    steerStatus: Status = None
    throttleStatus: Status = None
    brakesStatus: Status = None
    
    _proto_message: dv_commands_pb2.ActuatorsStatus = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = dv_commands_pb2.ActuatorsStatus()

    def _populate_proto(self):
        self._proto_message.steerStatus = self.steerStatus.value
        self._proto_message.throttleStatus = self.throttleStatus.value
        self._proto_message.brakesStatus = self.brakesStatus.value

    @classmethod
    def _from_proto(cls, proto_message) -> "ActuatorsStatus":
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
    def deserializeFromProtobufString(cls, data: bytes) -> "ActuatorsStatus":
        message = dv_commands_pb2.ActuatorsStatus()
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
    def deserializeFromJsonString(cls, data: str) -> "ActuatorsStatus":
        message = dv_commands_pb2.ActuatorsStatus()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())
