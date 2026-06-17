from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict

from configs import car_config_pb2
from google.protobuf.json_format import MessageToJson, Parse


@dataclass
class Aero:
    angleOfIncidenceFront: float = 0.0
    angleOfIncidenceRear: float = 0.0
    flap: str = ""
    
    _proto_message: car_config_pb2.Aero = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = car_config_pb2.Aero()

    def _populate_proto(self):
        self._proto_message.angleOfIncidenceFront = self.angleOfIncidenceFront
        self._proto_message.angleOfIncidenceRear = self.angleOfIncidenceRear
        self._proto_message.flap = self.flap

    @classmethod
    def _from_proto(cls, proto_message) -> "Aero":
        return cls(
            angleOfIncidenceFront = proto_message.angleOfIncidenceFront,
            angleOfIncidenceRear = proto_message.angleOfIncidenceRear,
            flap = proto_message.flap,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Aero":
        message = car_config_pb2.Aero()
        message.ParseFromString(data)
        return cls(
            angleOfIncidenceFront = message.angleOfIncidenceFront,
            angleOfIncidenceRear = message.angleOfIncidenceRear,
            flap = message.flap,
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Aero":
        message = car_config_pb2.Aero()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class Wheel:
    camber: float = 0.0
    toe: float = 0.0
    pressure: str = ""
    
    _proto_message: car_config_pb2.Wheel = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = car_config_pb2.Wheel()

    def _populate_proto(self):
        self._proto_message.camber = self.camber
        self._proto_message.toe = self.toe
        self._proto_message.pressure = self.pressure

    @classmethod
    def _from_proto(cls, proto_message) -> "Wheel":
        return cls(
            camber = proto_message.camber,
            toe = proto_message.toe,
            pressure = proto_message.pressure,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Wheel":
        message = car_config_pb2.Wheel()
        message.ParseFromString(data)
        return cls(
            camber = message.camber,
            toe = message.toe,
            pressure = message.pressure,
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Wheel":
        message = car_config_pb2.Wheel()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class Damper:
    bound_low_comp: float = 0.0
    bound_high_comp: float = 0.0
    rebound: float = 0.0
    preload: float = 0.0
    
    _proto_message: car_config_pb2.Damper = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = car_config_pb2.Damper()

    def _populate_proto(self):
        self._proto_message.bound_low_comp = self.bound_low_comp
        self._proto_message.bound_high_comp = self.bound_high_comp
        self._proto_message.rebound = self.rebound
        self._proto_message.preload = self.preload

    @classmethod
    def _from_proto(cls, proto_message) -> "Damper":
        return cls(
            bound_low_comp = proto_message.bound_low_comp,
            bound_high_comp = proto_message.bound_high_comp,
            rebound = proto_message.rebound,
            preload = proto_message.preload,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Damper":
        message = car_config_pb2.Damper()
        message.ParseFromString(data)
        return cls(
            bound_low_comp = message.bound_low_comp,
            bound_high_comp = message.bound_high_comp,
            rebound = message.rebound,
            preload = message.preload,
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Damper":
        message = car_config_pb2.Damper()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class ImuCorrections:
    x: float = 0.0
    y: float = 0.0
    z: float = 0.0
    
    _proto_message: car_config_pb2.ImuCorrections = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = car_config_pb2.ImuCorrections()

    def _populate_proto(self):
        self._proto_message.x = self.x
        self._proto_message.y = self.y
        self._proto_message.z = self.z

    @classmethod
    def _from_proto(cls, proto_message) -> "ImuCorrections":
        return cls(
            x = proto_message.x,
            y = proto_message.y,
            z = proto_message.z,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "ImuCorrections":
        message = car_config_pb2.ImuCorrections()
        message.ParseFromString(data)
        return cls(
            x = message.x,
            y = message.y,
            z = message.z,
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "ImuCorrections":
        message = car_config_pb2.ImuCorrections()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class Tyre:
    startDate: str = ""
    id: str = ""
    kilometers: float = 0.0
    
    _proto_message: car_config_pb2.Tyre = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = car_config_pb2.Tyre()

    def _populate_proto(self):
        self._proto_message.startDate = self.startDate
        self._proto_message.id = self.id
        self._proto_message.kilometers = self.kilometers

    @classmethod
    def _from_proto(cls, proto_message) -> "Tyre":
        return cls(
            startDate = proto_message.startDate,
            id = proto_message.id,
            kilometers = proto_message.kilometers,
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Tyre":
        message = car_config_pb2.Tyre()
        message.ParseFromString(data)
        return cls(
            startDate = message.startDate,
            id = message.id,
            kilometers = message.kilometers,
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Tyre":
        message = car_config_pb2.Tyre()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class Odometer:
    fl: Tyre = None
    fr: Tyre = None
    rl: Tyre = None
    rr: Tyre = None
    
    _proto_message: car_config_pb2.Odometer = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = car_config_pb2.Odometer()

    def _populate_proto(self):
        if self.fl:
            self.fl._populate_proto()
            self._proto_message.fl.CopyFrom(self.fl._proto_message)
        if self.fr:
            self.fr._populate_proto()
            self._proto_message.fr.CopyFrom(self.fr._proto_message)
        if self.rl:
            self.rl._populate_proto()
            self._proto_message.rl.CopyFrom(self.rl._proto_message)
        if self.rr:
            self.rr._populate_proto()
            self._proto_message.rr.CopyFrom(self.rr._proto_message)

    @classmethod
    def _from_proto(cls, proto_message) -> "Odometer":
        return cls(
            fl = Tyre._from_proto(proto_message.fl),
            fr = Tyre._from_proto(proto_message.fr),
            rl = Tyre._from_proto(proto_message.rl),
            rr = Tyre._from_proto(proto_message.rr),
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "Odometer":
        message = car_config_pb2.Odometer()
        message.ParseFromString(data)
        return cls(
            fl = (
                Tyre._from_proto(message.fl)
                if message.HasField("fl")
                else None
            ),
            fr = (
                Tyre._from_proto(message.fr)
                if message.HasField("fr")
                else None
            ),
            rl = (
                Tyre._from_proto(message.rl)
                if message.HasField("rl")
                else None
            ),
            rr = (
                Tyre._from_proto(message.rr)
                if message.HasField("rr")
                else None
            ),
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "Odometer":
        message = car_config_pb2.Odometer()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())

@dataclass
class CarConfig:
    aero: Aero = None
    wheelFront: Wheel = None
    wheelRear: Wheel = None
    damperFront: Damper = None
    damperRear: Damper = None
    wheelCompound: str = ""
    rideHeight: float = 0.0
    balancing: str = ""
    notes: str = ""
    imuCorrections: ImuCorrections = None
    odometer: Odometer = None
    
    _proto_message: car_config_pb2.CarConfig = field(init=False, repr=False)

    def __post_init__(self):
        self._proto_message = car_config_pb2.CarConfig()

    def _populate_proto(self):
        if self.aero:
            self.aero._populate_proto()
            self._proto_message.aero.CopyFrom(self.aero._proto_message)
        if self.wheelFront:
            self.wheelFront._populate_proto()
            self._proto_message.wheelFront.CopyFrom(self.wheelFront._proto_message)
        if self.wheelRear:
            self.wheelRear._populate_proto()
            self._proto_message.wheelRear.CopyFrom(self.wheelRear._proto_message)
        if self.damperFront:
            self.damperFront._populate_proto()
            self._proto_message.damperFront.CopyFrom(self.damperFront._proto_message)
        if self.damperRear:
            self.damperRear._populate_proto()
            self._proto_message.damperRear.CopyFrom(self.damperRear._proto_message)
        self._proto_message.wheelCompound = self.wheelCompound
        self._proto_message.rideHeight = self.rideHeight
        self._proto_message.balancing = self.balancing
        self._proto_message.notes = self.notes
        if self.imuCorrections:
            self.imuCorrections._populate_proto()
            self._proto_message.imuCorrections.CopyFrom(self.imuCorrections._proto_message)
        if self.odometer:
            self.odometer._populate_proto()
            self._proto_message.odometer.CopyFrom(self.odometer._proto_message)

    @classmethod
    def _from_proto(cls, proto_message) -> "CarConfig":
        return cls(
            aero = Aero._from_proto(proto_message.aero),
            wheelFront = Wheel._from_proto(proto_message.wheelFront),
            wheelRear = Wheel._from_proto(proto_message.wheelRear),
            damperFront = Damper._from_proto(proto_message.damperFront),
            damperRear = Damper._from_proto(proto_message.damperRear),
            wheelCompound = proto_message.wheelCompound,
            rideHeight = proto_message.rideHeight,
            balancing = proto_message.balancing,
            notes = proto_message.notes,
            imuCorrections = ImuCorrections._from_proto(proto_message.imuCorrections),
            odometer = Odometer._from_proto(proto_message.odometer),
        )

    def __str__(self):
        return self.serializeAsJsonString()

    def serializeAsProtobufString(self) -> bytes:
        self._populate_proto()
        return self._proto_message.SerializeToString()

    @classmethod
    def deserializeFromProtobufString(cls, data: bytes) -> "CarConfig":
        message = car_config_pb2.CarConfig()
        message.ParseFromString(data)
        return cls(
            aero = (
                Aero._from_proto(message.aero)
                if message.HasField("aero")
                else None
            ),
            wheelFront = (
                Wheel._from_proto(message.wheelFront)
                if message.HasField("wheelFront")
                else None
            ),
            wheelRear = (
                Wheel._from_proto(message.wheelRear)
                if message.HasField("wheelRear")
                else None
            ),
            damperFront = (
                Damper._from_proto(message.damperFront)
                if message.HasField("damperFront")
                else None
            ),
            damperRear = (
                Damper._from_proto(message.damperRear)
                if message.HasField("damperRear")
                else None
            ),
            wheelCompound = message.wheelCompound,
            rideHeight = message.rideHeight,
            balancing = message.balancing,
            notes = message.notes,
            imuCorrections = (
                ImuCorrections._from_proto(message.imuCorrections)
                if message.HasField("imuCorrections")
                else None
            ),
            odometer = (
                Odometer._from_proto(message.odometer)
                if message.HasField("odometer")
                else None
            ),
        )

    def serializeAsJsonString(self) -> str:
        self._populate_proto()
        return MessageToJson(self._proto_message)

    @classmethod
    def deserializeFromJsonString(cls, data: str) -> "CarConfig":
        message = car_config_pb2.CarConfig()
        Parse(data, message)
        return cls.deserializeFromProtobufString(message.SerializeToString())
