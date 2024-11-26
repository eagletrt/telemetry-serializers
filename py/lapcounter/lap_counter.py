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

    def populate_proto(self):
        self._proto_message.position_x = self.position_x
        self._proto_message.position_y = self.position_y
        self._proto_message.inclination_x = self.inclination_x
        self._proto_message.inclination_y = self.inclination_y

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "LcPoint":
        message = lap_counter_pb2.LcPoint()
        message.ParseFromString(data)
        return cls(
            position_x=message.position_x,
            position_y=message.position_y,
            inclination_x=message.inclination_x,
            inclination_y=message.inclination_y,
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "LcPoint":
        message = lap_counter_pb2.LcPoint()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    def __str__(self):
        return self.serializeAsJsonString()

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

    def populate_proto(self):
        self._proto_message.layout_id = self.layout_id
        self._proto_message.name = self.name
        if self.start1:
            self._proto_message.start1.CopyFrom(self.start1._proto_message)
        if self.start2:
            self._proto_message.start2.CopyFrom(self.start2._proto_message)
        self._proto_message.sector_count = self.sector_count
        del self._proto_message.sectors[:]
        for value in self.sectors:
            value.populate_proto()
            tmp = self._proto_message.sectors.add()
            tmp.CopyFrom(value._proto_message)

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "TrackLayout":
        message = lap_counter_pb2.TrackLayout()
        message.ParseFromString(data)
        return cls(
            layout_id=message.layout_id,
            name=message.name,
            start1=message.start1,
            start2=message.start2,
            sector_count=message.sector_count,
            sectors=[LcPoint(value) for value in message.sectors],
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "TrackLayout":
        message = lap_counter_pb2.TrackLayout()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    def __str__(self):
        return self.serializeAsJsonString()

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

    def populate_proto(self):
        self._proto_message.layout_id = self.layout_id
        self._proto_message.lap_number = self.lap_number
        self._proto_message.driver_name = self.driver_name
        self._proto_message.start_timestamp = self.start_timestamp
        self._proto_message.end_timestamp = self.end_timestamp
        del self._proto_message.sectors_timestamp[:]
        for value in self.sectors_timestamp:
            value.populate_proto()
            tmp = self._proto_message.sectors_timestamp.add()
            tmp.CopyFrom(value._proto_message)

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Time":
        message = lap_counter_pb2.Time()
        message.ParseFromString(data)
        return cls(
            layout_id=message.layout_id,
            lap_number=message.lap_number,
            driver_name=message.driver_name,
            start_timestamp=message.start_timestamp,
            end_timestamp=message.end_timestamp,
            sectors_timestamp=[int(value) for value in message.sectors_timestamp],
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Time":
        message = lap_counter_pb2.Time()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    def __str__(self):
        return self.serializeAsJsonString()

@dataclass
class DriverRecord:
    driver: str = ""
    start_timestamp: int = 0
    end_timestamp: int = 0
    sectors_timestamp: List[int] = field(default_factory=list)
    
    _proto_message: lap_counter_pb2.DriverRecord = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = lap_counter_pb2.DriverRecord()

    def populate_proto(self):
        self._proto_message.driver = self.driver
        self._proto_message.start_timestamp = self.start_timestamp
        self._proto_message.end_timestamp = self.end_timestamp
        del self._proto_message.sectors_timestamp[:]
        for value in self.sectors_timestamp:
            value.populate_proto()
            tmp = self._proto_message.sectors_timestamp.add()
            tmp.CopyFrom(value._proto_message)

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "DriverRecord":
        message = lap_counter_pb2.DriverRecord()
        message.ParseFromString(data)
        return cls(
            driver=message.driver,
            start_timestamp=message.start_timestamp,
            end_timestamp=message.end_timestamp,
            sectors_timestamp=[int(value) for value in message.sectors_timestamp],
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "DriverRecord":
        message = lap_counter_pb2.DriverRecord()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    def __str__(self):
        return self.serializeAsJsonString()

@dataclass
class TrackRecord:
    layout_id: int = 0
    lap_number: int = 0
    best_lap: DriverRecord = None
    best_sectors: List[DriverRecord] = field(default_factory=list)
    
    _proto_message: lap_counter_pb2.TrackRecord = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = lap_counter_pb2.TrackRecord()

    def populate_proto(self):
        self._proto_message.layout_id = self.layout_id
        self._proto_message.lap_number = self.lap_number
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
    def deserializeFromProtobufString(cls, data: bytes) -> "TrackRecord":
        message = lap_counter_pb2.TrackRecord()
        message.ParseFromString(data)
        return cls(
            layout_id=message.layout_id,
            lap_number=message.lap_number,
            best_lap=message.best_lap,
            best_sectors=[DriverRecord(value) for value in message.best_sectors],
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "TrackRecord":
        message = lap_counter_pb2.TrackRecord()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    def __str__(self):
        return self.serializeAsJsonString()

@dataclass
class Driver:
    name: str = ""
    times: List[Time] = field(default_factory=list)
    
    _proto_message: lap_counter_pb2.Driver = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = lap_counter_pb2.Driver()

    def populate_proto(self):
        self._proto_message.name = self.name
        del self._proto_message.times[:]
        for value in self.times:
            value.populate_proto()
            tmp = self._proto_message.times.add()
            tmp.CopyFrom(value._proto_message)

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Driver":
        message = lap_counter_pb2.Driver()
        message.ParseFromString(data)
        return cls(
            name=message.name,
            times=[Time(value) for value in message.times],
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Driver":
        message = lap_counter_pb2.Driver()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    def __str__(self):
        return self.serializeAsJsonString()

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

    def populate_proto(self):
        del self._proto_message.layouts[:]
        for value in self.layouts:
            value.populate_proto()
            tmp = self._proto_message.layouts.add()
            tmp.CopyFrom(value._proto_message)
        del self._proto_message.drivers[:]
        for value in self.drivers:
            value.populate_proto()
            tmp = self._proto_message.drivers.add()
            tmp.CopyFrom(value._proto_message)
        del self._proto_message.records[:]
        for value in self.records:
            value.populate_proto()
            tmp = self._proto_message.records.add()
            tmp.CopyFrom(value._proto_message)
        self._proto_message.last_id = self.last_id
        self._proto_message.lap_number = self.lap_number

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "DataBase":
        message = lap_counter_pb2.DataBase()
        message.ParseFromString(data)
        return cls(
            layouts=[TrackLayout(value) for value in message.layouts],
            drivers=[Driver(value) for value in message.drivers],
            records=[TrackRecord(value) for value in message.records],
            last_id=message.last_id,
            lap_number=message.lap_number,
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "DataBase":
        message = lap_counter_pb2.DataBase()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    def __str__(self):
        return self.serializeAsJsonString()
