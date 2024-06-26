#ifndef SERIALIZERS_H
#define SERIALIZERS_H

#include "app/app_config.h"
#include "app/app_data.h"
#include "app/user_data.h"
#include "app/data_processing.h"
#include "tpms/rtl433_payload.h"
#include "handcart/settings.h"
#include "data/vehicle_state.h"
#include "data/steer_command.h"
#include "influxlogger/configuration.h"
#include "sessions/gpsSession.h"
#include "lapcounter/lapcounter.h"
#include "lapcounter/lap_counter.h"
#include "actions/file_transaction.h"
#include "actions/command.h"
#include "can/can_frequencies.h"
#include "configs/telemetry_config.h"
#include "configs/car_config.h"
#include "configs/session_config.h"
#include "telemetry/status.h"
#include "telemetry/login_data.h"
#include "telemetry/statistics.h"
#include "telemetry/error.h"
#include "telemetry/gps_maps.h"
#include "telemetry/odometer.h"

#endif