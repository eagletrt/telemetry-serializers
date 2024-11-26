from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict

from influxlogger import configuration_pb2
from google.protobuf.json_format import MessageToJson, Parse


@dataclass
class Configuration:
    mqtt_host: str = ""
    mqtt_port: int = 0
    vehicle_id: str = ""
    device_id: str = ""
    influx_host: str = ""
    influx_port: int = 0
    influx_https: bool = ""
    influx_bucket: str = ""
    influx_orgid: str = ""
    influx_token: str = ""
    networks: List[str] = field(default_factory=list)
    proxy_host: str = ""
    proxy_port: int = 0
    
    _proto_message: configuration_pb2.Configuration = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = configuration_pb2.Configuration()

    def populate_proto(self):
        self._proto_message.mqtt_host = self.mqtt_host
        self._proto_message.mqtt_port = self.mqtt_port
        self._proto_message.vehicle_id = self.vehicle_id
        self._proto_message.device_id = self.device_id
        self._proto_message.influx_host = self.influx_host
        self._proto_message.influx_port = self.influx_port
        self._proto_message.influx_https = self.influx_https
        self._proto_message.influx_bucket = self.influx_bucket
        self._proto_message.influx_orgid = self.influx_orgid
        self._proto_message.influx_token = self.influx_token
        del self._proto_message.networks[:]
        for value in self.networks:
            value.populate_proto()
            tmp = self._proto_message.networks.add()
            tmp.CopyFrom(value._proto_message)
        self._proto_message.proxy_host = self.proxy_host
        self._proto_message.proxy_port = self.proxy_port

    def serializeAsProtobufString(self) -> bytes:
        self.populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Configuration":
        message = configuration_pb2.Configuration()
        message.ParseFromString(data)
        return cls(
            mqtt_host=message.mqtt_host,
            mqtt_port=message.mqtt_port,
            vehicle_id=message.vehicle_id,
            device_id=message.device_id,
            influx_host=message.influx_host,
            influx_port=message.influx_port,
            influx_https=message.influx_https,
            influx_bucket=message.influx_bucket,
            influx_orgid=message.influx_orgid,
            influx_token=message.influx_token,
            networks=[str(value) for value in message.networks],
            proxy_host=message.proxy_host,
            proxy_port=message.proxy_port,
        )

    def serializeAsJsonString(self) -> str:
        self.populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Configuration":
        message = configuration_pb2.Configuration()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

    def __str__(self):
        return self.serializeAsJsonString()
