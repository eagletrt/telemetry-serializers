from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict

from configs import forwarder_config_pb2
from google.protobuf.json_format import MessageToJson, Parse


@dataclass
class NtripClient:
    casterHost: str = ""
    casterPort: int = 0
    mountPoint: str = ""
    username: str = ""
    password: str = ""
    
    _proto_message: forwarder_config_pb2.NtripClient = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = forwarder_config_pb2.NtripClient()

    def _populate_proto(self):
        self._proto_message.casterHost = self.casterHost
        self._proto_message.casterPort = self.casterPort
        self._proto_message.mountPoint = self.mountPoint
        self._proto_message.username = self.username
        self._proto_message.password = self.password

    @classmethod
    def _from_proto(cls, proto_message) -> "NtripClient":
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
    def deserializeFromProtobufString(cls, data: bytes) -> "NtripClient":
        message = forwarder_config_pb2.NtripClient()
        message.ParseFromString(data)
        return cls(
            casterHost = message.casterHost,
            casterPort = message.casterPort,
            mountPoint = message.mountPoint,
            username = message.username,
            password = message.password,
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "NtripClient":
        message = forwarder_config_pb2.NtripClient()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class GpsDev:
    address: str = ""
    port: str = ""
    mode: str = ""
    enabled: bool = False
    
    _proto_message: forwarder_config_pb2.GpsDev = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = forwarder_config_pb2.GpsDev()

    def _populate_proto(self):
        self._proto_message.address = self.address
        self._proto_message.port = self.port
        self._proto_message.mode = self.mode
        self._proto_message.enabled = self.enabled

    @classmethod
    def _from_proto(cls, proto_message) -> "GpsDev":
        return cls(
            address = proto_message.address,
            port = proto_message.port,
            mode = proto_message.mode,
            enabled = proto_message.enabled,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "GpsDev":
        message = forwarder_config_pb2.GpsDev()
        message.ParseFromString(data)
        return cls(
            address = message.address,
            port = message.port,
            mode = message.mode,
            enabled = message.enabled,
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "GpsDev":
        message = forwarder_config_pb2.GpsDev()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class ForwarderConfig:
    gpsDevice: GpsDev = None
    ntripClient: NtripClient = None
    
    _proto_message: forwarder_config_pb2.ForwarderConfig = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = forwarder_config_pb2.ForwarderConfig()

    def _populate_proto(self):
        if self.gpsDevice:
            self.gpsDevice._populate_proto()
            self._proto_message.gpsDevice.CopyFrom(self.gpsDevice._proto_message)
        if self.ntripClient:
            self.ntripClient._populate_proto()
            self._proto_message.ntripClient.CopyFrom(self.ntripClient._proto_message)

    @classmethod
    def _from_proto(cls, proto_message) -> "ForwarderConfig":
        return cls(
            gpsDevice = GpsDev._from_proto(proto_message.gpsDevice),
            ntripClient = NtripClient._from_proto(proto_message.ntripClient),
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "ForwarderConfig":
        message = forwarder_config_pb2.ForwarderConfig()
        message.ParseFromString(data)
        return cls(
            gpsDevice = (
                GpsDev._from_proto(message.gpsDevice)
                if message.HasField("gpsDevice")
                else None
            ),
            ntripClient = (
                NtripClient._from_proto(message.ntripClient)
                if message.HasField("ntripClient")
                else None
            ),
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "ForwarderConfig":
        message = forwarder_config_pb2.ForwarderConfig()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())
