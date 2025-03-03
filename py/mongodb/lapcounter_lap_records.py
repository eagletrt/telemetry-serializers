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

    def _populate_proto(self):
        self._proto_message.driver = self.driver
        self._proto_message.start = self.start
        self._proto_message.end = self.end
        del self._proto_message.sectors[:]
        for val in self.sectors:
            self._proto_message.sectors.append(val)

    @classmethod
    def _from_proto(cls, proto_message) -> "LapRecord":
        return cls(
            driver = proto_message.driver,
            start = proto_message.start,
            end = proto_message.end,
            sectors=[int(val) for val in proto_message.sectors],
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "LapRecord":
        message = lapcounter_lap_records_pb2.LapRecord()
        message.ParseFromString(data)
        return cls(
            driver = message.driver,
            start = message.start,
            end = message.end,
            sectors = [int(val) for val in message.sectors],
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "LapRecord":
        message = lapcounter_lap_records_pb2.LapRecord()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class SectorsRecord:
    driver: str = ""
    start_time_sector: int = 0
    end_time_sector: int = 0
    
    _proto_message: lapcounter_lap_records_pb2.SectorsRecord = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = lapcounter_lap_records_pb2.SectorsRecord()

    def _populate_proto(self):
        self._proto_message.driver = self.driver
        self._proto_message.start_time_sector = self.start_time_sector
        self._proto_message.end_time_sector = self.end_time_sector

    @classmethod
    def _from_proto(cls, proto_message) -> "SectorsRecord":
        return cls(
            driver = proto_message.driver,
            start_time_sector = proto_message.start_time_sector,
            end_time_sector = proto_message.end_time_sector,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "SectorsRecord":
        message = lapcounter_lap_records_pb2.SectorsRecord()
        message.ParseFromString(data)
        return cls(
            driver = message.driver,
            start_time_sector = message.start_time_sector,
            end_time_sector = message.end_time_sector,
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "SectorsRecord":
        message = lapcounter_lap_records_pb2.SectorsRecord()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class DriverRecord:
    driver: str = ""
    best_lap: LapRecord = None
    best_sectors: List[SectorsRecord] = field(default_factory=list)
    
    _proto_message: lapcounter_lap_records_pb2.DriverRecord = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = lapcounter_lap_records_pb2.DriverRecord()

    def _populate_proto(self):
        self._proto_message.driver = self.driver
        if self.best_lap:
            self.best_lap._populate_proto()
            self._proto_message.best_lap.CopyFrom(self.best_lap._proto_message)
        del self._proto_message.best_sectors[:]
        for val in self.best_sectors:
            val._populate_proto()
            tmp = self._proto_message.best_sectors.add()
            tmp.CopyFrom(val._proto_message)

    @classmethod
    def _from_proto(cls, proto_message) -> "DriverRecord":
        return cls(
            driver = proto_message.driver,
            best_lap = LapRecord._from_proto(proto_message.best_lap),
            best_sectors=[SectorsRecord._from_proto(val) for val in proto_message.best_sectors],
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "DriverRecord":
        message = lapcounter_lap_records_pb2.DriverRecord()
        message.ParseFromString(data)
        return cls(
            driver = message.driver,
            best_lap = (
                LapRecord._from_proto(message.best_lap)
                if message.HasField("best_lap")
                else None
            ),
            best_sectors = [SectorsRecord._from_proto(val) for val in message.best_sectors],
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "DriverRecord":
        message = lapcounter_lap_records_pb2.DriverRecord()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

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

    def _populate_proto(self):
        self._proto_message.version = self.version
        self._proto_message.baseline_version = self.baseline_version
        self._proto_message.vehicle_id = self.vehicle_id
        self._proto_message.device_id = self.device_id
        self._proto_message.location = self.location
        self._proto_message.layout = self.layout
        if self.best_lap:
            self.best_lap._populate_proto()
            self._proto_message.best_lap.CopyFrom(self.best_lap._proto_message)
        del self._proto_message.best_sectors[:]
        for val in self.best_sectors:
            val._populate_proto()
            tmp = self._proto_message.best_sectors.add()
            tmp.CopyFrom(val._proto_message)
        del self._proto_message.drivers_records[:]
        for val in self.drivers_records:
            val._populate_proto()
            tmp = self._proto_message.drivers_records.add()
            tmp.CopyFrom(val._proto_message)

    @classmethod
    def _from_proto(cls, proto_message) -> "LapRecords":
        return cls(
            version = proto_message.version,
            baseline_version = proto_message.baseline_version,
            vehicle_id = proto_message.vehicle_id,
            device_id = proto_message.device_id,
            location = proto_message.location,
            layout = proto_message.layout,
            best_lap = LapRecord._from_proto(proto_message.best_lap),
            best_sectors=[SectorsRecord._from_proto(val) for val in proto_message.best_sectors],
            drivers_records=[DriverRecord._from_proto(val) for val in proto_message.drivers_records],
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "LapRecords":
        message = lapcounter_lap_records_pb2.LapRecords()
        message.ParseFromString(data)
        return cls(
            version = message.version,
            baseline_version = message.baseline_version,
            vehicle_id = message.vehicle_id,
            device_id = message.device_id,
            location = message.location,
            layout = message.layout,
            best_lap = (
                LapRecord._from_proto(message.best_lap)
                if message.HasField("best_lap")
                else None
            ),
            best_sectors = [SectorsRecord._from_proto(val) for val in message.best_sectors],
            drivers_records = [DriverRecord._from_proto(val) for val in message.drivers_records],
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "LapRecords":
        message = lapcounter_lap_records_pb2.LapRecords()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())
