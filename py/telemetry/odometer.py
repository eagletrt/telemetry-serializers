from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict

from telemetry import odometer_pb2
from google.protobuf.json_format import MessageToJson, Parse


@dataclass
class Odometer:
    startDate: str = ""
    kilometers: float = 0.0
    
    _proto_message: odometer_pb2.Odometer = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = odometer_pb2.Odometer()

    def populate_proto(self):
        self._proto_message.startDate = self.startDate
        self._proto_message.kilometers = self.kilometers

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Odometer":
        message = odometer_pb2.Odometer()
        message.ParseFromString(data)
        return cls(
            startDate=message.startDate,
            kilometers=message.kilometers,
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Odometer":
        message = odometer_pb2.Odometer()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    def __str__(self):
        return self.serializeAsJsonString()
