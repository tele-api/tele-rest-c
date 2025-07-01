/*
 * mask_position.h
 *
 * This object describes the position on faces where a mask should be placed by default.
 */

#ifndef _mask_position_H_
#define _mask_position_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct mask_position_t mask_position_t;


// Enum POINT for mask_position

typedef enum  { telegram_bot_api_mask_position_POINT_NULL = 0, telegram_bot_api_mask_position_POINT_forehead, telegram_bot_api_mask_position_POINT_eyes, telegram_bot_api_mask_position_POINT_mouth, telegram_bot_api_mask_position_POINT_chin } telegram_bot_api_mask_position_POINT_e;

char* mask_position_point_ToString(telegram_bot_api_mask_position_POINT_e point);

telegram_bot_api_mask_position_POINT_e mask_position_point_FromString(char* point);



typedef struct mask_position_t {
    telegram_bot_api_mask_position_POINT_e point; //enum
    double x_shift; //numeric
    double y_shift; //numeric
    double scale; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} mask_position_t;

__attribute__((deprecated)) mask_position_t *mask_position_create(
    telegram_bot_api_mask_position_POINT_e point,
    double x_shift,
    double y_shift,
    double scale
);

void mask_position_free(mask_position_t *mask_position);

mask_position_t *mask_position_parseFromJSON(cJSON *mask_positionJSON);

cJSON *mask_position_convertToJSON(mask_position_t *mask_position);

#endif /* _mask_position_H_ */

