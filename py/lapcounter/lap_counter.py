from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict

from lapcounter import lap_counter_pb2
from google.protobuf.json_format import MessageToJson, Parse


@dataclass
class LcPoint:
    position_x: float = 0.0
    position_y: float = 0.0
    inclination_x: float = 0.0
    inclination_y: float = 0.0
    
    _proto_message: lap_counter_pb2.LcPoint = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = lap_counter_pb2.LcPoint()

    def _populate_proto(self):
        self._proto_message.position_x = self.position_x
        self._proto_message.position_y = self.position_y
        self._proto_message.inclination_x = self.inclination_x
        self._proto_message.inclination_y = self.inclination_y

    @classmethod
    def _from_proto(cls, proto_message) -> "LcPoint":
        return cls(
            position_x = proto_message.position_x,
            position_y = proto_message.position_y,
            inclination_x = proto_message.inclination_x,
            inclination_y = proto_message.inclination_y,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "LcPoint":
        message = lap_counter_pb2.LcPoint()
        message.ParseFromString(data)
        return cls(
            position_x = message.position_x,
            position_y = message.position_y,
            inclination_x = message.inclination_x,
            inclination_y = message.inclination_y,
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "LcPoint":
        message = lap_counter_pb2.LcPoint()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class TrackLayout:
    layout_id: int = 0
    name: str = ""
    start1: LcPoint = None
    start2: LcPoint = None
    sector_count: int = 0
    sectors: List[LcPoint] = field(default_factory=list)
    
    _proto_message: lap_counter_pb2.TrackLayout = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = lap_counter_pb2.TrackLayout()

    def _populate_proto(self):
        self._proto_message.layout_id = self.layout_id
        self._proto_message.name = self.name
        if self.start1:
            self.start1._populate_proto()
            self._proto_message.start1.CopyFrom(self.start1._proto_message)
        if self.start2:
            self.start2._populate_proto()
            self._proto_message.start2.CopyFrom(self.start2._proto_message)
        self._proto_message.sector_count = self.sector_count
        del self._proto_message.sectors[:]
        for val in self.sectors:
            val._populate_proto()
            tmp = self._proto_message.sectors.add()
            tmp.CopyFrom(val._proto_message)

    @classmethod
    def _from_proto(cls, proto_message) -> "TrackLayout":
        return cls(
            layout_id = proto_message.layout_id,
            name = proto_message.name,
            start1 = LcPoint._from_proto(proto_message.start1),
            start2 = LcPoint._from_proto(proto_message.start2),
            sector_count = proto_message.sector_count,
            sectors=[LcPoint._from_proto(val) for val in proto_message.sectors],
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "TrackLayout":
        message = lap_counter_pb2.TrackLayout()
        message.ParseFromString(data)
        return cls(
            layout_id = message.layout_id,
            name = message.name,
            start1 = (
                LcPoint._from_proto(message.start1)
                if message.HasField("start1")
                else None
            ),
            start2 = (
                LcPoint._from_proto(message.start2)
                if message.HasField("start2")
                else None
            ),
            sector_count = message.sector_count,
            sectors = [LcPoint._from_proto(val) for val in message.sectors],
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "TrackLayout":
        message = lap_counter_pb2.TrackLayout()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class Time:
    layout_id: int = 0
    lap_number: int = 0
    driver_name: str = ""
    start_timestamp: int = 0
    end_timestamp: int = 0
    sectors_timestamp: List[int] = field(default_factory=list)
    
    _proto_message: lap_counter_pb2.Time = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = lap_counter_pb2.Time()

    def _populate_proto(self):
        self._proto_message.layout_id = self.layout_id
        self._proto_message.lap_number = self.lap_number
        self._proto_message.driver_name = self.driver_name
        self._proto_message.start_timestamp = self.start_timestamp
        self._proto_message.end_timestamp = self.end_timestamp
        del self._proto_message.sectors_timestamp[:]
        for val in self.sectors_timestamp:
            self._proto_message.sectors_timestamp.append(val)

    @classmethod
    def _from_proto(cls, proto_message) -> "Time":
        return cls(
            layout_id = proto_message.layout_id,
            lap_number = proto_message.lap_number,
            driver_name = proto_message.driver_name,
            start_timestamp = proto_message.start_timestamp,
            end_timestamp = proto_message.end_timestamp,
            sectors_timestamp=[int(val) for val in proto_message.sectors_timestamp],
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Time":
        message = lap_counter_pb2.Time()
        message.ParseFromString(data)
        return cls(
            layout_id = message.layout_id,
            lap_number = message.lap_number,
            driver_name = message.driver_name,
            start_timestamp = message.start_timestamp,
            end_timestamp = message.end_timestamp,
            sectors_timestamp = [int(val) for val in message.sectors_timestamp],
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Time":
        message = lap_counter_pb2.Time()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class DriverRecord:
    driver: str = ""
    start_timestamp: int = 0
    end_timestamp: int = 0
    sectors_timestamp: List[int] = field(default_factory=list)
    
    _proto_message: lap_counter_pb2.DriverRecord = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = lap_counter_pb2.DriverRecord()

    def _populate_proto(self):
        self._proto_message.driver = self.driver
        self._proto_message.start_timestamp = self.start_timestamp
        self._proto_message.end_timestamp = self.end_timestamp
        del self._proto_message.sectors_timestamp[:]
        for val in self.sectors_timestamp:
            self._proto_message.sectors_timestamp.append(val)

    @classmethod
    def _from_proto(cls, proto_message) -> "DriverRecord":
        return cls(
            driver = proto_message.driver,
            start_timestamp = proto_message.start_timestamp,
            end_timestamp = proto_message.end_timestamp,
            sectors_timestamp=[int(val) for val in proto_message.sectors_timestamp],
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "DriverRecord":
        message = lap_counter_pb2.DriverRecord()
        message.ParseFromString(data)
        return cls(
            driver = message.driver,
            start_timestamp = message.start_timestamp,
            end_timestamp = message.end_timestamp,
            sectors_timestamp = [int(val) for val in message.sectors_timestamp],
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "DriverRecord":
        message = lap_counter_pb2.DriverRecord()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class TrackRecord:
    layout_id: int = 0
    lap_number: int = 0
    best_lap: DriverRecord = None
    best_sectors: List[DriverRecord] = field(default_factory=list)
    
    _proto_message: lap_counter_pb2.TrackRecord = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = lap_counter_pb2.TrackRecord()

    def _populate_proto(self):
        self._proto_message.layout_id = self.layout_id
        self._proto_message.lap_number = self.lap_number
        if self.best_lap:
            self.best_lap._populate_proto()
            self._proto_message.best_lap.CopyFrom(self.best_lap._proto_message)
        del self._proto_message.best_sectors[:]
        for val in self.best_sectors:
            val._populate_proto()
            tmp = self._proto_message.best_sectors.add()
            tmp.CopyFrom(val._proto_message)

    @classmethod
    def _from_proto(cls, proto_message) -> "TrackRecord":
        return cls(
            layout_id = proto_message.layout_id,
            lap_number = proto_message.lap_number,
            best_lap = DriverRecord._from_proto(proto_message.best_lap),
            best_sectors=[DriverRecord._from_proto(val) for val in proto_message.best_sectors],
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "TrackRecord":
        message = lap_counter_pb2.TrackRecord()
        message.ParseFromString(data)
        return cls(
            layout_id = message.layout_id,
            lap_number = message.lap_number,
            best_lap = (
                DriverRecord._from_proto(message.best_lap)
                if message.HasField("best_lap")
                else None
            ),
            best_sectors = [DriverRecord._from_proto(val) for val in message.best_sectors],
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "TrackRecord":
        message = lap_counter_pb2.TrackRecord()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class Driver:
    name: str = ""
    times: List[Time] = field(default_factory=list)
    
    _proto_message: lap_counter_pb2.Driver = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = lap_counter_pb2.Driver()

    def _populate_proto(self):
        self._proto_message.name = self.name
        del self._proto_message.times[:]
        for val in self.times:
            val._populate_proto()
            tmp = self._proto_message.times.add()
            tmp.CopyFrom(val._proto_message)

    @classmethod
    def _from_proto(cls, proto_message) -> "Driver":
        return cls(
            name = proto_message.name,
            times=[Time._from_proto(val) for val in proto_message.times],
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Driver":
        message = lap_counter_pb2.Driver()
        message.ParseFromString(data)
        return cls(
            name = message.name,
            times = [Time._from_proto(val) for val in message.times],
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Driver":
        message = lap_counter_pb2.Driver()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class DataBase:
    layouts: List[TrackLayout] = field(default_factory=list)
    drivers: List[Driver] = field(default_factory=list)
    records: List[TrackRecord] = field(default_factory=list)
    last_id: int = 0
    lap_number: int = 0
    
    _proto_message: lap_counter_pb2.DataBase = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = lap_counter_pb2.DataBase()

    def _populate_proto(self):
        del self._proto_message.layouts[:]
        for val in self.layouts:
            val._populate_proto()
            tmp = self._proto_message.layouts.add()
            tmp.CopyFrom(val._proto_message)
        del self._proto_message.drivers[:]
        for val in self.drivers:
            val._populate_proto()
            tmp = self._proto_message.drivers.add()
            tmp.CopyFrom(val._proto_message)
        del self._proto_message.records[:]
        for val in self.records:
            val._populate_proto()
            tmp = self._proto_message.records.add()
            tmp.CopyFrom(val._proto_message)
        self._proto_message.last_id = self.last_id
        self._proto_message.lap_number = self.lap_number

    @classmethod
    def _from_proto(cls, proto_message) -> "DataBase":
        return cls(
            layouts=[TrackLayout._from_proto(val) for val in proto_message.layouts],
            drivers=[Driver._from_proto(val) for val in proto_message.drivers],
            records=[TrackRecord._from_proto(val) for val in proto_message.records],
            last_id = proto_message.last_id,
            lap_number = proto_message.lap_number,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "DataBase":
        message = lap_counter_pb2.DataBase()
        message.ParseFromString(data)
        return cls(
            layouts = [TrackLayout._from_proto(val) for val in message.layouts],
            drivers = [Driver._from_proto(val) for val in message.drivers],
            records = [TrackRecord._from_proto(val) for val in message.records],
            last_id = message.last_id,
            lap_number = message.lap_number,
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "DataBase":
        message = lap_counter_pb2.DataBase()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())
