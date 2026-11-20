from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict, Optional

from monitor import monitor_pb2
from google.protobuf.json_format import MessageToJson, Parse

class ServiceState(Enum):
    SERVICE_STATE_INIT = 0
    SERVICE_STATE_IDLE = 1
    SERVICE_STATE_RUN = 2
    SERVICE_STATE_ERROR = 3
    SERVICE_STATE_STOP = 4
    SERVICE_STATE_OFFLINE = 5

class Capability(Enum):
    CAPABILITY_CPU_STATS = 0
    CAPABILITY_RAM_STATS = 1
    CAPABILITY_CONNECTION_STATS = 2
    CAPABILITY_FIX = 3

class Severity(Enum):
    SEVERITY_DEBUG = 0
    SEVERITY_INFO = 1
    SEVERITY_WARNING = 2
    SEVERITY_ERROR = 3


@dataclass
class Setup:
    timestamp: int = 0
    name: str = ""
    version: str = ""
    address: str = ""
    heartbeatSeconds: int = 0
    
    _proto_message: monitor_pb2.Setup = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = monitor_pb2.Setup()

    def _populate_proto(self):
        self._proto_message.timestamp = self.timestamp
        self._proto_message.name = self.name
        self._proto_message.version = self.version
        self._proto_message.address = self.address
        self._proto_message.heartbeatSeconds = self.heartbeatSeconds

    @classmethod
    def _from_proto(cls, proto_message) -> "Setup":
        return cls(
            timestamp = proto_message.timestamp,
            name = proto_message.name,
            version = proto_message.version,
            address = proto_message.address,
            heartbeatSeconds = proto_message.heartbeatSeconds,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Setup":
        message = monitor_pb2.Setup()
        message.ParseFromString(data)
        return cls._from_proto(message)

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message, preserving_proto_field_name=True)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Setup":
        message = monitor_pb2.Setup()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class State:
    timestamp: int = 0
    state: ServiceState = None
    
    _proto_message: monitor_pb2.State = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = monitor_pb2.State()

    def _populate_proto(self):
        self._proto_message.timestamp = self.timestamp
        self._proto_message.state = self.state.value

    @classmethod
    def _from_proto(cls, proto_message) -> "State":
        return cls(
            timestamp = proto_message.timestamp,
            state = ServiceState(proto_message.state),
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "State":
        message = monitor_pb2.State()
        message.ParseFromString(data)
        return cls._from_proto(message)

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message, preserving_proto_field_name=True)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "State":
        message = monitor_pb2.State()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class Alive:
    timestamp: int = 0
    uptimeMs: int = 0
    
    _proto_message: monitor_pb2.Alive = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = monitor_pb2.Alive()

    def _populate_proto(self):
        self._proto_message.timestamp = self.timestamp
        self._proto_message.uptimeMs = self.uptimeMs

    @classmethod
    def _from_proto(cls, proto_message) -> "Alive":
        return cls(
            timestamp = proto_message.timestamp,
            uptimeMs = proto_message.uptimeMs,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Alive":
        message = monitor_pb2.Alive()
        message.ParseFromString(data)
        return cls._from_proto(message)

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message, preserving_proto_field_name=True)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Alive":
        message = monitor_pb2.Alive()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class CpuStats:
    timestamp: int = 0
    usage: float = 0.0
    processUsage: float = 0.0
    temperature: float = 0.0
    
    _proto_message: monitor_pb2.CpuStats = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = monitor_pb2.CpuStats()

    def _populate_proto(self):
        self._proto_message.timestamp = self.timestamp
        self._proto_message.usage = self.usage
        self._proto_message.processUsage = self.processUsage
        self._proto_message.temperature = self.temperature

    @classmethod
    def _from_proto(cls, proto_message) -> "CpuStats":
        return cls(
            timestamp = proto_message.timestamp,
            usage = proto_message.usage,
            processUsage = proto_message.processUsage,
            temperature = proto_message.temperature,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "CpuStats":
        message = monitor_pb2.CpuStats()
        message.ParseFromString(data)
        return cls._from_proto(message)

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message, preserving_proto_field_name=True)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "CpuStats":
        message = monitor_pb2.CpuStats()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class RAMStats:
    timestamp: int = 0
    usage: float = 0.0
    processUsage: float = 0.0
    memoryAvailable: int = 0
    
    _proto_message: monitor_pb2.RAMStats = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = monitor_pb2.RAMStats()

    def _populate_proto(self):
        self._proto_message.timestamp = self.timestamp
        self._proto_message.usage = self.usage
        self._proto_message.processUsage = self.processUsage
        self._proto_message.memoryAvailable = self.memoryAvailable

    @classmethod
    def _from_proto(cls, proto_message) -> "RAMStats":
        return cls(
            timestamp = proto_message.timestamp,
            usage = proto_message.usage,
            processUsage = proto_message.processUsage,
            memoryAvailable = proto_message.memoryAvailable,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "RAMStats":
        message = monitor_pb2.RAMStats()
        message.ParseFromString(data)
        return cls._from_proto(message)

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message, preserving_proto_field_name=True)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "RAMStats":
        message = monitor_pb2.RAMStats()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class Link:
    name: str = ""
    connected: bool = False
    bytesSent: int = 0
    bytesReceived: int = 0
    rttMs: float = 0.0
    
    _proto_message: monitor_pb2.Link = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = monitor_pb2.Link()

    def _populate_proto(self):
        self._proto_message.name = self.name
        self._proto_message.connected = self.connected
        self._proto_message.bytesSent = self.bytesSent
        self._proto_message.bytesReceived = self.bytesReceived
        self._proto_message.rttMs = self.rttMs

    @classmethod
    def _from_proto(cls, proto_message) -> "Link":
        return cls(
            name = proto_message.name,
            connected = proto_message.connected,
            bytesSent = proto_message.bytesSent,
            bytesReceived = proto_message.bytesReceived,
            rttMs = proto_message.rttMs,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Link":
        message = monitor_pb2.Link()
        message.ParseFromString(data)
        return cls._from_proto(message)

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message, preserving_proto_field_name=True)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Link":
        message = monitor_pb2.Link()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class ConnectionStats:
    timestamp: int = 0
    links: List[Link] = field(default_factory=list)
    
    _proto_message: monitor_pb2.ConnectionStats = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = monitor_pb2.ConnectionStats()

    def _populate_proto(self):
        self._proto_message.timestamp = self.timestamp
        del self._proto_message.links[:]
        for val in self.links:
            val._populate_proto()
            tmp = self._proto_message.links.add()
            tmp.CopyFrom(val._proto_message)

    @classmethod
    def _from_proto(cls, proto_message) -> "ConnectionStats":
        return cls(
            timestamp = proto_message.timestamp,
            links=[Link._from_proto(val) for val in proto_message.links],
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "ConnectionStats":
        message = monitor_pb2.ConnectionStats()
        message.ParseFromString(data)
        return cls._from_proto(message)

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message, preserving_proto_field_name=True)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "ConnectionStats":
        message = monitor_pb2.ConnectionStats()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())
