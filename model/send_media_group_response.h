/*
 * send_media_group_response.h
 *
 * 
 */

#ifndef _send_media_group_response_H_
#define _send_media_group_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct send_media_group_response_t send_media_group_response_t;

#include "message.h"



typedef struct send_media_group_response_t {
    int ok; //boolean
    list_t *result; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} send_media_group_response_t;

__attribute__((deprecated)) send_media_group_response_t *send_media_group_response_create(
    int ok,
    list_t *result
);

void send_media_group_response_free(send_media_group_response_t *send_media_group_response);

send_media_group_response_t *send_media_group_response_parseFromJSON(cJSON *send_media_group_responseJSON);

cJSON *send_media_group_response_convertToJSON(send_media_group_response_t *send_media_group_response);

#endif /* _send_media_group_response_H_ */

