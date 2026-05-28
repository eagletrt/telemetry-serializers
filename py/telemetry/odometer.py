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
    fl: Tyre = None
    fr: Tyre = None
    rl: Tyre = None
    rr: Tyre = None
    
    _proto_message: odometer_pb2.Odometer = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = odometer_pb2.Odometer()

    def _populate_proto(self):
        self._proto_message.startDate = self.startDate
        if self.fl:
            self.fl._populate_proto()
            self._proto_message.fl.CopyFrom(self.fl._proto_message)
        if self.fr:
            self.fr._populate_proto()
            self._proto_message.fr.CopyFrom(self.fr._proto_message)
        if self.rl:
            self.rl._populate_proto()
            self._proto_message.rl.CopyFrom(self.rl._proto_message)
        if self.rr:
            self.rr._populate_proto()
            self._proto_message.rr.CopyFrom(self.rr._proto_message)

    @classmethod
    def _from_proto(cls, proto_message) -> "Odometer":
        return cls(
            startDate = proto_message.startDate,
            fl = Tyre._from_proto(proto_message.fl),
            fr = Tyre._from_proto(proto_message.fr),
            rl = Tyre._from_proto(proto_message.rl),
            rr = Tyre._from_proto(proto_message.rr),
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
            fl = (
                Tyre._from_proto(message.fl)
                if message.HasField("fl")
                else None
            ),
            fr = (
                Tyre._from_proto(message.fr)
                if message.HasField("fr")
                else None
            ),
            rl = (
                Tyre._from_proto(message.rl)
                if message.HasField("rl")
                else None
            ),
            rr = (
                Tyre._from_proto(message.rr)
                if message.HasField("rr")
                else None
            ),
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Odometer":
        message = odometer_pb2.Odometer()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())
