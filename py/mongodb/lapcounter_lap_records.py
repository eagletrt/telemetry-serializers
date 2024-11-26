from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict

from mongodb import lapcounter_lap_records_pb2
from google.protobuf.json_format import MessageToJson, Parse


@dataclass
class LapRecord:
    driver: str = ""
    start: int = 0
    end: int = 0
    sectors: List[int] = field(default_factory=list)
    
    _proto_message: lapcounter_lap_records_pb2.LapRecord = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = lapcounter_lap_records_pb2.LapRecord()

    def populate_proto(self):
        self._proto_message.driver = self.driver
        self._proto_message.start = self.start
        self._proto_message.end = self.end
        del self._proto_message.sectors[:]
        for value in self.sectors:
            value.populate_proto()
            tmp = self._proto_message.sectors.add()
            tmp.CopyFrom(value._proto_message)

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "LapRecord":
        message = lapcounter_lap_records_pb2.LapRecord()
        message.ParseFromString(data)
        return cls(
            driver=message.driver,
            start=message.start,
            end=message.end,
            sectors=[int(value) for value in message.sectors],
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "LapRecord":
        message = lapcounter_lap_records_pb2.LapRecord()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    def __str__(self):
        return self.serializeAsJsonString()

@dataclass
class SectorsRecord:
    driver: str = ""
    start_time_sector: int = 0
    end_time_sector: int = 0
    
    _proto_message: lapcounter_lap_records_pb2.SectorsRecord = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = lapcounter_lap_records_pb2.SectorsRecord()

    def populate_proto(self):
        self._proto_message.driver = self.driver
        self._proto_message.start_time_sector = self.start_time_sector
        self._proto_message.end_time_sector = self.end_time_sector

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "SectorsRecord":
        message = lapcounter_lap_records_pb2.SectorsRecord()
        message.ParseFromString(data)
        return cls(
            driver=message.driver,
            start_time_sector=message.start_time_sector,
            end_time_sector=message.end_time_sector,
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "SectorsRecord":
        message = lapcounter_lap_records_pb2.SectorsRecord()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    def __str__(self):
        return self.serializeAsJsonString()

@dataclass
class DriverRecord:
    driver: str = ""
    best_lap: LapRecord = None
    best_sectors: List[SectorsRecord] = field(default_factory=list)
    
    _proto_message: lapcounter_lap_records_pb2.DriverRecord = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = lapcounter_lap_records_pb2.DriverRecord()

    def populate_proto(self):
        self._proto_message.driver = self.driver
        if self.best_lap:
            self._proto_message.best_lap.CopyFrom(self.best_lap._proto_message)
        del self._proto_message.best_sectors[:]
        for value in self.best_sectors:
            value.populate_proto()
            tmp = self._proto_message.best_sectors.add()
            tmp.CopyFrom(value._proto_message)

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "DriverRecord":
        message = lapcounter_lap_records_pb2.DriverRecord()
        message.ParseFromString(data)
        return cls(
            driver=message.driver,
            best_lap=message.best_lap,
            best_sectors=[SectorsRecord(value) for value in message.best_sectors],
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "DriverRecord":
        message = lapcounter_lap_records_pb2.DriverRecord()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    def __str__(self):
        return self.serializeAsJsonString()

@dataclass
class LapRecords:
    version: int = 0
    baseline_version: int = 0
    vehicle_id: str = ""
    device_id: str = ""
    location: str = ""
    layout: str = ""
    best_lap: LapRecord = None
    best_sectors: List[SectorsRecord] = field(default_factory=list)
    drivers_records: List[DriverRecord] = field(default_factory=list)
    
    _proto_message: lapcounter_lap_records_pb2.LapRecords = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = lapcounter_lap_records_pb2.LapRecords()

    def populate_proto(self):
        self._proto_message.version = self.version
        self._proto_message.baseline_version = self.baseline_version
        self._proto_message.vehicle_id = self.vehicle_id
        self._proto_message.device_id = self.device_id
        self._proto_message.location = self.location
        self._proto_message.layout = self.layout
        if self.best_lap:
            self._proto_message.best_lap.CopyFrom(self.best_lap._proto_message)
        del self._proto_message.best_sectors[:]
        for value in self.best_sectors:
            value.populate_proto()
            tmp = self._proto_message.best_sectors.add()
            tmp.CopyFrom(value._proto_message)
        del self._proto_message.drivers_records[:]
        for value in self.drivers_records:
            value.populate_proto()
            tmp = self._proto_message.drivers_records.add()
            tmp.CopyFrom(value._proto_message)

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "LapRecords":
        message = lapcounter_lap_records_pb2.LapRecords()
        message.ParseFromString(data)
        return cls(
            version=message.version,
            baseline_version=message.baseline_version,
            vehicle_id=message.vehicle_id,
            device_id=message.device_id,
            location=message.location,
            layout=message.layout,
            best_lap=message.best_lap,
            best_sectors=[SectorsRecord(value) for value in message.best_sectors],
            drivers_records=[DriverRecord(value) for value in message.drivers_records],
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "LapRecords":
        message = lapcounter_lap_records_pb2.LapRecords()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    def __str__(self):
        return self.serializeAsJsonString()
