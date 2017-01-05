#ifndef   _MESH_SYNC_H_
#define   _MESH_SYNC_H_

#include <Arduino.h>

#define SCAN_INTERVAL       10000
#define SYNC_INTERVAL       7000
#define TIME_SYNC_INTERVAL  60000000
#define NUMBER_OF_TIMESTAMS 4
#define MIN_ACCURACY        10000 // Minimum time sync accuracy

enum timeSyncMessageType_t {
    TIME_SYNC_ERROR = -1,
    TIME_SYNC_REQUEST,
    TIME_REQUEST,
    TIME_RESPONSE
};

class timeSync {
public:
    uint32_t        times[NUMBER_OF_TIMESTAMS];

    String buildTimeStamp(timeSyncMessageType_t timeSyncMessageType, uint32_t originateTS = 0, uint32_t receiveTS = 0, uint32_t transmitTS = 0);
    timeSyncMessageType_t processTimeStamp(String &str);
    int32_t calcAdjustment();
};

#endif //   _MESH_SYNC_H_

