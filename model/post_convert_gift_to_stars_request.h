/*
 * post_convert_gift_to_stars_request.h
 *
 * 
 */

#ifndef _post_convert_gift_to_stars_request_H_
#define _post_convert_gift_to_stars_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct post_convert_gift_to_stars_request_t post_convert_gift_to_stars_request_t;




typedef struct post_convert_gift_to_stars_request_t {
    char *business_connection_id; // string
    char *owned_gift_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} post_convert_gift_to_stars_request_t;

__attribute__((deprecated)) post_convert_gift_to_stars_request_t *post_convert_gift_to_stars_request_create(
    char *business_connection_id,
    char *owned_gift_id
);

void post_convert_gift_to_stars_request_free(post_convert_gift_to_stars_request_t *post_convert_gift_to_stars_request);

post_convert_gift_to_stars_request_t *post_convert_gift_to_stars_request_parseFromJSON(cJSON *post_convert_gift_to_stars_requestJSON);

cJSON *post_convert_gift_to_stars_request_convertToJSON(post_convert_gift_to_stars_request_t *post_convert_gift_to_stars_request);

#endif /* _post_convert_gift_to_stars_request_H_ */

