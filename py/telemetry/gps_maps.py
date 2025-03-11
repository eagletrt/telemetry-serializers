from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict

from telemetry import gps_maps_pb2
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
    
    _proto_message: gps_maps_pb2.Baseline = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = gps_maps_pb2.Baseline()

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
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Baseline":
        message = gps_maps_pb2.Baseline()
        message.ParseFromString(data)
        return cls(
            valid = message.valid,
            logging = message.logging,
            length = message.length,
            x = [float(val) for val in message.x],
            y = [float(val) for val in message.y],
            resampled = message.resampled,
            s = [float(val) for val in message.s],
            theta = [float(val) for val in message.theta],
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Baseline":
        message = gps_maps_pb2.Baseline()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class GPSMapOrigin:
    latitude: float = 0.0
    longitude: float = 0.0
    altitude: float = 0.0
    
    _proto_message: gps_maps_pb2.GPSMapOrigin = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = gps_maps_pb2.GPSMapOrigin()

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
        message = gps_maps_pb2.GPSMapOrigin()
        message.ParseFromString(data)
        return cls(
            latitude = message.latitude,
            longitude = message.longitude,
            altitude = message.altitude,
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "GPSMapOrigin":
        message = gps_maps_pb2.GPSMapOrigin()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class GPSMapOrigins:
    trackLocation: str = ""
    trackLayout: str = ""
    origins: Dict[str, GPSMapOrigin] = field(default_factory=dict)
    tracksBaseline: Dict[str, Baseline] = field(default_factory=dict)
    
    _proto_message: gps_maps_pb2.GPSMapOrigins = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = gps_maps_pb2.GPSMapOrigins()

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
        message = gps_maps_pb2.GPSMapOrigins()
        message.ParseFromString(data)
        return cls(
            trackLocation = message.trackLocation,
            trackLayout = message.trackLayout,
            origins = {key: GPSMapOrigin._from_proto(val) for key, val in message.origins.items()},
            tracksBaseline = {key: Baseline._from_proto(val) for key, val in message.tracksBaseline.items()},
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "GPSMapOrigins":
        message = gps_maps_pb2.GPSMapOrigins()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

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
        message = gps_maps_pb2.SetBaseline()
        message.ParseFromString(data)
        return cls(
            trackLocation = message.trackLocation,
            trackLayout = message.trackLayout,
            origin = (
                GPSMapOrigin._from_proto(message.origin)
                if message.HasField("origin")
                else None
            ),
            x = [float(val) for val in message.x],
            y = [float(val) for val in message.y],
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "SetBaseline":
        message = gps_maps_pb2.SetBaseline()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())
