from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict

from configs import session_config_pb2
from google.protobuf.json_format import MessageToJson, Parse


@dataclass
class Weather:
    ambientTemperature: float = 0.0
    trackTemperature: float = 0.0
    humidity: float = 0.0
    
    _proto_message: session_config_pb2.Weather = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = session_config_pb2.Weather()

    def populate_proto(self):
        self._proto_message.ambientTemperature = self.ambientTemperature
        self._proto_message.trackTemperature = self.trackTemperature
        self._proto_message.humidity = self.humidity

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Weather":
        message = session_config_pb2.Weather()
        message.ParseFromString(data)
        return cls(
            ambientTemperature = message.ambientTemperature,
            trackTemperature = message.trackTemperature,
            humidity = message.humidity,
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Weather":
        message = session_config_pb2.Weather()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    @classmethod
    def from_proto(cls, proto_message) -> "Weather":
        return cls(
            ambientTemperature = proto_message.ambientTemperature,
            trackTemperature = proto_message.trackTemperature,
            humidity = proto_message.humidity,
        )

    def __str__(self):
        return self.serializeAsJsonString()

@dataclass
class SessionConfig:
    trackLocation: str = ""
    trackLayout: str = ""
    sessionName: str = ""
    driver: str = ""
    date: str = ""
    time: str = ""
    weather: Weather = None
    notes: str = ""
    canlibVersion: float = 0.0
    startTimestamp: int = 0
    endTimestamp: int = 0
    
    _proto_message: session_config_pb2.SessionConfig = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = session_config_pb2.SessionConfig()

    def populate_proto(self):
        self._proto_message.trackLocation = self.trackLocation
        self._proto_message.trackLayout = self.trackLayout
        self._proto_message.sessionName = self.sessionName
        self._proto_message.driver = self.driver
        self._proto_message.date = self.date
        self._proto_message.time = self.time
        if self.weather:
            self.weather.populate_proto()
            self._proto_message.weather.CopyFrom(self.weather._proto_message)
        self._proto_message.notes = self.notes
        self._proto_message.canlibVersion = self.canlibVersion
        self._proto_message.startTimestamp = self.startTimestamp
        self._proto_message.endTimestamp = self.endTimestamp

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "SessionConfig":
        message = session_config_pb2.SessionConfig()
        message.ParseFromString(data)
        return cls(
            trackLocation = message.trackLocation,
            trackLayout = message.trackLayout,
            sessionName = message.sessionName,
            driver = message.driver,
            date = message.date,
            time = message.time,
            weather = (
                Weather.from_proto(message.weather)
                if message.HasField("weather")
                else None
            ),
            notes = message.notes,
            canlibVersion = message.canlibVersion,
            startTimestamp = message.startTimestamp,
            endTimestamp = message.endTimestamp,
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "SessionConfig":
        message = session_config_pb2.SessionConfig()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    @classmethod
    def from_proto(cls, proto_message) -> "SessionConfig":
        return cls(
            trackLocation = proto_message.trackLocation,
            trackLayout = proto_message.trackLayout,
            sessionName = proto_message.sessionName,
            driver = proto_message.driver,
            date = proto_message.date,
            time = proto_message.time,
            weather = proto_message.weather,
            notes = proto_message.notes,
            canlibVersion = proto_message.canlibVersion,
            startTimestamp = proto_message.startTimestamp,
            endTimestamp = proto_message.endTimestamp,
        )

    def __str__(self):
        return self.serializeAsJsonString()
