from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict

from configs import telemetry_config_pb2
from google.protobuf.json_format import MessageToJson, Parse


@dataclass
class CanDevice:
    socket: str = ""
    name: str = ""
    networks: List[str] = field(default_factory=list)
    
    _proto_message: telemetry_config_pb2.CanDevice = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = telemetry_config_pb2.CanDevice()

    def _populate_proto(self):
        self._proto_message.socket = self.socket
        self._proto_message.name = self.name
        del self._proto_message.networks[:]
        for val in self.networks:
            self._proto_message.networks.append(val)

    @classmethod
    def _from_proto(cls, proto_message) -> "CanDevice":
        return cls(
            socket = proto_message.socket,
            name = proto_message.name,
            networks=[str(val) for val in proto_message.networks],
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "CanDevice":
        message = telemetry_config_pb2.CanDevice()
        message.ParseFromString(data)
        return cls(
            socket = message.socket,
            name = message.name,
            networks = [str(val) for val in message.networks],
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "CanDevice":
        message = telemetry_config_pb2.CanDevice()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class GpsDevice:
    address: str = ""
    mode: str = ""
    enabled: bool = False
    
    _proto_message: telemetry_config_pb2.GpsDevice = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = telemetry_config_pb2.GpsDevice()

    def _populate_proto(self):
        self._proto_message.address = self.address
        self._proto_message.mode = self.mode
        self._proto_message.enabled = self.enabled

    @classmethod
    def _from_proto(cls, proto_message) -> "GpsDevice":
        return cls(
            address = proto_message.address,
            mode = proto_message.mode,
            enabled = proto_message.enabled,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "GpsDevice":
        message = telemetry_config_pb2.GpsDevice()
        message.ParseFromString(data)
        return cls(
            address = message.address,
            mode = message.mode,
            enabled = message.enabled,
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "GpsDevice":
        message = telemetry_config_pb2.GpsDevice()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class Connection:
    ip: str = ""
    port: str = ""
    mode: str = ""
    whoamiUrl: str = ""
    tlsEnabled: bool = False
    cafile: str = ""
    capath: str = ""
    certfile: str = ""
    keyfile: str = ""
    
    _proto_message: telemetry_config_pb2.Connection = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = telemetry_config_pb2.Connection()

    def _populate_proto(self):
        self._proto_message.ip = self.ip
        self._proto_message.port = self.port
        self._proto_message.mode = self.mode
        self._proto_message.whoamiUrl = self.whoamiUrl
        self._proto_message.tlsEnabled = self.tlsEnabled
        self._proto_message.cafile = self.cafile
        self._proto_message.capath = self.capath
        self._proto_message.certfile = self.certfile
        self._proto_message.keyfile = self.keyfile

    @classmethod
    def _from_proto(cls, proto_message) -> "Connection":
        return cls(
            ip = proto_message.ip,
            port = proto_message.port,
            mode = proto_message.mode,
            whoamiUrl = proto_message.whoamiUrl,
            tlsEnabled = proto_message.tlsEnabled,
            cafile = proto_message.cafile,
            capath = proto_message.capath,
            certfile = proto_message.certfile,
            keyfile = proto_message.keyfile,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Connection":
        message = telemetry_config_pb2.Connection()
        message.ParseFromString(data)
        return cls(
            ip = message.ip,
            port = message.port,
            mode = message.mode,
            whoamiUrl = message.whoamiUrl,
            tlsEnabled = message.tlsEnabled,
            cafile = message.cafile,
            capath = message.capath,
            certfile = message.certfile,
            keyfile = message.keyfile,
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Connection":
        message = telemetry_config_pb2.Connection()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class ConnectionSettings:
    enabled: bool = False
    downsampleEnabled: bool = False
    downsampleSkipData: bool = False
    downsampleMps: int = 0
    sendRate: int = 0
    sendSensorData: bool = False
    
    _proto_message: telemetry_config_pb2.ConnectionSettings = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = telemetry_config_pb2.ConnectionSettings()

    def _populate_proto(self):
        self._proto_message.enabled = self.enabled
        self._proto_message.downsampleEnabled = self.downsampleEnabled
        self._proto_message.downsampleSkipData = self.downsampleSkipData
        self._proto_message.downsampleMps = self.downsampleMps
        self._proto_message.sendRate = self.sendRate
        self._proto_message.sendSensorData = self.sendSensorData

    @classmethod
    def _from_proto(cls, proto_message) -> "ConnectionSettings":
        return cls(
            enabled = proto_message.enabled,
            downsampleEnabled = proto_message.downsampleEnabled,
            downsampleSkipData = proto_message.downsampleSkipData,
            downsampleMps = proto_message.downsampleMps,
            sendRate = proto_message.sendRate,
            sendSensorData = proto_message.sendSensorData,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "ConnectionSettings":
        message = telemetry_config_pb2.ConnectionSettings()
        message.ParseFromString(data)
        return cls(
            enabled = message.enabled,
            downsampleEnabled = message.downsampleEnabled,
            downsampleSkipData = message.downsampleSkipData,
            downsampleMps = message.downsampleMps,
            sendRate = message.sendRate,
            sendSensorData = message.sendSensorData,
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "ConnectionSettings":
        message = telemetry_config_pb2.ConnectionSettings()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class TpmsSensorIds:
    fl: int = 0
    fr: int = 0
    rl: int = 0
    rr: int = 0
    
    _proto_message: telemetry_config_pb2.TpmsSensorIds = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = telemetry_config_pb2.TpmsSensorIds()

    def _populate_proto(self):
        self._proto_message.fl = self.fl
        self._proto_message.fr = self.fr
        self._proto_message.rl = self.rl
        self._proto_message.rr = self.rr

    @classmethod
    def _from_proto(cls, proto_message) -> "TpmsSensorIds":
        return cls(
            fl = proto_message.fl,
            fr = proto_message.fr,
            rl = proto_message.rl,
            rr = proto_message.rr,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "TpmsSensorIds":
        message = telemetry_config_pb2.TpmsSensorIds()
        message.ParseFromString(data)
        return cls(
            fl = message.fl,
            fr = message.fr,
            rl = message.rl,
            rr = message.rr,
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "TpmsSensorIds":
        message = telemetry_config_pb2.TpmsSensorIds()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class TpmsSensors:
    enabled: bool = False
    rtl433Path: str = ""
    recordSignals: bool = False
    sensorIds: TpmsSensorIds = None
    
    _proto_message: telemetry_config_pb2.TpmsSensors = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = telemetry_config_pb2.TpmsSensors()

    def _populate_proto(self):
        self._proto_message.enabled = self.enabled
        self._proto_message.rtl433Path = self.rtl433Path
        self._proto_message.recordSignals = self.recordSignals
        if self.sensorIds:
            self.sensorIds._populate_proto()
            self._proto_message.sensorIds.CopyFrom(self.sensorIds._proto_message)

    @classmethod
    def _from_proto(cls, proto_message) -> "TpmsSensors":
        return cls(
            enabled = proto_message.enabled,
            rtl433Path = proto_message.rtl433Path,
            recordSignals = proto_message.recordSignals,
            sensorIds = TpmsSensorIds._from_proto(proto_message.sensorIds),
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "TpmsSensors":
        message = telemetry_config_pb2.TpmsSensors()
        message.ParseFromString(data)
        return cls(
            enabled = message.enabled,
            rtl433Path = message.rtl433Path,
            recordSignals = message.recordSignals,
            sensorIds = (
                TpmsSensorIds._from_proto(message.sensorIds)
                if message.HasField("sensorIds")
                else None
            ),
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "TpmsSensors":
        message = telemetry_config_pb2.TpmsSensors()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class TelemetryConfig:
    vehicleId: str = ""
    deviceId: str = ""
    role: int = 0
    cameraEnabled: bool = False
    generateCsv: bool = False
    waitForReady: bool = False
    connection: Connection = None
    connectionSettings: ConnectionSettings = None
    canDevices: List[CanDevice] = field(default_factory=list)
    gpsDevices: List[GpsDevice] = field(default_factory=list)
    tpmsSensors: TpmsSensors = None
    
    _proto_message: telemetry_config_pb2.TelemetryConfig = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = telemetry_config_pb2.TelemetryConfig()

    def _populate_proto(self):
        self._proto_message.vehicleId = self.vehicleId
        self._proto_message.deviceId = self.deviceId
        self._proto_message.role = self.role
        self._proto_message.cameraEnabled = self.cameraEnabled
        self._proto_message.generateCsv = self.generateCsv
        self._proto_message.waitForReady = self.waitForReady
        if self.connection:
            self.connection._populate_proto()
            self._proto_message.connection.CopyFrom(self.connection._proto_message)
        if self.connectionSettings:
            self.connectionSettings._populate_proto()
            self._proto_message.connectionSettings.CopyFrom(self.connectionSettings._proto_message)
        del self._proto_message.canDevices[:]
        for val in self.canDevices:
            val._populate_proto()
            tmp = self._proto_message.canDevices.add()
            tmp.CopyFrom(val._proto_message)
        del self._proto_message.gpsDevices[:]
        for val in self.gpsDevices:
            val._populate_proto()
            tmp = self._proto_message.gpsDevices.add()
            tmp.CopyFrom(val._proto_message)
        if self.tpmsSensors:
            self.tpmsSensors._populate_proto()
            self._proto_message.tpmsSensors.CopyFrom(self.tpmsSensors._proto_message)

    @classmethod
    def _from_proto(cls, proto_message) -> "TelemetryConfig":
        return cls(
            vehicleId = proto_message.vehicleId,
            deviceId = proto_message.deviceId,
            role = proto_message.role,
            cameraEnabled = proto_message.cameraEnabled,
            generateCsv = proto_message.generateCsv,
            waitForReady = proto_message.waitForReady,
            connection = Connection._from_proto(proto_message.connection),
            connectionSettings = ConnectionSettings._from_proto(proto_message.connectionSettings),
            canDevices=[CanDevice._from_proto(val) for val in proto_message.canDevices],
            gpsDevices=[GpsDevice._from_proto(val) for val in proto_message.gpsDevices],
            tpmsSensors = TpmsSensors._from_proto(proto_message.tpmsSensors),
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "TelemetryConfig":
        message = telemetry_config_pb2.TelemetryConfig()
        message.ParseFromString(data)
        return cls(
            vehicleId = message.vehicleId,
            deviceId = message.deviceId,
            role = message.role,
            cameraEnabled = message.cameraEnabled,
            generateCsv = message.generateCsv,
            waitForReady = message.waitForReady,
            connection = (
                Connection._from_proto(message.connection)
                if message.HasField("connection")
                else None
            ),
            connectionSettings = (
                ConnectionSettings._from_proto(message.connectionSettings)
                if message.HasField("connectionSettings")
                else None
            ),
            canDevices = [CanDevice._from_proto(val) for val in message.canDevices],
            gpsDevices = [GpsDevice._from_proto(val) for val in message.gpsDevices],
            tpmsSensors = (
                TpmsSensors._from_proto(message.tpmsSensors)
                if message.HasField("tpmsSensors")
                else None
            ),
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "TelemetryConfig":
        message = telemetry_config_pb2.TelemetryConfig()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())
