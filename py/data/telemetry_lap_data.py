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

    def _populate_proto(self):
        del self._proto_message.buffer[:]
        for val in self.buffer:
            self._proto_message.buffer.append(val)

    @classmethod
    def _from_proto(cls, proto_message) -> "VectorDouble":
        return cls(
            buffer=[float(val) for val in proto_message.buffer],
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "VectorDouble":
        message = telemetry_lap_data_pb2.VectorDouble()
        message.ParseFromString(data)
        return cls(
            buffer = [float(val) for val in message.buffer],
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "VectorDouble":
        message = telemetry_lap_data_pb2.VectorDouble()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class DataFile:
    data: Dict[str, VectorDouble] = field(default_factory=dict)
    
    _proto_message: telemetry_lap_data_pb2.DataFile = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = telemetry_lap_data_pb2.DataFile()

    def _populate_proto(self):
        self._proto_message.data.clear()
        for key, val in self.data.items():
            val._populate_proto()
            tmp = self._proto_message.data.setdefault(key)
            tmp.CopyFrom(val._proto_message)

    @classmethod
    def _from_proto(cls, proto_message) -> "DataFile":
        return cls(
            data={key: VectorDouble._from_proto(val) for key, val in proto_message.data.items()},
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "DataFile":
        message = telemetry_lap_data_pb2.DataFile()
        message.ParseFromString(data)
        return cls(
            data = {key: VectorDouble._from_proto(val) for key, val in message.data.items()},
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "DataFile":
        message = telemetry_lap_data_pb2.DataFile()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

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

    def _populate_proto(self):
        self._proto_message.dateTime = self.dateTime
        self._proto_message.trackLocation = self.trackLocation
        self._proto_message.trackLayout = self.trackLayout
        self._proto_message.driver = self.driver
        self._proto_message.lapNumber = self.lapNumber
        self._proto_message.filenameHash = self.filenameHash

    @classmethod
    def _from_proto(cls, proto_message) -> "TelemetryLapData":
        return cls(
            dateTime = proto_message.dateTime,
            trackLocation = proto_message.trackLocation,
            trackLayout = proto_message.trackLayout,
            driver = proto_message.driver,
            lapNumber = proto_message.lapNumber,
            filenameHash = proto_message.filenameHash,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "TelemetryLapData":
        message = telemetry_lap_data_pb2.TelemetryLapData()
        message.ParseFromString(data)
        return cls(
            dateTime = message.dateTime,
            trackLocation = message.trackLocation,
            trackLayout = message.trackLayout,
            driver = message.driver,
            lapNumber = message.lapNumber,
            filenameHash = message.filenameHash,
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "TelemetryLapData":
        message = telemetry_lap_data_pb2.TelemetryLapData()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class DataBase:
    lapsData: List[TelemetryLapData] = field(default_factory=list)
    
    _proto_message: telemetry_lap_data_pb2.DataBase = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = telemetry_lap_data_pb2.DataBase()

    def _populate_proto(self):
        del self._proto_message.lapsData[:]
        for val in self.lapsData:
            val._populate_proto()
            tmp = self._proto_message.lapsData.add()
            tmp.CopyFrom(val._proto_message)

    @classmethod
    def _from_proto(cls, proto_message) -> "DataBase":
        return cls(
            lapsData=[TelemetryLapData._from_proto(val) for val in proto_message.lapsData],
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "DataBase":
        message = telemetry_lap_data_pb2.DataBase()
        message.ParseFromString(data)
        return cls(
            lapsData = [TelemetryLapData._from_proto(val) for val in message.lapsData],
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "DataBase":
        message = telemetry_lap_data_pb2.DataBase()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())
