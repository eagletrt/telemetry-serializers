from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict

from mongodb import lapcounter_lap_times_pb2
from google.protobuf.json_format import MessageToJson, Parse


@dataclass
class LapTime:
    number: int = 0
    start_timestamp: int = 0
    end_timestamp: int = 0
    sectors: List[int] = field(default_factory=list)
    
    _proto_message: lapcounter_lap_times_pb2.LapTime = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = lapcounter_lap_times_pb2.LapTime()

    def _populate_proto(self):
        self._proto_message.number = self.number
        self._proto_message.start_timestamp = self.start_timestamp
        self._proto_message.end_timestamp = self.end_timestamp
        del self._proto_message.sectors[:]
        for val in self.sectors:
            self._proto_message.sectors.append(val)

    @classmethod
    def _from_proto(cls, proto_message) -> "LapTime":
        return cls(
            number = proto_message.number,
            start_timestamp = proto_message.start_timestamp,
            end_timestamp = proto_message.end_timestamp,
            sectors=[int(val) for val in proto_message.sectors],
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "LapTime":
        message = lapcounter_lap_times_pb2.LapTime()
        message.ParseFromString(data)
        return cls(
            number = message.number,
            start_timestamp = message.start_timestamp,
            end_timestamp = message.end_timestamp,
            sectors = [int(val) for val in message.sectors],
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "LapTime":
        message = lapcounter_lap_times_pb2.LapTime()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class LapTimes:
    version: int = 0
    baseline_version: int = 0
    vehicle_id: str = ""
    device_id: str = ""
    location: str = ""
    layout: str = ""
    driver: str = ""
    times: List[LapTime] = field(default_factory=list)
    
    _proto_message: lapcounter_lap_times_pb2.LapTimes = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = lapcounter_lap_times_pb2.LapTimes()

    def _populate_proto(self):
        self._proto_message.version = self.version
        self._proto_message.baseline_version = self.baseline_version
        self._proto_message.vehicle_id = self.vehicle_id
        self._proto_message.device_id = self.device_id
        self._proto_message.location = self.location
        self._proto_message.layout = self.layout
        self._proto_message.driver = self.driver
        del self._proto_message.times[:]
        for val in self.times:
            val._populate_proto()
            tmp = self._proto_message.times.add()
            tmp.CopyFrom(val._proto_message)

    @classmethod
    def _from_proto(cls, proto_message) -> "LapTimes":
        return cls(
            version = proto_message.version,
            baseline_version = proto_message.baseline_version,
            vehicle_id = proto_message.vehicle_id,
            device_id = proto_message.device_id,
            location = proto_message.location,
            layout = proto_message.layout,
            driver = proto_message.driver,
            times=[LapTime._from_proto(val) for val in proto_message.times],
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "LapTimes":
        message = lapcounter_lap_times_pb2.LapTimes()
        message.ParseFromString(data)
        return cls(
            version = message.version,
            baseline_version = message.baseline_version,
            vehicle_id = message.vehicle_id,
            device_id = message.device_id,
            location = message.location,
            layout = message.layout,
            driver = message.driver,
            times = [LapTime._from_proto(val) for val in message.times],
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "LapTimes":
        message = lapcounter_lap_times_pb2.LapTimes()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())
