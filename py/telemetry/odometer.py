from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict

from telemetry import odometer_pb2
from google.protobuf.json_format import MessageToJson, Parse


@dataclass
class Tyre:
    id: str = ""
    kilometers: float = 0.0
    
    _proto_message: odometer_pb2.Tyre = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = odometer_pb2.Tyre()

    def _populate_proto(self):
        self._proto_message.id = self.id
        self._proto_message.kilometers = self.kilometers

    @classmethod
    def _from_proto(cls, proto_message) -> "Tyre":
        return cls(
            id = proto_message.id,
            kilometers = proto_message.kilometers,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Tyre":
        message = odometer_pb2.Tyre()
        message.ParseFromString(data)
        return cls(
            id = message.id,
            kilometers = message.kilometers,
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Tyre":
        message = odometer_pb2.Tyre()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class Odometer:
    startDate: str = ""
    tyres: List[Tyre] = field(default_factory=list)
    
    _proto_message: odometer_pb2.Odometer = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = odometer_pb2.Odometer()

    def _populate_proto(self):
        self._proto_message.startDate = self.startDate
        del self._proto_message.tyres[:]
        for val in self.tyres:
            val._populate_proto()
            tmp = self._proto_message.tyres.add()
            tmp.CopyFrom(val._proto_message)

    @classmethod
    def _from_proto(cls, proto_message) -> "Odometer":
        return cls(
            startDate = proto_message.startDate,
            tyres=[Tyre._from_proto(val) for val in proto_message.tyres],
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Odometer":
        message = odometer_pb2.Odometer()
        message.ParseFromString(data)
        return cls(
            startDate = message.startDate,
            tyres = [Tyre._from_proto(val) for val in message.tyres],
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Odometer":
        message = odometer_pb2.Odometer()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())
