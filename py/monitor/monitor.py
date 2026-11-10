from dataclasses import dataclass, field
from enum import Enum
from typing import List, Dict, Optional

from monitor import monitor_pb2
from google.protobuf.json_format import MessageToJson, Parse

