from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict

from sessions import gpsSession_pb2
from google.protobuf.json_format import MessageToJson, Parse


@dataclass
class GpsSession:
    gpsName: str = ""
    dateTime: str = ""
    durationSeconds: float = 0.0
    startTimestamp: int = 0
    endTimestamp: int = 0
    messages: int = 0
    
    _proto_message: gpsSession_pb2.GpsSession = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = gpsSession_pb2.GpsSession()

    def _populate_proto(self):
        self._proto_message.gpsName = self.gpsName
        self._proto_message.dateTime = self.dateTime
        self._proto_message.durationSeconds = self.durationSeconds
        self._proto_message.startTimestamp = self.startTimestamp
        self._proto_message.endTimestamp = self.endTimestamp
        self._proto_message.messages = self.messages

    @classmethod
    def _from_proto(cls, proto_message) -> "GpsSession":
        return cls(
            gpsName = proto_message.gpsName,
            dateTime = proto_message.dateTime,
            durationSeconds = proto_message.durationSeconds,
            startTimestamp = proto_message.startTimestamp,
            endTimestamp = proto_message.endTimestamp,
            messages = proto_message.messages,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "GpsSession":
        message = gpsSession_pb2.GpsSession()
        message.ParseFromString(data)
        return cls(
            gpsName = message.gpsName,
            dateTime = message.dateTime,
            durationSeconds = message.durationSeconds,
            startTimestamp = message.startTimestamp,
            endTimestamp = message.endTimestamp,
            messages = message.messages,
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "GpsSession":
        message = gpsSession_pb2.GpsSession()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())
