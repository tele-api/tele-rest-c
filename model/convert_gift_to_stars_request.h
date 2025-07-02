/*
 * convert_gift_to_stars_request.h
 *
 * Request parameters for convertGiftToStars
 */

#ifndef _convert_gift_to_stars_request_H_
#define _convert_gift_to_stars_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct convert_gift_to_stars_request_t convert_gift_to_stars_request_t;




typedef struct convert_gift_to_stars_request_t {
    char *business_connection_id; // string
    char *owned_gift_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} convert_gift_to_stars_request_t;

__attribute__((deprecated)) convert_gift_to_stars_request_t *convert_gift_to_stars_request_create(
    char *business_connection_id,
    char *owned_gift_id
);

void convert_gift_to_stars_request_free(convert_gift_to_stars_request_t *convert_gift_to_stars_request);

convert_gift_to_stars_request_t *convert_gift_to_stars_request_parseFromJSON(cJSON *convert_gift_to_stars_requestJSON);

cJSON *convert_gift_to_stars_request_convertToJSON(convert_gift_to_stars_request_t *convert_gift_to_stars_request);

#endif /* _convert_gift_to_stars_request_H_ */

