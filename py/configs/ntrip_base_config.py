from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict, Optional

from configs import ntrip_base_config_pb2
from google.protobuf.json_format import MessageToJson, Parse


@dataclass
class NtripBaseSurveyIn:
    minDurationS: int = 0
    accuracyLimitM: float = 0.0
    
    _proto_message: ntrip_base_config_pb2.NtripBaseSurveyIn = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = ntrip_base_config_pb2.NtripBaseSurveyIn()

    def _populate_proto(self):
        self._proto_message.minDurationS = self.minDurationS
        self._proto_message.accuracyLimitM = self.accuracyLimitM

    @classmethod
    def _from_proto(cls, proto_message) -> "NtripBaseSurveyIn":
        return cls(
            minDurationS = proto_message.minDurationS,
            accuracyLimitM = proto_message.accuracyLimitM,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "NtripBaseSurveyIn":
        message = ntrip_base_config_pb2.NtripBaseSurveyIn()
        message.ParseFromString(data)
        return cls._from_proto(message)

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message, preserving_proto_field_name=True)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "NtripBaseSurveyIn":
        message = ntrip_base_config_pb2.NtripBaseSurveyIn()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class NtripBaseFixedPosition:
    lat: float = 0.0
    lon: float = 0.0
    heightM: float = 0.0
    accuracyM: float = 0.0
    
    _proto_message: ntrip_base_config_pb2.NtripBaseFixedPosition = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = ntrip_base_config_pb2.NtripBaseFixedPosition()

    def _populate_proto(self):
        self._proto_message.lat = self.lat
        self._proto_message.lon = self.lon
        self._proto_message.heightM = self.heightM
        self._proto_message.accuracyM = self.accuracyM

    @classmethod
    def _from_proto(cls, proto_message) -> "NtripBaseFixedPosition":
        return cls(
            lat = proto_message.lat,
            lon = proto_message.lon,
            heightM = proto_message.heightM,
            accuracyM = proto_message.accuracyM,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "NtripBaseFixedPosition":
        message = ntrip_base_config_pb2.NtripBaseFixedPosition()
        message.ParseFromString(data)
        return cls._from_proto(message)

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message, preserving_proto_field_name=True)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "NtripBaseFixedPosition":
        message = ntrip_base_config_pb2.NtripBaseFixedPosition()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class NtripBaseFixAveraging:
    averageS: int = 0
    accuracyLimitM: float = 0.0
    maxStdM: float = 0.0
    
    _proto_message: ntrip_base_config_pb2.NtripBaseFixAveraging = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = ntrip_base_config_pb2.NtripBaseFixAveraging()

    def _populate_proto(self):
        self._proto_message.averageS = self.averageS
        self._proto_message.accuracyLimitM = self.accuracyLimitM
        self._proto_message.maxStdM = self.maxStdM

    @classmethod
    def _from_proto(cls, proto_message) -> "NtripBaseFixAveraging":
        return cls(
            averageS = proto_message.averageS,
            accuracyLimitM = proto_message.accuracyLimitM,
            maxStdM = proto_message.maxStdM,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "NtripBaseFixAveraging":
        message = ntrip_base_config_pb2.NtripBaseFixAveraging()
        message.ParseFromString(data)
        return cls._from_proto(message)

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message, preserving_proto_field_name=True)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "NtripBaseFixAveraging":
        message = ntrip_base_config_pb2.NtripBaseFixAveraging()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class NtripBaseUpstream:
    casterHost: str = ""
    casterPort: int = 0
    mountPoint: str = ""
    username: str = ""
    password: str = ""
    
    _proto_message: ntrip_base_config_pb2.NtripBaseUpstream = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = ntrip_base_config_pb2.NtripBaseUpstream()

    def _populate_proto(self):
        self._proto_message.casterHost = self.casterHost
        self._proto_message.casterPort = self.casterPort
        self._proto_message.mountPoint = self.mountPoint
        self._proto_message.username = self.username
        self._proto_message.password = self.password

    @classmethod
    def _from_proto(cls, proto_message) -> "NtripBaseUpstream":
        return cls(
            casterHost = proto_message.casterHost,
            casterPort = proto_message.casterPort,
            mountPoint = proto_message.mountPoint,
            username = proto_message.username,
            password = proto_message.password,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "NtripBaseUpstream":
        message = ntrip_base_config_pb2.NtripBaseUpstream()
        message.ParseFromString(data)
        return cls._from_proto(message)

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message, preserving_proto_field_name=True)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "NtripBaseUpstream":
        message = ntrip_base_config_pb2.NtripBaseUpstream()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class NtripBaseDelivery:
    ntrip: bool = False
    mqtt: bool = False
    uplink: bool = False
    
    _proto_message: ntrip_base_config_pb2.NtripBaseDelivery = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = ntrip_base_config_pb2.NtripBaseDelivery()

    def _populate_proto(self):
        self._proto_message.ntrip = self.ntrip
        self._proto_message.mqtt = self.mqtt
        self._proto_message.uplink = self.uplink

    @classmethod
    def _from_proto(cls, proto_message) -> "NtripBaseDelivery":
        return cls(
            ntrip = proto_message.ntrip,
            mqtt = proto_message.mqtt,
            uplink = proto_message.uplink,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "NtripBaseDelivery":
        message = ntrip_base_config_pb2.NtripBaseDelivery()
        message.ParseFromString(data)
        return cls._from_proto(message)

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message, preserving_proto_field_name=True)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "NtripBaseDelivery":
        message = ntrip_base_config_pb2.NtripBaseDelivery()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())
