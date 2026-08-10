from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict, Optional

from track import track_pb2
from google.protobuf.json_format import MessageToJson, Parse


@dataclass
class Baseline:
    valid: bool = False
    logging: bool = False
    length: float = 0.0
    x: List[float] = field(default_factory=list)
    y: List[float] = field(default_factory=list)
    resampled: bool = False
    s: List[float] = field(default_factory=list)
    theta: List[float] = field(default_factory=list)
    hash: str = ""
    
    _proto_message: track_pb2.Baseline = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = track_pb2.Baseline()

    def _populate_proto(self):
        self._proto_message.valid = self.valid
        self._proto_message.logging = self.logging
        self._proto_message.length = self.length
        del self._proto_message.x[:]
        for val in self.x:
            self._proto_message.x.append(val)
        del self._proto_message.y[:]
        for val in self.y:
            self._proto_message.y.append(val)
        self._proto_message.resampled = self.resampled
        del self._proto_message.s[:]
        for val in self.s:
            self._proto_message.s.append(val)
        del self._proto_message.theta[:]
        for val in self.theta:
            self._proto_message.theta.append(val)
        self._proto_message.hash = self.hash

    @classmethod
    def _from_proto(cls, proto_message) -> "Baseline":
        return cls(
            valid = proto_message.valid,
            logging = proto_message.logging,
            length = proto_message.length,
            x=[float(val) for val in proto_message.x],
            y=[float(val) for val in proto_message.y],
            resampled = proto_message.resampled,
            s=[float(val) for val in proto_message.s],
            theta=[float(val) for val in proto_message.theta],
            hash = proto_message.hash,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Baseline":
        message = track_pb2.Baseline()
        message.ParseFromString(data)
        return cls._from_proto(message)

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message, preserving_proto_field_name=True)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Baseline":
        message = track_pb2.Baseline()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class GPSMapOrigin:
    latitude: float = 0.0
    longitude: float = 0.0
    altitude: float = 0.0
    
    _proto_message: track_pb2.GPSMapOrigin = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = track_pb2.GPSMapOrigin()

    def _populate_proto(self):
        self._proto_message.latitude = self.latitude
        self._proto_message.longitude = self.longitude
        self._proto_message.altitude = self.altitude

    @classmethod
    def _from_proto(cls, proto_message) -> "GPSMapOrigin":
        return cls(
            latitude = proto_message.latitude,
            longitude = proto_message.longitude,
            altitude = proto_message.altitude,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "GPSMapOrigin":
        message = track_pb2.GPSMapOrigin()
        message.ParseFromString(data)
        return cls._from_proto(message)

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message, preserving_proto_field_name=True)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "GPSMapOrigin":
        message = track_pb2.GPSMapOrigin()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class GPSMapOrigins:
    trackLocation: str = ""
    trackLayout: str = ""
    origins: Dict[str, GPSMapOrigin] = field(default_factory=dict)
    tracksBaseline: Dict[str, Baseline] = field(default_factory=dict)
    
    _proto_message: track_pb2.GPSMapOrigins = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = track_pb2.GPSMapOrigins()

    def _populate_proto(self):
        self._proto_message.trackLocation = self.trackLocation
        self._proto_message.trackLayout = self.trackLayout
        self._proto_message.origins.clear()
        for key, val in self.origins.items():
            val._populate_proto()
            tmp = self._proto_message.origins.setdefault(key)
            tmp.CopyFrom(val._proto_message)
        self._proto_message.tracksBaseline.clear()
        for key, val in self.tracksBaseline.items():
            val._populate_proto()
            tmp = self._proto_message.tracksBaseline.setdefault(key)
            tmp.CopyFrom(val._proto_message)

    @classmethod
    def _from_proto(cls, proto_message) -> "GPSMapOrigins":
        return cls(
            trackLocation = proto_message.trackLocation,
            trackLayout = proto_message.trackLayout,
            origins={key: GPSMapOrigin._from_proto(val) for key, val in proto_message.origins.items()},
            tracksBaseline={key: Baseline._from_proto(val) for key, val in proto_message.tracksBaseline.items()},
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "GPSMapOrigins":
        message = track_pb2.GPSMapOrigins()
        message.ParseFromString(data)
        return cls._from_proto(message)

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message, preserving_proto_field_name=True)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "GPSMapOrigins":
        message = track_pb2.GPSMapOrigins()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class SetBaseline:
    trackLocation: str = ""
    trackLayout: str = ""
    origin: GPSMapOrigin = None
    x: List[float] = field(default_factory=list)
    y: List[float] = field(default_factory=list)
    
    _proto_message: track_pb2.SetBaseline = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = track_pb2.SetBaseline()

    def _populate_proto(self):
        self._proto_message.trackLocation = self.trackLocation
        self._proto_message.trackLayout = self.trackLayout
        if self.origin:
            self.origin._populate_proto()
            self._proto_message.origin.CopyFrom(self.origin._proto_message)
        del self._proto_message.x[:]
        for val in self.x:
            self._proto_message.x.append(val)
        del self._proto_message.y[:]
        for val in self.y:
            self._proto_message.y.append(val)

    @classmethod
    def _from_proto(cls, proto_message) -> "SetBaseline":
        return cls(
            trackLocation = proto_message.trackLocation,
            trackLayout = proto_message.trackLayout,
            origin = GPSMapOrigin._from_proto(proto_message.origin),
            x=[float(val) for val in proto_message.x],
            y=[float(val) for val in proto_message.y],
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "SetBaseline":
        message = track_pb2.SetBaseline()
        message.ParseFromString(data)
        return cls._from_proto(message)

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message, preserving_proto_field_name=True)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "SetBaseline":
        message = track_pb2.SetBaseline()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class LapRecord:
    driver: str = ""
    start: int = 0
    end: int = 0
    sectors: List[int] = field(default_factory=list)
    
    _proto_message: track_pb2.LapRecord = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = track_pb2.LapRecord()

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
        message = track_pb2.LapRecord()
        message.ParseFromString(data)
        return cls._from_proto(message)

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message, preserving_proto_field_name=True)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "LapRecord":
        message = track_pb2.LapRecord()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class SectorsRecord:
    driver: str = ""
    start_time_sector: int = 0
    end_time_sector: int = 0
    
    _proto_message: track_pb2.SectorsRecord = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = track_pb2.SectorsRecord()

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
        message = track_pb2.SectorsRecord()
        message.ParseFromString(data)
        return cls._from_proto(message)

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message, preserving_proto_field_name=True)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "SectorsRecord":
        message = track_pb2.SectorsRecord()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class DriverRecord:
    driver: str = ""
    best_lap: LapRecord = None
    best_sectors: List[SectorsRecord] = field(default_factory=list)
    
    _proto_message: track_pb2.DriverRecord = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = track_pb2.DriverRecord()

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
        message = track_pb2.DriverRecord()
        message.ParseFromString(data)
        return cls._from_proto(message)

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message, preserving_proto_field_name=True)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "DriverRecord":
        message = track_pb2.DriverRecord()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class LapTime:
    number: int = 0
    start_timestamp: int = 0
    end_timestamp: int = 0
    sectors: List[int] = field(default_factory=list)
    
    _proto_message: track_pb2.LapTime = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = track_pb2.LapTime()

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
        message = track_pb2.LapTime()
        message.ParseFromString(data)
        return cls._from_proto(message)

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message, preserving_proto_field_name=True)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "LapTime":
        message = track_pb2.LapTime()
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
    baseline_hash: str = ""
    session_start_timestamp: int = 0
    session_name: str = ""
    
    _proto_message: track_pb2.LapTimes = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = track_pb2.LapTimes()

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
        self._proto_message.baseline_hash = self.baseline_hash
        self._proto_message.session_start_timestamp = self.session_start_timestamp
        self._proto_message.session_name = self.session_name

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
            baseline_hash = proto_message.baseline_hash,
            session_start_timestamp = proto_message.session_start_timestamp,
            session_name = proto_message.session_name,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "LapTimes":
        message = track_pb2.LapTimes()
        message.ParseFromString(data)
        return cls._from_proto(message)

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message, preserving_proto_field_name=True)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "LapTimes":
        message = track_pb2.LapTimes()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class Vec2:
    x: float = 0.0
    y: float = 0.0
    
    _proto_message: track_pb2.Vec2 = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = track_pb2.Vec2()

    def _populate_proto(self):
        self._proto_message.x = self.x
        self._proto_message.y = self.y

    @classmethod
    def _from_proto(cls, proto_message) -> "Vec2":
        return cls(
            x = proto_message.x,
            y = proto_message.y,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Vec2":
        message = track_pb2.Vec2()
        message.ParseFromString(data)
        return cls._from_proto(message)

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message, preserving_proto_field_name=True)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Vec2":
        message = track_pb2.Vec2()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class PositionAndDirection:
    position: Vec2 = None
    direction: Vec2 = None
    
    _proto_message: track_pb2.PositionAndDirection = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = track_pb2.PositionAndDirection()

    def _populate_proto(self):
        if self.position:
            self.position._populate_proto()
            self._proto_message.position.CopyFrom(self.position._proto_message)
        if self.direction:
            self.direction._populate_proto()
            self._proto_message.direction.CopyFrom(self.direction._proto_message)

    @classmethod
    def _from_proto(cls, proto_message) -> "PositionAndDirection":
        return cls(
            position = Vec2._from_proto(proto_message.position),
            direction = Vec2._from_proto(proto_message.direction),
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "PositionAndDirection":
        message = track_pb2.PositionAndDirection()
        message.ParseFromString(data)
        return cls._from_proto(message)

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message, preserving_proto_field_name=True)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "PositionAndDirection":
        message = track_pb2.PositionAndDirection()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class Layout:
    version: int = 0
    baseline_version: int = 0
    vehicle_id: str = ""
    device_id: str = ""
    location: str = ""
    layout: str = ""
    start_line: PositionAndDirection = None
    finish_line: PositionAndDirection = None
    sectors: List[PositionAndDirection] = field(default_factory=list)
    baseline_hash: str = ""
    start_s: float = 0.0
    sectors_s: List[float] = field(default_factory=list)
    baseline_length: float = 0.0
    
    _proto_message: track_pb2.Layout = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = track_pb2.Layout()

    def _populate_proto(self):
        self._proto_message.version = self.version
        self._proto_message.baseline_version = self.baseline_version
        self._proto_message.vehicle_id = self.vehicle_id
        self._proto_message.device_id = self.device_id
        self._proto_message.location = self.location
        self._proto_message.layout = self.layout
        if self.start_line:
            self.start_line._populate_proto()
            self._proto_message.start_line.CopyFrom(self.start_line._proto_message)
        if self.finish_line:
            self.finish_line._populate_proto()
            self._proto_message.finish_line.CopyFrom(self.finish_line._proto_message)
        del self._proto_message.sectors[:]
        for val in self.sectors:
            val._populate_proto()
            tmp = self._proto_message.sectors.add()
            tmp.CopyFrom(val._proto_message)
        self._proto_message.baseline_hash = self.baseline_hash
        self._proto_message.start_s = self.start_s
        del self._proto_message.sectors_s[:]
        for val in self.sectors_s:
            self._proto_message.sectors_s.append(val)
        self._proto_message.baseline_length = self.baseline_length

    @classmethod
    def _from_proto(cls, proto_message) -> "Layout":
        return cls(
            version = proto_message.version,
            baseline_version = proto_message.baseline_version,
            vehicle_id = proto_message.vehicle_id,
            device_id = proto_message.device_id,
            location = proto_message.location,
            layout = proto_message.layout,
            start_line = PositionAndDirection._from_proto(proto_message.start_line),
            finish_line = PositionAndDirection._from_proto(proto_message.finish_line),
            sectors=[PositionAndDirection._from_proto(val) for val in proto_message.sectors],
            baseline_hash = proto_message.baseline_hash,
            start_s = proto_message.start_s,
            sectors_s=[float(val) for val in proto_message.sectors_s],
            baseline_length = proto_message.baseline_length,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Layout":
        message = track_pb2.Layout()
        message.ParseFromString(data)
        return cls._from_proto(message)

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message, preserving_proto_field_name=True)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Layout":
        message = track_pb2.Layout()
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
    baseline_hash: str = ""
    session_start_timestamp: int = 0
    session_name: str = ""
    
    _proto_message: track_pb2.LapRecords = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = track_pb2.LapRecords()

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
        self._proto_message.baseline_hash = self.baseline_hash
        self._proto_message.session_start_timestamp = self.session_start_timestamp
        self._proto_message.session_name = self.session_name

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
            baseline_hash = proto_message.baseline_hash,
            session_start_timestamp = proto_message.session_start_timestamp,
            session_name = proto_message.session_name,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "LapRecords":
        message = track_pb2.LapRecords()
        message.ParseFromString(data)
        return cls._from_proto(message)

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message, preserving_proto_field_name=True)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "LapRecords":
        message = track_pb2.LapRecords()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class Track:
    layout: Layout = None
    lapTimes: LapTimes = None
    lapRecords: LapRecords = None
    gpsInfo: GPSMapOrigins = None
    
    _proto_message: track_pb2.Track = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = track_pb2.Track()

    def _populate_proto(self):
        if self.layout:
            self.layout._populate_proto()
            self._proto_message.layout.CopyFrom(self.layout._proto_message)
        if self.lapTimes:
            self.lapTimes._populate_proto()
            self._proto_message.lapTimes.CopyFrom(self.lapTimes._proto_message)
        if self.lapRecords:
            self.lapRecords._populate_proto()
            self._proto_message.lapRecords.CopyFrom(self.lapRecords._proto_message)
        if self.gpsInfo:
            self.gpsInfo._populate_proto()
            self._proto_message.gpsInfo.CopyFrom(self.gpsInfo._proto_message)

    @classmethod
    def _from_proto(cls, proto_message) -> "Track":
        return cls(
            layout = Layout._from_proto(proto_message.layout),
            lapTimes = LapTimes._from_proto(proto_message.lapTimes),
            lapRecords = LapRecords._from_proto(proto_message.lapRecords),
            gpsInfo = GPSMapOrigins._from_proto(proto_message.gpsInfo),
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Track":
        message = track_pb2.Track()
        message.ParseFromString(data)
        return cls._from_proto(message)

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message, preserving_proto_field_name=True)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Track":
        message = track_pb2.Track()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())
