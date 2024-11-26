from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict

from data import telemetry_lap_data_pb2
from google.protobuf.json_format import MessageToJson, Parse


@dataclass
class VectorDouble:
    buffer: List[float] = field(default_factory=list)
    
    _proto_message: telemetry_lap_data_pb2.VectorDouble = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = telemetry_lap_data_pb2.VectorDouble()

    def populate_proto(self):
        del self._proto_message.buffer[:]
        for value in self.buffer:
            value.populate_proto()
            tmp = self._proto_message.buffer.add()
            tmp.CopyFrom(value._proto_message)

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "VectorDouble":
        message = telemetry_lap_data_pb2.VectorDouble()
        message.ParseFromString(data)
        return cls(
            buffer=[float(value) for value in message.buffer],
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "VectorDouble":
        message = telemetry_lap_data_pb2.VectorDouble()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    def __str__(self):
        return self.serializeAsJsonString()

@dataclass
class DataFile:
    data: Dict[str, VectorDouble] = field(default_factory=dict)
    
    _proto_message: telemetry_lap_data_pb2.DataFile = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = telemetry_lap_data_pb2.DataFile()

    def populate_proto(self):
        self._proto_message.data.clear()
        for key, value in self.data.items():
            value.populate_proto()
            tmp = self._proto_message.data.setdefault(key)
            tmp.CopyFrom(value._proto_message)

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "DataFile":
        message = telemetry_lap_data_pb2.DataFile()
        message.ParseFromString(data)
        return cls(
            data={key: value for key, value in message.data.items()},
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "DataFile":
        message = telemetry_lap_data_pb2.DataFile()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    def __str__(self):
        return self.serializeAsJsonString()

@dataclass
class TelemetryLapData:
    dateTime: str = ""
    trackLocation: str = ""
    trackLayout: str = ""
    driver: str = ""
    lapNumber: int = 0
    filenameHash: str = ""
    
    _proto_message: telemetry_lap_data_pb2.TelemetryLapData = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = telemetry_lap_data_pb2.TelemetryLapData()

    def populate_proto(self):
        self._proto_message.dateTime = self.dateTime
        self._proto_message.trackLocation = self.trackLocation
        self._proto_message.trackLayout = self.trackLayout
        self._proto_message.driver = self.driver
        self._proto_message.lapNumber = self.lapNumber
        self._proto_message.filenameHash = self.filenameHash

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "TelemetryLapData":
        message = telemetry_lap_data_pb2.TelemetryLapData()
        message.ParseFromString(data)
        return cls(
            dateTime=message.dateTime,
            trackLocation=message.trackLocation,
            trackLayout=message.trackLayout,
            driver=message.driver,
            lapNumber=message.lapNumber,
            filenameHash=message.filenameHash,
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "TelemetryLapData":
        message = telemetry_lap_data_pb2.TelemetryLapData()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    def __str__(self):
        return self.serializeAsJsonString()

@dataclass
class DataBase:
    lapsData: List[TelemetryLapData] = field(default_factory=list)
    
    _proto_message: telemetry_lap_data_pb2.DataBase = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = telemetry_lap_data_pb2.DataBase()

    def populate_proto(self):
        del self._proto_message.lapsData[:]
        for value in self.lapsData:
            value.populate_proto()
            tmp = self._proto_message.lapsData.add()
            tmp.CopyFrom(value._proto_message)

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "DataBase":
        message = telemetry_lap_data_pb2.DataBase()
        message.ParseFromString(data)
        return cls(
            lapsData=[TelemetryLapData(value) for value in message.lapsData],
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "DataBase":
        message = telemetry_lap_data_pb2.DataBase()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    def __str__(self):
        return self.serializeAsJsonString()
