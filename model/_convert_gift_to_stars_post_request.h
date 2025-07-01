/*
 * _convert_gift_to_stars_post_request.h
 *
 * 
 */

#ifndef __convert_gift_to_stars_post_request_H_
#define __convert_gift_to_stars_post_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct _convert_gift_to_stars_post_request_t _convert_gift_to_stars_post_request_t;




typedef struct _convert_gift_to_stars_post_request_t {
    char *business_connection_id; // string
    char *owned_gift_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} _convert_gift_to_stars_post_request_t;

__attribute__((deprecated)) _convert_gift_to_stars_post_request_t *_convert_gift_to_stars_post_request_create(
    char *business_connection_id,
    char *owned_gift_id
);

void _convert_gift_to_stars_post_request_free(_convert_gift_to_stars_post_request_t *_convert_gift_to_stars_post_request);

_convert_gift_to_stars_post_request_t *_convert_gift_to_stars_post_request_parseFromJSON(cJSON *_convert_gift_to_stars_post_requestJSON);

cJSON *_convert_gift_to_stars_post_request_convertToJSON(_convert_gift_to_stars_post_request_t *_convert_gift_to_stars_post_request);

#endif /* __convert_gift_to_stars_post_request_H_ */