class NtripBaseMode(Enum):
    NTRIP_BASE_MODE_SURVEY_IN = 0
    NTRIP_BASE_MODE_NTRIP_FIX = 1
    NTRIP_BASE_MODE_FIXED = 2
    NTRIP_BASE_MODE_RELAY = 3


@dataclass
class NtripBaseConfig:
    mode: NtripBaseMode = None
    surveyIn: NtripBaseSurveyIn = None
    upstream: NtripBaseUpstream = None
    ntripFix: NtripBaseFixAveraging = None
    fixed: NtripBaseFixedPosition = None
    delivery: NtripBaseDelivery = None
    
    _proto_message: ntrip_base_config_pb2.NtripBaseConfig = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = ntrip_base_config_pb2.NtripBaseConfig()

    def _populate_proto(self):
        self._proto_message.mode = self.mode.value
        if self.surveyIn:
            self.surveyIn._populate_proto()
            self._proto_message.surveyIn.CopyFrom(self.surveyIn._proto_message)
        if self.upstream:
            self.upstream._populate_proto()
            self._proto_message.upstream.CopyFrom(self.upstream._proto_message)
        if self.ntripFix:
            self.ntripFix._populate_proto()
            self._proto_message.ntripFix.CopyFrom(self.ntripFix._proto_message)
        if self.fixed:
            self.fixed._populate_proto()
            self._proto_message.fixed.CopyFrom(self.fixed._proto_message)
        if self.delivery:
            self.delivery._populate_proto()
            self._proto_message.delivery.CopyFrom(self.delivery._proto_message)

    @classmethod
    def _from_proto(cls, proto_message) -> "NtripBaseConfig":
        return cls(
            mode = NtripBaseMode(proto_message.mode),
            surveyIn = NtripBaseSurveyIn._from_proto(proto_message.surveyIn),
            upstream = NtripBaseUpstream._from_proto(proto_message.upstream),
            ntripFix = NtripBaseFixAveraging._from_proto(proto_message.ntripFix),
            fixed = NtripBaseFixedPosition._from_proto(proto_message.fixed),
            delivery = NtripBaseDelivery._from_proto(proto_message.delivery),
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "NtripBaseConfig":
        message = ntrip_base_config_pb2.NtripBaseConfig()
        message.ParseFromString(data)
        return cls._from_proto(message)

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message, preserving_proto_field_name=True)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "NtripBaseConfig":
        message = ntrip_base_config_pb2.NtripBaseConfig()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())
