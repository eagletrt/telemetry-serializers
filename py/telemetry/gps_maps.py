from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict

from telemetry import gps_maps_pb2
from google.protobuf.json_format import MessageToJson, Parse


@dataclass
class Baseline:
    valid: bool = ""
    logging: bool = ""
    length: float = 0.0
    x: List[float] = field(default_factory=list)
    y: List[float] = field(default_factory=list)
    resampled: bool = ""
    s: List[float] = field(default_factory=list)
    theta: List[float] = field(default_factory=list)
    
    _proto_message: gps_maps_pb2.Baseline = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = gps_maps_pb2.Baseline()

    def populate_proto(self):
        self._proto_message.valid = self.valid
        self._proto_message.logging = self.logging
        self._proto_message.length = self.length
        del self._proto_message.x[:]
        for value in self.x:
            value.populate_proto()
            tmp = self._proto_message.x.add()
            tmp.CopyFrom(value._proto_message)
        del self._proto_message.y[:]
        for value in self.y:
            value.populate_proto()
            tmp = self._proto_message.y.add()
            tmp.CopyFrom(value._proto_message)
        self._proto_message.resampled = self.resampled
        del self._proto_message.s[:]
        for value in self.s:
            value.populate_proto()
            tmp = self._proto_message.s.add()
            tmp.CopyFrom(value._proto_message)
        del self._proto_message.theta[:]
        for value in self.theta:
            value.populate_proto()
            tmp = self._proto_message.theta.add()
            tmp.CopyFrom(value._proto_message)

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Baseline":
        message = gps_maps_pb2.Baseline()
        message.ParseFromString(data)
        return cls(
            valid=message.valid,
            logging=message.logging,
            length=message.length,
            x=[float(value) for value in message.x],
            y=[float(value) for value in message.y],
            resampled=message.resampled,
            s=[float(value) for value in message.s],
            theta=[float(value) for value in message.theta],
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Baseline":
        message = gps_maps_pb2.Baseline()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    def __str__(self):
        return self.serializeAsJsonString()

@dataclass
class GPSMapOrigin:
    latitude: float = 0.0
    longitude: float = 0.0
    altitude: float = 0.0
    
    _proto_message: gps_maps_pb2.GPSMapOrigin = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = gps_maps_pb2.GPSMapOrigin()

    def populate_proto(self):
        self._proto_message.latitude = self.latitude
        self._proto_message.longitude = self.longitude
        self._proto_message.altitude = self.altitude

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "GPSMapOrigin":
        message = gps_maps_pb2.GPSMapOrigin()
        message.ParseFromString(data)
        return cls(
            latitude=message.latitude,
            longitude=message.longitude,
            altitude=message.altitude,
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "GPSMapOrigin":
        message = gps_maps_pb2.GPSMapOrigin()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    def __str__(self):
        return self.serializeAsJsonString()

@dataclass
class GPSMapOrigins:
    trackLocation: str = ""
    trackLayout: str = ""
    origins: Dict[str, GPSMapOrigin] = field(default_factory=dict)
    tracksBaseline: Dict[str, Baseline] = field(default_factory=dict)
    
    _proto_message: gps_maps_pb2.GPSMapOrigins = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = gps_maps_pb2.GPSMapOrigins()

    def populate_proto(self):
        self._proto_message.trackLocation = self.trackLocation
        self._proto_message.trackLayout = self.trackLayout
        self._proto_message.origins.clear()
        for key, value in self.origins.items():
            value.populate_proto()
            tmp = self._proto_message.origins.setdefault(key)
            tmp.CopyFrom(value._proto_message)
        self._proto_message.tracksBaseline.clear()
        for key, value in self.tracksBaseline.items():
            value.populate_proto()
            tmp = self._proto_message.tracksBaseline.setdefault(key)
            tmp.CopyFrom(value._proto_message)

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "GPSMapOrigins":
        message = gps_maps_pb2.GPSMapOrigins()
        message.ParseFromString(data)
        return cls(
            trackLocation=message.trackLocation,
            trackLayout=message.trackLayout,
            origins={key: value for key, value in message.origins.items()},
            tracksBaseline={key: value for key, value in message.tracksBaseline.items()},
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "GPSMapOrigins":
        message = gps_maps_pb2.GPSMapOrigins()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    def __str__(self):
        return self.serializeAsJsonString()

@dataclass
class SetBaseline:
    trackLocation: str = ""
    trackLayout: str = ""
    origin: GPSMapOrigin = None
    x: List[float] = field(default_factory=list)
    y: List[float] = field(default_factory=list)
    
    _proto_message: gps_maps_pb2.SetBaseline = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = gps_maps_pb2.SetBaseline()

    def populate_proto(self):
        self._proto_message.trackLocation = self.trackLocation
        self._proto_message.trackLayout = self.trackLayout
        if self.origin:
            self._proto_message.origin.CopyFrom(self.origin._proto_message)
        del self._proto_message.x[:]
        for value in self.x:
            value.populate_proto()
            tmp = self._proto_message.x.add()
            tmp.CopyFrom(value._proto_message)
        del self._proto_message.y[:]
        for value in self.y:
            value.populate_proto()
            tmp = self._proto_message.y.add()
            tmp.CopyFrom(value._proto_message)

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "SetBaseline":
        message = gps_maps_pb2.SetBaseline()
        message.ParseFromString(data)
        return cls(
            trackLocation=message.trackLocation,
            trackLayout=message.trackLayout,
            origin=message.origin,
            x=[float(value) for value in message.x],
            y=[float(value) for value in message.y],
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "SetBaseline":
        message = gps_maps_pb2.SetBaseline()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    def __str__(self):
        return self.serializeAsJsonString()
