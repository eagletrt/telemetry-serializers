from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict

from handcart import settings_pb2
from google.protobuf.json_format import MessageToJson, Parse


@dataclass
class Settings:
    status: int = 0
    targetVoltage: float = 0.0
    fansOverride: bool = ""
    fansSpeed: float = 0.0
    accChargeCurrent: float = 0.0
    gridMaxCurrent: float = 0.0
    
    _proto_message: settings_pb2.Settings = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = settings_pb2.Settings()

    def populate_proto(self):
        self._proto_message.status = self.status
        self._proto_message.targetVoltage = self.targetVoltage
        self._proto_message.fansOverride = self.fansOverride
        self._proto_message.fansSpeed = self.fansSpeed
        self._proto_message.accChargeCurrent = self.accChargeCurrent
        self._proto_message.gridMaxCurrent = self.gridMaxCurrent

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Settings":
        message = settings_pb2.Settings()
        message.ParseFromString(data)
        return cls(
            status=message.status,
            targetVoltage=message.targetVoltage,
            fansOverride=message.fansOverride,
            fansSpeed=message.fansSpeed,
            accChargeCurrent=message.accChargeCurrent,
            gridMaxCurrent=message.gridMaxCurrent,
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Settings":
        message = settings_pb2.Settings()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    def __str__(self):
        return self.serializeAsJsonString()
