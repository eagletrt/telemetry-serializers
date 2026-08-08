from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict, Optional

from query import query_pb2
from google.protobuf.json_format import MessageToJson, Parse


@dataclass
class Weather:
    ambientTemperature: float = 0.0
    trackTemperature: float = 0.0
    humidity: float = 0.0
    
    _proto_message: query_pb2.Weather = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = query_pb2.Weather()

    def _populate_proto(self):
        self._proto_message.ambientTemperature = self.ambientTemperature
        self._proto_message.trackTemperature = self.trackTemperature
        self._proto_message.humidity = self.humidity

    @classmethod
    def _from_proto(cls, proto_message) -> "Weather":
        return cls(
            ambientTemperature = proto_message.ambientTemperature,
            trackTemperature = proto_message.trackTemperature,
            humidity = proto_message.humidity,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Weather":
        message = query_pb2.Weather()
        message.ParseFromString(data)
        return cls._from_proto(message)

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Weather":
        message = query_pb2.Weather()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

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
    
    _proto_message: query_pb2.SessionConfig = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = query_pb2.SessionConfig()

    def _populate_proto(self):
        self._proto_message.trackLocation = self.trackLocation
        self._proto_message.trackLayout = self.trackLayout
        self._proto_message.sessionName = self.sessionName
        self._proto_message.driver = self.driver
        self._proto_message.date = self.date
        self._proto_message.time = self.time
        if self.weather:
            self.weather._populate_proto()
            self._proto_message.weather.CopyFrom(self.weather._proto_message)
        self._proto_message.notes = self.notes
        self._proto_message.canlibVersion = self.canlibVersion
        self._proto_message.startTimestamp = self.startTimestamp
        self._proto_message.endTimestamp = self.endTimestamp

    @classmethod
    def _from_proto(cls, proto_message) -> "SessionConfig":
        return cls(
            trackLocation = proto_message.trackLocation,
            trackLayout = proto_message.trackLayout,
            sessionName = proto_message.sessionName,
            driver = proto_message.driver,
            date = proto_message.date,
            time = proto_message.time,
            weather = Weather._from_proto(proto_message.weather),
            notes = proto_message.notes,
            canlibVersion = proto_message.canlibVersion,
            startTimestamp = proto_message.startTimestamp,
            endTimestamp = proto_message.endTimestamp,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "SessionConfig":
        message = query_pb2.SessionConfig()
        message.ParseFromString(data)
        return cls._from_proto(message)

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "SessionConfig":
        message = query_pb2.SessionConfig()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class SessionByYearMonth:
    year: str = ""
    month: str = ""
    
    _proto_message: query_pb2.SessionByYearMonth = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = query_pb2.SessionByYearMonth()

    def _populate_proto(self):
        self._proto_message.year = self.year
        self._proto_message.month = self.month

    @classmethod
    def _from_proto(cls, proto_message) -> "SessionByYearMonth":
        return cls(
            year = proto_message.year,
            month = proto_message.month,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "SessionByYearMonth":
        message = query_pb2.SessionByYearMonth()
        message.ParseFromString(data)
        return cls._from_proto(message)

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "SessionByYearMonth":
        message = query_pb2.SessionByYearMonth()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class SessionByYearMonthFound:
    daysFound: List[int] = field(default_factory=list)
    
    _proto_message: query_pb2.SessionByYearMonthFound = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = query_pb2.SessionByYearMonthFound()

    def _populate_proto(self):
        del self._proto_message.daysFound[:]
        for val in self.daysFound:
            self._proto_message.daysFound.append(val)

    @classmethod
    def _from_proto(cls, proto_message) -> "SessionByYearMonthFound":
        return cls(
            daysFound=[int(val) for val in proto_message.daysFound],
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "SessionByYearMonthFound":
        message = query_pb2.SessionByYearMonthFound()
        message.ParseFromString(data)
        return cls._from_proto(message)

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "SessionByYearMonthFound":
        message = query_pb2.SessionByYearMonthFound()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class SessionByDayRange:
    yearMonth: SessionByYearMonth = None
    startDay: str = ""
    endDay: str = ""
    
    _proto_message: query_pb2.SessionByDayRange = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = query_pb2.SessionByDayRange()

    def _populate_proto(self):
        if self.yearMonth:
            self.yearMonth._populate_proto()
            self._proto_message.yearMonth.CopyFrom(self.yearMonth._proto_message)
        self._proto_message.startDay = self.startDay
        self._proto_message.endDay = self.endDay

    @classmethod
    def _from_proto(cls, proto_message) -> "SessionByDayRange":
        return cls(
            yearMonth = SessionByYearMonth._from_proto(proto_message.yearMonth),
            startDay = proto_message.startDay,
            endDay = proto_message.endDay,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "SessionByDayRange":
        message = query_pb2.SessionByDayRange()
        message.ParseFromString(data)
        return cls._from_proto(message)

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "SessionByDayRange":
        message = query_pb2.SessionByDayRange()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class sessionByDayRangeFound:
    sessionsFound: List[SessionConfig] = field(default_factory=list)
    
    _proto_message: query_pb2.sessionByDayRangeFound = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = query_pb2.sessionByDayRangeFound()

    def _populate_proto(self):
        del self._proto_message.sessionsFound[:]
        for val in self.sessionsFound:
            val._populate_proto()
            tmp = self._proto_message.sessionsFound.add()
            tmp.CopyFrom(val._proto_message)

    @classmethod
    def _from_proto(cls, proto_message) -> "sessionByDayRangeFound":
        return cls(
            sessionsFound=[SessionConfig._from_proto(val) for val in proto_message.sessionsFound],
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "sessionByDayRangeFound":
        message = query_pb2.sessionByDayRangeFound()
        message.ParseFromString(data)
        return cls._from_proto(message)

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "sessionByDayRangeFound":
        message = query_pb2.sessionByDayRangeFound()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())
